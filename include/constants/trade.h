#ifndef GUARD_CONSTANTS_TRADE_H
#define GUARD_CONSTANTS_TRADE_H

#define TRADE_PLAYER  0
#define TRADE_PARTNER 1

// In-game Trade IDs
#define INGAME_TRADE_SEEDOT 0
#define INGAME_TRADE_PLUSLE 1
#define INGAME_TRADE_BAGON 2
#define INGAME_TRADE_MEOWTH 3
#define INGAME_TRADE_TORCHIC_MAY_TREECKO 4
#define INGAME_TRADE_TORCHIC_MAY_MUDKIP 5
#define INGAME_TRADE_TORCHIC_BRENDAN_TREECKO 6
#define INGAME_TRADE_TORCHIC_BRENDAN_MUDKIP 7
#define INGAME_TRADE_MUDKIP_MAY_TREECKO 8
#define INGAME_TRADE_MUDKIP_MAY_TORCHIC 9
#define INGAME_TRADE_MUDKIP_BRENDAN_TREECKO 10
#define INGAME_TRADE_MUDKIP_BRENDAN_TORCHIC 11
#define INGAME_TRADE_TREECKO_MAY_MUDKIP 12
#define INGAME_TRADE_TREECKO_MAY_TORCHIC 13
#define INGAME_TRADE_TREECKO_BRENDAN_MUDKIP 14
#define INGAME_TRADE_TREECKO_BRENDAN_TORCHIC 15
#define INGAME_TRADE_NUMEL 16
#define INGAME_TRADE_SNORUNT 17
#define INGAME_TRADE_LOUDRED 18

// National Dex Mode Starter Trades
#define INGAME_TRADE_TORCHIC_MAY_BULBASAUR 19       // Trade 1 - Bulbasaur  - May
#define INGAME_TRADE_TORCHIC_MAY_CHARMANDER 20      // Trade 3 - Charmander - May       - Same Type
#define INGAME_TRADE_TORCHIC_MAY_SQUIRTLE 21        // Trade 1 - Squirtle   - May
#define INGAME_TRADE_TORCHIC_BRENDAN_BULBASAUR 22   // Trade 1 - Bulbasaur  - Brendan
#define INGAME_TRADE_TORCHIC_BRENDAN_CHARMANDER 23  // Trade 3 - Charmander - Brendan   - Same Type
#define INGAME_TRADE_TORCHIC_BRENDAN_SQUIRTLE 24    // Trade 1 - Squirtle   - Brendan
#define INGAME_TRADE_MUDKIP_MAY_BULBASAUR 25        // Trade 2 - Bulbasaur  - May
#define INGAME_TRADE_MUDKIP_MAY_CHARMANDER 26       // Trade 1 - Charmander - May
#define INGAME_TRADE_MUDKIP_MAY_SQUIRTLE 27         // Trade 3 - Squirtle   - May       - Same Type
#define INGAME_TRADE_MUDKIP_BRENDAN_BULBASAUR 28    // Trade 2 - Bulbasaur  - Brendan
#define INGAME_TRADE_MUDKIP_BRENDAN_CHARMANDER 29   // Trade 1 - Charmander - Brendan
#define INGAME_TRADE_MUDKIP_BRENDAN_SQUIRTLE 30     // Trade 3 - Squirtle   - Brendan   - Same Type
#define INGAME_TRADE_TREECKO_MAY_BULBASAUR 31       // Trade 3 - Bulbasaur  - May       - Same Type
#define INGAME_TRADE_TREECKO_MAY_CHARMANDER 32      // Trade 2 - Charmander - May
#define INGAME_TRADE_TREECKO_MAY_SQUIRTLE 33        // Trade 2 - Squirtle   - May
#define INGAME_TRADE_TREECKO_BRENDAN_BULBASAUR 34   // Trade 3 - Bulbasaur  - Brendan   - Same Type
#define INGAME_TRADE_TREECKO_BRENDAN_CHARMANDER 35  // Trade 2 - Charmander - Brendan
#define INGAME_TRADE_TREECKO_BRENDAN_SQUIRTLE 36    // Trade 2 - Squirtle   - Brendan
#define INGAME_TRADE_TORCHIC_MAY_CHIKORITA 37       // Trade 1 - Chikorita  - May
#define INGAME_TRADE_TORCHIC_MAY_CYNDAQUIL 38       // Trade 3 - Cyndaquil  - May       - Same Type
#define INGAME_TRADE_TORCHIC_MAY_TOTODILE 39        // Trade 1 - Totodile   - May
#define INGAME_TRADE_TORCHIC_BRENDAN_CHIKORITA 40   // Trade 1 - Chikorita  - Brendan
#define INGAME_TRADE_TORCHIC_BRENDAN_CYNDAQUIL 41   // Trade 3 - Cyndaquil  - Brendan   - Same Type
#define INGAME_TRADE_TORCHIC_BRENDAN_TOTODILE 42    // Trade 1 - Totodile   - Brendan
#define INGAME_TRADE_MUDKIP_MAY_CHIKORITA 43        // Trade 2 - Chikorita  - May
#define INGAME_TRADE_MUDKIP_MAY_CYNDAQUIL 44        // Trade 1 - Cyndaquil  - May
#define INGAME_TRADE_MUDKIP_MAY_TOTODILE 45         // Trade 3 - Totodile   - May       - Same Type
#define INGAME_TRADE_MUDKIP_BRENDAN_CHIKORITA 46    // Trade 2 - Chikorita  - Brendan
#define INGAME_TRADE_MUDKIP_BRENDAN_CYNDAQUIL 47    // Trade 1 - Cyndaquil  - Brendan
#define INGAME_TRADE_MUDKIP_BRENDAN_TOTODILE 48     // Trade 3 - Totodile   - Brendan   - Same Type
#define INGAME_TRADE_TREECKO_MAY_CHIKORITA 49       // Trade 3 - Chikorita  - May       - Same Type
#define INGAME_TRADE_TREECKO_MAY_CYNDAQUIL 50       // Trade 2 - Cyndaquil  - May
#define INGAME_TRADE_TREECKO_MAY_TOTODILE 51        // Trade 2 - Totodile   - May
#define INGAME_TRADE_TREECKO_BRENDAN_CHIKORITA 52   // Trade 3 - Chikorita  - Brendan   - Same Type
#define INGAME_TRADE_TREECKO_BRENDAN_CYNDAQUIL 53   // Trade 2 - Cyndaquil  - Brendan
#define INGAME_TRADE_TREECKO_BRENDAN_TOTODILE 54    // Trade 2 - Totodile   - Brendan

// Return values for CanTradeSelectedMon and CanSpinTradeMon
#define CAN_TRADE_MON              0
#define CANT_TRADE_LAST_MON        1
#define CANT_TRADE_NATIONAL        2
#define CANT_TRADE_EGG_YET         3
#define CANT_TRADE_INVALID_MON     4
#define CANT_TRADE_PARTNER_EGG_YET 5

// Return values for CheckValidityOfTradeMons
#define PLAYER_MON_INVALID   0
#define BOTH_MONS_VALID      1
#define PARTNER_MON_INVALID  2

// Return values for GetGameProgressForLinkTrade
#define TRADE_BOTH_PLAYERS_READY      0
#define TRADE_PLAYER_NOT_READY        1
#define TRADE_PARTNER_NOT_READY       2

// Message indexes for sUnionRoomTradeMessages
#define UR_TRADE_MSG_NONE                         0
#define UR_TRADE_MSG_NOT_MON_PARTNER_WANTS        1
#define UR_TRADE_MSG_NOT_EGG                      2
#define UR_TRADE_MSG_MON_CANT_BE_TRADED_1         3
#define UR_TRADE_MSG_MON_CANT_BE_TRADED_2         4
#define UR_TRADE_MSG_PARTNERS_MON_CANT_BE_TRADED  5
#define UR_TRADE_MSG_EGG_CANT_BE_TRADED           6
#define UR_TRADE_MSG_PARTNER_CANT_ACCEPT_MON      7
#define UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_1    8
#define UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_2    9

// Return values for CanRegisterMonForTradingBoard
#define CAN_REGISTER_MON   0
#define CANT_REGISTER_MON  1
#define CANT_REGISTER_EGG  2


#endif //GUARD_CONSTANTS_TRADE_H
