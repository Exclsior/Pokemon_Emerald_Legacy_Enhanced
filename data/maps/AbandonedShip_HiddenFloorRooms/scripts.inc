.set LOCALID_SUICUNE, 5

AbandonedShip_HiddenFloorRooms_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_HiddenFloorRooms_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorRooms_OnResume
	.byte 0

AbandonedShip_HiddenFloorRooms_OnFrame:
	map_script_2 VAR_TEMP_1, 0, AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle
	.2byte 0

AbandonedShip_HiddenFloorRooms_OnTransition:
	call_if_unset FLAG_CAUGHT_SUICUNE, AbandonedShip_HiddenFloorRooms_EventScript_TryShowSuicune
	call_if_set FLAG_CAUGHT_SUICUNE, AbandonedShip_HiddenFloorRooms_EventScript_HideSuicune
	call_if_unset FLAG_STARTED_FINAL_PURITY_READING, AbandonedShip_HiddenFloorRooms_EventScript_HideSuicune
	end

AbandonedShip_HiddenFloorRooms_EventScript_HideSuicune::
	setflag FLAG_HIDE_SUICUNE
	return

AbandonedShip_HiddenFloorRooms_EventScript_TryShowSuicune::
	goto_if_set FLAG_DEFEATED_SUICUNE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SUICUNE
	return

AbandonedShip_HiddenFloorRooms_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AbandonedShip_HiddenFloorRooms_EventScript_TryRemoveSuicune
	setdivewarp MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, 0, 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SUICUNE
	return

@ After the below calculation, VAR_TEMP_4 is the room number of the door the player entered
@ Bottom row, left column   (Rm 1)
@ Bottom row, middle column (Rm 2)
@ Bottom row, right column	(Rm 3)
@ Upper row,  left column   (Rm 4)
@ Upper row,  middle column (Rm 5)
@ Upper row,  right column  (Rm 6)
AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle::
	setvar VAR_TEMP_1, 1
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	setvar VAR_TEMP_4, 1
	call_if_eq VAR_TEMP_2, 21, AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn
	call_if_eq VAR_TEMP_2, 36, AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn
	call_if_eq VAR_TEMP_3, 2, AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow
	switch VAR_TEMP_4
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6
	end

AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn::
	addvar VAR_TEMP_4, 1
	return

AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn::
	addvar VAR_TEMP_4, 2
	return

AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow::
	addvar VAR_TEMP_4, 3
	return

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1::
	delay 20
	dofieldeffectsparkle 10, 10, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom4Key
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2::
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3::
	specialvar VAR_RESULT, FoundAbandonedShipRoom1Key
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle
	delay 20
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle::
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4::
	delay 20
	dofieldeffectsparkle 8, 5, 0
	dofieldeffectsparkle 11, 3, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom6Key
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5::
	delay 20
	dofieldeffectsparkle 16, 3, 0
	dofieldeffectsparkle 25, 2, 0
	dofieldeffectsparkle 24, 6, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom2Key
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6::
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle::
	dofieldeffectsparkle 42, 10, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle::
	dofieldeffectsparkle 20, 5, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle::
	dofieldeffectsparkle 1, 12, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle::
	dofieldeffectsparkle 1, 2, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Trash::
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorRooms_EventScript_Suicune::
	applymovement LOCALID_SUICUNE, Common_Movement_FacePlayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUICUNE
	seteventmon SPECIES_SUICUNE, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AbandonedShip_HiddenFloorRooms_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AbandonedShip_HiddenFloorRooms_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AbandonedShip_HiddenFloorRooms_EventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	releaseall
	end

AbandonedShip_HiddenFloorRooms_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end

AbandonedShip_HiddenFloorRooms_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end

AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash:
	.string "It's bright and shiny!\n"
	.string "But it's just trash…$"

