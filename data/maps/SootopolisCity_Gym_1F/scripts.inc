SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	map_script_2 VAR_TEMP_1, 1, SootopolisCity_Gym_1F_EventScript_TryRematchReward
	.2byte 0

SootopolisCity_Gym_1F_EventScript_TryRematchReward::
	setvar VAR_TEMP_1, 0
	goto_if_set FLAG_GOT_JUAN_REMATCH_REWARD, SootopolisCity_Gym_1F_EventScript_TryRematchRewardEnd
	setvar 0x8005, TRAINER_JUAN_3
	special HasRematchBeenFought
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_GiveRematchReward
SootopolisCity_Gym_1F_EventScript_TryRematchRewardEnd::
	ClearTrainerFlag TRAINER_JUAN_5
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_WallaceDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_Wallace::
	trainerbattle_single TRAINER_WALLACE_1, SootopolisCity_Gym_1F_Text_WallaceIntro, SootopolisCity_Gym_1F_Text_WallaceDefeat, SootopolisCity_Gym_1F_EventScript_WallaceDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_WallaceDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadgeWallace
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	settrainerflag TRAINER_JUAN_1
	setflag FLAG_ENABLE_NORMAN_REMATCH_CALL
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	goto_if_set FLAG_SOOTOPOLIS_CITY_RIVAL_PROFESSOR, SootopolisCity_Gym_1F_EventScript_SootopolisDoneRivalScene1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 7
	goto SootopolisCity_Gym_1F_EventScript_SootopolisDoneRivalScene2
SootopolisCity_Gym_1F_EventScript_SootopolisDoneRivalScene1::
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
SootopolisCity_Gym_1F_EventScript_SootopolisDoneRivalScene2::
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	goto_if_set FLAG_GOT_JUAN_REMATCH_REWARD, SootopolisCity_Gym_1F_EventScript_JuanRematchContinue
	setvar 0x8005, TRAINER_JUAN_3
	special HasRematchBeenFought
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_GiveRematchReward
SootopolisCity_Gym_1F_EventScript_JuanRematchContinue::
	setvar VAR_TEMP_1, 1
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	release
	end
SootopolisCity_Gym_1F_EventScript_GiveRematchReward::
	msgbox SootopolisCity_Gym_1F_Text_JuanGiveRematchReward, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_DRAGON_SCALE, 1
	waitfanfare
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_Gym_1F_EventScript_NoRoom
	msgbox SootopolisCity_Gym_1F_Text_GaveReward, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_JUAN_REMATCH_REWARD
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end
SootopolisCity_Gym_1F_EventScript_NoRoom::
	msgbox SootopolisCity_Gym_1F_Text_NoRoomForReward, MSGBOX_DEFAULT
	closemessage
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, SootopolisCity_Gym_1F_EventScript_GymGuidePostGame
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostGame::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostGame, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	goto_if_set FLAG_IS_CHAMPION, SootopolisCity_Gym_1F_EventScript_GymStatueJuanCertified
	msgbox SootopolisCity_Gym_1F_Text_GymStatueWallaceCertified, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Gym_1F_EventScript_GymStatueJuanCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueJuanCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! CHAMP-in-making!\n"
	.string "I can't believe how far you've come!\p"
	.string "Are you ready to finish this out?\p"
	.string "SOOTOPOLIS's GYM LEADER WALLACE is\n"
	.string "a master of WATER-type POKéMON\l"
	.string "and all things beautiful.\p"
	.string "You've battled WATER-types before,\n"
	.string "but WALLACE is on another level.\p"
	.string "Watching WALLACE fight, there's a grace\n"
	.string "that few other trainers possess.\p"
	.string "Many believe him to be as strong\n"
	.string "as those in the ELITE FOUR.\p"
	.string "Some even say…\n"
	.string "Ah, it doesn't matter.\p"
	.string "{PLAYER}!\n"
	.string "I know you can do this!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! You've beaten WALLACE, who\n"
	.string "is supposedly the best in HOENN!\p"
	.string "{PLAYER}! It's been an honor!\p"
	.string "It's time for you to take on the\n"
	.string "POKéMON LEAGUE challenge!\p"
	.string "I can't come with you, but just\n"
	.string "know I'll be rooting for you!$"

SootopolisCity_Gym_1F_Text_GymGuidePostGame:
	.string "Yow! You've come so far,\n"
	.string "{PLAYER}!\p"
	.string "As the CHAMPION of HOENN, you’ve\n"
	.string "already reached the peak!\p"
	.string "Facing JUAN, the new leader here,\n"
	.string "is a true test of skill!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Let me ask you.\n"
	.string "Did you know?\l"
	.string "Ah, I should not be so coy.\p"
	.string "It was I who taught WALLACE everything\n"
	.string "there is to know about POKéMON.\p"
	.string "Once, I had given up my position as\n"
	.string "the GYM LEADER.\p"
	.string "In my place, I had entrusted WALLACE\n"
	.string "with the GYM.\p"
	.string "However, a compelling reason arose for\n"
	.string "me to make a comeback.\p"
	.string "Ah, but enough chatter.\n"
	.string "Let us begin our match, shall we?\p"
	.string "Please, you shall bear witness to\n"
	.string "our artistry.\p"
	.string "A grand illusion of water sculpted\n"
	.string "by POKéMON and myself!$"

SootopolisCity_Gym_1F_Text_WallaceIntro:
	.string "Allow me to formally introduce\n"
	.string "myself.\p"
	.string "I am WALLACE.\n"
	.string "The GYM LEADER of SOOTOPOLIS.\p"
	.string "There's something about you…\n"
	.string "A difference in your demeanor.\p"
	.string "I think I sense that in you.\p"
	.string "What happened on top of the SKY\n"
	.string "PILLAR, and what you did, I will likely\l"
	.string "learn through our upcoming battle.\p"
	.string "Now, show me. Show me the power you\n"
	.string "wield with your POKéMON.\p"
	.string "And I, in turn, shall present you with\n"
	.string "a performance of illusions in water\l"
	.string "by me and my POKéMON!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, excellent!\n"
	.string "Very well, you are the winner.\p"
	.string "From you, I sense the brilliant shine\n"
	.string "of skill that will overcome all.\p"
	.string "However, compared with me or even\n"
	.string "WALLACE, you are lacking in elegance.\p"
	.string "Perhaps I should make you a loan\n"
	.string "of my outfit?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, I merely jest!\p"
	.string "Rather than my clothes, I shall reward\n"
	.string "you with this, the RAIN BADGE!$"

SootopolisCity_Gym_1F_Text_WallaceDefeat:
	.string "Bravo.\p"
	.string "I realize now your authenticity and\n"
	.string "magnificence as a POKéMON TRAINER.\p"
	.string "I find much joy in having met you and\n"
	.string "your POKéMON.\p"
	.string "You have proven yourself worthy of\n"
	.string "the RAIN BADGE. Accept it.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the RAIN BADGE\n"
	.string "from JUAN.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadgeWallace:
	.string "{PLAYER} received the RAIN BADGE\n"
	.string "from WALLACE.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Having the RAIN BADGE shall assure you\n"
	.string "the full obedience of all your POKéMON\l"
	.string "to your every command.\p"
	.string "The RAIN BADGE also allows the use\n"
	.string "of the HM move WATERFALL to scale\l"
	.string "walls of cascading water.\p"
	.string "And, so that you never forget the\n"
	.string "battle we shared, take this…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "The TECHNICAL MACHINE I handed you\n"
	.string "contains WATER PULSE.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Registered GYM LEADER JUAN\n"
	.string "in the POKéNAV.$"

SootopolisCity_Gym_1F_Text_RegisteredWallace:
	.string "Registered GYM LEADER WALLACE\n"
	.string "in the POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "The TRAINERS who have gathered all\n"
	.string "the GYM BADGES of HOENN should make\l"
	.string "way to the ultimate destination.\p"
	.string "The POKéMON LEAGUE.\p"
	.string "Travel to the easternmost reaches\n"
	.string "of HOENN, to the island EVER GRANDE.\p"
	.string "There, you shall find the POKéMON\n"
	.string "LEAGUE.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "There remains but one BADGE to\n"
	.string "obtain in HOENN.\p"
	.string "If you wish to challenge the POKéMON\n"
	.string "LEAGUE, you must obtain the last\l"
	.string "BADGE from the GYM in FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "SOOTOPOLIS CITY POKéMON GYM$"

SootopolisCity_Gym_1F_Text_GymStatueWallaceCertified:
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
	.string "WALLACE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_GymStatueJuanCertified:
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
	.string "JUAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, this GYM had returned to its\n"
	.string "usual state of serenity…\p"
	.string "Yet here comes our young typhoon,\n"
	.string "ready to stir its waters anew!\p"
	.string "Well, my friend, most certainly!\p"
	.string "I shall be delighted to dance with you\n"
	.string "as often as you wish!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, you are the winner!\n"
	.string "You have defeated me!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: If I told you to become my\n"
	.string "apprentice, you will refuse, I am sure.\p"
	.string "I would like to make a gift of my coat\n"
	.string "to you.\p"
	.string "But again, you will refuse.\n"
	.string "I imagine that to be so.\p"
	.string "And that, my friend, is a certain sign\n"
	.string "of nobility!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, this GYM had returned to its\n"
	.string "usual state of serenity…\p"
	.string "Yet here comes our young typhoon,\n"
	.string "ready to stir its waters anew!\p"
	.string "Well, my friend, most certainly!\n"
	.string "I shall be delighted to dance with you…\p"
	.string "Ah, no, no, no.\n"
	.string "You have with you but one POKéMON.\p"
	.string "I wish that you would return with\n"
	.string "two, perhaps more, POKéMON, please.$"

SootopolisCity_Gym_1F_Text_JuanGiveRematchReward:
	.string "Ah, splendid indeed, {PLAYER}.\n"
	.string "Your performance was nothing short\l"
	.string "of mesmerizing.\p"
	.string "To honor this remarkable battle, I shall\n"
	.string "bestow upon you a rare item, one that is\l"
	.string "close to my heart.$"

SootopolisCity_Gym_1F_Text_NoRoomForReward:
	.string "Ah, it seems your BAG is filled to\n"
	.string "the brim.\p"
	.string "No matter, I shall keep this safe until\n"
	.string "you make space for it.$"

SootopolisCity_Gym_1F_Text_GaveReward:
	.string "This DRAGON SCALE embodies the majesty\n"
	.string "and power of dragons, much like the\l"
	.string "KINGDRA that I have trained with care.\p"
	.string "May it serve you well on your journey.$"
