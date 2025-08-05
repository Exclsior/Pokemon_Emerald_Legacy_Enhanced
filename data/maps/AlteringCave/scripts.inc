.set LOCALID_MEWTWO, 1

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	call_if_unset FLAG_CAUGHT_MEWTWO, AlteringCave_EventScript_TryShowMewtwo
	call_if_set FLAG_CAUGHT_MEWTWO, AlteringCave_EventScript_HideMewtwo
	call_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, AlteringCave_EventScript_HideMewtwo
	end

AlteringCave_EventScript_HideMewtwo::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_MEWTWO
	return

AlteringCave_EventScript_TryShowMewtwo::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_MEWTWO
	return

AlteringCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_EventScript_TryRemoveMewtwo
	end

AlteringCave_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MEWTWO
	return

AlteringCave_EventScript_Mewtwo::
	faceplayer
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MEWTWO
	seteventmon SPECIES_MEWTWO, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	releaseall
	end

AlteringCave_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

AlteringCave_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto AlteringCave_EventScript_MewtwoTeleportedAway
	end

AlteringCave_EventScript_MewtwoTeleportedAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox AlteringCave_Text_MewtwoTeleportedAway, MSGBOX_DEFAULT
	release
	end

AlteringCave_Text_MewtwoTeleportedAway::
	.string "{STR_VAR_1} teleported away!$"
