.set LOCALID_MOLTRES, 2

MagmaHideout_3F_3R_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_3F_3R_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MagmaHideout_3F_3R_OnResume
	.byte 0

MagmaHideout_3F_3R_OnTransition:
	call_if_set FLAG_CAUGHT_MOLTRES, MagmaHideout_3F_3R_EventScript_HideMoltres
	call_if_unset FLAG_BEAT_ALL_3RD_REMATCHES, MagmaHideout_3F_3R_EventScript_HideMoltres
	call_if_unset FLAG_CAUGHT_MOLTRES, MagmaHideout_3F_3R_EventScript_TryShowMoltres
	end

MagmaHideout_3F_3R_EventScript_HideMoltres::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_MOLTRES
	return

MagmaHideout_3F_3R_EventScript_TryShowMoltres::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
	goto_if_unset FLAG_BEAT_ALL_3RD_REMATCHES, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_MOLTRES
	return

MagmaHideout_3F_3R_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MagmaHideout_3F_3R_EventScript_TryRemoveMoltres
	end

MagmaHideout_3F_3R_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MOLTRES
	return

MagmaHideout_3F_3R_EventScript_Moltres::
	faceplayer
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MOLTRES
	seteventmon SPECIES_MOLTRES, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MagmaHideout_3F_3R_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MagmaHideout_3F_3R_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MagmaHideout_3F_3R_EventScript_RanFromMoltres
	setflag FLAG_CAUGHT_MOLTRES
	releaseall
	end

MagmaHideout_3F_3R_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

MagmaHideout_3F_3R_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
