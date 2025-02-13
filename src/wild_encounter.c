#include "global.h"
#include "wild_encounter.h"
#include "pokemon.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "random.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "safari_zone.h"
#include "overworld.h"
#include "pokeblock.h"
#include "battle_setup.h"
#include "roamer.h"
#include "tv.h"
#include "link.h"
#include "script.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "constants/abilities.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/weather.h"

extern const u8 EventScript_RepelWoreOff[];

#define MAX_ENCOUNTER_RATE 2880

#define NUM_FEEBAS_SPOTS 6

// Number of accessible fishing spots in each section of Route 119
// Each section is an area of the route between the y coordinates in sRoute119WaterTileData
#define NUM_FISHING_SPOTS_1 131
#define NUM_FISHING_SPOTS_2 167
#define NUM_FISHING_SPOTS_3 149
#define NUM_FISHING_SPOTS (NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2 + NUM_FISHING_SPOTS_3)

enum {
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    (1 << 0)
#define WILD_CHECK_KEEN_EYE (1 << 1)

#define HEADER_NONE 0xFFFF

static u16 FeebasRandom(void);
static void FeebasSeedRng(u16 seed);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *encRate);
static void ApplyCleanseTagEncounterRateMod(u32 *encRate);
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u8 ability, u8 *monIndex, u32 size);
static bool8 IsAbilityAllowingEncounter(u8 level);

EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA u32 sFeebasRngValue = 0;
EWRAM_DATA u16 gFeebasTiles[6][2] = {0};

#include "data/wild_encounters.h"

static const struct WildPokemon sWildFeebas = {20, 25, SPECIES_FEEBAS};

static const u16 sRoute119WaterTileData[] =
{
//yMin, yMax, numSpots in previous sections
     0,  45,  0,
    46,  91,  NUM_FISHING_SPOTS_1,
    92, 139,  NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2,
};

static const u16 gRoute119MetatileTable[] =
{
    [0x02C - 0x02C] = 0x2A9,
    [0x034 - 0x02C] = 0x2CB,
    [0x03C - 0x02C] = 0x2AA,
    [0x11D - 0x02C] = 0x31B,
    [0x125 - 0x02C] = 0x31A,
    [0x12C - 0x02C] = 0x318,
    [0x12D - 0x02C] = 0x319,
    [0x170 - 0x02C] = 0x308,
    [0x178 - 0x02C] = 0x2FD,
    [0x179 - 0x02C] = 0x305,
    [0x188 - 0x02C] = 0x31C,
    [0x189 - 0x02C] = 0x31F,
    [0x18A - 0x02C] = 0x31D,
    [0x190 - 0x02C] = 0x310,
    [0x192 - 0x02C] = 0x31E,
    [0x198 - 0x02C] = 0x311,
    [0x19A - 0x02C] = 0x30D,
    [0x20F - 0x02C] = 0x2D3,
    [0x266 - 0x02C] = 0x312,
    [0x267 - 0x02C] = 0x315
};

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

// Each fishing spot on Route 119 is given a number between 1 and NUM_FISHING_SPOTS inclusive.
// The number is determined by counting the valid fishing spots left to right top to bottom.
// The map is divided into three sections, with each section having a pre-counted number of
// fishing spots to start from to avoid counting a large number of spots at the bottom of the map.
// Note that a spot is considered valid if it is surfable and not a waterfall. To exclude all
// of the inaccessible water metatiles (so that they can't be selected as a Feebas spot) they
// use a different metatile that isn't actually surfable because it has MB_NORMAL instead.
// This function is given the coordinates and section of a fishing spot and returns which number it is.
static u16 GetFeebasFishingSpotId(s16 targetX, s16 targetY, u8 section)
{
    u16 x, y;
    u16 yMin = sRoute119WaterTileData[section * 3 + 0];
    u16 yMax = sRoute119WaterTileData[section * 3 + 1];
    u16 spotId = sRoute119WaterTileData[section * 3 + 2];

    for (y = yMin; y <= yMax; y++)
    {
        for (x = 0; x < gMapHeader.mapLayout->width; x++)
        {
            u8 behavior = MapGridGetMetatileBehaviorAt(x + MAP_OFFSET, y + MAP_OFFSET);
            if (MetatileBehavior_IsSurfableAndNotWaterfall(behavior) == TRUE)
            {
                spotId++;
                if (targetX == x && targetY == y)
                    return spotId;
            }
        }
    }
    return spotId + 1;
}

static bool8 CheckFeebas(void)
{
    u8 i;
    s16 x, y;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE119) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE119))
    {
        GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

        // Updated 50% chance of encountering Feebas to 25% (assuming this is a Feebas spot) due to Feebas tiles visible after Devon Scope recieved (Random() % 100 > 49
        if (Random() % 100 > 74)
            return FALSE;

        for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        {
            if (x == gFeebasTiles[i][0] && y == gFeebasTiles[i][1])
                return TRUE;
        }
    }
    return FALSE;
}

static u16 FeebasRandom(void)
{
    sFeebasRngValue = ISO_RANDOMIZE2(sFeebasRngValue);
    return sFeebasRngValue >> 16;
}

static void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = seed;
}

#define nWaterTiles 447
void GetFeebasTiles(void)
{
    u32 nFeebasGenerated = 0;
    u32 nFeebasHighlighted = 0;
    u32 currentWaterTile = 0;
    u32 feebasTiles[NUM_FEEBAS_SPOTS];
    u32 x;
    u32 y;
    u32 i;
    FeebasSeedRng(gSaveBlock1Ptr->dewfordTrends[0].rand);
    for (; nFeebasGenerated < NUM_FEEBAS_SPOTS; nFeebasGenerated++)
    {
        u32 randomTile = FeebasRandom() % nWaterTiles;
        if (randomTile == 0)
            randomTile = nWaterTiles;
        if (randomTile == 0 || randomTile > 3)
            feebasTiles[nFeebasGenerated] = randomTile;
    }
    for (y = 0; y < 140; y++)
    {
        for (x = 0; x < 40; x++)
        {
            if (MetatileBehavior_IsSurfableAndNotWaterfall(MapHeaderGetMetatileBehaviorAt(x, y, MAP_GROUP(ROUTE119), MAP_NUM(ROUTE119))))
            {
                currentWaterTile++;
                if (nFeebasHighlighted < NUM_FEEBAS_SPOTS)
                {
                    for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
                    {
                        if (currentWaterTile == feebasTiles[i])
                        {
                            gFeebasTiles[i][0] = x + 7;
                            gFeebasTiles[i][1] = y + 7;
                        }
                    }
                }
            }
        }
    }
}

#undef nWaterTiles

void HighlightFeebasTiles(void)
{
    u32 i;
    for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        MapGridSetMetatileIdAt(gFeebasTiles[i][0], gFeebasTiles[i][1], gRoute119MetatileTable[MapGridGetMetatileIdAt(gFeebasTiles[i][0], gFeebasTiles[i][1]) - 0x2C]);
}

// LAND_WILD_COUNT
static u8 ChooseWildMonIndex_Land(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        return 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        return 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        return 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        return 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        return 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        return 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 9;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_10)
        return 10;
    else
        return 11;
}

// ROCK_WILD_COUNT / WATER_WILD_COUNT
static u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        return 3;
    else
        return 4;
}

// FISH_WILD_COUNT
static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)
            wildMonIndex = 9;
        break;
    }
    return wildMonIndex;
}

static u8 ChooseWildMonLevel(const struct WildPokemon *wildPokemon)
{
    u8 min;
    u8 max;
    u8 range;
    u8 rand;

    // Make sure minimum level is less than maximum level
    if (wildPokemon->maxLevel >= wildPokemon->minLevel)
    {
        min = wildPokemon->minLevel;
        max = wildPokemon->maxLevel;
    }
    else
    {
        min = wildPokemon->maxLevel;
        max = wildPokemon->minLevel;
    }
    range = max - min + 1;
    rand = Random() % range;

    // check ability for max level mon
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u8 ability = GetMonAbility(&gPlayerParty[0]);
        if (ability == ABILITY_HUSTLE || ability == ABILITY_VITAL_SPIRIT || ability == ABILITY_PRESSURE)
        {
            if (Random() % 2 == 0)
                return max;

            if (rand != 0)
                rand--;
        }
    }
    return min + rand;
}

static u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == MAP_GROUP(UNDEFINED))
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE101) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE101))
            {
                i += VarGet(VAR_ROUTE101_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE102) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE102))
            {
                i += VarGet(VAR_ROUTE102_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE103) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE103))
            {
                i += VarGet(VAR_ROUTE103_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE104) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE104))
            {
                i += VarGet(VAR_ROUTE104_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE110) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE110))
            {
                i += VarGet(VAR_ROUTE110_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE111) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE111))
            {
                i += VarGet(VAR_ROUTE111_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE112) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE112))
            {
                i += VarGet(VAR_ROUTE112_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE114) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE114))
            {
                i += VarGet(VAR_ROUTE114_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE116) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE116))
            {
                i += VarGet(VAR_ROUTE116_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE117) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE117))
            {
                i += VarGet(VAR_ROUTE117_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PETALBURG_WOODS) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(PETALBURG_WOODS))
            {
                i += VarGet(VAR_PETALBURG_WOODS_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(RUSTURF_TUNNEL) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(RUSTURF_TUNNEL))
            {
                i += VarGet(VAR_RUSTURF_TUNNEL_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(GRANITE_CAVE_1F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(GRANITE_CAVE_1F))
            {
                i += VarGet(VAR_GRANITE_CAVE_1F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(GRANITE_CAVE_B1F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(GRANITE_CAVE_B1F))
            {
                i += VarGet(VAR_GRANITE_CAVE_B1F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(VICTORY_ROAD_1F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(VICTORY_ROAD_1F))
            {
                i += VarGet(VAR_VICTORY_ROAD_1F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FIERY_PATH) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(FIERY_PATH))
            {
                i += VarGet(VAR_FIERY_PATH_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(JAGGED_PASS) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(JAGGED_PASS))
            {
                i += VarGet(VAR_JAGGED_PASS_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE107) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE107))
            {
                i += VarGet(VAR_ROUTE107_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE115) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE115))
            {
                i += VarGet(VAR_ROUTE115_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(NEW_MAUVILLE_INSIDE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(NEW_MAUVILLE_INSIDE))
            {
                i += VarGet(VAR_NEW_MAUVILLE_INSIDE_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE119) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE119))
            {
                i += VarGet(VAR_ROUTE119_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE120) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE120))
            {
                i += VarGet(VAR_ROUTE120_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE121) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE121))
            {
                i += VarGet(VAR_ROUTE121_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE122) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE122))
            {
                i += VarGet(VAR_ROUTE122_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE123) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE123))
            {
                i += VarGet(VAR_ROUTE123_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MT_PYRE_2F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MT_PYRE_2F))
            {
                i += VarGet(VAR_MT_PYRE_2F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MT_PYRE_3F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MT_PYRE_3F))
            {
                i += VarGet(VAR_MT_PYRE_3F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MT_PYRE_4F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MT_PYRE_4F))
            {
                i += VarGet(VAR_MT_PYRE_4F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MT_PYRE_5F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MT_PYRE_5F))
            {
                i += VarGet(VAR_MT_PYRE_5F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MT_PYRE_EXTERIOR) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MT_PYRE_EXTERIOR))
            {
                i += VarGet(VAR_MT_PYRE_EXTERIOR_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE131) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE131))
            {
                i += VarGet(VAR_ROUTE131_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE133) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE133))
            {
                i += VarGet(VAR_ROUTE133_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(VICTORY_ROAD_B1F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(VICTORY_ROAD_B1F))
            {
                i += VarGet(VAR_VICTORY_ROAD_B1F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(VICTORY_ROAD_B2F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(VICTORY_ROAD_B2F))
            {
                i += VarGet(VAR_VICTORY_ROAD_B2F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(METEOR_FALLS_1F_1R) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(METEOR_FALLS_1F_1R))
            {
                i += VarGet(VAR_METEOR_FALLS_1F_1R_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SLATEPORT_CITY) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(SLATEPORT_CITY))
            {
                i += VarGet(VAR_SLATEPORT_CITY_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MOSSDEEP_CITY) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MOSSDEEP_CITY))
            {
                i += VarGet(VAR_MOSSDEEP_CITY_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PETALBURG_CITY) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(PETALBURG_CITY))
            {
                i += VarGet(VAR_PETALBURG_CITY_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM))
            {
                i += VarGet(VAR_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(SOOTOPOLIS_CITY))
            {
                i += VarGet(VAR_SOOTOPOLIS_CITY_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ARTISAN_CAVE_B1F) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_B1F))
            {
                i += VarGet(VAR_ARTISAN_CAVE_B1F_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM))
            {
                i += VarGet(VAR_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_WILD_SET);
            }
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            return i;
        }
    }

    return HEADER_NONE;
}

static u8 PickWildMonNature(void)
{
    u8 i;
    u8 j;
    struct Pokeblock *safariPokeblock;
    u8 natures[NUM_NATURES];

    if (GetSafariZoneFlag() == TRUE && Random() % 100 < 80)
    {
        safariPokeblock = SafariZoneGetActivePokeblock();
        if (safariPokeblock != NULL)
        {
            for (i = 0; i < NUM_NATURES; i++)
                natures[i] = i;
            for (i = 0; i < NUM_NATURES - 1; i++)
            {
                for (j = i + 1; j < NUM_NATURES; j++)
                {
                    if (Random() & 1)
                    {
                        u8 temp;
                        SWAP(natures[i], natures[j], temp);
                    }
                }
            }
            for (i = 0; i < NUM_NATURES; i++)
            {
                if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
                    return natures[i];
            }
        }
    }
    // check synchronize for a Pokémon with the same ability
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_SYNCHRONIZE
        && Random() % 2 == 0)
    {
        return GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY) % NUM_NATURES;
    }

    // random nature
    return Random() % NUM_NATURES;
}

static void CreateWildMon(u16 species, u8 level)
{
    bool32 checkCuteCharm;

    ZeroEnemyPartyMons();
    checkCuteCharm = TRUE;

    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
    {
        u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
        u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

        // misses mon is genderless check, although no genderless mon can have cute charm as ability
        if (gender == MON_FEMALE)
            gender = MON_MALE;
        else
            gender = MON_FEMALE;

        CreateMonWithGenderNatureLetter(&gEnemyParty[0], species, level, USE_RANDOM_IVS, gender, PickWildMonNature(), 0, OT_ID_PLAYER_ID);
        return;
    }

    CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, PickWildMonNature());
}
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr, count)

static bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, u8 area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level;

    switch (area)
    {
    case WILD_AREA_LAND:
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex, LAND_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex, WATER_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    }

    level = ChooseWildMonLevel(&wildMonInfo->wildPokemon[wildMonIndex]);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;
    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return TRUE;
}

static u16 GenerateFishingWildMon(const struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);
    u8 level = ChooseWildMonLevel(&wildMonInfo->wildPokemon[wildMonIndex]);

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return wildMonInfo->wildPokemon[wildMonIndex].species;
}

static bool8 SetUpMassOutbreakEncounter(u8 flags)
{
    u16 i;

    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(gSaveBlock1Ptr->outbreakPokemonLevel))
        return FALSE;

    CreateWildMon(gSaveBlock1Ptr->outbreakPokemonSpecies, gSaveBlock1Ptr->outbreakPokemonLevel);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);

    return TRUE;
}

static bool8 DoMassOutbreakEncounterTest(void)
{
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        if (Random() % 100 < gSaveBlock1Ptr->outbreakPokemonProbability)
            return TRUE;
    }
    return FALSE;
}

static bool8 EncounterOddsCheck(u16 encounterRate)
{
    if (Random() % MAX_ENCOUNTER_RATE < encounterRate)
        return TRUE;
    else
        return FALSE;
}

// Returns true if it will try to create a wild encounter.
static bool8 WildEncounterCheck(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (!ignoreAbility && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u32 ability = GetMonAbility(&gPlayerParty[0]);

        if (ability == ABILITY_STENCH && gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            encounterRate = encounterRate * 3 / 4;
        else if (ability == ABILITY_STENCH)
            encounterRate /= 2;
        else if (ability == ABILITY_ILLUMINATE)
            encounterRate *= 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            encounterRate /= 2;
        else if (ability == ABILITY_ARENA_TRAP)
            encounterRate *= 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == WEATHER_SANDSTORM)
            encounterRate /= 2;
    }
    if (encounterRate > MAX_ENCOUNTER_RATE)
        encounterRate = MAX_ENCOUNTER_RATE;
    return EncounterOddsCheck(encounterRate);
}

// When you first step on a different type of metatile, there's a 40% chance it
// skips the wild encounter check entirely.
static bool8 AllowWildCheckOnNewMetatile(void)
{
    if (Random() % 100 >= 60)
        return FALSE;
    else
        return TRUE;
}

static bool8 AreLegendariesInSootopolisPreventingEncounters(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(SOOTOPOLIS_CITY)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(SOOTOPOLIS_CITY))
    {
        return FALSE;
    }

    return FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS);
}

bool8 StandardWildEncounter(u16 curMetatileBehavior, u16 prevMetatileBehavior)
{
    u16 headerId;
    struct Roamer *roamer;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePikeWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;

            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePyramidWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(curMetatileBehavior) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else
            {
                if (DoMassOutbreakEncounterTest() == TRUE && SetUpMassOutbreakEncounter(WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                return FALSE;
            }
        }
        else if (MetatileBehavior_IsWaterWildEncounter(curMetatileBehavior) == TRUE
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridgeOverWater(curMetatileBehavior) == TRUE))
        {
            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            else if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].waterMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                return FALSE;
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].rockSmashMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u16 headerId;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            if (DoMassOutbreakEncounterTest() == TRUE)
                SetUpMassOutbreakEncounter(0);
            else
                TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0);

            BattleSetup_StartWildBattle();
            return TRUE;
        }
        else if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter() == TRUE)
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, 0);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE && gWildMonHeaders[headerId].fishingMonsInfo != NULL)
        return TRUE;
    else
        return FALSE;
}

void FishingWildEncounter(u8 rod)
{
    u16 species;

    if (CheckFeebas() == TRUE)
    {
        u8 level = ChooseWildMonLevel(&sWildFeebas);

        species = sWildFeebas.species;
        CreateWildMon(species, level);
    }
    else
    {
        species = GenerateFishingWildMon(gWildMonHeaders[GetCurrentMapWildMonHeaderId()].fishingMonsInfo, rod);
    }
    IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
    SetPokemonAnglerSpecies(species);
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u16 headerId;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
        return SPECIES_NONE;
    landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    // Land Pokémon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    // Water Pokémon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    // Either land or water Pokémon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 steps;

    if (InBattlePike() || InBattlePyramid())
        return FALSE;
    if (InUnionRoom() == TRUE)
        return FALSE;

    steps = VarGet(VAR_REPEL_STEP_COUNT);

    if (steps != 0)
    {
        steps--;
        VarSet(VAR_REPEL_STEP_COUNT, steps);
        if (steps == 0)
        {
            ScriptContext_SetupScript(EventScript_RepelWoreOff);
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!VarGet(VAR_REPEL_STEP_COUNT))
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            u8 ourLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);

            if (wildLevel < ourLevel)
                return FALSE;
            else
                return TRUE;
        }
    }

    return FALSE;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    u8 ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, u8 type, u8 numMon, u8 *monIndex)
{
    u8 validIndexes[numMon]; // variable length array, an interesting feature
    u8 i, validMonCount;

    for (i = 0; i < numMon; i++)
        validIndexes[i] = 0;

    for (validMonCount = 0, i = 0; i < numMon; i++)
    {
        if (gSpeciesInfo[wildMon[i].species].types[0] == type || gSpeciesInfo[wildMon[i].species].types[1] == type)
            validIndexes[validMonCount++] = i;
    }

    if (validMonCount == 0 || validMonCount == numMon)
        return FALSE;

    *monIndex = validIndexes[Random() % validMonCount];
    return TRUE;
}

static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u8 ability, u8 *monIndex, u32 size)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return FALSE;
    else if (GetMonAbility(&gPlayerParty[0]) != ability)
        return FALSE;
    else if (Random() % 2 != 0)
        return FALSE;
    return TryGetRandomWildMonIndexByType(wildMon, type, size, monIndex);
}

static void ApplyFluteEncounterRateMod(u32 *encRate)
{
    if (FlagGet(FLAG_SYS_ENC_UP_ITEM) == TRUE)
        *encRate += *encRate / 2;
    else if (FlagGet(FLAG_SYS_ENC_DOWN_ITEM) == TRUE)
        *encRate = *encRate / 2;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encRate)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM) == ITEM_CLEANSE_TAG)
        *encRate = *encRate * 2 / 3;
}
