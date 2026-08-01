#include "global.h"
#include "data.h"
#include "debug.h"
#include "event_data.h"
#include "load_save.h"
#include "party_menu.h"
#include "pokemon.h"
#include "script_pokemon_util.h"
#include "shining_trial.h"
#include "constants/pokemon.h"
#include "constants/shining_trial.h"
#include "constants/species.h"
#include "constants/battle_ai.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"

#if TX_DEBUG_SYSTEM_ENABLE == TRUE
#include "string_util.h"
#include "strings.h"
#include "constants/battle.h"
#endif

enum
{
    SHINING_TRIAL_STATE_NONE,
    SHINING_TRIAL_STATE_IN_BATTLE,
    SHINING_TRIAL_STATE_RESTORED,
};

EWRAM_DATA static u32 sShiningTrialPersonality = 0;
EWRAM_DATA static u32 sShiningTrialOtId = 0;
EWRAM_DATA static u16 sShiningTrialChecksum = 0;
EWRAM_DATA static u8 sShiningTrialState = SHINING_TRIAL_STATE_NONE;

static const struct Trainer sShiningTrialTrainer =
{
    .trainerClass = TRAINER_CLASS_EXPERT,
    .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
    .trainerPic = TRAINER_PIC_EXPERT_F,
    .trainerName = _("AURELIA"),
    .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    .doubleBattle = FALSE,
    .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
    .partySize = 1,
};

const struct Trainer *GetShiningTrialTrainer(void)
{
    return &sShiningTrialTrainer;
}

bool8 ShiningTrial_CreateMirror(struct Pokemon *dest)
{
    u32 i, value, level, exp;
    u16 species;

    // Work only on a copy: the player's Pokémon is restored after battle and
    // receives only the final PID conversion if it wins.
    *dest = gPlayerParty[0];
    if (!MakeMonShinyPreservingAttributes(dest))
        return FALSE;

    species = GetMonData(dest, MON_DATA_SPECIES);
    level = GetMonData(dest, MON_DATA_LEVEL) + 10;
    if (level > MAX_LEVEL)
        level = MAX_LEVEL;
    exp = gExperienceTables[gSpeciesInfo[species].growthRate][level];
    SetMonData(dest, MON_DATA_EXP, &exp);

    for (i = 0; i < NUM_STATS; i++)
    {
        value = MAX_PER_STAT_IVS;
        SetMonData(dest, MON_DATA_HP_IV + i, &value);
    }

    for (i = 0; i < NUM_STATS; i++)
    {
        value = 0;
        SetMonData(dest, MON_DATA_HP_EV + i, &value);
    }
    value = 252;
    SetMonData(dest, MON_DATA_HP_EV, &value);
    SetMonData(dest, gSpeciesInfo[species].baseAttack >= gSpeciesInfo[species].baseSpAttack
                     ? MON_DATA_ATK_EV : MON_DATA_SPATK_EV, &value);
    value = MAX_TOTAL_EVS - (2 * 252);
    SetMonData(dest, MON_DATA_SPEED_EV, &value);

    CalculateMonStats(dest);

    // The mirror borrows identity and moves, but not incidental battle state
    // or an item that happened to be held when the trial began.
    value = 0;
    SetMonData(dest, MON_DATA_STATUS, &value);
    SetMonData(dest, MON_DATA_HELD_ITEM, &value);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        value = CalculatePPWithBonus(GetMonData(dest, MON_DATA_MOVE1 + i),
                                     GetMonData(dest, MON_DATA_PP_BONUSES), i);
        SetMonData(dest, MON_DATA_PP1 + i, &value);
    }
    value = GetMonData(dest, MON_DATA_MAX_HP);
    SetMonData(dest, MON_DATA_HP, &value);
    return TRUE;
}

static void ClearShiningTrialState(void)
{
    sShiningTrialPersonality = 0;
    sShiningTrialOtId = 0;
    sShiningTrialChecksum = 0;
    sShiningTrialState = SHINING_TRIAL_STATE_NONE;
}

static bool8 IsShiningTrialMon(struct Pokemon *mon)
{
    return mon->box.personality == sShiningTrialPersonality
        && mon->box.otId == sShiningTrialOtId
        && mon->box.checksum == sShiningTrialChecksum;
}

static u16 GetShiningTrialEligibility(void)
{
    struct Pokemon *mon = &gPlayerParty[0];
    struct Pokemon mirror;

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return SHINING_TRIAL_NO_MON;
    if (GetMonData(mon, MON_DATA_IS_EGG))
        return SHINING_TRIAL_EGG;
    if (IsMonShiny(mon))
        return SHINING_TRIAL_ALREADY_SHINY;
    if (GetMonData(mon, MON_DATA_FRIENDSHIP) != MAX_FRIENDSHIP)
        return SHINING_TRIAL_FRIENDSHIP_TOO_LOW;
    if (!ShiningTrial_CreateMirror(&mirror))
        return SHINING_TRIAL_NO_SHINY_FORM;

    return SHINING_TRIAL_ELIGIBLE;
}

void ShiningTrial_CheckEligibility(void)
{
    gSpecialVar_Result = GetShiningTrialEligibility();
}

void ShiningTrial_Begin(void)
{
    u8 selectedOrder[MAX_FRONTIER_PARTY_SIZE];
    u16 eligibility;

    eligibility = GetShiningTrialEligibility();

    if (sShiningTrialState != SHINING_TRIAL_STATE_NONE
     || eligibility != SHINING_TRIAL_ELIGIBLE)
    {
        gSpecialVar_Result = (eligibility == SHINING_TRIAL_NO_SHINY_FORM)
                           ? SHINING_TRIAL_NO_SHINY_FORM
                           : FALSE;
        return;
    }

    sShiningTrialPersonality = gPlayerParty[0].box.personality;
    sShiningTrialOtId = gPlayerParty[0].box.otId;
    sShiningTrialChecksum = gPlayerParty[0].box.checksum;

    // Use the same save-block party backup and reduction path as the Frontier.
    // The selected-order array belongs to the party menu, so preserve it here.
    SavePlayerParty();
    memcpy(selectedOrder, gSelectedOrderFromParty, sizeof(selectedOrder));
    memset(gSelectedOrderFromParty, 0, sizeof(gSelectedOrderFromParty));
    gSelectedOrderFromParty[0] = 1;
    ReducePlayerPartyToSelectedMons();
    memcpy(gSelectedOrderFromParty, selectedOrder, sizeof(selectedOrder));
    sShiningTrialState = SHINING_TRIAL_STATE_IN_BATTLE;
    gSpecialVar_Result = TRUE;
}

void ShiningTrial_RestoreParty(void)
{
    if (sShiningTrialState != SHINING_TRIAL_STATE_IN_BATTLE)
        return;

    LoadPlayerParty();
    sShiningTrialState = SHINING_TRIAL_STATE_RESTORED;
}

void ShiningTrial_Finish(void)
{
    u16 result;

    // Normally the battle-end callback has already restored the party. Calling
    // this again makes Finish safe if that callback was skipped for any reason.
    ShiningTrial_RestoreParty();

    if (sShiningTrialState != SHINING_TRIAL_STATE_RESTORED
     || !IsShiningTrialMon(&gPlayerParty[0]))
    {
        result = SHINING_TRIAL_FINISH_IDENTITY_LOST;
    }
    else if (GetShiningTrialEligibility() != SHINING_TRIAL_ELIGIBLE)
    {
        result = SHINING_TRIAL_FINISH_INELIGIBLE;
    }
    else if (!MakeMonShinyPreservingAttributes(&gPlayerParty[0]))
    {
        result = SHINING_TRIAL_FINISH_NO_PID;
    }
    else
    {
        result = SHINING_TRIAL_FINISH_SUCCESS;
        SavePlayerParty();
    }

    ClearShiningTrialState();
    gSpecialVar_Result = result;
}

void ShiningTrial_Cancel(void)
{
    ShiningTrial_RestoreParty();
    ClearShiningTrialState();
}

#if TX_DEBUG_SYSTEM_ENABLE == TRUE
static bool8 ShiningTrial_TestMonDataEqual(struct Pokemon *before, struct Pokemon *after)
{
    s32 field;

    for (field = MON_DATA_OT_ID; field <= MON_DATA_HIDDEN_NATURE; field++)
    {
        u8 beforeData[32] = {0};
        u8 afterData[32] = {0};
        u32 beforeValue;
        u32 afterValue;

        // MON_DATA_NATURE has a legacy early-return path that does not re-encrypt
        // the BoxMon; PID nature is checked explicitly by the caller instead.
        // MON_DATA_KNOWN_MOVES expects a caller-provided move list rather than
        // returning a stored field, so it is not part of this generic sweep.
        if (field == MON_DATA_CHECKSUM || field == MON_DATA_NATURE || field == MON_DATA_KNOWN_MOVES)
            continue;
        beforeValue = GetMonData(before, field, beforeData);
        afterValue = GetMonData(after, field, afterData);
        if (beforeValue != afterValue || memcmp(beforeData, afterData, sizeof(beforeData)) != 0)
            return FALSE;
    }

    return TRUE;
}

static void ShiningTrial_PopulateTestMon(struct Pokemon *mon)
{
    static const u8 sNickname[] = _("TRIAL");
    static const u8 sOtName[] = _("AURELIA");
    static const u16 sMoves[MAX_MON_MOVES] = {MOVE_RETURN, MOVE_TOXIC, MOVE_PROTECT, MOVE_PSYCHIC};
    s32 i;
    u32 value;

    value = ITEM_LUM_BERRY;
    SetMonData(mon, MON_DATA_HELD_ITEM, &value);
    SetMonData(mon, MON_DATA_NICKNAME, sNickname);
    SetMonData(mon, MON_DATA_OT_NAME, sOtName);
    value = 0xA5;
    SetMonData(mon, MON_DATA_MARKINGS, &value);
    value = MAX_FRIENDSHIP;
    SetMonData(mon, MON_DATA_FRIENDSHIP, &value);
    value = NATURE_CAREFUL;
    SetMonData(mon, MON_DATA_HIDDEN_NATURE, &value);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        value = sMoves[i];
        SetMonData(mon, MON_DATA_MOVE1 + i, &value);
        value = 5 + i;
        SetMonData(mon, MON_DATA_PP1 + i, &value);
    }
    value = 0xFF;
    SetMonData(mon, MON_DATA_PP_BONUSES, &value);

    for (i = 0; i < NUM_STATS; i++)
    {
        value = 31 - i;
        SetMonData(mon, MON_DATA_HP_IV + i, &value);
        value = 40 + i;
        SetMonData(mon, MON_DATA_HP_EV + i, &value);
    }
    for (i = MON_DATA_COOL; i <= MON_DATA_CUTE; i++)
    {
        value = 80 + i;
        SetMonData(mon, i, &value);
    }
    value = 90;
    SetMonData(mon, MON_DATA_SMART, &value);
    value = 91;
    SetMonData(mon, MON_DATA_TOUGH, &value);
    value = 92;
    SetMonData(mon, MON_DATA_SHEEN, &value);
    value = 1;
    SetMonData(mon, MON_DATA_CHAMPION_RIBBON, &value);
    SetMonData(mon, MON_DATA_EFFORT_RIBBON, &value);
    SetMonData(mon, MON_DATA_ARTIST_RIBBON, &value);
    SetMonData(mon, MON_DATA_WORLD_RIBBON, &value);
    value = 3;
    SetMonData(mon, MON_DATA_COOL_RIBBON, &value);
    SetMonData(mon, MON_DATA_BEAUTY_RIBBON, &value);
    value = 42;
    SetMonData(mon, MON_DATA_MET_LOCATION, &value);
    value = 37;
    SetMonData(mon, MON_DATA_MET_LEVEL, &value);
    value = VERSION_EMERALD;
    SetMonData(mon, MON_DATA_MET_GAME, &value);
    value = ITEM_ULTRA_BALL;
    SetMonData(mon, MON_DATA_POKEBALL, &value);
    value = 1;
    SetMonData(mon, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &value);
    value = STATUS1_POISON;
    SetMonData(mon, MON_DATA_STATUS, &value);
    CalculateMonStats(mon);
}

static bool8 ShiningTrial_TestConversionCase(u16 species, u8 nature, u8 gender, u8 abilityNum, u8 unownLetter, bool8 populate)
{
    const u32 otId = 0x12345678;
    u32 personality;

    for (personality = 1; personality < 0x1000000; personality++)
    {
        struct Pokemon mon;
        struct Pokemon before;

        if (GetNatureFromPersonality(personality) != nature
         || GetGenderFromSpeciesAndPersonality(species, personality) != gender
         || (personality & 1) != abilityNum
         || IsShinyOtIdPersonality(otId, personality))
            continue;
        if (species == SPECIES_UNOWN && GET_UNOWN_LETTER(personality) != unownLetter)
            continue;

        CreateMon(&mon, species, 50, 31, TRUE, personality, OT_ID_PRESET, otId);
        SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
        if (populate)
            ShiningTrial_PopulateTestMon(&mon);
        before = mon;

        if (!MakeMonShinyPreservingAttributes(&mon))
            continue;
        if (!IsMonShiny(&mon)
         || GetNatureFromPersonality(GetMonData(&mon, MON_DATA_PERSONALITY)) != nature
         || GetMonData(&mon, MON_DATA_ABILITY_NUM) != abilityNum
         || GetGenderFromSpeciesAndPersonality(species, GetMonData(&mon, MON_DATA_PERSONALITY)) != gender
         || (species == SPECIES_UNOWN
          && GET_UNOWN_LETTER(GetMonData(&mon, MON_DATA_PERSONALITY)) != unownLetter)
         || !ShiningTrial_TestMonDataEqual(&before, &mon))
            return FALSE;

        return TRUE;
    }

    return FALSE;
}

static bool8 ShiningTrial_TestMirrorCase(u8 sourceLevel, u8 expectedLevel)
{
    const u32 otId = 0x12345678;
    const u32 personality = 0x00100006;
    struct Pokemon source;
    struct Pokemon sourceBefore;
    struct Pokemon mirror;
    struct Pokemon savedLead;
    u8 sourceNickname[POKEMON_NAME_LENGTH + 1] = {0};
    u8 mirrorNickname[POKEMON_NAME_LENGTH + 1] = {0};
    u8 savedPartyCount;
    bool8 created;
    bool8 sourceUnchanged;
    u16 species;
    u32 expectedExp;
    u32 expectedEv;
    u32 i;

    CreateMon(&source, SPECIES_RALTS, sourceLevel, 20, TRUE, personality, OT_ID_PRESET, otId);
    ShiningTrial_PopulateTestMon(&source);
    sourceBefore = source;

    savedLead = gPlayerParty[0];
    savedPartyCount = gPlayerPartyCount;
    gPlayerParty[0] = source;
    gPlayerPartyCount = 1;
    created = ShiningTrial_CreateMirror(&mirror);
    sourceUnchanged = memcmp(&sourceBefore, &gPlayerParty[0], sizeof(sourceBefore)) == 0;
    gPlayerParty[0] = savedLead;
    gPlayerPartyCount = savedPartyCount;

    if (!created || !sourceUnchanged || !IsMonShiny(&mirror))
        return FALSE;

    species = GetMonData(&sourceBefore, MON_DATA_SPECIES);
    expectedExp = gExperienceTables[gSpeciesInfo[species].growthRate][expectedLevel];
    if (GetMonData(&mirror, MON_DATA_SPECIES) != species
     || GetMonData(&mirror, MON_DATA_LEVEL) != expectedLevel
     || GetMonData(&mirror, MON_DATA_EXP) != expectedExp
     || GetMonData(&mirror, MON_DATA_STATUS) != 0
     || GetMonData(&mirror, MON_DATA_HELD_ITEM) != ITEM_NONE
     || GetMonData(&mirror, MON_DATA_HP) != GetMonData(&mirror, MON_DATA_MAX_HP))
        return FALSE;

    GetMonData(&sourceBefore, MON_DATA_NICKNAME, sourceNickname);
    GetMonData(&mirror, MON_DATA_NICKNAME, mirrorNickname);
    if (memcmp(sourceNickname, mirrorNickname, sizeof(sourceNickname)) != 0)
        return FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetMonData(&mirror, MON_DATA_MOVE1 + i) != GetMonData(&sourceBefore, MON_DATA_MOVE1 + i)
         || GetMonData(&mirror, MON_DATA_PP1 + i)
          != CalculatePPWithBonus(GetMonData(&mirror, MON_DATA_MOVE1 + i),
                                  GetMonData(&mirror, MON_DATA_PP_BONUSES), i))
            return FALSE;
    }

    for (i = 0; i < NUM_STATS; i++)
    {
        expectedEv = 0;
        if (i == 0)
            expectedEv = 252;
        else if (i == 3)
            expectedEv = 6;
        else if ((gSpeciesInfo[species].baseAttack >= gSpeciesInfo[species].baseSpAttack && i == 1)
              || (gSpeciesInfo[species].baseAttack < gSpeciesInfo[species].baseSpAttack && i == 4))
            expectedEv = 252;

        if (GetMonData(&mirror, MON_DATA_HP_IV + i) != MAX_PER_STAT_IVS
         || GetMonData(&mirror, MON_DATA_HP_EV + i) != expectedEv)
            return FALSE;
    }

    return TRUE;
}

void ShiningTrial_RunConversionTests(void)
{
    static const u8 sTextPassed[] = _("Shining Trial PID tests passed.");
    static const u8 sTextFailed[] = _("Shining Trial PID test {STR_VAR_1} failed.");
    struct Pokemon mon;
    struct Pokemon before;
    struct Pokemon savedPlayerParty[PARTY_SIZE];
    struct Pokemon savedSaveParty[PARTY_SIZE];
    u8 savedPlayerPartyCount;
    u8 savedSavePartyCount;
    u32 value;
    u16 testId = 0;
    u8 nature;
    u8 letter;

#define RUN_SHINING_TRIAL_TEST(expression) \
    do \
    { \
        testId++; \
        if (!(expression)) \
            goto fail; \
    } while (0)

    RUN_SHINING_TRIAL_TEST(ShiningTrial_TestMirrorCase(50, 60));
    RUN_SHINING_TRIAL_TEST(ShiningTrial_TestMirrorCase(95, MAX_LEVEL));

    for (nature = 0; nature < NUM_NATURES; nature++)
    {
        RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_RALTS, nature, (nature & 1) ? MON_FEMALE : MON_MALE, 0, 0, nature == 0));
        RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_RALTS, nature, (nature & 1) ? MON_FEMALE : MON_MALE, 1, 0, FALSE));
    }
    RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_MAGNEMITE, NATURE_HARDY, MON_GENDERLESS, 0, 0, FALSE));
    RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_EEVEE, NATURE_ADAMANT, MON_MALE, 0, 0, FALSE));
    RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_EEVEE, NATURE_MODEST, MON_FEMALE, 1, 0, FALSE));
    for (letter = 0; letter < 28; letter++)
        RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_UNOWN, letter % NUM_NATURES, MON_GENDERLESS, letter & 1, letter, FALSE));

    CreateMon(&mon, SPECIES_RALTS, 50, 31, TRUE, 0xDEF09ABC, OT_ID_PRESET, 0x12345678);
    before = mon;
    RUN_SHINING_TRIAL_TEST(IsMonShiny(&mon) && !MakeMonShinyPreservingAttributes(&mon) && memcmp(&before, &mon, sizeof(mon)) == 0);

    // This Unown PID/OT pair has no shiny PID that also preserves nature,
    // gender, ability parity, and form.
    CreateMon(&mon, SPECIES_UNOWN, 50, 31, TRUE, 0x56D8C8AA, OT_ID_PRESET, 0x9DFEE001);
    before = mon;
    RUN_SHINING_TRIAL_TEST(!MakeMonShinyPreservingAttributes(&mon) && memcmp(&before, &mon, sizeof(mon)) == 0);

    CreateMon(&mon, SPECIES_RALTS, 50, 31, TRUE, 0x12345678, OT_ID_PRESET, 0x87654321);
    mon.box.checksum ^= 1;
    before = mon;
    RUN_SHINING_TRIAL_TEST(!MakeMonShinyPreservingAttributes(&mon) && memcmp(&before, &mon, sizeof(mon)) == 0);

    RUN_SHINING_TRIAL_TEST(ShiningTrial_TestConversionCase(SPECIES_RALTS, NATURE_BOLD, MON_FEMALE, 1, 0, TRUE));
    CreateMon(&mon, SPECIES_RALTS, 50, 31, TRUE, 0x00100006, OT_ID_PRESET, 0x12345678);
    value = 1;
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &value);
    ShiningTrial_PopulateTestMon(&mon);
    RUN_SHINING_TRIAL_TEST(MakeMonShinyPreservingAttributes(&mon));
    before = mon;

    memcpy(savedPlayerParty, gPlayerParty, sizeof(savedPlayerParty));
    memcpy(savedSaveParty, gSaveBlock1Ptr->playerParty, sizeof(savedSaveParty));
    savedPlayerPartyCount = gPlayerPartyCount;
    savedSavePartyCount = gSaveBlock1Ptr->playerPartyCount;
    ZeroPlayerPartyMons();
    gPlayerParty[0] = mon;
    gPlayerPartyCount = 1;
    SavePlayerParty();
    ZeroPlayerPartyMons();
    LoadPlayerParty();
    value = memcmp(&before, &gPlayerParty[0], sizeof(before)) == 0;
    memcpy(gPlayerParty, savedPlayerParty, sizeof(savedPlayerParty));
    memcpy(gSaveBlock1Ptr->playerParty, savedSaveParty, sizeof(savedSaveParty));
    gPlayerPartyCount = savedPlayerPartyCount;
    gSaveBlock1Ptr->playerPartyCount = savedSavePartyCount;
    RUN_SHINING_TRIAL_TEST(value);

    StringCopy(gStringVar4, sTextPassed);
    return;

fail:
    ConvertIntToDecimalStringN(gStringVar1, testId, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sTextFailed);
#undef RUN_SHINING_TRIAL_TEST
}
#endif
