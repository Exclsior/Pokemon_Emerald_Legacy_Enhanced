.set LOCALID_TRADEMON, 4

FortreeCity_House1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_House1_OnResume
	.byte 0

FortreeCity_House1_OnResume:
	call_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_SetUpKecleon
	call_if_unset FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_SetUpLoudred
	return

FortreeCity_House1_EventScript_SetUpKecleon::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_KECLEON
	return

FortreeCity_House1_EventScript_SetUpLoudred::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_LOUDRED
	return

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_LOUDRED
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	call FortreeCity_House1_EventScript_SetUpKecleon
	addobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_EventScript_Mon::
	call_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_Kecleon
	call_if_unset FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_Loudred
	end

FortreeCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_EventScript_Loudred::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LOUDRED, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Loudred, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Hey, listen up! I've been searching\n"
	.string "for a {STR_VAR_1} forever!\l"
	.string "I can’t rest until I have one!\p"
	.string "…Did you catch that?\n"
	.string "That’s the sound of pure determination!\p"
	.string "Now that you know, you'll trade\n"
	.string "your {STR_VAR_1} for my {STR_VAR_2},\l"
	.string "right?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Wow! You really want to trade! I’ll make\n"
	.string "sure to keep this {STR_VAR_1} in top\l"
	.string "shape.\p"
	.string "You take good care of my {STR_VAR_2},\n"
	.string "okay?$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Hmm, no, that’s not it.\n"
	.string "I need a real {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Oh, I see… Not interested in trading,\n"
	.string "huh? That’s okay, maybe another time!$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "My KECLEON is gonna be the strongest\n"
	.string "one around! I hope LOUDRED fits\l"
	.string "right into your team!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Trading POKéMON with others…\p"
	.string "It's as if you're trading your own\n"
	.string "memories with other people.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"

FortreeCity_House1_Text_Kecleon:
	.string "KECLEON: Puu puhyaah.$"

FortreeCity_House1_Text_Loudred:
	.string "ECHO: Lo lo LO!!$"
