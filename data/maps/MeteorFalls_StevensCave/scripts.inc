.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN_2, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	goto_if_unset FLAG_RECEIVED_EON_TICKET, MeteorFalls_StevensCave_EventScript_GiveEonTicket
	release
	end

MeteorFalls_StevensCave_EventScript_GiveEonTicket::
	checkitemspace ITEM_EON_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MeteorFalls_StevensCave_EventScript_EonTicketBagFull
	giveitem ITEM_EON_TICKET
	setflag FLAG_RECEIVED_EON_TICKET
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	releaseall
	end

MeteorFalls_StevensCave_EventScript_EonTicketBagFull::
	vmessage MeteorFalls_StevensCave_Text_EonTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_EON_TICKET, MeteorFalls_StevensCave_EventScript_GiveEonTicket
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "We battled alongside each other at\n"
	.string "the MOSSDEEP SPACE CENTER.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Come to think of it, ever since\n"
	.string "our paths first crossed in GRANITE\l"
	.string "CAVE in DEWFORD, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the CHAMPION.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"

MeteorFalls_StevensCave_Text_EonTicket1:
	.string "You've become incredibly strong,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "As a token of my respect, I want you to\n"
	.string "have this.$"

MeteorFalls_StevensCave_Text_EonTicketBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"

MeteorFalls_StevensCave_Text_EonTicket2:
	.string "With it, you can board the ferry in\n"
	.string "LILYCOVE and head to SOUTHERN ISLAND.\p"
	.string "I've heard rumors of an exceptionally\n"
	.string "strong POKéMON there.\p"
	.string "Given your strength, I trust you can\n"
	.string "handle it better than I could.\p"
	.string "You've proven yourself a true CHAMPION,\n"
	.string "{PLAYER}{KUN}.$"
