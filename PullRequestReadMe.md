# Randomized Intro Animation

This PR adds a randomized intro sequence that varies each time the game starts, bringing back elements from Ruby and Sapphire while maintaining Emerald's identity.

## Feature Overview

The intro now randomly selects between three different styles with equal probability (33% each):

| Style | Legendary | Scene | Player Sprites |
|-------|-----------|-------|----------------|
| **Emerald** | Flygon | Forest scenery | Emerald Brendan/May (50/50) |
| **Ruby** | Latios | Ocean scenery | RS Brendan/May (50/50) |
| **Sapphire** | Latias | Ocean scenery | RS Brendan/May (50/50) |

This gives 12 different possible animations.

## How It Works

1. **RTC-Based Randomness**: Uses `RtcGetMinuteCount()` to get a value that changes every minute
2. **Separate from Game RNG**: The `GetIntroRtcRandom()` function is cloned from the BUGFIX `SeedRngWithRtc` but returns a value instead of seeding the game RNG
3. **Style Selection**: `sIntroStyle = rtcRandom % 3` determines which legendary and background to use
4. **Player Selection**: `(rtcRandom / 3) % 2` determines which player sprite variant appears

This approach ensures the intro animation changes every minute while preserving RNG manipulation compatibility for speedrunners and challenge players - the game's main RNG remains completely untouched.

## Technical Changes

### Files Modified
- `src/intro.c` - Intro style selection logic and sprite loading
- `src/intro_credits_graphics.c` - RS player sprites, Latios/Latias sprite definitions
- `src/data/graphics/intro_scene.h` - INCBIN declarations for RS graphics
- `include/intro_credits_graphics.h` - Function declarations
- `include/graphics.h` - Extern declarations for RS sprites

### Files Added
- `graphics/intro/rs_graphics/` - RS-style intro graphics including:
  - `intro2_brendan.png`, `intro2_may.png` (RS player sprites)
  - `intro2_latios.png`, `intro2_latias.png` (Lati sprites with corrected palettes)
  - Background and cloud assets for ocean scenery

---
