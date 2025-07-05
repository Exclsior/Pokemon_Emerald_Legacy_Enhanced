MirageTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_2F_SetHoleWarp
	map_script MAP_SCRIPT_ON_LOAD, MirageTower_2F_OnLoad
	.byte 0

MirageTower_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MIRAGE_TOWER_1F
	end

MirageTower_2F_OnLoad:
	goto_if_set FLAG_SYS_GAME_CLEAR, MirageTower_2F_EventScript_FillCrackedFloor
	return

MirageTower_2F_EventScript_FillCrackedFloor::
	setmetatile 2, 4, METATILE_Route111_MirageTower_SandFloor, FALSE
	setmetatile 2, 5, METATILE_Route111_MirageTower_SandFloor, FALSE
	setmetatile 2, 6, METATILE_Route111_MirageTower_SandFloor, FALSE
	return
