#include "global.h"
#include "save.h"
#include "item.h"
#include "event_data.h"
#include "constants/heal_locations.h"
#include "constants/flags.h"

struct SaveBlock2_v2
{
    u8 _saveSentinel; // 0xFF
    u16 saveVersion;
    u8 playerName[7 + 1];
    u8 playerGender; // MALE, FEMALE
    u8 specialSaveWarpFlags;
    u8 playerTrainerId[4];
    u16 playTimeHours;
    u8 playTimeMinutes;
    u8 playTimeSeconds;
    u8 playTimeVBlanks;
            u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
            u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
            u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
            u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
            u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
            u16 optionsBattleSceneOff:1; // whether battle animations are disabled
            u16 regionMapZoom:1; // whether the map is zoomed in
            u16 optionsBikeMusic:1; // whether the bike music plays when riding
            u16 optionsSurfMusic:1; // whether the surf music plays when surfing
            u16 optionsSurfOverworld:1; // whether to use the original Surf blob or dynamic blob (False to use dynamic)
            u16 optionsBattleItemAnimation:3; // whether the battle animation is reduced or not
    struct Pokedex pokedex;
    u8 filler_90[0x8];
    struct Time localTimeOffset;
    struct Time lastBerryTreeUpdate;
    u32 gcnLinkFlags; // Read by Pokémon Colosseum/XD
    u32 encryptionKey;
    struct PlayersApprentice playerApprentice;
    struct Apprentice apprentices[4];
    struct BerryCrush berryCrush;
    struct PokemonJumpRecords pokeJump;
    struct BerryPickingResults berryPick;
    struct RankingHall1P hallRecords1P[9][2][3]; // From record mixing.
    struct RankingHall2P hallRecords2P[2][3]; // From record mixing.
    u16 contestLinkResults[5][4];
    struct BattleFrontier frontier;
};

struct SaveBlock1_v2
{
    struct Coords16 pos;
    struct WarpData location;
    struct WarpData continueGameWarp;
    struct WarpData dynamicWarp;
    struct WarpData lastHealLocation; // used by white-out and teleport
    struct WarpData escapeWarp; // used by Dig and Escape Rope
    struct WarpData secretBaseWarp; // used to fly to Secret Base
    u16 savedMusic;
    u8 weather;
    u8 weatherCycleStage;
    u8 flashLevel;
    //u8 padding1;
    u16 mapLayoutId;
    u16 mapView[0x100];
    u8 playerPartyCount;
    //u8 padding2[3];
    struct Pokemon playerParty[6];
    u32 money;
    u16 coins;
    u16 registeredItemSelect; // registered for use with SELECT button
    struct ItemSlot pcItems[50];
    struct ItemSlot bagPocket_Items[120];
    struct ItemSlot bagPocket_KeyItems[30];
    struct ItemSlot bagPocket_PokeBalls[16];
    struct ItemSlot bagPocket_TMHM[64];
    struct ItemSlot bagPocket_Berries[46];
    struct Pokeblock pokeblocks[40];
    u8 seen1[NUM_DEX_FLAG_BYTES];
    u16 berryBlenderRecords[3];
    //u8 unused_9C2[6];
    u16 trainerRematchStepCounter;
    u8 trainerRematches[100];
    //u8 padding3[2];
    struct ObjectEvent objectEvents[16];
    struct ObjectEventTemplate objectEventTemplates[64];
    u8 flags[NUM_FLAG_BYTES];
    u16 vars[VARS_COUNT];
    u32 gameStats[64];
    struct BerryTree berryTrees[128];
    struct SecretBase secretBases[20];
    u8 playerRoomDecorations[12];
    u8 playerRoomDecorationPositions[12];
    u8 decorationDesks[10];
    u8 decorationChairs[10];
    u8 decorationPlants[10];
    u8 decorationOrnaments[30];
    u8 decorationMats[30];
    u8 decorationPosters[10];
    u8 decorationDolls[40];
    u8 decorationCushions[10];
    //u8 padding4[2];
    TVShow tvShows[5 + 20];
    PokeNews pokeNews[16];
    u16 outbreakPokemonSpecies;
    u8 outbreakLocationMapNum;
    u8 outbreakLocationMapGroup;
    u8 outbreakPokemonLevel;
    u8 outbreakUnused1;
    u16 outbreakUnused2;
    u16 outbreakPokemonMoves[4];
    u8 outbreakUnused3;
    u8 outbreakPokemonProbability;
    u16 outbreakDaysLeft;
    struct GabbyAndTyData gabbyAndTyData;
    u16 easyChatProfile[6];
    u16 easyChatBattleStart[6];
    u16 easyChatBattleWon[6];
    u16 easyChatBattleLost[6];
    struct Mail mail[10 + 6];
    u8 unlockedTrendySayings[NUM_TRENDY_SAYING_BYTES]; // Bitfield for unlockable Easy Chat words in EC_GROUP_TRENDY_SAYING
    //u8 padding5[3];
    OldMan oldMan;
    struct DewfordTrend dewfordTrends[5];
    struct ContestWinner contestWinners[13]; // see CONTEST_WINNER_*
    struct DayCare daycare;
    struct LinkBattleRecords linkBattleRecords;
    u8 giftRibbons[11];
    struct ExternalEventData externalEventData;
    struct ExternalEventFlags externalEventFlags;
    struct Roamer roamer;
    struct EnigmaBerry enigmaBerry;
    struct MysteryGiftSave mysteryGift;
    u8 unused_3598[0x18];
    u32 trainerHillTimes[4];
    struct RamScript ramScript;
    struct RecordMixingGift recordMixingGift;
    u8 seen2[NUM_DEX_FLAG_BYTES];
    LilycoveLady lilycoveLady;
    struct TrainerNameRecord trainerNameRecords[20];
    u8 registeredTexts[10][21];
    u8 unused_3D5A[10];
    struct TrainerHillSave trainerHill;
    struct WaldaPhrase waldaPhrase;
               u8 registeredItemLastSelected:4; //max 16 items
               u8 registeredItemListCount:4;
               struct RegisteredItemSlot registeredItems[10];               
};

bool8 UpdateSave_v2_v3(const struct SaveSectorLocation *locations)
{
    const struct SaveBlock2_v2* sOldSaveBlock2Ptr = (struct SaveBlock2_v2*)(locations[SECTOR_ID_SAVEBLOCK2].data);
    const struct SaveBlock1_v2* sOldSaveBlock1Ptr = (struct SaveBlock1_v2*)(locations[SECTOR_ID_SAVEBLOCK1_START].data);
    const struct PokemonStorage* sOldPokemonStoragePtr = (struct PokemonStorage*)(locations[SECTOR_ID_PKMN_STORAGE_START].data);

    u32 arg, i, j, k;
    u16 tempOptionSurfMusic;
    u16 tempOptionBikeMusic;
    u16 tempOptionSurfOverworld;
    
    #define COPY_FIELD(field) gSaveBlock2Ptr->field = sOldSaveBlock2Ptr->field
    #define COPY_BLOCK(field) CpuCopy16(&sOldSaveBlock2Ptr->field, &gSaveBlock2Ptr->field, sizeof(gSaveBlock2Ptr->field))
    #define COPY_ARRAY(field) for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->field), ARRAY_COUNT(sOldSaveBlock2Ptr->field)); i++) gSaveBlock2Ptr->field[i] = sOldSaveBlock2Ptr->field[i];

    /** We need to fill in any data that's new in this version. */
    gSaveBlock2Ptr->_saveSentinel = 0xFF;
    gSaveBlock2Ptr->saveVersion = 3;
    gSaveBlock2Ptr->optionsDiveSpeed = 0;

    // Copy V1 items - SaveBlock2

    tempOptionSurfMusic = sOldSaveBlock2Ptr->optionsSurfMusic;
    tempOptionBikeMusic = sOldSaveBlock2Ptr->optionsBikeMusic;
    tempOptionSurfOverworld = sOldSaveBlock2Ptr->optionsSurfOverworld;
    COPY_FIELD(optionsBattleItemAnimation);

    COPY_ARRAY(playerName);
    COPY_FIELD(playerGender);
    COPY_FIELD(specialSaveWarpFlags);
    COPY_ARRAY(playerTrainerId);
    COPY_FIELD(playTimeHours);
    COPY_FIELD(playTimeMinutes);
    COPY_FIELD(playTimeSeconds);
    COPY_FIELD(playTimeVBlanks);
    COPY_FIELD(optionsButtonMode);
    COPY_FIELD(optionsTextSpeed);
    COPY_FIELD(optionsWindowFrameType);
    COPY_FIELD(optionsSound);
    COPY_FIELD(optionsBattleStyle);
    COPY_FIELD(optionsBattleSceneOff);
    COPY_FIELD(regionMapZoom);
    
    COPY_FIELD(pokedex);
    COPY_FIELD(localTimeOffset);
    COPY_FIELD(lastBerryTreeUpdate);
    COPY_FIELD(gcnLinkFlags);
    COPY_FIELD(encryptionKey);
    COPY_FIELD(playerApprentice);
    COPY_BLOCK(apprentices);
    COPY_FIELD(berryCrush);
    COPY_FIELD(pokeJump);
    COPY_FIELD(berryPick);
    COPY_BLOCK(hallRecords1P);
    COPY_BLOCK(hallRecords2P);
    COPY_BLOCK(contestLinkResults);
    COPY_FIELD(frontier);

    #undef COPY_FIELD
    #undef COPY_BLOCK
    #undef COPY_ARRAY

    #define COPY_FIELD(field) gSaveBlock1Ptr->field = sOldSaveBlock1Ptr->field
    #define COPY_BLOCK(field) CpuCopy16(&sOldSaveBlock1Ptr->field, &gSaveBlock1Ptr->field, sizeof(gSaveBlock1Ptr->field))
    #define COPY_ARRAY(field) for(i = 0; i < min(ARRAY_COUNT(gSaveBlock1Ptr->field), ARRAY_COUNT(sOldSaveBlock1Ptr->field)); i++) gSaveBlock1Ptr->field[i] = sOldSaveBlock1Ptr->field[i];

    // Copy V1 items - SaveBlock1
    COPY_FIELD(registeredItemSelect);
    COPY_FIELD(registeredItemLastSelected);
    COPY_FIELD(registeredItemListCount);
    COPY_ARRAY(registeredItems);

    // Copy V2 items - SaveBlock 1
    COPY_FIELD(secretBaseWarp);
    
    COPY_FIELD(pos);
    COPY_FIELD(location);
    COPY_FIELD(continueGameWarp);
    COPY_FIELD(dynamicWarp);
    COPY_FIELD(lastHealLocation);
    COPY_FIELD(escapeWarp);

    /** Only use this if there are no major map changes to load into original location
     * If there are any major map changes comment the below section out and use the 
     * heal warp at the bottom of this function instead. */
    /*
    COPY_FIELD(weather);
    COPY_FIELD(weatherCycleStage);
    COPY_FIELD(flashLevel);
    COPY_FIELD(savedMusic);
    COPY_FIELD(mapLayoutId);
    COPY_BLOCK(mapView);
    COPY_BLOCK(objectEvents);
    COPY_BLOCK(objectEventTemplates);
    */
    /** The pokemon structure hasn't changed at all this version, so
     *  we don't need to do anything special to copy the pokemon over. */
    COPY_FIELD(playerPartyCount);
    COPY_ARRAY(playerParty);
    
    COPY_FIELD(money);
    COPY_FIELD(coins);
    
    /** Because we changed the PC items, it's not gonna be a straight copy. */
    COPY_ARRAY(pcItems);
    COPY_ARRAY(bagPocket_Items);
    COPY_ARRAY(bagPocket_KeyItems);
    COPY_ARRAY(bagPocket_PokeBalls);
    COPY_ARRAY(bagPocket_TMHM);
    COPY_ARRAY(bagPocket_Berries);
    
    COPY_BLOCK(pokeblocks);
    COPY_BLOCK(seen1);
    COPY_BLOCK(berryBlenderRecords);
    COPY_FIELD(trainerRematchStepCounter);
    COPY_BLOCK(trainerRematches);
    
    COPY_BLOCK(flags);
    COPY_BLOCK(vars);
    COPY_BLOCK(gameStats);
    COPY_BLOCK(berryTrees);
    COPY_BLOCK(secretBases);
    COPY_BLOCK(playerRoomDecorations);
    COPY_BLOCK(playerRoomDecorationPositions);
    COPY_BLOCK(decorationDesks);
    COPY_BLOCK(decorationChairs);
    COPY_BLOCK(decorationPlants);
    COPY_BLOCK(decorationOrnaments);
    COPY_BLOCK(decorationMats);
    COPY_BLOCK(decorationPosters);
    COPY_BLOCK(decorationDolls);
    COPY_BLOCK(decorationCushions);
    
    COPY_BLOCK(tvShows);
    COPY_BLOCK(pokeNews);
    COPY_FIELD(outbreakPokemonSpecies);
    COPY_FIELD(outbreakLocationMapNum);
    COPY_FIELD(outbreakLocationMapGroup);
    COPY_FIELD(outbreakPokemonLevel);
    COPY_FIELD(outbreakUnused1);
    COPY_FIELD(outbreakUnused2);
    COPY_BLOCK(outbreakPokemonMoves);
    COPY_FIELD(outbreakUnused3);
    COPY_FIELD(outbreakPokemonProbability);
    COPY_FIELD(outbreakDaysLeft);
    COPY_FIELD(gabbyAndTyData);
    COPY_BLOCK(easyChatProfile);
    COPY_BLOCK(easyChatBattleStart);
    COPY_BLOCK(easyChatBattleWon);
    COPY_BLOCK(easyChatBattleLost);
    COPY_BLOCK(mail);
    COPY_BLOCK(unlockedTrendySayings);
    
    COPY_FIELD(oldMan);
    COPY_BLOCK(dewfordTrends);
    COPY_BLOCK(contestWinners);
    COPY_FIELD(daycare);
    COPY_FIELD(linkBattleRecords);
    COPY_BLOCK(giftRibbons);
    COPY_FIELD(externalEventData);
    COPY_FIELD(externalEventFlags);
    COPY_FIELD(roamer);
    COPY_FIELD(enigmaBerry);
    COPY_FIELD(mysteryGift);
    COPY_BLOCK(trainerHillTimes);
    COPY_FIELD(ramScript);
    COPY_FIELD(recordMixingGift);
    COPY_BLOCK(seen2);
    COPY_FIELD(lilycoveLady);
    COPY_BLOCK(trainerNameRecords);
    COPY_BLOCK(registeredTexts);
    COPY_FIELD(trainerHill);
    COPY_FIELD(waldaPhrase);
    
    #undef COPY_FIELD
    #undef COPY_BLOCK
    #undef COPY_ARRAY

    /**
     * The pokemon structure hasn't changed at all this version, so
     * we can just assign across the old box storage to the new.  */
    *gPokemonStoragePtr = *sOldPokemonStoragePtr;
    
    // Update Flags moved from Saveblock
    !FlagGet(FLAG_ENABLE_FOLLOWER)  ? FlagSet(FLAG_ENABLE_FOLLOWER)         : FlagClear(FLAG_ENABLE_FOLLOWER); // For consistency with other similar flags the flag name has been changed and use has been inverted throughout the code between V2 and V3 (same Flag dataslot hence not needing to change the name)
    tempOptionSurfOverworld == 0    ? FlagSet(FLAG_ENABLE_SURFOVERWORLD)    : FlagClear(FLAG_ENABLE_SURFOVERWORLD); // Inverse Flag setting due to 0 defaulting to on in saveblock configuration
    tempOptionSurfMusic == 0        ? FlagClear(FLAG_DISABLE_SURFMUSIC)     : FlagSet(FLAG_DISABLE_SURFMUSIC);
    tempOptionBikeMusic == 0        ? FlagClear(FLAG_DISABLE_BIKEMUSIC)     : FlagSet(FLAG_DISABLE_BIKEMUSIC);

    // Check for Game Cleared to unlocked for Stat Editor unlock due to change in flag configuration (Could use National Dex, but due to National Dex flag being used in more areas prefer to use game clear flag)
    FlagGet(FLAG_SYS_GAME_CLEAR)    ? FlagSet(FLAG_ENABLE_STAT_EDITOR)      : FlagClear(FLAG_ENABLE_STAT_EDITOR);
    FlagGet(FLAG_SYS_GAME_CLEAR)    ? FlagSet(FLAG_SHOW_STAT_EDITOR)        : FlagClear(FLAG_SHOW_STAT_EDITOR);

    // Add Shiny Charm to Save Upgrades
    AddPCItem(ITEM_SHINY_CHARM, 1); // One base Shiny Charm for the game

    // Add Shiny Charms based on in-game progression
    FlagGet(FLAG_SYS_GAME_CLEAR)                ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Beat the game
    FlagGet(FLAG_RECEIVED_GLASS_ORNAMENT)       ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Complete Master Rank Contests
    FlagGet(FLAG_DEFEATED_METEOR_FALLS_STEVEN)  ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Defeat Steven in Meteor Falls
    FlagGet(FLAG_HOENN_DEX_COMPLETE)            ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Complete the Hoenn Dex (not including Jirachi or Deoxys)
    FlagGet(FLAG_NATIONAL_DEX_COMPLETE)         ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Complete the National Dex (not including Mew, Celebi, Jirachi or Deoxys)
    FlagGet(FLAG_COLLECTED_ALL_SILVER_SYMBOLS)  ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Get all Silver Symbols
    FlagGet(FLAG_COLLECTED_ALL_GOLD_SYMBOLS)    ? AddPCItem(ITEM_SHINY_CHARM, 1) : 0; // Get all Gold Symbols

    /**
     * The most common kind of change that might happen between major versions are 
     * map changes. The save file usually saves the area around the player and 
     * event objects currently on the map, so that when the player resumes play, 
     * everything will be exactly where it was when they saved. But if the map has
     * changed at all, this means there could be incongruity between the saved
     * version of the map and the new version in the updated ROM. So to make it so
     * that the map reloads properly, we use the "Continue Game Warp" usually used
     * when the player clears the game to place the player at a known position and
     * with a newly loaded map and event objects. Here, we're using the last location
     * that the player healed, so the player will appear in the same spot they would
     * as if they blacked out. */
    SetContinueGameWarpStatus();

    if (gSaveBlock2Ptr->playerGender == MALE)
        SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F);
    else
        SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F);

    return TRUE;
}