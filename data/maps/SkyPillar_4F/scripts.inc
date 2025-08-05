SkyPillar_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_4F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_4F_SetHoleWarp
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_4F_OnLoad
	.byte 0

SkyPillar_4F_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_4F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SkyPillar_4F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_4F_CLEAN
	return

SkyPillar_4F_OnLoad:
	call_if_set FLAG_COLLECTED_ALL_SILVER_SYMBOLS, SkyPillar_4F_EventScript_MoveRocksAndFloor
	return

SkyPillar_4F_EventScript_MoveRocksAndFloor::
	setmetatile 12, 2, METATILE_General_GreyLargeRocksShaded, TRUE
	setmetatile 13, 3, METATILE_Pacifidlog_SkyPillar_GreyFloor, FALSE
	setmetatile 13, 8, METATILE_Pacifidlog_SkyPillar_GreyFloor, FALSE
	setmetatile 13, 9, METATILE_General_GreyLargeRocks, TRUE
	setmetatile 13, 10, METATILE_General_GreySmallRocks, TRUE
	setmetatile 11, 12, METATILE_Pacifidlog_SkyPillar_GreyFloor, FALSE
	setmetatile 2, 12, METATILE_Pacifidlog_SkyPillar_GreyFloor, FALSE
	setmetatile 0, 11, METATILE_General_GreyLargeRocks, TRUE
	setmetatile 4, 4, METATILE_Pacifidlog_SkyPillar_GreyFloor, FALSE
	return

SkyPillar_4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_3F
	end

SkyPillar_4F_EventScript_Zinnia::
	applymovement LOCALID_ZINNIA, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SkyPillar_4F_Text_Zinnia, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, Common_Movement_FaceUp
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZINNIA
	fadescreen FADE_FROM_BLACK
	setflag FLAG_SPOKE_TO_ZINNIA_4F
	setflag FLAG_HIDE_ZINNIA_4F
	clearflag FLAG_HIDE_ZINNIA_5F
	release
	end

SkyPillar_4F_Text_Zinnia::
	.string "From that eruption, the CAVE OF ORIGIN\n"
	.string "was born…\p"
	.string "A place holding secrets that go back to\n"
	.string "the very roots of SOOTOPOLIS itself.\p"
	.string "Only a handful, like WALLACE, can really\n"
	.string "understand it.\p"
	.string "The CAVE and the SKY PILLAR?\p"
	.string "They're two halves of the same mystery,\n"
	.string "each part of life's balance.\p"
	.string "WALLACE could guide you there because\n"
	.string "of his ancient SOOTOPOLIAN blood,\l"
	.string "just like mine to the DRACONIDS.\p"
	.string "See? We're bound together that way.$"
