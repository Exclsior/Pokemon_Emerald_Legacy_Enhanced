BattleFrontier_Lounge8_MapScripts::
	.byte 0

BattleFrontier_Lounge8_EventScript_Man::
	msgbox BattleFrontier_Lounge8_Text_WhatATrainerNeeds, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_Woman::
	msgbox BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_FRONTIER_PLUSLE_NPC_TRADE_COMPLETED, BattleFrontier_Lounge8_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge8_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge8_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge8_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge8_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge8_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FRONTIER_PLUSLE_NPC_TRADE_COMPLETED
	release
	end

BattleFrontier_Lounge8_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge8_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge8_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge8_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge8_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge8_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge8_Text_YouWillTradeWontYou:
	.string "At the BATTLE TOWER, an older girl\n"
	.string "told me that I have a lot of talent\l"
	.string "for battling!\p"
	.string "I like POKéMON CONTESTS more!\p"
	.string "But I'm no good at CONTESTS!\p"
	.string "I have to get me a {STR_VAR_1}!\n"
	.string "That will help me win POKéMON\l"
	.string "CONTESTS.\p"
	.string "Having heard that, you will trade\n"
	.string "your {STR_VAR_1} for my {STR_VAR_2},\l"
	.string "won't you?$"

BattleFrontier_Lounge8_Text_MonYouTakeCare:
	.string "Oh, yeah, right on!\p"
	.string "{STR_VAR_1}, welcome!\n"
	.string "{STR_VAR_2}, you take care!$"

BattleFrontier_Lounge8_Text_ThisIsntAMon:
	.string "Uh, no, I don't think so.\n"
	.string "That isn't a {STR_VAR_1}.$"

BattleFrontier_Lounge8_Text_YouWontTradeMe:
	.string "No? You won't trade me?\n"
	.string "Even after I bared my heart to you?$"

BattleFrontier_Lounge8_Text_GoingToMakeVolbeatStrong:
	.string "I'm going to make VOLBEAT super\n"
	.string "strong from this moment on!\p"
	.string "I hope you do the same with PLUSLE!$"

BattleFrontier_Lounge8_Text_WhatATrainerNeeds:
	.string "What a TRAINER needs…\p"
	.string "Knowledge…\n"
	.string "Strategy…\l"
	.string "Luck…\l"
	.string "Guts…\l"
	.string "Spirit…\l"
	.string "Bravery…\l"
	.string "And ability…\p"
	.string "Well, I'm all set in every way!\n"
	.string "I'll be unstoppable at every building!\p"
	.string "Huh? POKéMON?\n"
	.string "What's that?$"

BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains:
	.string "Do you know about the FRONTIER\n"
	.string "BRAINS?\p"
	.string "That's what SCOTT calls the seven\n"
	.string "special TRAINERS that run the seven\l"
	.string "facilities in the BATTLE FRONTIER.$"
