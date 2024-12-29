.set LOCALID_EXPERT, 1
.set LOCALID_WOMAN_2, 2
.set LOCALID_KIRI, 3
.set LOCALID_NINJA_BOY, 4
.set LOCALID_BOY_1, 5
.set LOCALID_STEVEN, 7
.set LOCALID_WOMAN_1, 8
.set LOCALID_GROUDON, 9
.set LOCALID_KYOGRE, 10
.set LOCALID_RAYQUAZA, 11
.set LOCALID_MANIAC, 12
.set LOCALID_GIRL, 13
.set LOCALID_BLACK_BELT, 14
.set LOCALID_BOY_2, 15
.set LOCALID_MAXIE, 16
.set LOCALID_ARCHIE, 17
.set LOCALID_WALLACE, 18
.set LOCALID_MAY, 19
.set LOCALID_BRENDAN, 20

SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
	.byte 0

SootopolisCity_OnLoad:
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
	end

SootopolisCity_EventScript_LegendariesNotArrived::
	end

SootopolisCity_EventScript_LockHouseDoors::
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
	return

SootopolisCity_EventScript_LockGymDoor::
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
	return

SootopolisCity_OnTransition:
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_BRENDAN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
	call SootopolisCity_EventScript_SetWeather
	call SootopolisCity_EventScript_SetLayout
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 7, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 7, SootopolisCity_EventScript_ShowRival
	call_if_set FLAG_OPEN_CAVE_OF_ORIGIN, SootopolisCity_EventScript_OpenCaveOfOrigin
	end

SootopolisCity_EventScript_ShowRival::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, SootopolisCity_EventScript_ShowBrendan
	goto_if_eq VAR_RESULT, MALE, SootopolisCity_EventScript_ShowMay
	return
SootopolisCity_EventScript_ShowMay::
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAY
	return
SootopolisCity_EventScript_ShowBrendan::
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_BRENDAN
	return

SootopolisCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_SetBattleSpectators::
	setobjectxyperm LOCALID_KIRI, 13, 48
	setobjectxyperm LOCALID_BOY_1, 46, 32
	setobjectxyperm LOCALID_NINJA_BOY, 48, 41
	setobjectxyperm LOCALID_WOMAN_1, 45, 43
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_BOY_1, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_SetLayout::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
	return

SootopolisCity_EventScript_SetNormalLayout::
	return

SootopolisCity_EventScript_SetLegendariesLayout::
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_SetWeather::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
	return

SootopolisCity_EventScript_SetNormalWeather::
	return

SootopolisCity_EventScript_SetDownpour::
	setweather WEATHER_DOWNPOUR
	return

SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
	return

SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
	setobjectxyperm LOCALID_EXPERT, 30, 18
	setobjectxyperm LOCALID_STEVEN, 32, 18
	return

SootopolisCity_EventScript_OpenCaveOfOrigin::
	setflag FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE
	setobjectxyperm LOCALID_EXPERT, 30, 18
	return

SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
	setobjectxyperm LOCALID_EXPERT, 30, 18
	setobjectxyperm LOCALID_WALLACE, 31, 18
	setobjectxyperm LOCALID_STEVEN, 32, 18
	end

SootopolisCity_EventScript_SetOutsideGymObjPos::
	setobjectxyperm LOCALID_EXPERT, 31, 18
	setobjectxyperm LOCALID_STEVEN, 29, 33
	setobjectxyperm LOCALID_MAXIE, 33, 35
	setobjectxyperm LOCALID_ARCHIE, 34, 35
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
	return

SootopolisCity_EventScript_SetWallaceMiddle::
	setobjectxyperm LOCALID_WALLACE, 31, 33
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceRight::
	setobjectxyperm LOCALID_WALLACE, 32, 33
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceLeft::
	setobjectxyperm LOCALID_WALLACE, 30, 33
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
	setobjectxyperm LOCALID_EXPERT, 31, 18
	return

SootopolisCity_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
	.2byte 0

SootopolisCity_EventScript_PlayerFaceLegendaries::
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
	end

SootopolisCity_EventScript_PlayerFaceLegendaries1::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

SootopolisCity_EventScript_PlayerFaceLegendaries2::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_SKY_PILLAR_STATE, 3
	return

SootopolisCity_OnResume:
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
	end

SootopolisCity_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 7, SootopolisCity_EventScript_RivalProfessor
	.2byte 0

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartLegendariesScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
	end

SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	waitstate
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromPokeCenter:
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_PanBackToPokeCenter:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_LegendariesSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	waitstate
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToDive
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromDive:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PanBackToDive:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_KyogreAttack:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreMoveBack:
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_KyogreIdle:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_GroudonAttack:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonMoveBack:
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_GroudonIdle:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartRayquazaScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
	end

SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_GROUDON
	removeobject LOCALID_KYOGRE
	addobject LOCALID_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate
	playse SE_THUNDER
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SOOTOPOLIS
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
	waitstate
	end

SootopolisCity_EventScript_RayquazaSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_GROUDON
	removeobject LOCALID_KYOGRE
	addobject LOCALID_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SURF
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
	waitstate
	end

SootopolisCity_EventScript_SetRoughWater::
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
	return

SootopolisCity_Movement_RayquazaFlyOff:
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

SootopolisCity_Movement_PanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerApproachLegendaries:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Unused
SootopolisCity_Movement_PlayerApproachLegendariesDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanUp:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanBack:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_EventScript_CaveOfOriginExpert::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLeadToCave::
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertPostLegendaries::
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLegendaries::
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_KiriRayquaza::
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
SootopolisCity_EventScript_KiriGiveBerry::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random 5
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
	goto_if_eq VAR_RESULT, 2, SootopolisCity_EventScript_GiveWikiBerry
	goto_if_eq VAR_RESULT, 3, SootopolisCity_EventScript_GiveMagoBerry
	goto_if_eq VAR_RESULT, 4, SootopolisCity_EventScript_GiveAguavBerry
	end

SootopolisCity_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveWikiBerry::
	giveitem ITEM_WIKI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveMagoBerry::
	giveitem ITEM_MAGO_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveAguavBerry::
	giveitem ITEM_AGUAV_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman2::
	lockall
	applymovement LOCALID_WOMAN_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WOMAN_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Woman2Rayquaza::
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Man::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ManPostLegendaries::
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Legendaries::
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Woman1PostLegendaries::
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Rayquaza::
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_NINJA_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_NinjaBoyNormal::
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoyRayquaza::
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOY_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1Rayquaza::
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1GameClear::
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1Normal::
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign::
	goto_if_set FLAG_IS_CHAMPION, SootopolisCity_EventScript_GymSignPostGame
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end
SootopolisCity_EventScript_GymSignPostGame::
	msgbox SootopolisCity_Text_GymSignPostGame, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor::
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
	end

SootopolisCity_EventScript_Steven::
	lockall
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpWallace::
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenMaxieArchieLeft::
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpedWallace::
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
	waitmovement 0
	delay 120
	applymovement LOCALID_EXPERT, SootopolisCity_Movement_ExpertMoveAside
	waitmovement 0
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
	waitmovement 0
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
	waitstate
	end

SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
	waitmovement 0
	return

SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
	waitmovement 0
	return

SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_ExpertMoveAside:
	walk_slow_left
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_StevenArriveCaveEntrance:
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_Movement_PlayerArriveCaveEntrance:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
	walk_up
	walk_up
	step_end

SootopolisCity_EventScript_Boy2::
	lockall
	applymovement LOCALID_BOY_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOY_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Boy2Rayquaza::
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_BlackBelt::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_BlackBeltRayquaza::
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Girl::
	lockall
	applymovement LOCALID_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_GirlRayquaza::
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_Maniac::
	lockall
	applymovement LOCALID_MANIAC, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MANIAC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_ManiacRayquaza::
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Wallace::
	lock
	faceplayer
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveWaterfall::
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
	setflag FLAG_RECEIVED_HM_WATERFALL
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
	closemessage
	opendoor 31, 32
	waitdooranim
	applymovement LOCALID_WALLACE, SootopolisCity_MovementWallaceMoveInsideGym
	waitmovement 0
	removeobject LOCALID_WALLACE
	closedoor 31, 32
	waitdooranim
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	release
	end

SootopolisCity_EventScript_GoToSkyPillar::
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GoToGym::
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MovementWallaceMoveInsideGym:
	walk_up
	step_end

SootopolisCity_EventScript_Maxie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_MaxieRayquaza::
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_Archie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_ArchieRayquaza::
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_MaxieArchieLeave::
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
	waitstate
	releaseall
	end

SootopolisCity_EventScript_RivalProfessor::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SootopolisCity_EventScript_MayProfessor
	goto_if_eq VAR_RESULT, FEMALE, SootopolisCity_EventScript_BrendanProfessor
	end

SootopolisCity_EventScript_MayProfessor::
	playse SE_PIN
	applymovement LOCALID_MAY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_FaceUp
	delay 80
	waitmovement 0
	msgbox SootopolisCity_Text_MayBecomingProfessor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, SootopolisCity_Movement_RivalMovement1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_RivalPlayerMovement1
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, SootopolisCity_Movement_RivalMovement2
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, Common_Movement_FaceDown
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, Common_Movement_FaceRight
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor5, MSGBOX_DEFAULT
	closemessage
	goto SootopolisCity_EventScript_RivalProfessorEnd

SootopolisCity_EventScript_BrendanProfessor::
	playse SE_PIN
	applymovement LOCALID_BRENDAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_FaceUp
	waitmovement 0
	msgbox SootopolisCity_Text_BrendanBecomingProfessor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, SootopolisCity_Movement_RivalMovement1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_RivalPlayerMovement1
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, SootopolisCity_Movement_RivalMovement2
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor3, MSGBOX_DEFAULT
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor4, MSGBOX_DEFAULT
	applymovement LOCALID_BRENDAN, Common_Movement_FaceRight
	waitmovement 0
	msgbox SootopolisCity_Text_RivalBecomingProfessor5, MSGBOX_DEFAULT
	closemessage
	goto SootopolisCity_EventScript_RivalProfessorEnd

SootopolisCity_EventScript_RivalProfessorEnd::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BRENDAN
	removeobject LOCALID_MAY
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_BRENDAN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAY
	setflag FLAG_SOOTOPOLIS_CITY_RIVAL_PROFESSOR
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	setflag FLAG_ENABLE_NORMAN_REMATCH_CALL
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	setvar VAR_NORMAN_REMATCH_CALL_STEP_COUNTER, 0
	fadescreen FADE_FROM_BLACK
	releaseall
	end

SootopolisCity_Movement_RivalMovement1:
	walk_left
	walk_left
	step_end

SootopolisCity_Movement_RivalPlayerMovement1:
	walk_down
	face_left
	step_end

SootopolisCity_Movement_RivalMovement2:
	walk_right
	step_end

@ Unused
SootopolisCity_Movement_Levitate::
	levitate
	step_end

@ Unused
SootopolisCity_Movement_DestroyTask::
	destroy_extra_task
	step_end

SootopolisCity_Text_GymSign:
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: WALLACE\p"
	.string "“Artist, and lover of WATER.”$"

SootopolisCity_Text_GymSignPostGame:
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: JUAN\p"
	.string "“The GYM LEADER with the beauty\n"
	.string "of pure water!”$"

SootopolisCity_Text_CitySign:
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"

SootopolisCity_Text_DoorIsClosed:
	.string "The door is closed.$"

SootopolisCity_Text_PhysicallyFitLivingHere:
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"

SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
	.string "These giant POKéMON suddenly appeared\n"
	.string "in the middle of the city!\p"
	.string "And, I've never seen them before!\p"
	.string "Why are they smashing into each\n"
	.string "other like that?\p"
	.string "Why can't they be friends, those\n"
	.string "POKéMON?$"

SootopolisCity_Text_WhatIsThatGreenPokemon:
	.string "What? What? What?\n"
	.string "What is that green POKéMON?!$"

SootopolisCity_Text_WhereDidLegendariesGo:
	.string "GROUDON and KYOGRE…\n"
	.string "Where did they go?\p"
	.string "Will they cause droughts or downpours\n"
	.string "somewhere else?$"

SootopolisCity_Text_TwoPokemonArentAngry:
	.string "I just get this sense somehow that\n"
	.string "the two POKéMON aren't angry.\p"
	.string "I think… They probably can't control\n"
	.string "their own power…$"

SootopolisCity_Text_FlyingMonStoppedRampage:
	.string "That flying POKéMON came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "POKéMON…$"

SootopolisCity_Text_WonderWhatWorldIsLike:
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"

SootopolisCity_Text_ThisIsWicked:
	.string "Wow!\n"
	.string "This is wicked!$"

SootopolisCity_Text_ThatWasWicked:
	.string "Wow!\n"
	.string "That was wicked!$"

SootopolisCity_Text_GoRedAndBlueMon:
	.string "Go for it, red POKéMON!\n"
	.string "Don't back off, blue POKéMON!$"

SootopolisCity_Text_DoYouKnowMonNames:
	.string "… … … … … …\p"
	.string "Hi, do you know the names of those\n"
	.string "POKéMON fighting over there?$"

SootopolisCity_Text_GreenOneSettlesThings:
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "it's the green one that settles things!\p"
	.string "Talk about a huge turn of events!$"

SootopolisCity_Text_SeeingLegendWithOwnEyes:
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I'm seeing that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_SawLegendWithOwnEyes:
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I saw that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_BigPokemonFighting:
	.string "A big POKéMON is fighting with\n"
	.string "another big POKéMON!\p"
	.string "Please, someone make them stop!$"

SootopolisCity_Text_PrettyMonCameFromSky:
	.string "A pretty POKéMON came down from\n"
	.string "the sky…$"

SootopolisCity_Text_SootopolisWillBeWrecked:
	.string "Oh, no!\n"
	.string "SOOTOPOLIS CITY will get wrecked!$"

SootopolisCity_Text_SootopolisDidntGetWrecked:
	.string "SOOTOPOLIS CITY didn't get wrecked!$"

SootopolisCity_Text_NoOrdinaryTourist:
	.string "Hm!\n"
	.string "You've come all the way to SOOTOPOLIS?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"

SootopolisCity_Text_CityRegainedCalm:
	.string "The city has regained its calm…$"

SootopolisCity_Text_CaveOfOriginPleaseLeave:
	.string "Who might you be?\p"
	.string "This is the CAVE OF ORIGIN.\p"
	.string "The spirits of POKéMON, becalmed at\n"
	.string "MT. PYRE, are said to be revived here.\p"
	.string "Please leave.$"

SootopolisCity_Text_LeadSuperiorTrainerToCave:
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A TRAINER who has knowledge and\n"
	.string "experience of many kinds of POKéMON…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by WALLACE to lead that\l"
	.string "TRAINER to this CAVE.$"

SootopolisCity_Text_AwakenedPokemonClash:
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "POKéMON was quelled by the awakening\l"
	.string "of a third POKéMON…$"

SootopolisCity_Text_CaveOfOriginSleepsToo:
	.string "This is the CAVE OF ORIGIN…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"

SootopolisCity_Text_SootopolisSkyBeautiful:
	.string "SOOTOPOLIS sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "SOOTOPOLIS the most beautiful.$"

SootopolisCity_Text_GiganticPokemonFight:
	.string "When two POKéMON that gigantic\n"
	.string "are fighting that savagely, there's\l"
	.string "not much that we can do.$"

SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
	.string "When that third POKéMON flew down,\n"
	.string "I feared the worst.$"

SootopolisCity_Text_NightSkyFavoriteScenery:
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"

SootopolisCity_Text_WeatherWentWild:
	.string "The weather was clear this morning,\n"
	.string "but…\p"
	.string "All of a sudden, dark clouds brewed up,\n"
	.string "rain started falling in sheets, and\l"
	.string "there was thunder and lightning, too.\p"
	.string "The weather just went completely\n"
	.string "wild!\p"
	.string "Is all of this because of those\n"
	.string "POKéMON?$"

SootopolisCity_Text_YouBroughtFlyingMon:
	.string "Oh?\p"
	.string "It was you who brought that flying\n"
	.string "POKéMON here?\p"
	.string "Well, aren't you amazing!$"

SootopolisCity_Text_GroudonPleaseStop:
	.string "MAXIE: G… GROUDON…\n"
	.string "Please! Stop what you're doing!\p"
	.string "I know the extent of your power now!\p"
	.string "If you continue, all of HOENN, not just\n"
	.string "SOOTOPOLIS, will be consumed by ruin!\p"
	.string "This wasn't what I sought… not like\n"
	.string "this.$"

SootopolisCity_Text_AfterAllOurScheming:
	.string "MAXIE: So, it wasn't only GROUDON and\n"
	.string "KYOGRE…\p"
	.string "After all our efforts,\n"
	.string "all our grand designs…\p"
	.string "A single action from one POKéMON \n"
	.string "restores everything…\p"
	.string "As if none of it had ever mattered…\p"
	.string "Fu…\n"
	.string "Fuhahaha…\p"
	.string "Perhaps we were never meant to control\n"
	.string "such forces.\p"
	.string "Perhaps… balance was always the key.$"

SootopolisCity_Text_KyogreCalmDown:
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
	.string "Look over here! It's the BLUE ORB!\l"
	.string "Calm down! KYOGRE!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "It's no good!\n"
	.string "It doesn't respond…\p"
	.string "Have I truly lost control?$"

SootopolisCity_Text_TryingMeaninglessToPokemon:
	.string "ARCHIE: KYOGRE and GROUDON have\n"
	.string "disappeared…\p"
	.string "And the weather in HOENN has returned\n"
	.string "to normal.\p"
	.string "Haha…\n"
	.string "Hahaha…\p"
	.string "Maybe what we were trying to do,\n"
	.string "to force nature's hand, was something\l"
	.string "small, something meaningless in the\l"
	.string "grand scheme.\p"
	.string "Nature doesn't bend to our will.\n"
	.string "Perhaps… it thrives in balance.$"

SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
	.string "STEVEN: Those POKéMON fighting…\n"
	.string "GROUDON… And KYOGRE…\p"
	.string "The two super-ancient titans,\n"
	.string "awoken from their long slumber…\p"
	.string "Now their power rages out of control,\n"
	.string "threatening to tear the land and sea\l"
	.string "apart.\p"
	.string "…{PLAYER}{KUN}.\p"
	.string "Your presence here means you're ready\n"
	.string "to face this disaster head-on.\p"
	.string "There's someone you need to meet.\n"
	.string "Come with me, please.$"

SootopolisCity_Text_DoesThisMakeYourFearPokemon:
	.string "STEVEN: {PLAYER}{KUN}, tell me…\p"
	.string "Seeing GROUDON and KYOGRE like this,\n"
	.string "does it make you fear POKéMON?\p"
	.string "You know better, don't you?\n"
	.string "POKéMON are more than just power.\p"
	.string "…Why am I asking you this?\n"
	.string "You already know.$"

SootopolisCity_Text_HereWereAreHelpWallace:
	.string "STEVEN: This is the CAVE OF ORIGIN.\p"
	.string "Inside, you'll find WALLACE,\n"
	.string "the GYM LEADER of SOOTOPOLIS CITY.\p"
	.string "He's been studying the ancient\n"
	.string "carvings and legends here.\p"
	.string "I believe he may have found a way\n"
	.string "to help us all.$"

SootopolisCity_Text_KnowWhatsNeededToHelpHim:
	.string "{PLAYER}{KUN}, I'm counting on you\n"
	.string "to assist him.$"

SootopolisCity_Text_NeverBeenToSkyPillar:
	.string "STEVEN: So, WALLACE believes the\n"
	.string "DRAGON LORD can help us…\p"
	.string "The SKY PILLAR…\n"
	.string "I've heard of it, though I've\l"
	.string "never ventured there myself.\p"
	.string "I must stay here in SOOTOPOLIS\n"
	.string "to ensure the safety of the people.\p"
	.string "{PLAYER}{KUN}, I have faith in you\n"
	.string "and WALLACE.$"

SootopolisCity_Text_SoThatsRayquaza:
	.string "STEVEN: So that's RAYQUAZA…\p"
	.string "It's incredible how the two rampaging\n"
	.string "POKéMON would flee from it in fear…$"

SootopolisCity_Text_MaxieArchieLeft:
	.string "STEVEN: It looks like both MAXIE and\n"
	.string "ARCHIE have gone away somewhere.\p"
	.string "Perhaps they've gone to MT. PYRE to\n"
	.string "return those ORBS…$"

SootopolisCity_Text_HaventYouScaledSkyPillar:
	.string "WALLACE: Oh?\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Haven't you scaled the SKY PILLAR\n"
	.string "yet?\p"
	.string "I'm sure that you can make it to\n"
	.string "the top of the SKY PILLAR…$"

SootopolisCity_Text_AquaMagmaDidntMeanHarm:
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
	.string "I don't think they meant harm.\p"
	.string "It wouldn't hurt to hear what they\n"
	.string "have to say for themselves.$"

SootopolisCity_Text_ThankYouForHelpAcceptThis:
	.string "WALLACE: {PLAYER}{KUN}…\n"
	.string "My eyes didn't deceive me.\p"
	.string "Thanks to your help, SOOTOPOLIS…\n"
	.string "No, all of HOENN was saved.\p"
	.string "On behalf of the people, I thank you.\p"
	.string "This is a gift from me.\n"
	.string "Please accept it.$"

SootopolisCity_Text_ExplainWaterfallGoToGym:
	.string "That HIDDEN MACHINE contains\n"
	.string "WATERFALL.\p"
	.string "If you have the RAIN BADGE, a POKéMON\n"
	.string "that can learn that HM move can\l"
	.string "force its way up waterfalls.\p"
	.string "The POKéMON just needs to be with you.\n"
	.string "They don't even need to learn the move!\p"
	.string "And where does one get the RAIN BADGE?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the SOOTOPOLIS GYM LEADER…\l"
	.string "Me!\p"
	.string "When you're ready, please come\n"
	.string "to the GYM.\p"
	.string "I shall await your arrival.\p"
	.string "Prepare yourself for a truly\n"
	.string "elegant battle.$"

SootopolisCity_Text_DazzledByMentor:
	.string "WALLACE: I trust you will be\n"
	.string "dazzled by my breathtakingly\l"
	.string "elegant battle style.$"

SootopolisCity_Text_MayBecomingProfessor:
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "There you are!\p"
	.string "I heard about what happened with\n"
	.string "GROUDON and KYOGRE! I was so worried!\p"
	.string "But… you look totally fine!\n"
	.string "Actually, you look even stronger!\p"
	.string "Wait, is that the RAIN BADGE?\n"
	.string "You already defeated WALLACE?!\p"
	.string "Wow, {PLAYER}{KUN}, you never cease\n"
	.string "to amaze me!$"

SootopolisCity_Text_BrendanBecomingProfessor:
	.string "BRENDAN: {PLAYER}{KUN}!\n"
	.string "There you are!\p"
	.string "I heard about what happened with\n"
	.string "GROUDON and KYOGRE! I was so worried!\p"
	.string "But… you look totally fine!\n"
	.string "Actually, you look even stronger!\p"
	.string "Wait, is that the RAIN BADGE?\n"
	.string "You already defeated WALLACE?!\p"
	.string "Wow, {PLAYER}{KUN}, you never cease\n"
	.string "to amaze me!$"

SootopolisCity_Text_RivalBecomingProfessor2:
	.string "You know, seeing you grow so much\n"
	.string "as a TRAINER made me think…\p"
	.string "I don't have the same talent and drive\n"
	.string "for battling that you do.\p"
	.string "And that's okay!\n"
	.string "We all have our own strengths.\p"
	.string "I realized my dream isn't about\n"
	.string "becoming the strongest TRAINER.$"

SootopolisCity_Text_RivalBecomingProfessor3:
	.string "I want to become friends with POKéMON\n"
	.string "all over the world, just like I said\l"
	.string "when we first met.\p"
	.string "So I've decided… I'm going to become\n"
	.string "a POKéMON PROFESSOR.\l"
	.string "Like my DAD!$"

SootopolisCity_Text_RivalBecomingProfessor4:
	.string "There's so much to learn about POKéMON,\n"
	.string "and I want to help others understand\l"
	.string "them better.$"

SootopolisCity_Text_RivalBecomingProfessor5:
	.string "But don't think I'm giving up on\n"
	.string "battling entirely!\l"
	.string "I'll still keep training my POKéMON.\p"
	.string "Anyway, I just wanted to let you know.\n"
	.string "I'll be cheering you on as you take on\l"
	.string "the POKéMON LEAGUE!\p"
	.string "I know you'll be just fine.\n"
	.string "You've got what it takes to become the\l"
	.string "CHAMPION!\p"
	.string "Well, I should get going.\n"
	.string "There's so much to learn!\p"
	.string "Let's meet again sometime!\p"
	.string "Maybe next time, I'll have some new\n"
	.string "discoveries to share with you!\p"
	.string "Good luck with everything,\n"
	.string "{PLAYER}{KUN}!$"
