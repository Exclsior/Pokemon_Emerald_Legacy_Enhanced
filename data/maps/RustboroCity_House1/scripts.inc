.set LOCALID_TRADEMON, 3

RustboroCity_House1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, RustboroCity_House1_OnResume
	.byte 0

RustboroCity_House1_OnResume:
	call_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_SetUpShroomish
	call_if_unset FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_SetUpNumel
	return

RustboroCity_House1_EventScript_SetUpShroomish::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_SHROOMISH
	return

RustboroCity_House1_EventScript_SetUpNumel::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_NUMEL
	return

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_NUMEL
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	call RustboroCity_House1_EventScript_SetUpShroomish
	addobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_EventScript_Mon::
	call_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_Shroomish
	call_if_unset FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_Numel
	end

RustboroCity_House1_EventScript_Shroomish::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHROOMISH, CRY_MODE_NORMAL
	msgbox RustboroCity_House1_Text_Shroomish, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House1_EventScript_Numel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NUMEL, CRY_MODE_NORMAL
	msgbox RustboroCity_House1_Text_Numel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Oh, do you think my POKéMON is cool?\n"
	.string "Yeah, I think so too!\p"
	.string "But hey, if you're interested, I'd be\n"
	.string "willing to trade it with you.\p"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1}, what do you say?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hehe… Take good care of {STR_VAR_2},\n"
	.string "okay? It loves adventure!$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hmm? That doesn't seem like a\n"
	.string "{STR_VAR_1} to me…$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, that's fine if you don't want to.\n"
	.string "NUMEL will always be my little explorer.$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "You know, any POKéMON can be special\n"
	.string "if you show it love and patience.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "In all sorts of places, there are all\n"
	.string "sorts of POKéMON and people.\p"
	.string "I find that fascinating, so I go to all\n"
	.string "sorts of places.$"

RustboroCity_House1_Text_Shroomish:
	.string "SHROOMISH: Shroooooo.$"

RustboroCity_House1_Text_Numel:
	.string "MEL: Nu mu nu!$"
