.set LOCALID_ENTEI, 2

ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_OnResume
	.byte 0

ScorchedSlab_OnTransition:
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	call_if_unset FLAG_CAUGHT_ENTEI, ScorchedSlab_EventScript_TryShowEntei
	call_if_set FLAG_CAUGHT_ENTEI, ScorchedSlab_EventScript_HideEntei
	call_if_unset FLAG_STARTED_FINAL_SEISMIC_READING, ScorchedSlab_EventScript_HideEntei
	end

ScorchedSlab_EventScript_HideEntei::
	setflag FLAG_HIDE_ENTEI
	return

ScorchedSlab_EventScript_TryShowEntei::
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ENTEI
	return

ScorchedSlab_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_EventScript_TryRemoveEntei
	setdivewarp MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, 0, 10
	end

ScorchedSlab_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ENTEI
	return

ScorchedSlab_EventScript_Entei::
	faceplayer
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ENTEI
	seteventmon SPECIES_ENTEI, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlab_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlab_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	releaseall
	end

ScorchedSlab_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end

ScorchedSlab_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end
