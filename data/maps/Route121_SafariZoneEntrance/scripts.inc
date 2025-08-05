Route121_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
	.byte 0

Route121_SafariZoneEntrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
	.2byte 0

Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
	end

Route121_SafariZoneEntrance_EventScript_RareItemSeller::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route121_SafariZoneEntrance_EventScript_RareItemSeller_PostGame
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route121_SafariZoneEntrance_EventScript_RareItemSeller_MainGame
	end

Route121_SafariZoneEntrance_EventScript_RareItemSeller_MainGame::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, Route121_SafariZoneEntrance_EventScript_SellRareItems_MainGame
	msgbox SafariZoneEntrance_Text_RareItemSellerIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto Route121_SafariZoneEntrance_EventScript_SellRareItems_MainGame
	end

Route121_SafariZoneEntrance_EventScript_SellRareItems_MainGame::
	goto_if_set FLAG_NATIONAL_DEX_MODE, Route121_SafariZoneEntrance_EventScript_SellRareItems_NatDexMode
	msgbox SafariZoneEntrance_Text_RareItemSellerBuyRareItems, MSGBOX_DEFAULT
	pokemart SafariZoneEntrance_Pokemart_RareItemMart
	msgbox SafariZoneEntrance_Text_ImpressMeNextTime, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneEntrance_Pokemart_RareItemMart:
	.2byte ITEM_LIGHT_BALL
	.2byte ITEM_NONE
	release
	end

Route121_SafariZoneEntrance_EventScript_SellRareItems_NatDexMode::
	msgbox SafariZoneEntrance_Text_RareItemSellerBuyRareItems, MSGBOX_DEFAULT
	pokemart SafariZoneEntrance_Pokemart_RareItemMart_PostGame
	msgbox SafariZoneEntrance_Text_RareItemSellerComeAgain, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_RareItemSeller_PostGame::
	lock
	faceplayer
	setvar 0x8005, SPECIES_LATIAS
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, Route121_SafariZoneEntrance_EventScript_RareItemSeller_GotLati
	setvar 0x8005, SPECIES_LATIOS
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, Route121_SafariZoneEntrance_EventScript_RareItemSeller_GotLati
	goto_if_set FLAG_TEMP_1, Route121_SafariZoneEntrance_EventScript_SellRareItems_PostGame
	msgbox SafariZoneEntrance_Text_RareItemSellerImpressed, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto Route121_SafariZoneEntrance_EventScript_SellRareItems_PostGame
	end

Route121_SafariZoneEntrance_EventScript_SellRareItems_PostGame::
	msgbox SafariZoneEntrance_Text_RareItemSellerBuyRareItems_PostGame, MSGBOX_DEFAULT
	pokemart SafariZoneEntrance_Pokemart_RareItemMart_PostGame
	msgbox SafariZoneEntrance_Text_RareItemSellerComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneEntrance_Pokemart_RareItemMart_PostGame:
	.2byte ITEM_LIGHT_BALL
	.2byte ITEM_STICK
	.2byte ITEM_LUCKY_PUNCH
	.2byte ITEM_METAL_POWDER
	.2byte ITEM_THICK_CLUB
	.2byte ITEM_NONE
	release
	end

Route121_SafariZoneEntrance_EventScript_RareItemSeller_GotLati::
	goto_if_set FLAG_TEMP_2, Route121_SafariZoneEntrance_EventScript_RareItemSeller_GotLatiItem
	msgbox SafariZoneEntrance_Text_RareItemSellerSurprised, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto Route121_SafariZoneEntrance_EventScript_RareItemSeller_GotLatiItem
	end

Route121_SafariZoneEntrance_EventScript_RareItemSeller_GotLatiItem::
	msgbox SafariZoneEntrance_Text_RareItemSellerBuyRareItems_Lati, MSGBOX_DEFAULT
	pokemart SafariZoneEntrance_Pokemart_RareItemMart_Lati
	msgbox SafariZoneEntrance_Text_RareItemSellerThankYou, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneEntrance_Pokemart_RareItemMart_Lati:
	.2byte ITEM_LIGHT_BALL
	.2byte ITEM_STICK
	.2byte ITEM_LUCKY_PUNCH
	.2byte ITEM_METAL_POWDER
	.2byte ITEM_THICK_CLUB
	.2byte ITEM_SOUL_DEW
	.2byte ITEM_NONE
	release
	end

Route121_SafariZoneEntrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox SafariZoneEntrance_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end


Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_right
	step_end

Route121_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
	end

SafariZoneEntrance_Text_RareItemSellerIntro:
	.string "You look like an up-and-coming trainer!\p"
	.string "Have you come to the SAFARI ZONE to\n"
	.string "find rare POKéMON?\p"
	.string "Of course that's why you're here!\n"
	.string "What a silly question!$"

SafariZoneEntrance_Text_RareItemSellerBuyRareItems:
	.string "I have some items rarer than SAFARI\n"
	.string "ZONE POKéMON if you're interested?$"

SafariZoneEntrance_Text_ImpressMeNextTime:
	.string "If you can impress me, maybe I'll show\n"
	.string "you some even rarer items next time!$"

SafariZoneEntrance_Text_RareItemSellerImpressed:
	.string "CHAMPION {PLAYER}!\n"
	.string "Well, I am impressed...$"

SafariZoneEntrance_Text_RareItemSellerBuyRareItems_PostGame:
	.string "I have some items much rarer than\n"
	.string "SAFARI ZONE POKéMON for you!$"

SafariZoneEntrance_Text_RareItemSellerComeAgain:
	.string "Come back if you'd like some more rare\n"
	.string "POKéMON items.$"

SafariZoneEntrance_Text_RareItemSellerSurprised:
	.string "CHAMPION {PLAYER}!\n"
	.string "Well, I am impre...!\p"
	.string "Wait!\l"
	.string "Is that the legendary EON POKéMON?!\p"
	.string "I thought they were just a myth...$"

SafariZoneEntrance_Text_RareItemSellerBuyRareItems_Lati:
	.string "I have an item said to belong to the\n"
	.string "EON POKéMON... Though it won't be cheap.$"

SafariZoneEntrance_Text_RareItemSellerThankYou:
	.string "Thank you for bringing the EON POKéMON.\l"
	.string "It turns out that there are some\n"
	.string "POKéMON rarer than items.$"

SafariZoneEntrance_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"
