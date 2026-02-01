# Ruby/Sapphire Style Player Avatar Option

## Overview

This PR adds the ability for players to choose between Emerald-style or Ruby/Sapphire (Classic) style player sprites. The option is available during new game creation and can be changed anytime via the options menu.

## Feature Description

### Player Style Selection

Players can choose their avatar style at two points:

1. **New Game** - After selecting gender, a new "Look" selection screen appears
2. **Options Menu** - A "PLAYER STYLE" option is available in the World options

### Style Options

| Style | Description |
|-------|-------------|
| Emerald | Default Emerald protagonist sprites (Brendan/May) |
| Classic | Ruby/Sapphire style protagonist sprites |

The style affects:
- Overworld sprites (walking, running, biking, surfing, etc.)
- Battle back sprites
- Trainer card portrait
- Region map player icon

## Technical Implementation

### Storage

The player's style choice is stored using `FLAG_PLAYER_STYLE_RS` (repurposed from unused flag 0x296).

```c
// Check current style
if (FlagGet(FLAG_PLAYER_STYLE_RS))
    // Use RS/Classic sprites
else
    // Use Emerald sprites

// Set style
FlagSet(FLAG_PLAYER_STYLE_RS);   // RS/Classic
FlagClear(FLAG_PLAYER_STYLE_RS); // Emerald
```

Note: The initial implementation used a new SaveBlock2 field, but this was changed to use an existing unused flag to avoid modifying the save structure.

### Files Modified

#### Core Implementation

| File | Changes |
|------|---------|
| `include/constants/flags.h` | Added `FLAG_PLAYER_STYLE_RS` (0x296) |
| `include/constants/event_objects.h` | Added RS sprite object event IDs |
| `src/field_player_avatar.c` | RS sprite selection for overworld states |
| `src/main_menu.c` | New game style selection UI with proper window sizing |
| `src/option_plus_menu.c` | Post-game style toggle option |
| `src/pokemon.c` | Battle back sprite selection |
| `src/trainer_card.c` | Trainer card portrait selection |
| `src/region_map.c` | Region map player icon selection |
| `src/new_game.c` | Preserve style flag through game initialization |
| `src/field_effect_helpers.c` | Shadow palette fix for RS style |
| `src/event_object_movement.c` | RS palette reflection tags |
| `src/data/object_events/object_event_graphics_info.h` | RS sprite graphics info with correct animation tables |
| `src/data/object_events/object_event_pic_tables.h` | RS sprite frame tables including running frames |

#### Graphics Added

```
graphics/object_events/pics/people/ruby_sapphire_brendan/
├── walking.png
├── running.png
├── acro_bike.png
├── decorating.png
├── field_move.png
├── fishing.png
├── mach_bike.png
├── surfing.png
├── underwater.png
└── watering.png

graphics/object_events/pics/people/ruby_sapphire_may/
└── (same structure as brendan)

graphics/pokenav/region_map/
├── brendan_rs_icon.png
└── may_rs_icon.png
```

#### Data Files Modified

| File | Changes |
|------|---------|
| `src/data/object_events/object_event_graphics.h` | RS sprite graphics references |
| `src/data/object_events/object_event_graphics_info.h` | RS sprite metadata with `sAnimTable_BrendanMayNormal` |
| `src/data/object_events/object_event_graphics_info_pointers.h` | RS sprite pointers |
| `src/data/object_events/object_event_pic_tables.h` | RS sprite animation tables (walking + running) |
| `spritesheet_rules.mk` | Build rules for RS sprites |

### Option Menu Integration

The Player Style option:
- Located in: Options+ Menu -> World
- Available: Anytime (no unlock requirement)
- Options: "EMERALD" / "CLASSIC"

## New Game Flow

```
Gender Selection (Boy/Girl)
        |
Style Selection (Emerald/Classic)  <- NEW
        |
Difficulty Selection (Normal/Hard/Hardcore)
        |
National Dex Selection
        |
Name Entry
        |
Game Start
```

The style selection screen:
- Shows live preview of selected style
- Animated sprite transition when changing selection
- Press B to go back to gender selection
- Press A to confirm and continue

## Key Technical Details

### Animation Tables
RS sprites use `sAnimTable_BrendanMayNormal` instead of `sAnimTable_Standard` to properly support both walking (frames 0-8) and running (frames 9-17) animations.

### Shadow Fix
The shadow field effect copies the palette from the linked player sprite to ensure correct shadow colors regardless of which style is active.

### Flag Preservation
`FLAG_PLAYER_STYLE_RS` is preserved through `NewGameInitData()` alongside other new game flags (nuzlocke, hard mode, national dex mode).

