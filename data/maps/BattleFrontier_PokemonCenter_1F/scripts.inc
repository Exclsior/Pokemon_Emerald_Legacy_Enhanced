.set LOCALID_NURSE, 1
.set LOCALID_TRADEMON, 6

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	call_if_set FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED, BattleFrontier_PokemonCenter_1F_EventScript_SetUpRalts
	call_if_unset FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED, BattleFrontier_PokemonCenter_1F_EventScript_SetUpSeedot
	end

BattleFrontier_PokemonCenter_1F_EventScript_SetUpRalts::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_RALTS
	return

BattleFrontier_PokemonCenter_1F_EventScript_SetUpSeedot::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_SEEDOT
	return

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	lock
	faceplayer
	goto_if_set FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED, BattleFrontier_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_PokemonCenter_1F_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_PokemonCenter_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_PokemonCenter_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	call BattleFrontier_PokemonCenter_1F_EventScript_SetUpRalts
	addobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	setflag FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox BattleFrontier_PokemonCenter_1F_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_PokemonCenter_1F_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox BattleFrontier_PokemonCenter_1F_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_Mon::
	call_if_set FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED, BattleFrontier_PokemonCenter_1F_EventScript_Ralts
	call_if_unset FLAG_FRONTIER_SEEDOT_NPC_TRADE_COMPLETED, BattleFrontier_PokemonCenter_1F_EventScript_Seedot
	end

BattleFrontier_PokemonCenter_1F_EventScript_Ralts::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RALTS, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Ralts, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_Seedot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEDOT, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Seedot, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
BattleFrontier_PokemonCenter_1F_Text_IllTradeIfYouWant:
	.string "There was someone here using a {STR_VAR_1},\n"
	.string "a POKéMON I've never seen before.\p"
	.string "I couldn't help but notice it was\n"
	.string "both rare and quite impressive.\p"
	.string "If you find one, I'm willing to\n"
	.string "trade you my {STR_VAR_2}.\p"
	.string "It may not be as rare, but I know\n"
	.string "my POKéMON is cute. Maybe you’ll\l"
	.string "find it worth the trade.$"

BattleFrontier_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Please be good to my POKéMON.$"

BattleFrontier_PokemonCenter_1F_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

BattleFrontier_PokemonCenter_1F_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.\n"
	.string "But my POKéMON is cute, you know…$"

BattleFrontier_PokemonCenter_1F_Text_AnyPokemonCanBeCute:
	.string "Any POKéMON can be cute if you raise\n"
	.string "it with care and kindness.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I'd better get the right POKéMON from\l"
	.string "the PC Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Mya myaaah!$"

BattleFrontier_PokemonCenter_1F_Text_Ralts:
	.string "RALTS: Ra ru!$"

BattleFrontier_PokemonCenter_1F_Text_Seedot:
	.string "DOTS: Sesesese!$"
