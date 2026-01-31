# Random Legendary Title Screen

## Overview

This PR adds a dynamic title screen feature where the legendary Pokemon displayed rotates between Rayquaza, Groudon, and Kyogre based on the player's story progression.

## Feature Description

### Story-Progression Based Selection

The title screen legendary is no longer static. Instead, it unlocks progressively as the player advances through the story:

| Story Progress | Available Legendaries | Selection Method |
|----------------|----------------------|------------------|
| No save file | Rayquaza only | Fixed |
| New game (pre-Magma Hideout) | Rayquaza only | Fixed |
| After Groudon awakens | Rayquaza + Groudon | Random |
| After Kyogre escapes | All three | Random |

### Flag Triggers

The system uses existing story flags to determine progression:

- **`FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT`** (0x6F) - Set when the player witnesses Groudon awakening in Magma Hideout after defeating Maxie
- **`FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN`** (0x81) - Set when Kyogre escapes from Seafloor Cavern after the player defeats Archie

## Technical Implementation

### Files Modified

#### `src/title_screen.c`
- Added `#include "constants/flags.h"` for flag access
- Modified the legendary selection logic in `CB2_InitTitleScreen` (case 0)
- Selection now checks `FlagGet()` for story progression flags
- Random selection uses `Random() % 3` for all three, or `(Random() % 2) ? 2 : 0` for Rayquaza/Groudon only

### New Graphics Added

```
graphics/title_screen/
├── groudon.png
├── groudon_dark.pal
├── groudon_glow.pal
├── groudon_map.bin
├── kyogre.png
├── kyogre_dark.pal
├── kyogre_glow.pal
├── kyogre_map.bin
├── lava_map.bin
├── water_map.bin
└── rubysapphire/
    └── (RS-style variants of above)
```

### Legendary Values

The `sTitleLegendary` variable determines which legendary to display:
- `0` = Rayquaza (default, uses clouds background)
- `1` = Kyogre (uses water overlay background)
- `2` = Groudon (uses lava overlay background)

## Behavior Details

### Save File States

The system respects save file status before checking flags:
- `SAVE_STATUS_OK` - Normal save, check flags
- `SAVE_STATUS_UPDATED` - Updated save format, check flags
- `SAVE_STATUS_ERROR` - Corrupted but readable, check flags
- `SAVE_STATUS_EMPTY` / `SAVE_STATUS_CORRUPT` - No usable save, Rayquaza only

### Randomization

- Selection occurs once per title screen load (in `CB2_InitTitleScreen` case 0)
- Uses the game's built-in `Random()` function
- Player can soft-reset to see different legendaries (if multiple are unlocked)

## Testing

To test all three legendaries without playing through the story:

1. Enable debug mode in `include/debug.h`:
   ```c
   #define TX_DEBUG_SYSTEM_ENABLE TRUE
   ```

2. Add a test script to `data/scripts/debug.inc`:
   ```
   Debug_Script_1::
       lockall
       setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
       setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
       msgbox YourTestText, MSGBOX_DEFAULT
       releaseall
       end
   ```

3. In-game: Hold R + press START to open debug menu, run Script 1
4. Restart the game to see the title screen cycle through all three

**Remember to disable debug before release!**

## Compatibility

- No save file format changes
- No new flags introduced (uses existing story flags)
- Backwards compatible with existing saves
- Players with post-Seafloor saves will immediately have all three legendaries available

## Credits

Feature ported from Pokemon Emerald Veritas by AxolotlOfTruth (Gabriel)
