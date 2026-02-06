# Custom PC Box Wallpapers Guide

This guide explains how to create and add custom wallpapers for the PC Box storage system using the Walda-style rendering system.

## Overview

Custom wallpapers use the same system as the "Friends" wallpaper (unlocked via Walda's phrase). Each wallpaper consists of:
- **Pattern**: Background tile design (16 available patterns)
- **Icon**: Decorative icon overlay (30 available icons)
- **Background Color**: Primary fill color (palette index 1)
- **Foreground Color**: Secondary/accent color (palette index 2)
- **Title Colors**: Shadow and text colors for the box title

## Unlocking Custom Wallpapers In-Game (Friends Wallpaper)

The "Friends" wallpaper can be customized in-game using Walda's phrase system. To generate a custom phrase for your desired wallpaper:

1. Visit the **Walda Phrase Generator**: https://www.pokewiki.de/Spezial:Geheimcode-Generator?uselang=en

2. Enter your **Trainer ID** (found on your Trainer Card)

3. Select your desired:
   - **Pattern** (background design)
   - **Icon** (decorative overlay)
   - **Background Color**
   - **Foreground Color**

4. The generator will provide a **phrase** to tell Walda

5. In-game, visit **Walda** in Rustboro City (in the house east of the Pokémon Center)

6. Tell her the generated phrase to unlock your custom "Friends" wallpaper

**Note:** The Friends wallpaper uses the same pattern/icon system as the special wallpapers documented below, so you can use the Pattern IDs and Icon IDs tables as reference.

## Color Format

### Hex to GBA RGB555 Conversion

GBA uses 15-bit color (5 bits per RGB channel, values 0-31). Convert hex colors:

```
#RRGGBB → RGB(R/8, G/8, B/8)

Examples:
  #FF0000 (Red)    → RGB(31, 0, 0)
  #00FF00 (Green)  → RGB(0, 31, 0)
  #0000FF (Blue)   → RGB(0, 0, 31)
  #FFFFFF (White)  → RGB(31, 31, 31)
  #808080 (Gray)   → RGB(16, 16, 16)
  #e090a8 (Pink)   → RGB(28, 18, 21)
```

### Color Limitations

The Walda system only customizes **2 palette colors** (indices 1 and 2). Any graphics using other palette indices will display using the pattern's original colors. This means:
- Some pattern decorations may appear in fixed colors (grays, whites)
- For best results, choose patterns where the main design uses indices 1 and 2

## Available Patterns (0-15)

| ID | Name       | Description                    |
|----|------------|--------------------------------|
| 0  | Zigzagoon  | Zigzagoon silhouettes          |
| 1  | Screen     | Grid/screen pattern            |
| 2  | Horizontal | Horizontal stripes             |
| 3  | Diagonal   | Diagonal stripes               |
| 4  | Block      | Block/checker pattern          |
| 5  | Ribbon     | Ribbon pattern (3 colors)      |
| 6  | Pokecenter2| Pokemon Center themed          |
| 7  | Frame      | Frame/border pattern           |
| 8  | Blank      | Solid/minimal background       |
| 9  | Circles    | Circle pattern                 |
| 10 | Azumarill  | Azumarill silhouettes          |
| 11 | Pikachu    | Pikachu silhouettes            |
| 12 | Legendary  | Legendary Pokemon themed       |
| 13 | Dusclops   | Dusclops silhouettes           |
| 14 | Ludicolo   | Ludicolo silhouettes           |
| 15 | Whiscash   | Whiscash silhouettes           |

## Available Icons (0-29)

| ID | Name         | ID | Name         |
|----|--------------|----|--------------|
| 0  | Aqua         | 15 | Ribbon       |
| 1  | Heart        | 16 | Bolt         |
| 2  | FiveStar     | 17 | FourCircles  |
| 3  | Brick        | 18 | Lotad        |
| 4  | FourStar     | 19 | Crystal      |
| 5  | Asterisk     | 20 | Pichu        |
| 6  | Dot          | 21 | Diglett      |
| 7  | Cross        | 22 | Luvdisc      |
| 8  | LineCircle   | 23 | StarInCircle |
| 9  | PokeBall     | 24 | Spinda       |
| 10 | Maze         | 25 | Latis        |
| 11 | Footprint    | 26 | Plusle       |
| 12 | BigAsterisk  | 27 | Minun        |
| 13 | Circle       | 28 | Togepi       |
| 14 | Koffing      | 29 | Magma        |

## Files to Modify

### 1. `src/data/wallpapers.h`

#### Add Enum Entry

Add your wallpaper to the enum (after `WALLPAPER_FRIENDS`, before `WALLPAPER_COUNT`):

```c
enum {
    // ... existing wallpapers ...
    WALLPAPER_FRIENDS,
    // Special wallpapers start here
    WALLPAPER_SPECIAL_CUTE,
    WALLPAPER_SPECIAL_SMART,
    // ... other special wallpapers ...
    WALLPAPER_SPECIAL_YOUR_NEW_WALLPAPER,  // Add here
    WALLPAPER_COUNT
};
```

#### Add Title Colors

Add entry to `sBoxTitleColors` array:

```c
static const u16 sBoxTitleColors[WALLPAPER_COUNT][2] = {
    // ... existing entries ...
    [WALLPAPER_SPECIAL_YOUR_NEW_WALLPAPER] = {RGB(10, 10, 10), RGB_WHITE},
    //                                        ^ Shadow color   ^ Text color
};
```

#### Add Configuration

Add entry to `sSpecialWallpapers` array:

```c
static const struct SpecialWallpaperConfig sSpecialWallpapers[WALLPAPER_SPECIAL_COUNT] = {
    // ... existing entries ...
    [WALLPAPER_SPECIAL_YOUR_NEW_WALLPAPER - WALLPAPER_SPECIAL_START] = {
        PATTERN_ID,           // Pattern (0-15)
        ICON_ID,              // Icon (0-29)
        RGB(bg_r, bg_g, bg_b), // Background color (RGB555)
        RGB(fg_r, fg_g, fg_b)  // Foreground color (RGB555)
    },
};
```

### 2. `src/pokemon_storage_system.c`

#### Add Menu Enum

Add to the menu enum (must match wallpapers.h order):

```c
enum {
    // ... existing menu items ...
    MENU_SPECIAL_YOUR_NEW_WALLPAPER,
};
```

#### Add to Category Menu

In `AddWallpapersMenu()`, add your wallpaper to the appropriate category case:

```c
case MENU_YOUR_CATEGORY - MENU_WALLPAPER_SETS_START:
    SetMenuText(MENU_SPECIAL_YOUR_NEW_WALLPAPER);
    // ... other wallpapers in this category ...
    break;
```

#### Add Menu Text Reference

Add to `sMenuOptionTexts` array:

```c
static const u8 *const sMenuOptionTexts[] = {
    // ... existing entries ...
    [MENU_SPECIAL_YOUR_NEW_WALLPAPER] = gPCText_YourNewWallpaper,
};
```

### 3. `src/strings.c`

Add the display string:

```c
const u8 gPCText_YourNewWallpaper[] = _("YOUR NAME");
```

### 4. `include/strings.h`

Declare the string:

```c
extern const u8 gPCText_YourNewWallpaper[];
```

## Adding a New Category

If you need a new category submenu:

### 1. Add Category Enum

In `pokemon_storage_system.c`, add to the category enum:

```c
enum {
    MENU_POKEMON_2,
    MENU_SECRET,
    MENU_YOUR_CATEGORY,  // Add new category
    MENU_TEAM,
    // ...
};
```

### 2. Add Category Handler

In the wallpaper state machine, add handling for your category:

```c
case MENU_YOUR_CATEGORY - MENU_WALLPAPER_SETS_START:
    SetMenuText(MENU_SPECIAL_WALLPAPER_1);
    SetMenuText(MENU_SPECIAL_WALLPAPER_2);
    // ... add all wallpapers in this category ...
    break;
```

### 3. Add Category to Special Menu

In `AddSpecialCategoriesMenu()`:

```c
SetMenuText(MENU_YOUR_CATEGORY);
```

### 4. Add Category String

In `strings.c`:
```c
const u8 gPCText_YourCategory[] = _("YOUR CAT");
```

In `strings.h`:
```c
extern const u8 gPCText_YourCategory[];
```

## Category Unlock Conditions

Categories can be locked behind game progress flags. The unlock logic is in `AddSpecialCategoriesMenu()` in `pokemon_storage_system.c`.

### Current Unlock Requirements

| Category | Unlock Condition | Flag/Function Used |
|----------|------------------|-------------------|
| Other | Always available | (none) |
| Pokemon 1 | Catch 100 Pokémon | `GetNationalPokedexCount(FLAG_GET_CAUGHT) >= 100` |
| Pokemon 2 | Catch 200 Pokémon | `GetNationalPokedexCount(FLAG_GET_CAUGHT) >= 200` |
| Team | Complete Aqua Hideout | `FlagGet(FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW)` |
| Contest | Receive Pokéblock Case | `FlagGet(FLAG_RECEIVED_POKEBLOCK_CASE)` |
| Legends | Catch Latias/Latios | `FlagGet(FLAG_CAUGHT_LATIAS_OR_LATIOS)` |
| Secret | Defeat Trainer Exclsior | `FlagGet(FLAG_DEFEATED_EXCLSIOR)` |

### Adding Unlock Conditions

To add an unlock condition for a new category:

```c
// In AddSpecialCategoriesMenu():
static void AddSpecialCategoriesMenu(void)
{
    InitMenu();
    // Example: Unlock after getting 50 Pokemon
    if (GetNationalPokedexCount(FLAG_GET_CAUGHT) >= 50)
        SetMenuText(MENU_YOUR_CATEGORY);
    // Example: Unlock after a specific flag
    if (FlagGet(FLAG_YOUR_CONDITION))
        SetMenuText(MENU_ANOTHER_CATEGORY);
    // Example: Unlock after defeating a boss trainer (use their defeat flag)
    if (FlagGet(FLAG_DEFEATED_TRAINER_NAME))
        SetMenuText(MENU_TRAINER_CATEGORY);
    AddMenu();
}
```

### Required Includes

Make sure these are included at the top of `pokemon_storage_system.c`:

```c
#include "constants/flags.h"
#include "debug.h"
#include "pokedex.h"
```

### Finding Flags

- Game flags are defined in `include/constants/flags.h`
- Boss trainer defeat flags typically follow the pattern `FLAG_DEFEATED_*`
- Use `FlagGet(FLAG_NAME)` for event flags
- Use `GetNationalPokedexCount(FLAG_GET_CAUGHT)` for Pokédex progress

### Debug Mode

When `TX_DEBUG_SYSTEM_ENABLE` is set to `TRUE` in `include/debug.h`, all wallpaper categories are automatically unlocked regardless of game progress. This is useful for testing new wallpapers during development.

## Example: Adding a "Rocket" Wallpaper

### Step 1: wallpapers.h

```c
// In enum:
WALLPAPER_SPECIAL_ROCKET,

// In sBoxTitleColors:
[WALLPAPER_SPECIAL_ROCKET] = {RGB(10, 10, 10), RGB_WHITE},

// In sSpecialWallpapers:
[WALLPAPER_SPECIAL_ROCKET - WALLPAPER_SPECIAL_START] = {
    1,                    // Screen pattern
    0,                    // Aqua icon (or add custom)
    RGB(5, 5, 5),         // Dark background (#292929)
    RGB(31, 0, 0)         // Red foreground (#FF0000)
},
```

### Step 2: pokemon_storage_system.c

```c
// In menu enum:
MENU_SPECIAL_ROCKET,

// In AddWallpapersMenu() under your category case:
SetMenuText(MENU_SPECIAL_ROCKET);

// In sMenuOptionTexts:
[MENU_SPECIAL_ROCKET] = gPCText_Rocket,
```

### Step 3: strings.c / strings.h

```c
// strings.c:
const u8 gPCText_Rocket[] = _("ROCKET");

// strings.h:
extern const u8 gPCText_Rocket[];
```

## Adding Custom Icons

To add a new icon:

1. Create a 16x16 4-bit grayscale PNG at:
   `graphics/pokemon_storage/wallpapers/icons/your_icon.png`

2. Add to `src/data/wallpapers.h`:
   ```c
   static const u32 sWallpaperIcon_YourIcon[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/your_icon.4bpp.lz");
   ```

3. Add to `sWaldaWallpaperIcons` array (this determines the icon ID)

4. Update `wallpaper_reference.txt` with the new icon ID

## Japanese Version Asset Limitations

Some pattern graphics and icons are only available in the Japanese version of Pokemon Emerald. Using these assets in the international version may cause:
- The asset not loading properly (appearing blank or corrupted)
- Memory access issues or unexpected behavior

### Affected Patterns

| Pattern | Issue |
|---------|-------|
| Ribbon (ID 5) | The central large ribbon decoration is Japanese-only. The smaller ribbon elements still work. |

### Affected Icons

| Icon ID | Name | Status |
|---------|------|--------|
| 7 | Cross | Japanese-only - may not display correctly |
| 16 | Bolt | Japanese-only - may not display correctly |
| 26 | Plusle | Japanese-only - may not display correctly |

**Recommendation:** Avoid using these assets in custom wallpapers intended for international versions. Test thoroughly if you need to use them.

## Tips

- **Test colors in-game**: GBA color precision is limited; test your wallpapers
- **Contrast matters**: Ensure bg and fg colors have enough contrast for visibility
- **Pattern choice**: Some patterns work better with certain color combinations
- **Icon visibility**: Icons use the foreground color; ensure it contrasts with background
- **Keep names short**: Menu display space is limited (8-10 characters max)

## Troubleshooting

### Wallpaper not appearing
- Verify enum order matches in wallpapers.h and pokemon_storage_system.c
- Check `WALLPAPER_SPECIAL_START` points to the first special wallpaper
- Ensure `WALLPAPER_SPECIAL_COUNT` is calculated correctly

### Wrong colors displayed
- Verify hex to RGB555 conversion (divide by 8, not 255)
- Check that bg/fg colors aren't swapped
- Remember the Walda system only sets 2 colors

### Icon not showing
- Verify icon PNG exists and is 16x16 4-bit grayscale
- Check icon ID is correct (0-29 for existing icons)
- Ensure foreground color contrasts with background

### Build errors
- Check all enum values are unique and sequential
- Verify string declarations match between .c and .h files
- Ensure array indices use correct enum math (e.g., `- WALLPAPER_SPECIAL_START`)
