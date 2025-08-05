.set LOCALID_LATI, 2
.set LOCALID_EXCLSIOR, 3
.set LOCALID_TYPHLOSION, 4
.set LOCALID_SHINY_LATI, 5
SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LATI
	removeobject LOCALID_SHINY_LATI
	return

SouthernIsland_Interior_OnTransition:
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatios
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatias
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	goto SouthernIsland_Interior_EventScript_CheckExclsior
	end

SouthernIsland_Interior_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE+SPECIES_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_CheckExclsior::
	goto_if_set FLAG_DEFEATED_EXCLSIOR, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_RIVAL_GOT_ALL_KANTO_MONS, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_DEFEATED_WEEBRA, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_DEFEATED_CRAIG, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_DEFEATED_SMITH, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_DEFEATED_METEOR_FALLS_STEVEN, SouthernIsland_Interior_EventScript_HideExclsior
	goto_if_unset FLAG_BATTLED_JIRACHI, SouthernIsland_Interior_EventScript_HideExclsior
	addobject LOCALID_EXCLSIOR
	addobject LOCALID_TYPHLOSION
	end

SouthernIsland_Interior_EventScript_HideExclsior::
	removeobject LOCALID_EXCLSIOR
	removeobject LOCALID_TYPHLOSION
	return

SouthernIsland_Interior_EventScript_Typhlosion::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_NORMAL
	msgbox SouthernIsland_Interior_Text_Typhlosion, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_TryLatiEncounter::
	lockall
	setvar VAR_0x8008, 12  @ Player's Y coordinate. Not read
	goto SouthernIsland_Interior_EventScript_Lati
	end

SouthernIsland_Interior_EventScript_Lati::
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_CloserLookAtStone
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_CloserLookAtStone
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	addobject LOCALID_LATI
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_LATI
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_LatiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_LatiDefeated::
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_RanFromLati::
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_Sign::
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
	seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
	seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_EventScript_Exclsior::
	goto_if_set FLAG_DEFEATED_EXCLSIOR, SouthernIsland_Interior_Text_ExclsiorPostBattle
	faceplayer
	applymovement LOCALID_TYPHLOSION, SouthernIsland_Interior_Movement_WalkSlowDown
	msgbox SouthernIsland_Interior_Text_Exclsior_ImCurious, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SouthernIsland_Interior_EventScript_Exclsior_NoBattle
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_EXCLSIOR, 0, SouthernIsland_Interior_Text_ExclsiorIntro, SouthernIsland_Interior_Text_ExclsiorDefeated, SouthernIsland_Interior_EventScript_ExclsiorPostBattle
	end

SouthernIsland_Interior_EventScript_Exclsior_NoBattle::
	msgbox SouthernIsland_Interior_Text_Exclsior_MaybeAnotherTime, MSGBOX_DEFAULT
	turnobject LOCALID_EXCLSIOR, DIR_NORTH
	release
	end

SouthernIsland_Interior_EventScript_ExclsiorPostBattle::
	msgbox SouthernIsland_Interior_Text_ExclsiorPostBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_EXCLSIOR
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_EXCLSIOR
	removeobject LOCALID_TYPHLOSION
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SouthernIsland_Interior_EventScript_CloserLookAtStone::
	goto_if_unset FLAG_DEFEATED_EXCLSIOR, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DEFEATED_SHINY_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_CAUGHT_SHINY_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	message SouthernIsland_Interior_Text_CloserLookAtStone
	waitmessage
	goto SouthernIsland_Interior_EventScript_ChooseShinyLati
	end

SouthernIsland_Interior_EventScript_ChooseShinyLati::
	multichoice 20, 8, MULTI_SHINY_LATI, TRUE
	switch VAR_RESULT
	case 0, SouthernIsland_Interior_EventScript_SetUpShinyLatias
	case 1, SouthernIsland_Interior_EventScript_SetUpShinyLatios
	end
	
SouthernIsland_Interior_EventScript_SetUpShinyLatios::
	closemessage
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES(LATIOS)
	setvar VAR_TEMP_4, SPECIES_LATIOS
	setflag FLAG_SHINY_CREATION
	call SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	goto SouthernIsland_Interior_EventScript_ShinyLati
	end

SouthernIsland_Interior_EventScript_SetUpShinyLatias::
	closemessage
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES(LATIAS)
	setvar VAR_TEMP_4, SPECIES_LATIAS
	setflag FLAG_SHINY_CREATION
	call SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	goto SouthernIsland_Interior_EventScript_ShinyLati
	end

SouthernIsland_Interior_EventScript_ShinyLati::
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	fadescreen FADE_TO_WHITE
	addobject LOCALID_SHINY_LATI
	fadescreen FADE_FROM_WHITE
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_SHINY_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_SHINY_LATI
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_ShinyLatiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_SHINY_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_ShinyLatiDefeated::
	setflag FLAG_DEFEATED_SHINY_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_Text_Exclsior_ImCurious:
	.string "Hmm...\n"
	.string "Few trainers know of this place...\p"
	.string "I'm curious...\p"
	.string "Would you like to battle?$"

SouthernIsland_Interior_Text_ExclsiorIntro:
	.string "Let's see the abilities of you and\n"
	.string "your POKéMON.$"

SouthernIsland_Interior_Text_ExclsiorDefeated:
	.string "Very impressive...$"

SouthernIsland_Interior_Text_Exclsior_MaybeAnotherTime::
	.string "Maybe another time then.$"

SouthernIsland_Interior_Text_ExclsiorPostBattle:
	.string "Thank you for the battle.\p"
	.string "...\p"
	.string "You may want to have a closer look at\n"
	.string "this stone...\p"
	.string "Goodbye.$"

SouthernIsland_Interior_Text_Typhlosion:
	.string "TYPHLOSION: Grooar!$"

SouthernIsland_Interior_Text_CloserLookAtStone:
	.string "You look closer at the strange stone.\p"
	.string "There seems to be a color shining\n"
	.string "through...\p"
	.string "Which color is shining through?$"

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SouthernIsland_Interior_Movement_LatiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_Movement_WalkSlowDown:
	walk_in_place_slow_down
	step_end

SouthernIsland_Interior_Movement_FaceUp:
	face_down
	step_end
