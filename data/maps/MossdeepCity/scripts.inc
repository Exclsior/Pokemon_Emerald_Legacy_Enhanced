.set LOCALID_GIRL, 8
.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16
.set LOCALID_JIRACHI, 18
.set LOCALID_BIRCH, 19

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_OnResume
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MossdeepCity_EventScript_TryRemoveJirachi
	end

MossdeepCity_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JIRACHI
	return

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	goto_if_set FLAG_BATTLED_JIRACHI, MossdeepCity_Text_SpecialSpaceCenterRockPostJirachi
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_Text_SpecialSpaceCenterRockPostJirachi::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRockAfterEvent, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	call_if_set FLAG_BATTLED_JIRACHI, MossdeepCity_EventScript_WhiteRock_CheckJirachi
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_WhiteRock_CheckJirachi::
	call_if_unset FLAG_CAUGHT_JIRACHI, MossdeepCity_EventScript_WhiteRock_CheckJirachiDefeated
	return

MossdeepCity_EventScript_WhiteRock_CheckJirachiDefeated::
	goto_if_unset FLAG_DEFEATED_JIRACHI, MossdeepCity_EventScript_RematchJirachiAppears
	return

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_SceneWithBirch_EventScript_BirchNoticesYou1::
	lockall
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, MossdeepCity_Movement_BirchWalksToPlayerL
	waitmovement 0
	msgbox MossdeepCity_Text_BirchYouMadeIt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, MossdeepCity_Movement_BirchWalksToRockL
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWalksToRockL
	waitmovement 0
	goto MossdeepCity_SceneWithBirch_EventScript_Birch

MossdeepCity_SceneWithBirch_EventScript_BirchNoticesYou2::
	lockall
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, MossdeepCity_Movement_BirchWalksToPlayerR
	waitmovement 0
	msgbox MossdeepCity_Text_BirchYouMadeIt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, MossdeepCity_Movement_BirchWalksToRockR
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWalksToRockR
	waitmovement 0

MossdeepCity_SceneWithBirch_EventScript_Birch::
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	msgbox MossdeepCity_SceneWithBirch_Text_RockExplanation, MSGBOX_DEFAULT
	msgbox MossdeepCity_SceneWithBirch_Text_WhoKnowsWhatMightHappen, MSGBOX_DEFAULT
	msgbox MossdeepCity_SceneWithBirch_Text_MakeAWish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_SceneWithBirch_EventScript_JustTryIt
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SceneWithBirch_EventScript_JirachiAppears
	closemessage
	releaseall
	end

MossdeepCity_SceneWithBirch_EventScript_JustTryIt::
	msgbox MossdeepCity_SceneWithBirch_Text_JustTryIt, MSGBOX_DEFAULT
	msgbox MossdeepCity_SceneWithBirch_Text_MakeAWish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_SceneWithBirch_EventScript_JustTryIt
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SceneWithBirch_EventScript_JirachiAppears
	end

MossdeepCity_SceneWithBirch_EventScript_JirachiAppears::
	closemessage
	hidefollower
	fadescreen FADE_TO_WHITE
	addobject LOCALID_JIRACHI
	special Script_FadeOutMapMusic
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiAppears
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceUp
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox MossdeepCity_Text_Jirachi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiThirdEye
	playmoncry SPECIES_JIRACHI, CRY_MODE_ECHO_START
	waitmoncry
	playmoncry SPECIES_JIRACHI, CRY_MODE_ECHO_END
	waitmovement 0
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 5   @ shake delay
	special ShakeCamera
	delay 20
	applymovement LOCALID_BIRCH, MossdeepCity_Movement_Spinning1
	applymovement LOCALID_GIRL, MossdeepCity_Movement_Spinning2
	delay 80
	fadescreen FADE_TO_WHITE
	delay 120
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJump
	waitmovement 0
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJump
	waitmovement 0
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special Overworld_PlaySpecialMapMusic
	msgbox MossdeepCity_Text_Jirachi, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCH, Common_Movement_FaceUp
	msgbox MossdeepCity_Text_BirchSeesJirachi, MSGBOX_DEFAULT
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJumpsAroundBirch1
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox MossdeepCity_Text_BirchWhatChanges, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCH, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJumpsAroundBirch2
	msgbox MossdeepCity_Text_BirchTouchedTheRegion, MSGBOX_DEFAULT
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJumpsAroundGirl
	msgbox MossdeepCity_Text_GirlSeesJirachi, MSGBOX_DEFAULT
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJumpsBackToCenter
	msgbox MossdeepCity_Text_BirchNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_BIRCH, Common_Movement_FaceUp
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiWantsToFight
	waitmovement 0
	msgbox MossdeepCity_Text_BirchTestBond, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCH, Common_Movement_FaceLeft
	msgbox MossdeepCity_Text_BirchAreYouReady, MSGBOX_DEFAULT
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_JIRACHI
	seteventmon SPECIES_JIRACHI, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_JirachiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_JirachiRunsAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_JirachiRunsAway
	setflag FLAG_BATTLED_JIRACHI
	setflag FLAG_CAUGHT_JIRACHI
	goto MossdeepCity_EventScript_EndJirachiEvent
	end

MossdeepCity_EventScript_JirachiDefeated::
	setflag FLAG_DEFEATED_JIRACHI
	goto MossdeepCity_EventScript_JirachiRunsAway
	end

MossdeepCity_EventScript_JirachiRunsAway::
	setflag FLAG_BATTLED_JIRACHI
	setvar VAR_0x8004, SPECIES_JIRACHI
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	msgbox MossdeepCity_Text_BirchJirachiFled, MSGBOX_DEFAULT
	goto MossdeepCity_EventScript_EndJirachiEvent
	end

MossdeepCity_EventScript_EndJirachiEvent:
	msgbox MossdeepCity_Text_BirchLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, MossdeepCity_Movement_BirchLeaves
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_BIRCH
	removeobject LOCALID_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_GAME_CORNER_PORYGON_PRIZE
	clearflag FLAG_HIDE_HELIX_FOSSIL
	clearflag FLAG_HIDE_DOME_FOSSIL
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	setvar VAR_ROUTE101_WILD_SET, 1
	setvar VAR_ROUTE102_WILD_SET, 1
	setvar VAR_ROUTE103_WILD_SET, 1
	setvar VAR_ROUTE104_WILD_SET, 1
	setvar VAR_ROUTE110_WILD_SET, 1
	setvar VAR_ROUTE111_WILD_SET, 1
	setvar VAR_ROUTE112_WILD_SET, 1
	setvar VAR_ROUTE114_WILD_SET, 1
	setvar VAR_ROUTE116_WILD_SET, 1
	setvar VAR_ROUTE117_WILD_SET, 1
	setvar VAR_PETALBURG_WOODS_WILD_SET, 1
	setvar VAR_RUSTURF_TUNNEL_WILD_SET, 1
	setvar VAR_GRANITE_CAVE_1F_WILD_SET, 1
	setvar VAR_GRANITE_CAVE_B1F_WILD_SET, 1
	setvar VAR_VICTORY_ROAD_1F_WILD_SET, 1
	setvar VAR_FIERY_PATH_WILD_SET, 1
	setvar VAR_JAGGED_PASS_WILD_SET, 1
	setvar VAR_MAGMA_HIDEOUT_WILD_SET, 1
	setvar VAR_ROUTE107_WILD_SET, 1
	setvar VAR_ROUTE115_WILD_SET, 1
	setvar VAR_NEW_MAUVILLE_INSIDE_WILD_SET, 1
	setvar VAR_ROUTE119_WILD_SET, 1
	setvar VAR_ROUTE120_WILD_SET, 1
	setvar VAR_ROUTE121_WILD_SET, 1
	setvar VAR_ROUTE122_WILD_SET, 1
	setvar VAR_ROUTE123_WILD_SET, 1
	setvar VAR_MT_PYRE_2F_WILD_SET, 1
	setvar VAR_MT_PYRE_3F_WILD_SET, 1
	setvar VAR_MT_PYRE_4F_WILD_SET, 1
	setvar VAR_MT_PYRE_5F_WILD_SET, 1
	setvar VAR_MT_PYRE_EXTERIOR_WILD_SET, 1
	setvar VAR_ROUTE131_WILD_SET, 1
	setvar VAR_ROUTE133_WILD_SET, 1
	setvar VAR_VICTORY_ROAD_B1F_WILD_SET, 1
	setvar VAR_VICTORY_ROAD_B2F_WILD_SET, 1
	setvar VAR_METEOR_FALLS_1F_1R_WILD_SET, 1
	setvar VAR_SLATEPORT_CITY_WILD_SET, 1
	setvar VAR_MOSSDEEP_CITY_WILD_SET, 1
	setvar VAR_PETALBURG_CITY_WILD_SET, 1
	setvar VAR_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_WILD_SET, 1
	setvar VAR_SOOTOPOLIS_CITY_WILD_SET, 1
	setvar VAR_ARTISAN_CAVE_B1F_WILD_SET, 1
	setvar VAR_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_WILD_SET, 1
	releaseall
	end

MossdeepCity_EventScript_RematchJirachiAppears::
	fadescreen FADE_TO_WHITE
	addobject LOCALID_JIRACHI
	special Script_FadeOutMapMusic
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiAppears
	waitmovement 0
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 20
	fadescreen FADE_TO_WHITE
	delay 20
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJump
	waitmovement 0
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiJump
	waitmovement 0
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox MossdeepCity_Text_Jirachi, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_JIRACHI, MossdeepCity_Movement_JirachiWantsToFight
	waitmovement 0
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_JIRACHI
	seteventmon SPECIES_JIRACHI, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_RematchJirachiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_RematchJirachiRunsAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_RematchJirachiRunsAway
	setflag FLAG_BATTLED_JIRACHI
	setflag FLAG_CAUGHT_JIRACHI
	releaseall
	end

MossdeepCity_EventScript_RematchJirachiDefeated::
	setflag FLAG_BATTLED_JIRACHI
	setflag FLAG_DEFEATED_JIRACHI
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

MossdeepCity_EventScript_RematchJirachiRunsAway::
	setflag FLAG_BATTLED_JIRACHI
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

MossdeepCity_Movement_BirchWalksToPlayerL:
	walk_down
	walk_down
	walk_down
	step_end

MossdeepCity_Movement_BirchWalksToPlayerR:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

MossdeepCity_Movement_PlayerWalksToRockL:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_Movement_PlayerWalksToRockR:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

MossdeepCity_Movement_BirchWalksToRockL:
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

MossdeepCity_Movement_BirchWalksToRockR:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

MossdeepCity_Movement_Spinning1:
	face_down
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_right
	delay_16
	face_left
	step_end

MossdeepCity_Movement_Spinning2:
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_right
	step_end

MossdeepCity_Movement_JirachiAppears:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	jump_special_in_place_down
	delay_4
	levitate
	step_end

MossdeepCity_Movement_JirachiThirdEye:
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_up
	step_end

MossdeepCity_Movement_JirachiJump:
	jump_special_in_place_right_left
	jump_special_in_place_left_right
	jump_special_in_place_down
	step_end

MossdeepCity_Movement_JirachiJumpsAroundBirch1:
	walk_fast_right
	walk_down
	jump_special_in_place_down_up
	jump_special_in_place_down_up
	walk_right
	walk_down
	face_left
	step_end

MossdeepCity_Movement_JirachiJumpsAroundBirch2:
	jump_special_in_place_left_right
	jump_special_in_place_left_right
	jump_special_down
	walk_left
	jump_special_in_place_up_down
	jump_special_in_place_up_down
	step_end

MossdeepCity_Movement_JirachiJumpsAroundGirl:
	walk_left
	walk_left
	walk_up
	jump_special_in_place_up_down
	jump_special_in_place_up_down
	walk_left
	walk_up
	jump_special_in_place_right_left
	jump_special_in_place_right_left
	step_end

MossdeepCity_Movement_JirachiJumpsBackToCenter:
	walk_up
	walk_right
	walk_right
	jump_special_in_place_Down_Up
	jump_special_in_place_Down_Up
	jump_special_in_place_down
	step_end

MossdeepCity_Movement_JirachiWantsToFight:
	jump_special_in_place_Down_Up
	jump_special_in_place_Down_Up
	jump_special_in_place_Down_Up
	jump_special_down
	step_end

MossdeepCity_Movement_BirchLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "I got this from STEVEN, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called KING'S ROCK.\n"
	.string "Do you want it?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "STEVEN's house is right over there!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"

MossdeepCity_Text_WailmerWatching:
	.string "Around MOSSDEEP, you can see wild\n"
	.string "WAILMER.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "I heard from a SAILOR buddy that\n"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that TEAM MAGMA.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "I'm a SAILOR, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"

MossdeepCity_Text_SurfExhilarating:
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with POKéMON\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "This rock has a special meaning to\n"
	.string "the people at the SPACE CENTER.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"

MossdeepCity_Text_SpecialSpaceCenterRockAfterEvent:
	.string "Did you see that?\n"
	.string "JIRACHI appeared right here!\p"
	.string "The people at the SPACE CENTER always\n"
	.string "believed this rock held a special\l"
	.string "meaning, and now I know why.\p"
	.string "It means our rockets are going to fly…\n"
	.string "We'll really reach the stars!$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "It's a white rock.$"

MossdeepCity_Text_BirchYouMadeIt:
	.string "PROF. BIRCH: Ah, {PLAYER}{KUN}!\n"
	.string "I'm glad you could make it!$"

MossdeepCity_SceneWithBirch_Text_RockExplanation:
	.string "This is the rock I mentioned.\p"

	.string "This rock holds a special meaning to\n"
	.string "the people here in MOSSDEEP.\p"

	.string "They say it's a symbol of their wish for\n"
	.string "their rockets to fly through the stars.\l"
	.string "Quite poetic, isn't it?\p"

	.string "That got me thinking… what if this rock\n"
	.string "is more than just a symbol?\p"

	.string "I’ve done some research, and there are\n"
	.string "ancient legends that speak of a rare\l"
	.string "POKéMON that can grant wishes.\p"

	.string "Some believe it sleeps within a star,\n"
	.string "awakening only once every thousand\l"
	.string "years.\p"

	.string "I believe this rock might be connected\n"
	.string "to that POKéMON. But, what truly lies\l"
	.string "within… We may never know.$"

MossdeepCity_SceneWithBirch_Text_WhoKnowsWhatMightHappen:
	.string "Try making a wish upon this rock.\n"
	.string "Who knows what might happen?$"

MossdeepCity_SceneWithBirch_Text_MakeAWish:
	.string "Make a wish?$"

MossdeepCity_SceneWithBirch_Text_JustTryIt:
	.string "Oh, come on, {PLAYER}{KUN}! What’s the\n"
	.string "harm in trying?\p"
	.string "Even the greatest discoveries start\n"
	.string "with a small step. Just give it a shot!$"

MossdeepCity_Text_Jirachi:
	.string "JIRACHI!$"

MossdeepCity_Text_BirchSeesJirachi:
	.string "PROF. BIRCH: Incredible… Could it be…?\n"
	.string "JIRACHI… did you really hear our\l"
	.string " wishes?$"

MossdeepCity_Text_BirchWhatChanges:
	.string "This must be the POKéMON connected to\n"
	.string "the rock's legends. But more than that…\l"
	.string "I sense something different in the air.$"

MossdeepCity_Text_BirchTouchedTheRegion:
	.string "Could it be… your wish has touched the\n"
	.string "entire region? I wonder what changes\l"
	.string "might be happening now…$"

MossdeepCity_Text_GirlSeesJirachi:
	.string "GIRL: Does this mean… we really will fly\n"
	.string "through the stars?\p"
	.string "To think our dreams could actually\n"
	.string "come true…$"

MossdeepCity_Text_BirchNewDiscoveries:
	.string "PROF. BIRCH: Your wish to befriend all\n"
	.string "kinds of POKéMON… It feels like JIRACHI\l"
	.string "has made that possible, {PLAYER}{KUN}.\p"
	.string "Who knows what new discoveries await\n"
	.string "you now?$"

MossdeepCity_Text_BirchTestBond:
	.string "It looks like JIRACHI wants to test\n"
	.string "your bond.$"

MossdeepCity_Text_BirchAreYouReady:
	.string "Are you ready? This may be your only\n"
	.string "chance!$"

MossdeepCity_Text_BirchJirachiFled:
	.string "PROF. BIRCH: Oh… It seems JIRACHI has\n"
	.string "disappeared.\p"
	.string "But don't be disheartened, {PLAYER}{KUN}.\n"
	.string "Perhaps JIRACHI will return to test\l"
	.string "your bond again in the future!$"

MossdeepCity_Text_BirchLeaves:
	.string "PROF. BIRCH: What an extraordinary\n"
	.string "event, {PLAYER}{KUN}.\p"
	.string "To think we’ve just witnessed the\n"
	.string "legendary JIRACHI…\p"
	.string "The legends, the wishes… They all feel\n"
	.string "more real now, don’t they?\p"
	.string "More than anything, it feels like a\n"
	.string "reminder of how vast and mysterious\l"
	.string "our universe is.\p"
	.string "Well, I must return to my research.\n"
	.string "There's much to document and so many\l"
	.string "new questions to explore.\p"
	.string "Thank you, {PLAYER}{KUN}, for\n"
	.string "everything. I'm sure we'll cross paths\l"
	.string "again soon.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“The mystic combination!”$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city SOOTOPOLIS?\p"
	.string "I think the GYM there is\n"
	.string "quite strong.\p"
	.string "People tell me he was mentored\n"
	.string "by a trainer named JUAN.$"

