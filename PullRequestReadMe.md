# Pull Request: Veritas Bugfixes and RS Sprite Improvements

This PR ports several bugfixes and RS-style sprite improvements from Pokemon Emerald Veritas to Emerald Enhanced.

## Note on Redundancy

Some of the assets and code lines included in this PR may already exist in the codebase from other PRs or branches. These are included redundantly here so that this PR can be tested in isolation without depending on those other branches being merged first. When merging, any duplicated definitions can be safely resolved by keeping whichever version already exists.

## Changes

### 1. Acro Bike Reverse Ledge Jump Fix

**Problem:** In the postgame, when the player has the upgraded acro bike with bunny-hop ledge jumping enabled (`FLAG_UNLOCKED_BIKE_SWITCHING`), the reverse jump allowed landing inside walls and on top of NPCs. This happened because the original code only checked if the tile was a ledge, not whether the destination tile (one past the ledge) was actually passable.

**Fix:** Split the ledge jump condition into two checks:

- Normal ledge jumps (direction matches ledge orientation) continue to work as before.
- Reverse bunny-hop jumps now call `GetCollisionAtCoords()` on the landing tile, which checks for walls, NPCs, elevation mismatches, and map borders. The jump is only allowed if the destination returns `COLLISION_NONE`.

**File changed:**

- `src/event_object_movement.c` — `GetLedgeJumpDirection()` function

---

### 2. RS Style Front Trainer Pic Fix

**Problem:** When the player selects the Classic (Ruby/Sapphire) avatar style via `FLAG_PLAYER_STYLE_RS`, the overworld sprites correctly use the RS style, but the front-facing trainer pics in VS cutscene mugshots, Battle Dome tournaments, Pokedex size comparison, and the Hall of Fame always showed the default Emerald style.

**Fix:** Added `FlagGet(FLAG_PLAYER_STYLE_RS)` checks to both trainer pic ID functions. When the flag is set, the functions now return the RS facility class variants (`FACILITY_CLASS_RS_BRENDAN` / `FACILITY_CLASS_RS_MAY`) instead of the default Emerald ones.

**Files changed:**

- `src/pokemon.c` — `PlayerGenderToFrontTrainerPicId()`
- `src/trainer_pokemon_sprites.c` — `PlayerGenderToFrontTrainerPicId_Debug()` (used by Hall of Fame)

**New include added:**

- `src/trainer_pokemon_sprites.c` now includes `event_data.h` for `FlagGet()`

---

### 2b. RS Style Back Sprite Throw Animation Palette Fix

**Problem:** When using RS style, the trainer back sprite shows correct RS colors on the first frame of battle, but the bag turns green (Emerald palette) during the pokeball throwing animation. This happens because `PlayerHandleIntroTrainerBallThrow()` reloads the sprite palette using `gSaveBlock2Ptr->playerGender` (which always indexes to the Emerald palette) instead of using `GetPlayerPreferredBackPicId()` which returns the correct RS back pic ID when `FLAG_PLAYER_STYLE_RS` is set.

**Fix:** Replaced the gender-based palette index with `GetPlayerPreferredBackPicId()` in both the player and recorded player battle controllers.

**Files changed:**

- `src/battle_controller_player.c` — `PlayerHandleIntroTrainerBallThrow()`
- `src/battle_controller_recorded_player.c` — `RecordedPlayerHandleIntroTrainerBallThrow()`

---

### 3. Sprite Weather Tinting Fix

**Problem:** When a sprite's graphics are changed (e.g., the player sprite changes from surfing to walking, or an NPC's appearance updates via script), the palette is reloaded fresh without weather tinting. This causes the sprite to appear unnaturally bright/clear during rain, sandstorm, or other weather conditions until the next full palette update. Also, the object event spawn order could cause issues where new sprites fail to spawn because slots haven't been freed yet.

**Fix:** Two changes in `src/event_object_movement.c`:

1. In `ObjectEventSetGraphics()`: After `UpdateSpritePalette()` reloads a sprite's palette, the fix now calls `UpdateSpritePaletteWithWeather()` to immediately reapply weather tinting (except during fog, which uses a different blending system).
2. In `UpdateObjectEventsForCameraUpdate()`: Swapped the order so `RemoveObjectEventsOutsideView()` runs before `TrySpawnObjectEvents()`, freeing sprite slots before attempting to spawn new ones.

**File changed:**

- `src/event_object_movement.c` — `ObjectEventSetGraphics()` and `UpdateObjectEventsForCameraUpdate()`

---

### 4. Credits Scene RS Sprite Support

**Problem:** During the credits bike scene, the player character always uses the Emerald-style sprite regardless of whether they selected the Classic (RS) avatar style.

**Fix:** Added `FlagGet(FLAG_PLAYER_STYLE_RS)` checks in `LoadBikeScene()` so that RS-style players see their correct RS sprite during credits. The rival character always uses the Emerald style regardless of player choice. This required adding:

- RS sprite sheet data, templates, palette entries, and creation functions in `intro_credits_graphics.c`
- RS sprite graphics assets (PNG source files for Brendan and May)
- Proper extern declarations in headers

**Files changed:**

- `src/credits.c` — `LoadBikeScene()` case 2 now branches on `FLAG_PLAYER_STYLE_RS`
- `src/intro_credits_graphics.c` — Added RS sprite templates, sheet data, palette entries, and `CreateIntroBrendanRSSprite()` / `CreateIntroMayRSSprite()` functions
- `include/intro_credits_graphics.h` — Added RS sprite sheet and function declarations
- `include/graphics.h` — Added RS graphics data externs
- `src/data/graphics/intro_scene.h` — Added RS sprite INCBIN data
- `graphics/intro/rs_graphics/` — Added RS sprite PNG assets (intro2_brendan.png, intro2_may.png)

**New include added:**

- `src/credits.c` now includes `event_data.h` for `FlagGet()`

---

### 5. FLAG_PLAYER_STYLE_RS Definition

**Change:** Repurposed `FLAG_UNUSED_0x296` as `FLAG_PLAYER_STYLE_RS` (value 0x296). This flag controls the player avatar style (0 = Emerald default, 1 = Ruby/Sapphire classic). No save structure change — this reuses an existing unused flag slot.

**File changed:**

- `include/constants/flags.h`

---

### 6. Region Map RS Style Player Icon

**Problem:** The player icon on the region map (both the colored icon in the PokéNav and the grayscale icon shown for secret base locations on the Fly map) always displays the Emerald-style headsprite, even when the player has selected the Classic (RS) avatar style via `FLAG_PLAYER_STYLE_RS`.

**Fix:** Added `FlagGet(FLAG_PLAYER_STYLE_RS)` checks to both icon creation functions. When the RS style is active:

- **Colored icon** (`CreateRegionMapPlayerIcon`): Uses RS tile data and RS palette for the correct colored RS headsprite.
- **Grayscale icon** (`CreateRegionMapPlayerGrayscaleIcon`): Uses dedicated RS grayscale icon assets (auto-generated from RS colored icons with luminance-based grayscale conversion) for correct shading and black borders.

**Files changed:**

- `src/region_map.c` — `CreateRegionMapPlayerIcon()` and `CreateRegionMapPlayerGrayscaleIcon()`, plus RS icon INCBIN data
- `graphics/pokenav/region_map/` — Added RS icon PNG assets (colored and grayscale for Brendan and May)

---

### 7. RS Style Bag Menu Sprite

**Problem:** When the player selects the Classic (Ruby/Sapphire) avatar style via `FLAG_PLAYER_STYLE_RS`, the bag menu always displays the Emerald green/pink bag sprite instead of the original Ruby/Sapphire yellow bag.

**Fix:** Added RS bag sprite assets (male backpack, female fanny pack, and yellow palette) sourced from pokeruby. The `LoadBagMenu_Graphics()` function now checks `FlagGet(FLAG_PLAYER_STYLE_RS)` when loading the bag sprite sheet (case 3) and palette (case 4). Wally's tutorial bag is unaffected — it always uses the Emerald male bag.

**Files changed:**

- `graphics/bag/bag_rs_male.png` — RS yellow backpack sprite (new asset)
- `graphics/bag/bag_rs_female.png` — RS yellow fanny pack sprite (new asset)
- `graphics/bag/bag_rs.pal` — RS yellow/brown palette (new asset)
- `src/graphics.c` — Added INCBIN declarations for RS bag tiles and palette
- `include/graphics.h` — Added extern declarations for RS bag data
- `src/item_menu_icons.c` — Added RS sprite sheet and palette structs
- `include/item_menu_icons.h` — Added extern declarations for RS bag structs
- `src/item_menu.c` — `LoadBagMenu_Graphics()` cases 3+4 branch on RS flag

---

## Summary of All Files Changed

| File                               | Changes                                                                                   |
| ---------------------------------- | ----------------------------------------------------------------------------------------- |
| `include/constants/flags.h`        | Renamed `FLAG_UNUSED_0x296` to `FLAG_PLAYER_STYLE_RS`                                     |
| `src/event_object_movement.c`      | Acro bike collision check, weather tinting fix, spawn order fix                           |
| `src/pokemon.c`                    | RS style check in `PlayerGenderToFrontTrainerPicId()`                                     |
| `src/trainer_pokemon_sprites.c`    | RS style check in `PlayerGenderToFrontTrainerPicId_Debug()`, added `event_data.h` include |
| `src/battle_controller_player.c`   | RS palette fix in throw animation                                                         |
| `src/battle_controller_recorded_player.c` | RS palette fix in recorded battle throw animation                                  |
| `src/credits.c`                    | RS sprite loading in credits scene, added `event_data.h` include                          |
| `src/intro_credits_graphics.c`     | RS sprite templates, sheets, palettes, creation functions, tag constants                  |
| `include/intro_credits_graphics.h` | RS sprite sheet and function declarations                                                 |
| `include/graphics.h`               | RS graphics data extern declarations                                                      |
| `src/data/graphics/intro_scene.h`  | RS sprite INCBIN data                                                                     |
| `graphics/intro/rs_graphics/`      | RS sprite PNG assets (new directory)                                                      |
| `src/region_map.c`                 | RS style checks in player icon functions, RS icon INCBIN data                             |
| `graphics/pokenav/region_map/`     | RS player icon PNGs (colored + grayscale for Brendan and May)                             |
| `graphics/bag/bag_rs_male.png`     | RS yellow backpack sprite (new asset)                                                     |
| `graphics/bag/bag_rs_female.png`   | RS yellow fanny pack sprite (new asset)                                                   |
| `graphics/bag/bag_rs.pal`          | RS yellow/brown palette (new asset)                                                       |
| `src/graphics.c`                   | RS bag INCBIN declarations (in addition to existing RS graphics externs)                   |
| `src/item_menu_icons.c`            | RS bag sprite sheet and palette structs                                                   |
| `include/item_menu_icons.h`        | RS bag struct extern declarations                                                         |
| `src/item_menu.c`                  | RS flag check in `LoadBagMenu_Graphics()` cases 3+4                                       |

---
