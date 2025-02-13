.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2

MarineCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	.byte 0

MarineCave_End_OnResume:
	setflag FLAG_HIDE_ARCHIE_MARINE_CAVE
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_TryRemoveKyogre
	end

MarineCave_End_EventScript_TryRemoveKyogre::
	clearflag FLAG_HIDE_ARCHIE_MARINE_CAVE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KYOGRE
	return

MarineCave_End_OnTransition:
	call_if_unset FLAG_DEFEATED_KYOGRE, MarineCave_End_EventScript_ShowKyogre
	setflag FLAG_HIDE_ARCHIE_MARINE_CAVE
	end

MarineCave_End_EventScript_ShowKyogre::
	clearflag FLAG_HIDE_MARINE_CAVE_KYOGRE
	setvar VAR_TEMP_1, 1
	return

MarineCave_End_EventScript_Kyogre::
	lockall
	call MarineCave_End_EventScript_Archie
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_KYOGRE, MarineCave_End_Movement_KyogreApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_KYOGRE
	setwildbattle SPECIES_KYOGRE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_End_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MarineCave_End_EventScript_RanFromKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MarineCave_End_EventScript_RanFromKyogre
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	goto MarineCave_End_EventScript_ArchieLeaves
	releaseall
	end

MarineCave_End_EventScript_Archie::
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, MarineCave_End_Movement_ArchieApproach
	waitmovement 0
	setvar VAR_LAST_TALKED, LOCALID_ARCHIE
	faceplayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto_if_set FLAG_BEAT_ARCHIE_MARINE_CAVE, MarineCave_End_EventScript_ArchiePostBattle
	msgbox MarineCave_End_Text_ArchieIntro, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_ARCHIE
	trainerbattle_no_intro TRAINER_ARCHIE_MARINE_CAVE, MarineCave_End_Text_ArchieDefeat
	special HealPlayerParty
MarineCave_End_EventScript_ArchiePostBattle::
	msgbox MarineCave_End_Text_ArchiePostBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BEAT_ARCHIE_MARINE_CAVE
	return

MarineCave_End_EventScript_DefeatedKyogre::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	goto MarineCave_End_EventScript_ArchieLeaves
	end

MarineCave_End_EventScript_RanFromKyogre::
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto Common_EventScript_LegendaryFlewAway
	msgbox MarineCave_End_Text_ArchieRanFromKyogre, MSGBOX_DEFAULT
	closemessage
	goto MarineCave_End_EventScript_ArchieLeaves_NoText
	end

MarineCave_End_EventScript_ArchieLeaves::
	msgbox MarineCave_End_Text_ArchieCaughtKyogre, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ARCHIE_LEFT_MARINE_CAVE
MarineCave_End_EventScript_ArchieLeaves_NoText::
	setflag FLAG_HIDE_ARCHIE_MARINE_CAVE
	call MarineCave_End_EventScript_SetMtPyre
	applymovement LOCALID_ARCHIE, MarineCave_End_Movement_ArchieLeaves
	waitmovement 0
	removeobject LOCALID_ARCHIE
	releaseall
	end

MarineCave_End_EventScript_SetMtPyre::
	goto_if_unset FLAG_ARCHIE_LEFT_MARINE_CAVE, Common_EventScript_NopReturn
	goto_if_unset FLAG_MAXIE_LEFT_TERRA_CAVE, Common_EventScript_NopReturn
	setvar VAR_MT_PYRE_STATE, 2
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	return

MarineCave_End_Movement_KyogreApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

MarineCave_End_Movement_ArchieApproach:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

MarineCave_End_Movement_ArchieLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MarineCave_End_Text_ArchieIntro:
	.string "ARCHIE: So, you're here for KYOGRE?\n"
	.string "You don't understand-\l"
	.string "this is my burden to bear!\p"
	.string "I was the one who woke it.\n"
	.string "Only I can keep it under control.\p"
	.string "I won't let you stand in my way.\p"
	.string "But if you think\n"
	.string "you can handle this…\p"
	.string "Then prove it to me in battle!$"

MarineCave_End_Text_ArchieDefeat:
	.string "ARCHIE: I can't believe it…\n"
	.string "But this isn't over yet. KYOGRE will\l"
	.string "rise, and you'll see the truth.$"

MarineCave_End_Text_ArchiePostBattle:
	.string "ARCHIE: So, it's come to this.\n"
	.string "I've made my mistakes\l"
	.string "but I can't turn back now.\p"
	.string "KYOGRE's anger is still my\n"
	.string "responsibility…\p"
	.string "But if you're going to try,\n"
	.string "I won't stop you…\p"
	.string "Just don't think it'll be easy.$"

MarineCave_End_Text_ArchieCaughtKyogre:
	.string "ARCHIE: You… actually calmed KYOGRE?\n"
	.string "I never thought anyone could…\p"
	.string "So, it's come to this.\p"
	.string "I wanted to save lives, to bring water\n"
	.string "where it was needed and let deserts\l"
	.string "bloom.\p"
	.string "Maybe I've been too driven by my\n"
	.string "emotions,\p"
	.string "too quick to summon the tides without\n"
	.string "seeing the ripples they'd cause.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Maybe MAXIE had a point.\p"
	.string "Charging ahead without understanding\n"
	.string "the delicate balance of things was\l"
	.string "foolish.\p"
	.string "It's not about flooding lands or drying\n"
	.string "seas, but about letting nature find its\l"
	.string "balance.\p"
	.string "A single drop can create ripples…\n"
	.string "maybe that's where real change begins.\p"
	.string "Small acts might matter more than grand\n"
	.string "gestures.\p"
	.string "I can't abandon my dream, but perhaps\n"
	.string "there's a better way to achieve it…\p"
	.string "One that respects the world we belong\n"
	.string "to.$"

MarineCave_End_Text_ArchieRanFromKyogre:
	.string "ARCHIE: So, Kyogre escaped?\n"
	.string "I knew it was beyond anyone's grasp!\p"
	.string "Only I can understand its power,\n"
	.string "its purpose… the world will see soon.\p"
	.string "You just proved it.\n"
	.string "Kyogre is my responsibility, and I'll see\l"
	.string "that it's handled correctly from now on.$"
