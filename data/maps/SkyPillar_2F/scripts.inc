.set LOCALID_ZINNIA, 1

SkyPillar_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_2F_SetHoleWarp
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_2F_OnLoad
	.byte 0

SkyPillar_2F_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_2F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

SkyPillar_2F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_2F_CLEAN
	return

SkyPillar_2F_OnLoad:
	call_if_set FLAG_COLLECTED_ALL_SILVER_SYMBOLS, SkyPillar_2F_EventScript_MoveRocks
	return

SkyPillar_2F_EventScript_MoveRocks::
	setmetatile 0, 6, METATILE_Pacifidlog_SkyPillar_GreyFloor, FALSE
	setmetatile 0, 4, METATILE_General_GreySmallRocks, TRUE
	setmetatile 2, 5, METATILE_General_GreySmallRocks, TRUE
	return

SkyPillar_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_1F
	end

SkyPillar_2F_EventScript_Zinnia::
	applymovement LOCALID_ZINNIA, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SkyPillar_2F_Text_Zinnia, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZINNIA, Common_Movement_FaceUp
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZINNIA
	fadescreen FADE_FROM_BLACK
	setflag FLAG_SPOKE_TO_ZINNIA_2F
	setflag FLAG_HIDE_ZINNIA_2F
	clearflag FLAG_HIDE_ZINNIA_3F
	release
	end

SkyPillar_2F_Text_Zinnia::
	.string "Let me tell you a story.\p"
	.string "A thousand years ago, a fierce eruption\n"
	.string "rose up from the sea.\p"
	.string "That's what gave us SOOTOPOLIS, but it\n"
	.string "also stirred up GROUDON and KYOGRE.\p"
	.string "At first, they seemed calm… until they\n"
	.string "met each other.\l"
	.string "Then, chaos!\p"
	.string "My ancestor back then was the\n"
	.string "LOREKEEPER, and she prayed with\l"
	.string "everything she had for RAYQUAZA\l"
	.string "to return.\p"
	.string "And when RAYQUAZA did, it calmed the\n"
	.string "storm, putting those two back to sleep.\p"
	.string "Since then, we've carried on this role,\n"
	.string "passing down our knowledge…\p"
	.string "ready to call RAYQUAZA again if it's\n"
	.string "ever needed.$"
