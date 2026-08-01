SecretBase_EventScript_ShiningTrial::
	lock
	msgbox ShiningTrial_Text_Requirements, MSGBOX_DEFAULT
	special ShiningTrial_CheckEligibility
	switch VAR_RESULT
	case SHINING_TRIAL_NO_MON, ShiningTrial_EventScript_NoMon
	case SHINING_TRIAL_EGG, ShiningTrial_EventScript_Egg
	case SHINING_TRIAL_ALREADY_SHINY, ShiningTrial_EventScript_AlreadyShiny
	case SHINING_TRIAL_FRIENDSHIP_TOO_LOW, ShiningTrial_EventScript_Friendship
	case SHINING_TRIAL_NO_SHINY_FORM, ShiningTrial_EventScript_NoShinyForm
	msgbox ShiningTrial_Text_Accept, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShiningTrial_EventScript_Declined
	bufferpartymonnick STR_VAR_1, 0
	msgbox ShiningTrial_Text_Begin, MSGBOX_DEFAULT
	special ShiningTrial_Begin
	goto_if_eq VAR_RESULT, SHINING_TRIAL_NO_SHINY_FORM, ShiningTrial_EventScript_NoShinyForm
	goto_if_eq VAR_RESULT, FALSE, ShiningTrial_EventScript_Interrupted
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_SHINING_TRIAL
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, ShiningTrial_EventScript_Lost
	special ShiningTrial_Finish
	goto_if_eq VAR_RESULT, SHINING_TRIAL_FINISH_IDENTITY_LOST, ShiningTrial_EventScript_IdentityLost
	goto_if_eq VAR_RESULT, SHINING_TRIAL_FINISH_INELIGIBLE, ShiningTrial_EventScript_Interrupted
	goto_if_eq VAR_RESULT, SHINING_TRIAL_FINISH_NO_PID, ShiningTrial_EventScript_NoPid
	bufferpartymonnick STR_VAR_1, 0
	msgbox ShiningTrial_Text_LightGathers, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_WHITE
	playse SE_SHINY
	delay 60
	fadescreen FADE_FROM_WHITE
	waitse
	msgbox ShiningTrial_Text_Success, MSGBOX_DEFAULT
	release
	end

ShiningTrial_EventScript_NoMon::
	msgbox ShiningTrial_Text_NoMon, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_Egg::
	msgbox ShiningTrial_Text_Egg, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_AlreadyShiny::
	msgbox ShiningTrial_Text_AlreadyShiny, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_Friendship::
	msgbox ShiningTrial_Text_Friendship, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_NoShinyForm::
	msgbox ShiningTrial_Text_NoShinyForm, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_Declined::
	msgbox ShiningTrial_Text_Declined, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_Lost::
	special ShiningTrial_Cancel
	msgbox ShiningTrial_Text_Lost, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_IdentityLost::
	msgbox ShiningTrial_Text_IdentityLost, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_Interrupted::
	special ShiningTrial_Cancel
	msgbox ShiningTrial_Text_Interrupted, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_NoPid::
	msgbox ShiningTrial_Text_NoPid, MSGBOX_DEFAULT
	goto ShiningTrial_EventScript_End

ShiningTrial_EventScript_End::
	release
	end

ShiningTrial_Text_Requirements:
	.string "The TRIAL TOTEM hums with a faint\n"
	.string "light. A voice echoes in your mind…\p"
	.string "Your lead POKéMON must not be an EGG\n"
	.string "or already shine. It must trust you\l"
	.string "completely.$"

ShiningTrial_Text_Accept:
	.string "Your partner meets every condition.\p"
	.string "It must face its shining mirror ten\n"
	.string "levels stronger. Your party\l"
	.string "will be restored afterward.\p"
	.string "Will you accept the SHINING TRIAL?$"

ShiningTrial_Text_Begin:
	.string "{STR_VAR_1}, let your bond be tested!$"

ShiningTrial_Text_NoMon:
	.string "Place the POKéMON you wish to test at\n"
	.string "the head of your party.$"

ShiningTrial_Text_Egg:
	.string "An EGG cannot undertake the trial.\n"
	.string "Return after it has hatched.$"

ShiningTrial_Text_AlreadyShiny:
	.string "Your lead already carries a brilliant\n"
	.string "shining light. It needs no trial.$"

ShiningTrial_Text_Friendship:
	.string "Your lead does not yet trust you\n"
	.string "completely. Deepen your friendship.$"

ShiningTrial_Text_NoShinyForm:
	.string "No safe shining form can preserve this\n"
	.string "partner exactly. The trial cannot begin.$"

ShiningTrial_Text_Declined:
	.string "A true trial should never be rushed.\n"
	.string "Return when you are ready.$"

ShiningTrial_Text_Lost:
	.string "Your party has been restored exactly as\n"
	.string "it was. Strengthen your strategy and\l"
	.string "return when you are ready.$"

ShiningTrial_Text_IdentityLost:
	.string "The partner who began the trial could\n"
	.string "not be verified. No change was made.$"

ShiningTrial_Text_Interrupted:
	.string "The trial could not be completed safely.\n"
	.string "Your party has not been changed.$"

ShiningTrial_Text_NoPid:
	.string "This partner has no safe shining form.\n"
	.string "No change was made.$"

ShiningTrial_Text_LightGathers:
	.string "A brilliant light gathers around\n"
	.string "{STR_VAR_1}!$"

ShiningTrial_Text_Success:
	.string "{STR_VAR_1}'s proven bond now shines for\n"
	.string "all to see!$"
