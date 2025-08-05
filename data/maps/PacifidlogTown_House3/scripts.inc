.set LOCALID_TRADEMON, 3

PacifidlogTown_House3_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_House3_OnResume
	.byte 0

PacifidlogTown_House3_OnResume:
	call_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_SetUpRelicanth
	call_if_unset FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_SetUpBagon
	return

PacifidlogTown_House3_EventScript_SetUpRelicanth::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_RELICANTH
	return

PacifidlogTown_House3_EventScript_SetUpBagon::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_BAGON
	return

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_BAGON
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	call PacifidlogTown_House3_EventScript_SetUpRelicanth
	addobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_EventScript_Mon::
	call_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_Relicanth
	call_if_unset FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_Bagon
	end

PacifidlogTown_House3_EventScript_Relicanth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RELICANTH, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House3_Text_Relicanth, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PacifidlogTown_House3_EventScript_Bagon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House3_Text_Bagon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Check out this {STR_VAR_2}!\p"
	.string "It's the {STR_VAR_2} that I caught\n"
	.string "yesterday to celebrate my birthday!\p"
	.string "Oh, I can see that you want it!\n"
	.string "After all, it's priceless!\p"
	.string "I'll tell you what. I might be willing\n"
	.string "to trade it for a {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, so this is a {STR_VAR_1}?\p"
	.string "It's sort of like a {STR_VAR_2},\n"
	.string "and yet it's subtly different.\p"
	.string "Thank you!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "I know I could go looking for one\n"
	.string "on my own, but…\p"
	.string "But I really wanted to get a RELICANTH\n"
	.string "that another TRAINER caught…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Is that a POKéDEX?\p"
	.string "Did you get to meet a lot of different\n"
	.string "POKéMON?\p"
	.string "I wish I was like you.$"

PacifidlogTown_House3_Text_Relicanth:
	.string "RELICANTH: Re li rel!$"

PacifidlogTown_House3_Text_Bagon:
	.string "SEASOR: Ba-go!$"
