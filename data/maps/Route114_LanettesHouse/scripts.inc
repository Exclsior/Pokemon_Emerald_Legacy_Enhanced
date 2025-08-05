.set LOCALID_LANETTE, 1
.set LOCALID_EEVEE, 2

Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_LanettesHouse_OnLoad
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	goto_if_set FLAG_SYS_GAME_CLEAR, Route114_LanettesHouse_EventScript_SetTempChampFlag
	end

Route114_LanettesHouse_EventScript_SetTempChampFlag::
	clearflag FLAG_TEMP_2
	end

Route114_LanettesHouse_OnLoad:
	goto_if_set FLAG_LANETTE_RECEIVED_GIFT_EEVEE, Route114_LanettesHouse_EventScript_RemoveEevee
	goto_if_set FLAG_NATIONAL_DEX_MODE, Route114_LanettesHouse_EventScript_ShowEevee
	goto_if_set FLAG_SYS_GAME_CLEAR, Route114_LanettesHouse_EventScript_ShowEevee
	goto Route114_LanettesHouse_EventScript_RemoveEevee
	end

Route114_LanettesHouse_EventScript_RemoveEevee::
	setflag FLAG_TEMP_1
	end

Route114_LanettesHouse_EventScript_ShowEevee::
	clearflag FLAG_TEMP_1
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_CheckChampion
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_CheckChampion::
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route114_LanettesHouse_EventScript_CheckEeveeGifted
	goto_if_unset FLAG_TEMP_2, Route114_LanettesHouse_EventScript_CongratsChampion
	random 2
	goto_if_ne VAR_RESULT, 0, Route114_LanettesHouse_EventScript_CheckEeveeGifted
	msgbox Route114_LanettesHouse_Text_StevenPassingBy, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_CongratsChampion::
	msgbox Route114_LanettesHouse_Text_CongratulationsChampion, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route114_LanettesHouse_EventScript_CheckEeveeGifted::
	goto_if_unset FLAG_LANETTE_RECEIVED_GIFT_EEVEE, Route114_LanettesHouse_EventScript_OfferAdvice
	random 2
	goto_if_ne VAR_RESULT, 0, Route114_LanettesHouse_EventScript_OfferAdvice
	msgbox Route114_LanettesHouse_Text_HopeEeveeIsDoingWell, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox Route114_LanettesHouse_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_CheckEeveeGift
	release
	end

Route114_LanettesHouse_EventScript_CheckEeveeGift::
	goto_if_set FLAG_LANETTE_RECEIVED_GIFT_EEVEE, Route114_LanettesHouse_EventScript_SafetyEnd
	goto_if_set FLAG_NATIONAL_DEX_MODE, Route114_LanettesHouse_EventScript_EeveeGift
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route114_LanettesHouse_EventScript_SafetyEnd
	goto Route114_LanettesHouse_EventScript_EeveeGift
	release
	end

Route114_LanettesHouse_EventScript_SafetyEnd::
	release
	end

Route114_LanettesHouse_EventScript_EeveeGift::
	lockall
	waitmovement 0
	applymovement LOCALID_LANETTE, Common_Movement_FacePlayer
	call_if_set FLAG_TEMP_3, Route114_LanettesHouse_EventScript_WouldYouLikeEevee
	setflag FLAG_TEMP_3
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LANETTE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route114_LanettesHouse_Text_ISeeYouFoundEevee, MSGBOX_DEFAULT
	goto Route114_LanettesHouse_EventScript_WouldYouLikeEevee
	release
	end

Route114_LanettesHouse_EventScript_WouldYouLikeEevee::
	msgbox Route114_LanettesHouse_Text_WouldYouTakeCareofEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route114_LanettesHouse_EventScript_Nevermind
	goto Route114_LanettesHouse_EventScript_GiveEevee
	release
	end

Route114_LanettesHouse_EventScript_GiveEevee::
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 25, ITEM_PERSIM_BERRY, MOVE_CHARM
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route114_LanettesHouse_EventScript_SendEeveeToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route114_LanettesHouse_EventScript_SendEeveeToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route114_LanettesHouse_EventScript_SendEeveeToParty::
	call Route114_LanettesHouse_EventScript_ReceivedEevee
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route114_LanettesHouse_EventScript_FinishReceivedEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route114_LanettesHouse_EventScript_FinishReceivedEevee
	end

Route114_LanettesHouse_EventScript_SendEeveeToPC::
	call Route114_LanettesHouse_EventScript_ReceivedEevee
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route114_LanettesHouse_EventScript_EeveeTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route114_LanettesHouse_EventScript_EeveeTransferredToPC
	end

Route114_LanettesHouse_EventScript_EeveeTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto Route114_LanettesHouse_EventScript_FinishReceivedEevee
	end

Route114_LanettesHouse_EventScript_ReceivedEevee::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_EEVEE
	fadescreenswapbuffers FADE_FROM_BLACK
	playfanfare MUS_OBTAIN_ITEM
	message Route114_LanettesHouse_Text_ReceivedEevee
	waitmessage
	waitfanfare
	return

Route114_LanettesHouse_EventScript_FinishReceivedEevee::
	msgbox Route114_LanettesHouse_Text_TakeCareOfEevee, MSGBOX_DEFAULT
	setflag FLAG_LANETTE_RECEIVED_GIFT_EEVEE
	releaseall
	end

Route114_LanettesHouse_EventScript_Nevermind::
	msgbox Route114_LanettesHouse_Text_NevermindIllGetOutsideSoon, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "This is embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_Text_CongratulationsChampion:
	.string "LANETTE: {PLAYER}{KUN}!\n"
	.string "I saw your HALL OF FAME Record!\p"
	.string "Congratulations on becoming CHAMPION!$"

Route114_LanettesHouse_Text_StevenPassingBy:
	.string "STEVEN's been coming past here a lot\n"
	.string "more often since you become CHAMPION.\p"
	.string "He's probably in METEOR FALLS right now.\n"
	.string "You should give him a visit!$"

Route114_LanettesHouse_Text_ISeeYouFoundEevee:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I see you've found EEVEE!\n"
	.string "My friend BILL sent me EEVEE. But…\l"
	.string "I get so engrossed in my research\l"
	.string "that they barely get time outside…$"

Route114_LanettesHouse_Text_WouldYouTakeCareofEevee:
	.string "LANETTE: Hm...\p"
	.string "EEVEE seems very fond of you already.\l"
	.string "Would you like to take EEVEE with you?$"

Route114_LanettesHouse_Text_NevermindIllGetOutsideSoon:
	.string "Ah… Nevermind\p"
	.string "Don't worry EEVEE we'll go outside soon!$"

Route114_LanettesHouse_Text_ReceivedEevee:
	.string "{PLAYER} received {STR_VAR_1}\n"
	.string "from LANETTE!$"

Route114_LanettesHouse_Text_TakeCareOfEevee:
	.string "I'm sure you'll take great care of EEVEE.\n"
	.string "BILL will be thrilled!$"

Route114_LanettesHouse_Text_HopeEeveeIsDoingWell:
	.string "I hope EEVEE is doing well!$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

Route114_LanettesHouse_Text_Eevee:
	.string "EEVEE!$"
