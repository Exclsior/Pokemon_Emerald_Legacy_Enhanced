.set LOCALID_NURSE, 1
.set LOCALID_TRADEMON, 6

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	call_if_set FLAG_MAUVILLE_NPC_TRADE_COMPLETED, MauvilleCity_PokemonCenter_1F_EventScript_SetUpWhismur
	call_if_unset FLAG_MAUVILLE_NPC_TRADE_COMPLETED, MauvilleCity_PokemonCenter_1F_EventScript_SetUpSnorunt
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetUpWhismur::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_WHISMUR
	return

MauvilleCity_PokemonCenter_1F_EventScript_SetUpSnorunt::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_SNORUNT
	return

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_MAUVILLE_NPC_TRADE_COMPLETED, MauvilleCity_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SNORUNT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclinePokemonTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_PokemonCenter_1F_EventScript_DeclinePokemonTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_Text_MonYouTakeCare, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	call MauvilleCity_PokemonCenter_1F_EventScript_SetUpWhismur
	addobject LOCALID_TRADEMON
	fadescreen FADE_FROM_BLACK
	setflag FLAG_MAUVILLE_NPC_TRADE_COMPLETED
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclinePokemonTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThrilledToSeeNewPlaces, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Mon::
	call_if_set FLAG_MAUVILLE_NPC_TRADE_COMPLETED, MauvilleCity_PokemonCenter_1F_EventScript_Whismur
	call_if_unset FLAG_MAUVILLE_NPC_TRADE_COMPLETED, MauvilleCity_PokemonCenter_1F_EventScript_Snorunt
	end

MauvilleCity_PokemonCenter_1F_EventScript_Whismur::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
	msgbox MauvilleCity_PokemonCenter_1F_Text_Whismur, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Snorunt::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNORUNT, CRY_MODE_NORMAL
	msgbox MauvilleCity_PokemonCenter_1F_Text_Snorunt, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

MauvilleCity_PokemonCenter_1F_Text_YouWillTradeWontYou:
	.string "Oh! You have a {STR_VAR_1}, don't you?\p"
	.string "They're so lively! Would you be willing\n"
	.string "to trade it for my {STR_VAR_2}?\p"
	.string "It's quite the unique POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_MonYouTakeCare:
	.string "Take good care of NIPPY, okay?\p"
	.string "It's a bit shy at first, but it warms up\n"
	.string "quickly!$"

MauvilleCity_PokemonCenter_1F_Text_ThisIsntAMon:
	.string "Hm? Wait a moment… That's not the\n"
	.string "{STR_VAR_1} I was hoping for!\p"
	.string "Are you teasing me?$"

MauvilleCity_PokemonCenter_1F_Text_YouWontTradeMe:
	.string "Oh, you don't want to trade?\p"
	.string "That's alright, but if you change your\n"
	.string "mind, I'd love to find a good partner for\l"
	.string "my SNORUNT!$"

MauvilleCity_PokemonCenter_1F_Text_ThrilledToSeeNewPlaces:
	.string "I know NIPPY will be thrilled to\n"
	.string "see new places! With a bit of training, I\l"
	.string "bet it'll become a real star!$"

MauvilleCity_PokemonCenter_1F_Text_Whismur:
	.string "WHISMUR: Whi wi wis...$"

MauvilleCity_PokemonCenter_1F_Text_Snorunt:
	.string "NIPPY: Rororororo!$"
