#include <stdint.h>
#include <stdbool.h>
#include "global.h"
#include "constants/abilities.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "graphics.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "sound.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "safari_zone.h"
#include "battle_anim.h"
#include "data.h"
#include "pokemon_summary_screen.h"
#include "strings.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "battle_setup.h"

struct TestingBar
{
    int32_t maxValue;
    int32_t oldValue;
    int32_t receivedValue;
    uint32_t unkC_0:5;
    uint32_t unk10;
};

enum
{   // Corresponds to gHealthboxElementsGfxTable (and the tables after it) in graphics.c
    // These are indexes into the tables, which are filled with 8x8 square pixel data.
    HEALTHBOX_GFX_0, //hp bar [black section]
    HEALTHBOX_GFX_1, //hp bar "H"
    HEALTHBOX_GFX_2, //hp bar "P"
    HEALTHBOX_GFX_HP_BAR_GREEN, //hp bar [0 pixels]
    HEALTHBOX_GFX_4,  //hp bar [1 pixels]
    HEALTHBOX_GFX_5,  //hp bar [2 pixels]
    HEALTHBOX_GFX_6,  //hp bar [3 pixels]
    HEALTHBOX_GFX_7,  //hp bar [4 pixels]
    HEALTHBOX_GFX_8,  //hp bar [5 pixels]
    HEALTHBOX_GFX_9,  //hp bar [6 pixels]
    HEALTHBOX_GFX_10, //hp bar [7 pixels]
    HEALTHBOX_GFX_11, //hp bar [8 pixels]
    HEALTHBOX_GFX_12, //exp bar [0 pixels]
    HEALTHBOX_GFX_13, //exp bar [1 pixels]
    HEALTHBOX_GFX_14, //exp bar [2 pixels]
    HEALTHBOX_GFX_15, //exp bar [3 pixels]
    HEALTHBOX_GFX_16, //exp bar [4 pixels]
    HEALTHBOX_GFX_17, //exp bar [5 pixels]
    HEALTHBOX_GFX_18, //exp bar [6 pixels]
    HEALTHBOX_GFX_19, //exp bar [7 pixels]
    HEALTHBOX_GFX_20, //exp bar [8 pixels]
    HEALTHBOX_GFX_STATUS_PSN_BATTLER0,  //status psn "(P"
    HEALTHBOX_GFX_22,                   //status psn "SN"
    HEALTHBOX_GFX_23,                   //status psn "|)""
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER0,  //status prz
    HEALTHBOX_GFX_25,
    HEALTHBOX_GFX_26,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER0,  //status slp
    HEALTHBOX_GFX_28,
    HEALTHBOX_GFX_29,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER0,  //status frz
    HEALTHBOX_GFX_31,
    HEALTHBOX_GFX_32,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER0,  //status brn
    HEALTHBOX_GFX_34,
    HEALTHBOX_GFX_35,
    //Overgrow(not a real status)
    HEALTHBOX_GFX_STATUS_OVERGROW_BATTLER0_FIRST_PIXEL_SET,  
    HEALTHBOX_GFX_STATUS_OVERGROW_BATTLER0_SECOND_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_OVERGROW_BATTLER0_THIRD_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_TORRENT_BATTLER0_FIRST_PIXEL_SET,  
    HEALTHBOX_GFX_STATUS_TORRENT_BATTLER0_SECOND_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_TORRENT_BATTLER0_THIRD_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_BLAZE_BATTLER0_FIRST_PIXEL_SET,  
    HEALTHBOX_GFX_STATUS_BLAZE_BATTLER0_SECOND_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_BLAZE_BATTLER0_THIRD_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_SWARM_BATTLER0_FIRST_PIXEL_SET,  
    HEALTHBOX_GFX_STATUS_SWARM_BATTLER0_SECOND_PIXEL_SET,
    HEALTHBOX_GFX_STATUS_SWARM_BATTLER0_THIRD_PIXEL_SET,
    HEALTHBOX_GFX_36, //misc [Black section]
    HEALTHBOX_GFX_37, //misc [Black section]
    HEALTHBOX_GFX_38, //misc [Black section]
    HEALTHBOX_GFX_39, //misc [Blank Health Window?]
    HEALTHBOX_GFX_40, //misc [Blank Health Window?]
    HEALTHBOX_GFX_41, //misc [Blank Health Window?]
    HEALTHBOX_GFX_42, //misc [Blank Health Window?]
    HEALTHBOX_GFX_43, //misc [Top of Health Window?]
    HEALTHBOX_GFX_44, //misc [Top of Health Window?]
    HEALTHBOX_GFX_45, //misc [Top of Health Window?]
    HEALTHBOX_GFX_46, //misc [Blank Health Window?]
    HEALTHBOX_GFX_HP_BAR_YELLOW, //hp bar yellow [0 pixels]
    HEALTHBOX_GFX_48, //hp bar yellow [1 pixels]
    HEALTHBOX_GFX_49, //hp bar yellow [2 pixels]
    HEALTHBOX_GFX_50, //hp bar yellow [3 pixels]
    HEALTHBOX_GFX_51, //hp bar yellow [4 pixels]
    HEALTHBOX_GFX_52, //hp bar yellow [5 pixels]
    HEALTHBOX_GFX_53, //hp bar yellow [6 pixels]
    HEALTHBOX_GFX_54, //hp bar yellow [7 pixels]
    HEALTHBOX_GFX_55, //hp bar yellow [8 pixels]
    HEALTHBOX_GFX_HP_BAR_RED,  //hp bar red [0 pixels]
    HEALTHBOX_GFX_57, //hp bar red [1 pixels]
    HEALTHBOX_GFX_58, //hp bar red [2 pixels]
    HEALTHBOX_GFX_59, //hp bar red [3 pixels]
    HEALTHBOX_GFX_60, //hp bar red [4 pixels]
    HEALTHBOX_GFX_61, //hp bar red [5 pixels]
    HEALTHBOX_GFX_62, //hp bar red [6 pixels]
    HEALTHBOX_GFX_63, //hp bar red [7 pixels]
    HEALTHBOX_GFX_64, //hp bar red [8 pixels]
    HEALTHBOX_GFX_65, //hp bar frame end
    HEALTHBOX_GFX_STATUS_BALL, // Full
    HEALTHBOX_GFX_STATUS_BALL_EMPTY,
    HEALTHBOX_GFX_STATUS_BALL_FAINTED,
    HEALTHBOX_GFX_STATUS_BALL_STATUSED,
    HEALTHBOX_GFX_STATUS_BALL_CAUGHT,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER1, //status2 "PSN"
    HEALTHBOX_GFX_72,
    HEALTHBOX_GFX_73,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER1, //status2 "PRZ"
    HEALTHBOX_GFX_75,
    HEALTHBOX_GFX_76,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER1, //status2 "SLP"
    HEALTHBOX_GFX_78,
    HEALTHBOX_GFX_79,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER1, //status2 "FRZ"
    HEALTHBOX_GFX_81,
    HEALTHBOX_GFX_82,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER1, //status2 "BRN"
    HEALTHBOX_GFX_84,
    HEALTHBOX_GFX_85,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER2, //status3 "PSN"
    HEALTHBOX_GFX_87,
    HEALTHBOX_GFX_88,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER2, //status3 "PRZ"
    HEALTHBOX_GFX_90,
    HEALTHBOX_GFX_91,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER2, //status3 "SLP"
    HEALTHBOX_GFX_93,
    HEALTHBOX_GFX_94,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER2, //status3 "FRZ"
    HEALTHBOX_GFX_96,
    HEALTHBOX_GFX_97,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER2, //status3 "BRN"
    HEALTHBOX_GFX_99,
    HEALTHBOX_GFX_100,
    HEALTHBOX_GFX_STATUS_PSN_BATTLER3, //status4 "PSN"
    HEALTHBOX_GFX_102,
    HEALTHBOX_GFX_103,
    HEALTHBOX_GFX_STATUS_PRZ_BATTLER3, //status4 "PRZ"
    HEALTHBOX_GFX_105,
    HEALTHBOX_GFX_106,
    HEALTHBOX_GFX_STATUS_SLP_BATTLER3, //status4 "SLP"
    HEALTHBOX_GFX_108,
    HEALTHBOX_GFX_109,
    HEALTHBOX_GFX_STATUS_FRZ_BATTLER3, //status4 "FRZ"
    HEALTHBOX_GFX_111,
    HEALTHBOX_GFX_112,
    HEALTHBOX_GFX_STATUS_BRN_BATTLER3, //status4 "BRN"
    HEALTHBOX_GFX_114,
    HEALTHBOX_GFX_115,
    HEALTHBOX_GFX_FRAME_END,
    HEALTHBOX_GFX_FRAME_END_BAR,
};

static const uint8_t *GetHealthboxElementGfxPtr(uint8_t);
static uint8_t *AddTextPrinterAndCreateWindowOnHealthbox(const uint8_t *, uint32_t, uint32_t, uint32_t, uint32_t *);

static void RemoveWindowOnHealthbox(uint32_t windowId);
static void UpdateHpTextInHealthboxInDoubles(uint8_t, int16_t, uint8_t);
static void UpdateStatusIconInHealthbox(uint8_t);

static void TextIntoHealthboxObject(void *, uint8_t *, int32_t);
static void SafariTextIntoHealthboxObject(void *, uint8_t *, uint32_t);
static void HpTextIntoHealthboxObject(void *, uint8_t *, uint32_t);
static void FillHealthboxObject(void *, uint32_t, uint32_t);

static void Task_HidePartyStatusSummary_BattleStart_1(uint8_t);
static void Task_HidePartyStatusSummary_BattleStart_2(uint8_t);
static void Task_HidePartyStatusSummary_DuringBattle(uint8_t);

static void SpriteCB_HealthBoxOther(struct Sprite *);
static void SpriteCB_HealthBar(struct Sprite *);
static void SpriteCB_StatusSummaryBar_Enter(struct Sprite *);
static void SpriteCB_StatusSummaryBar_Exit(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_Enter(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_Exit(struct Sprite *);
static void SpriteCB_StatusSummaryBalls_OnSwitchout(struct Sprite *);

static uint8_t GetStatusIconForBattlerId(uint8_t, uint8_t);
static int32_t CalcNewBarValue(int32_t, int32_t, int32_t, int32_t *, uint8_t, uint16_t);
static uint8_t GetScaledExpFraction(int32_t, int32_t, int32_t, uint8_t);
static void MoveBattleBarGraphically(uint8_t, uint8_t);
static uint8_t CalcBarFilledPixels(int32_t, int32_t, int32_t, int32_t *, uint8_t *, uint8_t);
static void Debug_TestHealthBar_Helper(struct TestingBar *, int32_t *, uint16_t *);

static bool isHPAtOrBelow30Percent(struct Pokemon *mon);

static const struct OamData sOamData_64x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sHealthboxPlayerSpriteTemplates[2] =
{
    {
        .tileTag = TAG_HEALTHBOX_PLAYER1_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = TAG_HEALTHBOX_PLAYER2_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

static const struct SpriteTemplate sHealthboxOpponentSpriteTemplates[2] =
{
    {
        .tileTag = TAG_HEALTHBOX_OPPONENT1_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = TAG_HEALTHBOX_OPPONENT2_TILE,
        .paletteTag = TAG_HEALTHBOX_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

static const struct SpriteTemplate sHealthboxSafariSpriteTemplate =
{
    .tileTag = TAG_HEALTHBOX_SAFARI_TILE,
    .paletteTag = TAG_HEALTHBOX_PAL,
    .oam = &sOamData_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_Healthbar =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sHealthbarSpriteTemplates[MAX_BATTLERS_COUNT] =
{
    {
        .tileTag = TAG_HEALTHBAR_PLAYER1_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    },
    {
        .tileTag = TAG_HEALTHBAR_OPPONENT1_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    },
    {
        .tileTag = TAG_HEALTHBAR_PLAYER2_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    },
    {
        .tileTag = TAG_HEALTHBAR_OPPONENT2_TILE,
        .paletteTag = TAG_HEALTHBAR_PAL,
        .oam = &sOamData_Healthbar,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_HealthBar
    }
};

/*   v-- Origin
[0   +         ][1     ]
[              ][      ]
[              ][      ]
[______________][______]   96x40
[2     ][3     ][4     ]
*/
static const struct Subsprite sUnused_Subsprites_0[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 48,
        .y = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 32,
        .priority = 1
    },
    {
        .x = -16,
        .y = 32,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 48,
        .priority = 1
    },
    {
        .x = 16,
        .y = 32,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 52,
        .priority = 1
    },
    {
        .x = 48,
        .y = 32,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 56,
        .priority = 1
    }
};

// This subsprite table has the same layout as above, but offset by 64 base tiles.
static const struct Subsprite sUnused_Subsprites_2[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 64,
        .priority = 1
    },
    {
        .x = 48,
        .y = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 96,
        .priority = 1
    },
    {
        .x = -16,
        .y = 32,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 112,
        .priority = 1
    },
    {
        .x = 16,
        .y = 32,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 116,
        .priority = 1
    },
    {
        .x = 48,
        .y = 32,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 120,
        .priority = 1
    }
};

/*   v-- Origin
[0   +         ][1     ]
[              ][      ]
[              ][      ]
[              ][      ]   96x32
*/
static const struct Subsprite sUnused_Subsprites_1[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 48,
        .y = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 32,
        .priority = 1
    }
};

// Same as above
static const struct Subsprite sUnused_Subsprites_3[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 48,
        .y = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 32,
        .priority = 1
    }
};

/*  v-- Origin
[0  +  ][1     ]   64x8
*/
static const struct Subsprite sHealthBar_Subsprites_Player[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    }
};

/*       v-- Origin
[]  [0  +  ][1     ]   8x8 + 64x8
2^ ^--- Note 8px space
*/
static const struct Subsprite sHealthBar_Subsprites_Opponent[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = -32,
        .y = 0,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 8,
        .priority = 1
    }
};

static const struct SubspriteTable sUnused_SubspriteTable[] =
{
    {ARRAY_COUNT(sUnused_Subsprites_0), sUnused_Subsprites_0},
    {ARRAY_COUNT(sUnused_Subsprites_1), sUnused_Subsprites_1},
    {ARRAY_COUNT(sUnused_Subsprites_2), sUnused_Subsprites_2},
    {ARRAY_COUNT(sUnused_Subsprites_3), sUnused_Subsprites_3}
};

static const struct SubspriteTable sHealthBar_SubspriteTables[] =
{
    [B_SIDE_PLAYER]   = {ARRAY_COUNT(sHealthBar_Subsprites_Player), sHealthBar_Subsprites_Player},
    [B_SIDE_OPPONENT] = {ARRAY_COUNT(sHealthBar_Subsprites_Opponent), sHealthBar_Subsprites_Opponent}
};
/*                      v-- Origin
[0     ][1     ][2     ][3     ]   128x8
*/
static const struct Subsprite sStatusSummaryBar_Subsprites_Enter[] =
{
    {
        .x = 32 * -3,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 32 * -2,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = 32 * -1,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1
    }
};

/*                      v-- Origin
[0     ][1     ][2     ][3     ][4     ][5     ]   192x8
                 ^-- uses same tiles --^
*/
static const struct Subsprite sStatusSummaryBar_Subsprites_Exit[] =
{
    {
        .x = 32 * -3,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 32 * -2,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = 32 * -1,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 32 * 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 32 * 1,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 32 * 2,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1
    }
};

static const struct SubspriteTable sStatusSummaryBar_SubspriteTable_Enter[] =
{
    {ARRAY_COUNT(sStatusSummaryBar_Subsprites_Enter), sStatusSummaryBar_Subsprites_Enter}
};

static const struct SubspriteTable sStatusSummaryBar_SubspriteTable_Exit[] =
{
    {ARRAY_COUNT(sStatusSummaryBar_Subsprites_Exit), sStatusSummaryBar_Subsprites_Exit}
};

// unused unknown image
static const uint8_t sUnusedStatusSummary[] = INCBIN_U8("graphics/battle_interface/unused_status_summary.4bpp");

static const struct CompressedSpriteSheet sStatusSummaryBarSpriteSheet =
{
    gBattleInterface_BallStatusBarGfx, 0x200, TAG_STATUS_SUMMARY_BAR_TILE
};

static const struct SpritePalette sStatusSummaryBarSpritePal =
{
    gBattleInterface_BallStatusBarPal, TAG_STATUS_SUMMARY_BAR_PAL
};

static const struct SpritePalette sStatusSummaryBallsSpritePal =
{
    gBattleInterface_BallDisplayPal, TAG_STATUS_SUMMARY_BALLS_PAL
};

static const struct SpriteSheet sStatusSummaryBallsSpriteSheet =
{
    &gHealthboxElementsGfxTable[HEALTHBOX_GFX_STATUS_BALL], 0x80, TAG_STATUS_SUMMARY_BALLS_TILE
};

// unused oam data
static const struct OamData sOamData_Unused64x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOamData_StatusSummaryBalls =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sStatusSummaryBarSpriteTemplates[2] =
{
    { // Player
        .tileTag = TAG_STATUS_SUMMARY_BAR_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BAR_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBar_Enter
    },
    { // Opponent
        .tileTag = TAG_STATUS_SUMMARY_BAR_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BAR_PAL,
        .oam = &sOamData_64x32,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBar_Enter
    }
};

static const struct SpriteTemplate sStatusSummaryBallsSpriteTemplates[2] =
{
    {
        .tileTag = TAG_STATUS_SUMMARY_BALLS_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BALLS_PAL,
        .oam = &sOamData_StatusSummaryBalls,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBalls_Enter
    },
    {
        .tileTag = TAG_STATUS_SUMMARY_BALLS_TILE,
        .paletteTag = TAG_STATUS_SUMMARY_BALLS_PAL,
        .oam = &sOamData_StatusSummaryBalls,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_StatusSummaryBalls_Enter
    }
};

static const uint8_t sEmptyWhiteText_GrayHighlight[] = __("{COLOR WHITE}{HIGHLIGHT DARK_GRAY}              ");
static const uint8_t sEmptyWhiteText_TransparentHighlight[] = __("{COLOR WHITE}{HIGHLIGHT TRANSPARENT}              ");

enum
{
    PAL_STATUS_PSN,
    PAL_STATUS_PAR,
    PAL_STATUS_SLP,
    PAL_STATUS_FRZ,
    PAL_STATUS_BRN,
    PAL_STATUS_OVERGROW,
    PAL_STATUS_TORRENT,
    PAL_STATUS_BLAZE,
    PAL_STATUS_SWARM,
};

static const uint16_t sStatusIconColors[] =
{
    [PAL_STATUS_PSN] = RGB(24, 12, 24),
    [PAL_STATUS_PAR] = RGB(23, 23, 3),
    [PAL_STATUS_SLP] = RGB(20, 20, 17),
    [PAL_STATUS_FRZ] = RGB(17, 22, 28),
    [PAL_STATUS_BRN] = RGB(28, 14, 10),
    [PAL_STATUS_OVERGROW] = RGB(23, 23, 3),
    [PAL_STATUS_TORRENT] = RGB(20, 20, 17),
    [PAL_STATUS_BLAZE] = RGB(17, 22, 28),
    [PAL_STATUS_SWARM] = RGB(28, 14, 10),
};

static const struct WindowTemplate sHealthboxWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 8,
    .height = 2,
    .paletteNum = 0,
    .baseBlock = 0
};

static int32_t DummiedOutFunction(int16_t unused1, int16_t unused2, int32_t unused3)
{
    return 9;
}

static void Debug_DrawNumber(int16_t number, uint16_t *dest, bool8 unk)
{
    s8 i, j;
    uint8_t buff[4];

    for (i = 0; i < 4; i++)
        buff[i] = 0;

    for (i = 3; ; i--)
    {
        if (number > 0)
        {
            buff[i] = number % 10;
            number /= 10;
        }
        else
        {
            for (; i > -1; i--)
                buff[i] = 0xFF;

            if (buff[3] == 0xFF)
                buff[3] = 0;
            break;
        }
    }

    if (!unk)
    {
        for (i = 0, j = 0; i < 4; i++)
        {
            if (buff[j] == 0xFF)
            {
                dest[j + 0x00] &= 0xFC00;
                dest[j + 0x00] |= 0x1E;
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x1E;
            }
            else
            {
                dest[j + 0x00] &= 0xFC00;
                dest[j + 0x00] |= 0x14 + buff[j];
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x34 + buff[i];
            }
            j++;
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (buff[i] == 0xFF)
            {
                dest[i + 0x00] &= 0xFC00;
                dest[i + 0x00] |= 0x1E;
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x1E;
            }
            else
            {
                dest[i + 0x00] &= 0xFC00;
                dest[i + 0x00] |= 0x14 + buff[i];
                dest[i + 0x20] &= 0xFC00;
                dest[i + 0x20] |= 0x34 + buff[i];
            }
        }
    }
}

static void UNUSED Debug_DrawNumberPair(int16_t number1, int16_t number2, uint16_t *dest)
{
    dest[4] = 0x1E;
    Debug_DrawNumber(number2, dest, FALSE);
    Debug_DrawNumber(number1, dest + 5, TRUE);
}

// Because the healthbox is too large to fit into one sprite, it is divided into two sprites.
// healthboxLeft  or healthboxMain  is the left part that is used as the 'main' sprite.
// healthboxRight or healthboxOther is the right part of the healthbox.
// There's also the third sprite under name of healthbarSprite that refers to the healthbar visible on the healtbox.

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_HealthBarSpriteId     data[5]
#define hMain_Battler               data[6]
#define hMain_Data7                 data[7]

// data fields for healthboxRight
#define hOther_HealthBoxSpriteId    data[5]

// data fields for healthbar
#define hBar_HealthBoxSpriteId      data[5]
#define hBar_Data6                  data[6]

uint8_t CreateBattlerHealthboxSprites(uint8_t battlerId)
{
    int16_t data6 = 0;
    uint8_t healthboxLeftSpriteId, healthboxRightSpriteId;
    uint8_t healthbarSpriteId;
    struct Sprite *healthBarSpritePtr;

    if (!IsDoubleBattle())
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxPlayerSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.shape = ST_OAM_SQUARE;

            gSprites[healthboxRightSpriteId].oam.shape = ST_OAM_SQUARE;
            gSprites[healthboxRightSpriteId].oam.tileNum += 64;
        }
        else
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxOpponentSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[0], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxRightSpriteId].oam.tileNum += 32;

            data6 = 2;
        }
        gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

        gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
        gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;
    }
    else
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxPlayerSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxPlayerSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

            gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
            gSprites[healthboxRightSpriteId].oam.tileNum += 32;
            gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

            data6 = 1;
        }
        else
        {
            healthboxLeftSpriteId = CreateSprite(&sHealthboxOpponentSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
            healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxOpponentSpriteTemplates[GetBattlerPosition(battlerId) / 2], DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

            gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;

            gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;
            gSprites[healthboxRightSpriteId].oam.tileNum += 32;
            gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

            data6 = 2;
        }
    }

    healthbarSpriteId = CreateSpriteAtEnd(&sHealthbarSpriteTemplates[gBattlerPositions[battlerId]], 140, 60, 0);
    healthBarSpritePtr = &gSprites[healthbarSpriteId];
    SetSubspriteTables(healthBarSpritePtr, &sHealthBar_SubspriteTables[GetBattlerSide(battlerId)]);
    healthBarSpritePtr->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    healthBarSpritePtr->oam.priority = 1;

    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + healthBarSpritePtr->oam.tileNum * TILE_SIZE_4BPP), 64);

    gSprites[healthboxLeftSpriteId].hMain_HealthBarSpriteId = healthbarSpriteId;
    gSprites[healthboxLeftSpriteId].hMain_Battler = battlerId;
    gSprites[healthboxLeftSpriteId].invisible = TRUE;

    gSprites[healthboxRightSpriteId].invisible = TRUE;

    healthBarSpritePtr->hBar_HealthBoxSpriteId = healthboxLeftSpriteId;
    healthBarSpritePtr->hBar_Data6 = data6;
    healthBarSpritePtr->invisible = TRUE;

    return healthboxLeftSpriteId;
}

uint8_t CreateSafariPlayerHealthboxSprites(void)
{
    uint8_t healthboxLeftSpriteId, healthboxRightSpriteId;

    healthboxLeftSpriteId = CreateSprite(&sHealthboxSafariSpriteTemplate, DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);
    healthboxRightSpriteId = CreateSpriteAtEnd(&sHealthboxSafariSpriteTemplate, DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);

    gSprites[healthboxLeftSpriteId].oam.shape = ST_OAM_SQUARE;
    gSprites[healthboxRightSpriteId].oam.shape = ST_OAM_SQUARE;

    gSprites[healthboxRightSpriteId].oam.tileNum += 64;

    gSprites[healthboxLeftSpriteId].oam.affineParam = healthboxRightSpriteId;
    gSprites[healthboxRightSpriteId].hOther_HealthBoxSpriteId = healthboxLeftSpriteId;

    gSprites[healthboxRightSpriteId].callback = SpriteCB_HealthBoxOther;

    return healthboxLeftSpriteId;
}

static const uint8_t *GetHealthboxElementGfxPtr(uint8_t elementId)
{
    return gHealthboxElementsGfxTable[elementId];
}

// Syncs the position of healthbar accordingly with the healthbox.
static void SpriteCB_HealthBar(struct Sprite *sprite)
{
    uint8_t healthboxSpriteId = sprite->hBar_HealthBoxSpriteId;

    switch (sprite->hBar_Data6)
    {
    case 0:
        sprite->x = gSprites[healthboxSpriteId].x + 16;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    case 1:
        sprite->x = gSprites[healthboxSpriteId].x + 16;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    case 2:
    default:
        sprite->x = gSprites[healthboxSpriteId].x + 8;
        sprite->y = gSprites[healthboxSpriteId].y;
        break;
    }

    sprite->x2 = gSprites[healthboxSpriteId].x2;
    sprite->y2 = gSprites[healthboxSpriteId].y2;
}

static void SpriteCB_HealthBoxOther(struct Sprite *sprite)
{
    uint8_t healthboxMainSpriteId = sprite->hOther_HealthBoxSpriteId;

    sprite->x = gSprites[healthboxMainSpriteId].x + 64;
    sprite->y = gSprites[healthboxMainSpriteId].y;

    sprite->x2 = gSprites[healthboxMainSpriteId].x2;
    sprite->y2 = gSprites[healthboxMainSpriteId].y2;
}

void SetBattleBarStruct(uint8_t battlerId, uint8_t healthboxSpriteId, int32_t maxVal, int32_t oldVal, int32_t receivedValue)
{
    gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId = healthboxSpriteId;
    gBattleSpritesDataPtr->battleBars[battlerId].maxValue = maxVal;
    gBattleSpritesDataPtr->battleBars[battlerId].oldValue = oldVal;
    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue = receivedValue;
    gBattleSpritesDataPtr->battleBars[battlerId].currValue = -32768;
}

void SetHealthboxSpriteInvisible(uint8_t healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = TRUE;
    gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId].invisible = TRUE;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = TRUE;
}

void SetHealthboxSpriteVisible(uint8_t healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = FALSE;
    gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId].invisible = FALSE;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = FALSE;
}

static void UpdateSpritePos(uint8_t spriteId, int16_t x, int16_t y)
{
    gSprites[spriteId].x = x;
    gSprites[spriteId].y = y;
}

void DestoryHealthboxSprite(uint8_t healthboxSpriteId)
{
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].oam.affineParam]);
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].hMain_HealthBarSpriteId]);
    DestroySprite(&gSprites[healthboxSpriteId]);
}

void DummyBattleInterfaceFunc(uint8_t healthboxSpriteId, bool8 isDoubleBattleBattlerOnly)
{

}

void UpdateOamPriorityInAllHealthboxes(uint8_t priority)
{
    int32_t i;

    for (i = 0; i < gBattlersCount; i++)
    {
        uint8_t healthboxLeftSpriteId = gHealthboxSpriteIds[i];
        uint8_t healthboxRightSpriteId = gSprites[gHealthboxSpriteIds[i]].oam.affineParam;
        uint8_t healthbarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

        gSprites[healthboxLeftSpriteId].oam.priority = priority;
        gSprites[healthboxRightSpriteId].oam.priority = priority;
        gSprites[healthbarSpriteId].oam.priority = priority;
    }
}

void InitBattlerHealthboxCoords(uint8_t battler)
{
    int16_t x = 0, y = 0;

    if (!IsDoubleBattle())
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            x = 44, y = 30;
        else
            x = 158, y = 88;
    }
    else
    {
        switch (GetBattlerPosition(battler))
        {
        case B_POSITION_PLAYER_LEFT:
            x = 159, y = 76;
            break;
        case B_POSITION_PLAYER_RIGHT:
            x = 171, y = 101;
            break;
        case B_POSITION_OPPONENT_LEFT:
            x = 44, y = 19;
            break;
        case B_POSITION_OPPONENT_RIGHT:
            x = 32, y = 44;
            break;
        }
    }

    UpdateSpritePos(gHealthboxSpriteIds[battler], x, y);
}

static void UpdateLvlInHealthbox(uint8_t healthboxSpriteId, uint8_t lvl)
{
    uint32_t windowId, spriteTileNum;
    uint8_t *windowTileData;
    uint8_t text[16];
    uint32_t xPos;
    uint8_t *objVram;

    text[0] = CHAR_EXTRA_SYMBOL;
    text[1] = CHAR_LV_2;

    objVram = ConvertIntToDecimalStringN(text + 2, lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
    xPos = 5 * (3 - (objVram - (text + 2)));

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, xPos, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;

    if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
    {
        objVram = (void *)(OBJ_VRAM0);
        if (!IsDoubleBattle())
            objVram += spriteTileNum + 0x820;
        else
            objVram += spriteTileNum + 0x420;
    }
    else
    {
        objVram = (void *)(OBJ_VRAM0);
        objVram += spriteTileNum + 0x400;
    }
    TextIntoHealthboxObject(objVram, windowTileData, 3);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateHpTextInHealthbox(uint8_t healthboxSpriteId, int16_t value, uint8_t maxOrCurrent)
{
    uint32_t windowId, spriteTileNum;
    uint8_t *windowTileData;
    uint8_t text[32];
    void *objVram;

    if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER && !IsDoubleBattle())
    {
        spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;
        if (maxOrCurrent != HP_CURRENT) // singles, max
        {
            ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 0, 5, 2, &windowId);
            objVram = (void *)(OBJ_VRAM0);
            objVram += spriteTileNum + 0xB40;
            HpTextIntoHealthboxObject(objVram, windowTileData, 2);
            RemoveWindowOnHealthbox(windowId);
        }
        else // singles, current
        {
            ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text[3] = CHAR_SLASH;
            text[4] = EOS;
            windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 4, 5, 2, &windowId);
            objVram = (void *)(OBJ_VRAM0);
            objVram += spriteTileNum + 0x3E0;
            HpTextIntoHealthboxObject(objVram, windowTileData, 1);
            objVram = (void *)(OBJ_VRAM0);
            objVram += spriteTileNum + 0xB00;
            HpTextIntoHealthboxObject(objVram, windowTileData + 0x20, 2);
            RemoveWindowOnHealthbox(windowId);
        }
    }
    else
    {
        uint8_t battler;

        memcpy(text, sEmptyWhiteText_GrayHighlight, sizeof(sEmptyWhiteText_GrayHighlight));
        battler = gSprites[healthboxSpriteId].hMain_Battler;
        if (IsDoubleBattle() == TRUE || GetBattlerSide(battler) == B_SIDE_OPPONENT)
        {
            UpdateHpTextInHealthboxInDoubles(healthboxSpriteId, value, maxOrCurrent);
        }
        else
        {
            uint32_t var;
            uint8_t i;

            if (GetBattlerSide(gSprites[healthboxSpriteId].data[6]) == B_SIDE_PLAYER)
            {
                if (maxOrCurrent == HP_CURRENT)
                    var = 29;
                else
                    var = 89;
            }
            else
            {
                if (maxOrCurrent == HP_CURRENT)
                    var = 20;
                else
                    var = 48;
            }

            ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            RenderTextHandleBold(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

            for (i = 0; i < 3; i++)
            {
                CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[i * 64 + 32],
                          (void *)((OBJ_VRAM0) + TILE_SIZE_4BPP * (gSprites[healthboxSpriteId].oam.tileNum + var + i)),
                          0x20);
            }
        }
    }
}

static void UpdateHpTextInHealthboxInDoubles(uint8_t healthboxSpriteId, int16_t value, uint8_t maxOrCurrent)
{
    uint32_t windowId, spriteTileNum;
    uint8_t *windowTileData;
    uint8_t text[32];
    void *objVram;

    if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
    {
        if (gBattleSpritesDataPtr->battlerData[gSprites[healthboxSpriteId].data[6]].hpNumbersNoBars) // don't print text if only bars are visible
        {
            spriteTileNum = gSprites[gSprites[healthboxSpriteId].data[5]].oam.tileNum * TILE_SIZE_4BPP;
            objVram = (void *)(OBJ_VRAM0) + spriteTileNum;

            if (maxOrCurrent != HP_CURRENT) // doubles, max hp
            {
                ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
                windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 0, 5, 0, &windowId);
                HpTextIntoHealthboxObject((void *)(OBJ_VRAM0) + spriteTileNum + 0xC0, windowTileData, 2);
                RemoveWindowOnHealthbox(windowId);
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END),
                          (void *)(OBJ_VRAM0 + 0x680) + (gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP),
                           0x20);
            }
            else
            {
                ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
                text[3] = CHAR_SLASH;
                text[4] = EOS;
                windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 4, 5, 0, &windowId);
                FillHealthboxObject(objVram, 0, 3); // Erases HP bar leftover.
                HpTextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x60) + spriteTileNum, windowTileData, 3);
                RemoveWindowOnHealthbox(windowId);
            }
        }
    }
    else
    {
        uint8_t battlerId;

        memcpy(text, sEmptyWhiteText_TransparentHighlight, sizeof(sEmptyWhiteText_TransparentHighlight));
        battlerId = gSprites[healthboxSpriteId].hMain_Battler;

        if (gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars) // don't print text if only bars are visible
        {
            uint8_t var = 4;
            uint8_t r7;
            uint8_t *txtPtr;
            uint8_t i;

            if (maxOrCurrent == HP_CURRENT)
                var = 0;

            r7 = gSprites[healthboxSpriteId].data[5];
            txtPtr = ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            if (!maxOrCurrent)
                StringCopy(txtPtr, gText_Slash);
            RenderTextHandleBold(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

            for (i = var; i < var + 3; i++)
            {
                if (i < 3)
                {
                    CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[((i - var) * 64) + 32],
                          (void *)((OBJ_VRAM0) + 32 * (1 + gSprites[r7].oam.tileNum + i)),
                          0x20);
                }
                else
                {
                    CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[((i - var) * 64) + 32],
                          (void *)((OBJ_VRAM0 + 0x20) + 32 * (i + gSprites[r7].oam.tileNum)),
                          0x20);
                }
            }

            if (maxOrCurrent == HP_CURRENT)
            {
                CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[224],
                          (void *)((OBJ_VRAM0) + ((gSprites[r7].oam.tileNum + 4) * TILE_SIZE_4BPP)),
                          0x20);
                CpuFill32(0, (void *)((OBJ_VRAM0) + (gSprites[r7].oam.tileNum * TILE_SIZE_4BPP)), 0x20);
            }
            else
            {
                if (GetBattlerSide(battlerId) == B_SIDE_PLAYER) // Impossible to reach part, because the battlerId is from the opponent's side.
                {
                    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END),
                          (void *)(OBJ_VRAM0) + ((gSprites[healthboxSpriteId].oam.tileNum + 52) * TILE_SIZE_4BPP),
                           0x20);
                }
            }
        }
    }
}

// Prints mon's nature, catch and flee rate. Probably used to test pokeblock-related features.
static void PrintSafariMonInfo(uint8_t healthboxSpriteId, struct Pokemon *mon)
{
    uint8_t text[20];
    int32_t j, spriteTileNum;
    uint8_t *barFontGfx;
    uint8_t i, var, nature, healthBarSpriteId;

    memcpy(text, sEmptyWhiteText_GrayHighlight, sizeof(sEmptyWhiteText_GrayHighlight));
    barFontGfx = &gMonSpritesGfxPtr->barFontGfx[0x520 + (GetBattlerPosition(gSprites[healthboxSpriteId].hMain_Battler) * 384)];
    var = 5;
    nature = GetNature(mon, FALSE);
    StringCopy(text + 6, gNatureNamePointers[nature]);
    RenderTextHandleBold(barFontGfx, FONT_BOLD, text);

    for (j = 6, i = 0; i < var; i++, j++)
    {
        uint8_t elementId;

        if ((text[j] >= 55 && text[j] <= 74) || (text[j] >= 135 && text[j] <= 154))
            elementId = 44;
        else if ((text[j] >= 75 && text[j] <= 79) || (text[j] >= 155 && text[j] <= 159))
            elementId = 45;
        else
            elementId = 43;

        CpuCopy32(GetHealthboxElementGfxPtr(elementId), barFontGfx + (i * 64), 0x20);
    }

    for (j = 1; j < var + 1; j++)
    {
        spriteTileNum = (gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * TILE_SIZE_4BPP;
        CpuCopy32(barFontGfx, (void *)(OBJ_VRAM0) + (spriteTileNum), 0x20);
        barFontGfx += 0x20;

        spriteTileNum = (8 + gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * TILE_SIZE_4BPP;
        CpuCopy32(barFontGfx, (void *)(OBJ_VRAM0) + (spriteTileNum), 0x20);
        barFontGfx += 0x20;
    }

    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;
    ConvertIntToDecimalStringN(&text[6], gBattleStruct->safariCatchFactor, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(&text[9], gBattleStruct->safariEscapeFactor, STR_CONV_MODE_RIGHT_ALIGN, 2);
    text[5] = CHAR_SPACE;
    text[8] = CHAR_SLASH;
    RenderTextHandleBold(gMonSpritesGfxPtr->barFontGfx, FONT_BOLD, text);

    j = healthBarSpriteId; // Needed to match for some reason.
    for (j = 0; j < 5; j++)
    {
        if (j <= 1)
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[0x40 * j + 0x20],
                      (void *)(OBJ_VRAM0) + (gSprites[healthBarSpriteId].oam.tileNum + 2 + j) * TILE_SIZE_4BPP,
                      32);
        }
        else
        {
            CpuCopy32(&gMonSpritesGfxPtr->barFontGfx[0x40 * j + 0x20],
                      (void *)(OBJ_VRAM0 + 0xC0) + (j + gSprites[healthBarSpriteId].oam.tileNum) * TILE_SIZE_4BPP,
                      32);
        }
    }
}

void SwapHpBarsWithHpText(void)
{
    int32_t i;
    uint8_t healthBarSpriteId;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gSprites[gHealthboxSpriteIds[i]].callback == SpriteCallbackDummy
         && GetBattlerSide(i) != B_SIDE_OPPONENT
         && (IsDoubleBattle() || GetBattlerSide(i) != B_SIDE_PLAYER))
        {
            bool8 noBars;

            gBattleSpritesDataPtr->battlerData[i].hpNumbersNoBars ^= 1;
            noBars = gBattleSpritesDataPtr->battlerData[i].hpNumbersNoBars;
            if (GetBattlerSide(i) == B_SIDE_PLAYER)
            {
                if (!IsDoubleBattle())
                    continue;
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    continue;

                if (noBars == TRUE) // bars to text
                {
                    healthBarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

                    CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 0x100);
                    UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_HP), HP_CURRENT);
                    UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_MAX_HP), HP_MAX);
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthboxSpriteIds[i]);
                    UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gPlayerParty[gBattlerPartyIndexes[i]], HEALTHBOX_HEALTH_BAR);
                    CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_FRAME_END_BAR), (void *)(OBJ_VRAM0 + 0x680 + gSprites[gHealthboxSpriteIds[i]].oam.tileNum * TILE_SIZE_4BPP), 32);
                }
            }
            else
            {
                if (noBars == TRUE) // bars to text
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    {
                        // Most likely a debug function.
                        PrintSafariMonInfo(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]]);
                    }
                    else
                    {
                        healthBarSpriteId = gSprites[gHealthboxSpriteIds[i]].hMain_HealthBarSpriteId;

                        CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * 32), 0x100);
                        UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gEnemyParty[gBattlerPartyIndexes[i]], MON_DATA_HP), HP_CURRENT);
                        UpdateHpTextInHealthboxInDoubles(gHealthboxSpriteIds[i], GetMonData(&gEnemyParty[gBattlerPartyIndexes[i]], MON_DATA_MAX_HP), HP_MAX);
                    }
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthboxSpriteIds[i]);
                    UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]], HEALTHBOX_HEALTH_BAR);
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                        UpdateHealthboxAttribute(gHealthboxSpriteIds[i], &gEnemyParty[gBattlerPartyIndexes[i]], HEALTHBOX_NICK);
                }
            }
            gSprites[gHealthboxSpriteIds[i]].hMain_Data7 ^= 1;
        }
    }
}

#define tBattler                data[0]
#define tSummaryBarSpriteId     data[1]
#define tBallIconSpriteId(n)    data[3 + n]
#define tIsBattleStart          data[10]
#define tBlend                  data[15]

uint8_t CreatePartyStatusSummarySprites(uint8_t battlerId, struct HpAndStatus *partyInfo, bool8 skipPlayer, bool8 isBattleStart)
{
    bool8 isOpponent;
    int16_t bar_X, bar_Y, bar_pos2_X, bar_data0;
    int32_t i, j, var;
    uint8_t summaryBarSpriteId;
    uint8_t ballIconSpritesIds[PARTY_SIZE];
    uint8_t taskId;

    if (!skipPlayer || GetBattlerPosition(battlerId) != B_POSITION_OPPONENT_RIGHT)
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        {
            isOpponent = FALSE;
            bar_X = 136, bar_Y = 96;
            bar_pos2_X = 100;
            bar_data0 = -5;
        }
        else
        {
            isOpponent = TRUE;

            if (!skipPlayer || !IsDoubleBattle())
                bar_X = 104, bar_Y = 40;
            else
                bar_X = 104, bar_Y = 16;

            bar_pos2_X = -100;
            bar_data0 = 5;
        }
    }
    else
    {
        isOpponent = TRUE;
        bar_X = 104, bar_Y = 40;
        bar_pos2_X = -100;
        bar_data0 = 5;
    }

    LoadCompressedSpriteSheetUsingHeap(&sStatusSummaryBarSpriteSheet);
    LoadSpriteSheet(&sStatusSummaryBallsSpriteSheet);
    LoadSpritePalette(&sStatusSummaryBarSpritePal);
    LoadSpritePalette(&sStatusSummaryBallsSpritePal);

    summaryBarSpriteId = CreateSprite(&sStatusSummaryBarSpriteTemplates[isOpponent], bar_X, bar_Y, 10);
    SetSubspriteTables(&gSprites[summaryBarSpriteId], sStatusSummaryBar_SubspriteTable_Enter);
    gSprites[summaryBarSpriteId].x2 = bar_pos2_X;
    gSprites[summaryBarSpriteId].data[0] = bar_data0;

    if (isOpponent)
    {
        gSprites[summaryBarSpriteId].x -= 96;
        gSprites[summaryBarSpriteId].oam.matrixNum = ST_OAM_HFLIP;
    }
    else
    {
        gSprites[summaryBarSpriteId].x += 96;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        ballIconSpritesIds[i] = CreateSpriteAtEnd(&sStatusSummaryBallsSpriteTemplates[isOpponent], bar_X, bar_Y - 4, 9);

        if (!isBattleStart)
            gSprites[ballIconSpritesIds[i]].callback = SpriteCB_StatusSummaryBalls_OnSwitchout;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].x2 = 0;
            gSprites[ballIconSpritesIds[i]].y2 = 0;
        }

        gSprites[ballIconSpritesIds[i]].data[0] = summaryBarSpriteId;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].x += 10 * i + 24;
            gSprites[ballIconSpritesIds[i]].data[1] = i * 7 + 10;
            gSprites[ballIconSpritesIds[i]].x2 = 120;
        }
        else
        {
            gSprites[ballIconSpritesIds[i]].x -= 10 * (5 - i) + 24;
            gSprites[ballIconSpritesIds[i]].data[1] = (6 - i) * 7 + 10;
            gSprites[ballIconSpritesIds[i]].x2 = -120;
        }

        gSprites[ballIconSpritesIds[i]].data[2] = isOpponent;
    }

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (partyInfo[i].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data[7] = 1;
                }
                else if (partyInfo[i].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0)
                {
                    // mon with major status
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
            }
        }
        else
        {
            for (i = 0, var = PARTY_SIZE - 1, j = 0; j < PARTY_SIZE; j++)
            {
                if (partyInfo[j].hp == HP_EMPTY_SLOT)
                {
                     // empty slot or an egg
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data[7] = 1;
                    var--;
                    continue;
                }
                else if (partyInfo[j].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaLostPlayerMons & gBitTable[j])
                {
                    // fainted arena mon
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0)
                {
                    // mon with primary status
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
                i++;
            }
        }
    }
    else
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS))
        {
            for (var = PARTY_SIZE - 1, i = 0; i < PARTY_SIZE; i++)
            {
                if (partyInfo[i].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data[7] = 1;
                }
                else if (partyInfo[i].hp == 0)
                {
                    // fainted mon
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0)
                {
                    // mon with primary status
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 2;
                }
                var--;
            }
        }
        else
        {
            for (var = 0, i = 0, j = 0; j < PARTY_SIZE; j++)
            {
                if (partyInfo[j].hp == HP_EMPTY_SLOT)
                {
                    // empty slot or an egg
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data[7] = 1;
                    i++;
                    continue;
                }
                else if (partyInfo[j].hp == 0)
                {
                     // fainted mon
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaLostOpponentMons & gBitTable[j])
                {
                     // fainted arena mon
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0)
                {
                     // mon with primary status
                    gSprites[ballIconSpritesIds[PARTY_SIZE - 1 - var]].oam.tileNum += 2;
                }
                var++;
            }
        }
    }

    taskId = CreateTask(TaskDummy, 5);
    gTasks[taskId].tBattler = battlerId;
    gTasks[taskId].tSummaryBarSpriteId = summaryBarSpriteId;

    for (i = 0; i < PARTY_SIZE; i++)
        gTasks[taskId].tBallIconSpriteId(i) = ballIconSpritesIds[i];

    gTasks[taskId].tIsBattleStart = isBattleStart;

    if (isBattleStart)
    {
        gBattleSpritesDataPtr->animationData->field_9_x1C++;
    }

    PlaySE12WithPanning(SE_BALL_TRAY_ENTER, 0);
    return taskId;
}

// Slide the party summary tray back offscreen
void Task_HidePartyStatusSummary(uint8_t taskId)
{
    uint8_t ballIconSpriteIds[PARTY_SIZE];
    bool8 isBattleStart;
    uint8_t summaryBarSpriteId;
    uint8_t battlerId;
    int32_t i;

    isBattleStart = gTasks[taskId].tIsBattleStart;
    summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;
    battlerId = gTasks[taskId].tBattler;

    for (i = 0; i < PARTY_SIZE; i++)
        ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));

    gTasks[taskId].tBlend = 16;

    for (i = 0; i < PARTY_SIZE; i++)
        gSprites[ballIconSpriteIds[i]].oam.objMode = ST_OAM_OBJ_BLEND;

    gSprites[summaryBarSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;

    if (isBattleStart)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
            {
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[1] = 7 * i;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[3] = 0;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].data[4] = 0;
                gSprites[ballIconSpriteIds[PARTY_SIZE - 1 - i]].callback = SpriteCB_StatusSummaryBalls_Exit;
            }
            else
            {
                gSprites[ballIconSpriteIds[i]].data[1] = 7 * i;
                gSprites[ballIconSpriteIds[i]].data[3] = 0;
                gSprites[ballIconSpriteIds[i]].data[4] = 0;
                gSprites[ballIconSpriteIds[i]].callback = SpriteCB_StatusSummaryBalls_Exit;
            }
        }
        gSprites[summaryBarSpriteId].data[0] /= 2;
        gSprites[summaryBarSpriteId].data[1] = 0;
        gSprites[summaryBarSpriteId].callback = SpriteCB_StatusSummaryBar_Exit;
        SetSubspriteTables(&gSprites[summaryBarSpriteId], sStatusSummaryBar_SubspriteTable_Exit);
        gTasks[taskId].func = Task_HidePartyStatusSummary_BattleStart_1;
    }
    else
    {
        gTasks[taskId].func = Task_HidePartyStatusSummary_DuringBattle;
    }
}

static void Task_HidePartyStatusSummary_BattleStart_1(uint8_t taskId)
{
    if ((gTasks[taskId].data[11]++ % 2) == 0)
    {
        if (--gTasks[taskId].tBlend < 0)
            return;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
    }
    if (gTasks[taskId].tBlend == 0)
        gTasks[taskId].func = Task_HidePartyStatusSummary_BattleStart_2;
}

static void Task_HidePartyStatusSummary_BattleStart_2(uint8_t taskId)
{
    uint8_t ballIconSpriteIds[PARTY_SIZE];
    int32_t i;

    uint8_t battlerId = gTasks[taskId].tBattler;
    if (--gTasks[taskId].tBlend == -1)
    {
        uint8_t summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;

        for (i = 0; i < PARTY_SIZE; i++)
            ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

        gBattleSpritesDataPtr->animationData->field_9_x1C--;
        if (gBattleSpritesDataPtr->animationData->field_9_x1C == 0)
        {
            DestroySpriteAndFreeResources(&gSprites[summaryBarSpriteId]);
            DestroySpriteAndFreeResources(&gSprites[ballIconSpriteIds[0]]);
        }
        else
        {
            FreeSpriteOamMatrix(&gSprites[summaryBarSpriteId]);
            DestroySprite(&gSprites[summaryBarSpriteId]);
            FreeSpriteOamMatrix(&gSprites[ballIconSpriteIds[0]]);
            DestroySprite(&gSprites[ballIconSpriteIds[0]]);
        }

        for (i = 1; i < PARTY_SIZE; i++)
            DestroySprite(&gSprites[ballIconSpriteIds[i]]);
    }
    else if (gTasks[taskId].tBlend == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[battlerId].partyStatusSummaryShown = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

static void Task_HidePartyStatusSummary_DuringBattle(uint8_t taskId)
{
    uint8_t ballIconSpriteIds[PARTY_SIZE];
    int32_t i;
    uint8_t battlerId = gTasks[taskId].tBattler;

    if (--gTasks[taskId].tBlend >= 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
    }
    else if (gTasks[taskId].tBlend == -1)
    {
        uint8_t summaryBarSpriteId = gTasks[taskId].tSummaryBarSpriteId;

        for (i = 0; i < PARTY_SIZE; i++)
            ballIconSpriteIds[i] = gTasks[taskId].tBallIconSpriteId(i);

        DestroySpriteAndFreeResources(&gSprites[summaryBarSpriteId]);
        DestroySpriteAndFreeResources(&gSprites[ballIconSpriteIds[0]]);

        for (i = 1; i < PARTY_SIZE; i++)
            DestroySprite(&gSprites[ballIconSpriteIds[i]]);
    }
    else if (gTasks[taskId].tBlend == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[battlerId].partyStatusSummaryShown = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

#undef tBattler
#undef tSummaryBarSpriteId
#undef tBallIconSpriteId
#undef tIsBattleStart
#undef tBlend

static void SpriteCB_StatusSummaryBar_Enter(struct Sprite *sprite)
{
    if (sprite->x2 != 0)
        sprite->x2 += sprite->data[0];
}

static void SpriteCB_StatusSummaryBar_Exit(struct Sprite *sprite)
{
    sprite->data[1] += 32;
    if (sprite->data[0] > 0)
        sprite->x2 += sprite->data[1] >> 4;
    else
        sprite->x2 -= sprite->data[1] >> 4;
    sprite->data[1] &= 0xF;
}

static void SpriteCB_StatusSummaryBalls_Enter(struct Sprite *sprite)
{
    uint8_t var1;
    uint16_t var2;
    s8 pan;

    if (sprite->data[1] > 0)
    {
        sprite->data[1]--;
        return;
    }

    var1 = sprite->data[2];
    var2 = sprite->data[3];
    var2 += 56;
    sprite->data[3] = var2 & 0xFFF0;

    if (var1 != 0)
    {
        sprite->x2 += var2 >> 4;
        if (sprite->x2 > 0)
            sprite->x2 = 0;
    }
    else
    {
        sprite->x2 -= var2 >> 4;
        if (sprite->x2 < 0)
            sprite->x2 = 0;
    }

    if (sprite->x2 == 0)
    {
        pan = SOUND_PAN_TARGET;
        if (var1 != 0)
            pan = SOUND_PAN_ATTACKER;

        if (sprite->data[7] != 0)
            PlaySE2WithPanning(SE_BALL_TRAY_EXIT, pan);
        else
            PlaySE1WithPanning(SE_BALL_TRAY_BALL, pan);

        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBalls_Exit(struct Sprite *sprite)
{
    uint8_t var1;
    uint16_t var2;

    if (sprite->data[1] > 0)
    {
        sprite->data[1]--;
        return;
    }
    var1 = sprite->data[2];
    var2 = sprite->data[3];
    var2 += 56;
    sprite->data[3] = var2 & 0xFFF0;
    if (var1 != 0)
        sprite->x2 += var2 >> 4;
    else
        sprite->x2 -= var2 >> 4;
    if (sprite->x2 + sprite->x > 248
     || sprite->x2 + sprite->x < -8)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_StatusSummaryBalls_OnSwitchout(struct Sprite *sprite)
{
    uint8_t barSpriteId = sprite->data[0];

    sprite->x2 = gSprites[barSpriteId].x2;
    sprite->y2 = gSprites[barSpriteId].y2;
}

static void UpdateNickInHealthbox(uint8_t healthboxSpriteId, struct Pokemon *mon)
{
    uint8_t nickname[POKEMON_NAME_LENGTH + 1];
    void *ptr;
    uint32_t windowId, spriteTileNum;
    uint8_t *windowTileData;
    uint16_t species;
    uint8_t gender;

    StringCopy(gDisplayedStringBattle, gText_HealthboxNickname);
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    StringGet_Nickname(nickname);
    ptr = StringAppend(gDisplayedStringBattle, nickname);

    gender = GetMonGender(mon);
    species = GetMonData(mon, MON_DATA_SPECIES);

    if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && StringCompare(nickname, gSpeciesNames[species]) == 0)
        gender = 100;

    // AddTextPrinterAndCreateWindowOnHealthbox's arguments are the same in all 3 cases.
    // It's possible they may have been different in early development phases.
    switch (gender)
    {
    default:
        StringCopy(ptr, gText_HealthboxGender_None);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    case MON_MALE:
        StringCopy(ptr, gText_HealthboxGender_Male);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    case MON_FEMALE:
        StringCopy(ptr, gText_HealthboxGender_Female);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    }

    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;

    if (GetBattlerSide(gSprites[healthboxSpriteId].data[6]) == B_SIDE_PLAYER)
    {
        TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x40 + spriteTileNum), windowTileData, 6);
        ptr = (void *)(OBJ_VRAM0);
        if (!IsDoubleBattle())
            ptr += spriteTileNum + 0x800;
        else
            ptr += spriteTileNum + 0x400;
        TextIntoHealthboxObject(ptr, windowTileData + 0xC0, 1);
    }
    else
    {
        TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x20 + spriteTileNum), windowTileData, 7);
    }

    RemoveWindowOnHealthbox(windowId);
}

static void TryAddPokeballIconToHealthbox(uint8_t healthboxSpriteId, bool8 noStatus)
{
    uint8_t battlerId, healthBarSpriteId;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
        return;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return;

    battlerId = gSprites[healthboxSpriteId].hMain_Battler;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return;
    if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES)), FLAG_GET_CAUGHT))
        return;

    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;

    if (noStatus)
        CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_BALL_CAUGHT), (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 8) * TILE_SIZE_4BPP), 32);
    else
        CpuFill32(0, (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 8) * TILE_SIZE_4BPP), 32);
}

static void UpdateStatusIconInHealthbox(uint8_t healthboxSpriteId)
{
    int32_t i;
    uint8_t battlerId, healthBarSpriteId;
    uint32_t status, pltAdder;
    const uint8_t *statusGfxPtr;
    int16_t tileNumAdder;
    uint8_t statusPalId;
    struct Pokemon *mon; // So we can use this later
    uint16_t ability;

    battlerId = gSprites[healthboxSpriteId].hMain_Battler;
    ability = gBattleMons[battlerId].ability;
    healthBarSpriteId = gSprites[healthboxSpriteId].hMain_HealthBarSpriteId;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
    {
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
        status = GetMonData(mon, MON_DATA_STATUS);

        if (!IsDoubleBattle())
            tileNumAdder = 0x1A;
        else
            tileNumAdder = 0x12;
    }
    else
    {
        status = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_STATUS);
        tileNumAdder = 0x11;
    }    

    if (status & STATUS1_SLEEP)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_SLP_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_SLP;
    }
    else if (status & STATUS1_PSN_ANY)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_PSN_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_PSN;
    }
    else if (status & STATUS1_BURN)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_BRN_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_BRN;
    }
    else if (status & STATUS1_FREEZE)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_FRZ_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_FRZ;
    }
    else if (status & STATUS1_PARALYSIS)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBattlerId(HEALTHBOX_GFX_STATUS_PRZ_BATTLER0, battlerId));
        statusPalId = PAL_STATUS_PAR;
    }

    // else if hp is at 30% or below
    // Right now we only want to test it on the players pokemon
    else if ((ability == ABILITY_OVERGROW || ability == ABILITY_TORRENT || ability == ABILITY_BLAZE || ability == ABILITY_SWARM) && battlerId == 0)
    {
        if (isHPAtOrBelow30Percent(mon))
        {
            switch(ability)
            {
                case ABILITY_OVERGROW:
                    statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_OVERGROW_BATTLER0_FIRST_PIXEL_SET);
                    statusPalId = PAL_STATUS_OVERGROW;
                    break;

                case ABILITY_BLAZE:
                    statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_BLAZE_BATTLER0_FIRST_PIXEL_SET);
                    statusPalId = PAL_STATUS_BLAZE;
                    break;

                case ABILITY_TORRENT:
                    statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_TORRENT_BATTLER0_FIRST_PIXEL_SET);
                    statusPalId = PAL_STATUS_TORRENT;
                    break;

                case ABILITY_SWARM:
                    statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_STATUS_SWARM_BATTLER0_FIRST_PIXEL_SET);
                    statusPalId = PAL_STATUS_SWARM;
                    break;

                default:
                    break;
            }
        }

        else
        {
            statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_39);

            for (i = 0; i < 3; i++)
            CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder + i) * TILE_SIZE_4BPP), 32);

            if (!gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars)
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 64);

            TryAddPokeballIconToHealthbox(healthboxSpriteId, TRUE);
            return;
        }
        
    }
    

    else
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(HEALTHBOX_GFX_39);

        for (i = 0; i < 3; i++)
            CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder + i) * TILE_SIZE_4BPP), 32);

        if (!gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars)
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_1), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 64);

        TryAddPokeballIconToHealthbox(healthboxSpriteId, TRUE);
        return;
    }

    pltAdder = PLTT_ID(gSprites[healthboxSpriteId].oam.paletteNum);
    pltAdder += battlerId + 12;

    FillPalette(sStatusIconColors[statusPalId], OBJ_PLTT_OFFSET + pltAdder, PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[OBJ_PLTT_OFFSET + pltAdder], (uint16_t *)OBJ_PLTT + pltAdder, PLTT_SIZEOF(1));
    CpuCopy32(statusGfxPtr, (void *)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder) * TILE_SIZE_4BPP), 96);

    if (IsDoubleBattle() == TRUE || GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
    {
        if (!gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars)
        {
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_0), (void *)(OBJ_VRAM0 + gSprites[healthBarSpriteId].oam.tileNum * TILE_SIZE_4BPP), 32);
            CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_65), (void *)(OBJ_VRAM0 + (gSprites[healthBarSpriteId].oam.tileNum + 1) * TILE_SIZE_4BPP), 32);
        }
    }
    TryAddPokeballIconToHealthbox(healthboxSpriteId, FALSE);
}

static uint8_t GetStatusIconForBattlerId(uint8_t statusElementId, uint8_t battlerId)
{
    uint8_t ret = statusElementId;

    switch (statusElementId)
    {
    case HEALTHBOX_GFX_STATUS_PSN_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_PSN_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_PRZ_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_PRZ_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_SLP_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_SLP_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_FRZ_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_FRZ_BATTLER3;
        break;
    case HEALTHBOX_GFX_STATUS_BRN_BATTLER0:
        if (battlerId == 0)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER0;
        else if (battlerId == 1)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER1;
        else if (battlerId == 2)
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER2;
        else
            ret = HEALTHBOX_GFX_STATUS_BRN_BATTLER3;
        break;

    }
    return ret;
}

static void UpdateSafariBallsTextOnHealthbox(uint8_t healthboxSpriteId)
{
    uint32_t windowId, spriteTileNum;
    uint8_t *windowTileData;

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gText_SafariBalls, 0, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;
    TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x40) + spriteTileNum, windowTileData, 6);
    TextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x800) + spriteTileNum, windowTileData + 0xC0, 2);
    RemoveWindowOnHealthbox(windowId);
}

static void UpdateLeftNoOfBallsTextOnHealthbox(uint8_t healthboxSpriteId)
{
    uint8_t text[16];
    uint8_t *txtPtr;
    uint32_t windowId, spriteTileNum;
    uint8_t *windowTileData;

    txtPtr = StringCopy(text, gText_SafariBallLeft);
    ConvertIntToDecimalStringN(txtPtr, gNumSafariBalls, STR_CONV_MODE_LEFT_ALIGN, 2);

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, GetStringRightAlignXOffset(FONT_SMALL, text, 0x2F), 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * TILE_SIZE_4BPP;
    SafariTextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0x2C0) + spriteTileNum, windowTileData, 2);
    SafariTextIntoHealthboxObject((void *)(OBJ_VRAM0 + 0xA00) + spriteTileNum, windowTileData + 0x40, 4);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateHealthboxAttribute(uint8_t healthboxSpriteId, struct Pokemon *mon, uint8_t elementId)
{
    int32_t maxHp, currHp;
    uint8_t battlerId = gSprites[healthboxSpriteId].hMain_Battler;

    if (elementId == HEALTHBOX_ALL && !IsDoubleBattle())
        GetBattlerSide(battlerId); // Pointless function call.

    if (GetBattlerSide(gSprites[healthboxSpriteId].hMain_Battler) == B_SIDE_PLAYER)
    {
        uint8_t isDoubles;

        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_CURRENT_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_HP), HP_CURRENT);
        if (elementId == HEALTHBOX_MAX_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_MAX_HP), HP_MAX);
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(battlerId, healthboxSpriteId, maxHp, currHp, 0);
            MoveBattleBar(battlerId, healthboxSpriteId, HEALTH_BAR, 0);
        }
        isDoubles = IsDoubleBattle();
        if (!isDoubles && (elementId == HEALTHBOX_EXP_BAR || elementId == HEALTHBOX_ALL))
        {
            uint16_t species;
            uint32_t exp, currLevelExp;
            int32_t currExpBarValue, maxExpBarValue;
            uint8_t level;

            LoadBattleBarGfx(3);
            species = GetMonData(mon, MON_DATA_SPECIES);
            level = GetMonData(mon, MON_DATA_LEVEL);
            exp = GetMonData(mon, MON_DATA_EXP);
            currLevelExp = gExperienceTables[gSpeciesInfo[species].growthRate][level];
            currExpBarValue = exp - currLevelExp;
            maxExpBarValue = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1] - currLevelExp;
            SetBattleBarStruct(battlerId, healthboxSpriteId, maxExpBarValue, currExpBarValue, isDoubles);
            MoveBattleBar(battlerId, healthboxSpriteId, EXP_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT)
            UpdateSafariBallsTextOnHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT || elementId == HEALTHBOX_SAFARI_BALLS_TEXT)
            UpdateLeftNoOfBallsTextOnHealthbox(healthboxSpriteId);
    }
    else
    {
        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(battlerId, healthboxSpriteId, maxHp, currHp, 0);
            MoveBattleBar(battlerId, healthboxSpriteId, HEALTH_BAR, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
    }
}

#define B_EXPBAR_PIXELS 64
#define B_HEALTHBAR_PIXELS 48

int32_t MoveBattleBar(uint8_t battlerId, uint8_t healthboxSpriteId, uint8_t whichBar, uint8_t unused)
{
    int32_t currentBarValue;

    if (whichBar == HEALTH_BAR) // health bar
    {
        currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                    B_HEALTHBAR_PIXELS / 8, 1);
    }
    else // exp bar
    {
        uint16_t expFraction = GetScaledExpFraction(gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].maxValue, 8);
        if (expFraction == 0)
            expFraction = 1;
        expFraction = abs(gBattleSpritesDataPtr->battleBars[battlerId].receivedValue / expFraction);

        currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                    B_EXPBAR_PIXELS / 8, expFraction);
    }

    if (whichBar == EXP_BAR || (whichBar == HEALTH_BAR && !gBattleSpritesDataPtr->battlerData[battlerId].hpNumbersNoBars))
        MoveBattleBarGraphically(battlerId, whichBar);

    if (currentBarValue == -1)
        gBattleSpritesDataPtr->battleBars[battlerId].currValue = 0;

    return currentBarValue;
}

static void MoveBattleBarGraphically(uint8_t battlerId, uint8_t whichBar)
{
    uint8_t array[8];
    uint8_t filledPixelsCount, level;
    uint8_t barElementId;
    uint8_t i;

    switch (whichBar)
    {
    case HEALTH_BAR:
        filledPixelsCount = CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                            gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                            gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                            &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                            array, B_HEALTHBAR_PIXELS / 8);

        if (filledPixelsCount > (B_HEALTHBAR_PIXELS * 50 / 100)) // more than 50 % hp
            barElementId = HEALTHBOX_GFX_HP_BAR_GREEN;
        else if (filledPixelsCount > (B_HEALTHBAR_PIXELS * 20 / 100)) // more than 20% hp
            barElementId = HEALTHBOX_GFX_HP_BAR_YELLOW;
        else
            barElementId = HEALTHBOX_GFX_HP_BAR_RED; // 20 % or less

        for (i = 0; i < 6; i++)
        {
            uint8_t healthbarSpriteId = gSprites[gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId].hMain_HealthBarSpriteId;
            if (i < 2)
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + (gSprites[healthbarSpriteId].oam.tileNum + 2 + i) * TILE_SIZE_4BPP), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(barElementId) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + 64 + (i + gSprites[healthbarSpriteId].oam.tileNum) * TILE_SIZE_4BPP), 32);
        }
        break;
    case EXP_BAR:
        CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                    &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                    array, B_EXPBAR_PIXELS / 8);
        level = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_LEVEL);
        if (level == MAX_LEVEL || levelCappedNuzlocke(level))
        {
            for (i = 0; i < 8; i++)
                array[i] = 0;
        }
        for (i = 0; i < 8; i++)
        {
            if (i < 4)
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + (gSprites[gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId].oam.tileNum + 0x24 + i) * TILE_SIZE_4BPP), 32);
            else
                CpuCopy32(GetHealthboxElementGfxPtr(HEALTHBOX_GFX_12) + array[i] * 32,
                          (void *)(OBJ_VRAM0 + 0xB80 + (i + gSprites[gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId].oam.tileNum) * TILE_SIZE_4BPP), 32);
        }
        break;
    }
}

static int32_t CalcNewBarValue(int32_t maxValue, int32_t oldValue, int32_t receivedValue, int32_t *currValue, uint8_t scale, uint16_t toAdd)
{
    int32_t ret, newValue;
    scale *= 8;

    if (*currValue == -32768) // first function call
    {
        if (maxValue < scale)
            *currValue = Q_24_8(oldValue);
        else
            *currValue = oldValue;
    }

    newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    if (maxValue < scale)
    {
        if (newValue == Q_24_8_TO_INT(*currValue) && (*currValue & 0xFF) == 0)
            return -1;
    }
    else
    {
        if (newValue == *currValue) // we're done, the bar's value has been updated
            return -1;
    }

    if (maxValue < scale) // handle cases of max var having less pixels than the whole bar
    {
        int32_t toAdd = Q_24_8(maxValue) / scale;

        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            if (ret >= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
        else // move bar left
        {
            *currValue -= toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            // try round up
            if ((*currValue & 0xFF) > 0)
                ret++;
            if (ret <= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
    }
    else
    {
        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            if (*currValue > newValue)
                *currValue = newValue;
            ret = *currValue;
        }
        else // move bar left
        {
            *currValue -= toAdd;
            if (*currValue < newValue)
                *currValue = newValue;
            ret = *currValue;
        }
    }

    return ret;
}

static uint8_t CalcBarFilledPixels(int32_t maxValue, int32_t oldValue, int32_t receivedValue, int32_t *currValue, uint8_t *pixelsArray, uint8_t scale)
{
    uint8_t pixels, filledPixels, totalPixels;
    uint8_t i;

    int32_t newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    totalPixels = scale * 8;

    for (i = 0; i < scale; i++)
        pixelsArray[i] = 0;

    if (maxValue < totalPixels)
        pixels = (*currValue * totalPixels / maxValue) >> 8;
    else
        pixels = *currValue * totalPixels / maxValue;

    filledPixels = pixels;

    if (filledPixels == 0 && newValue > 0)
    {
        pixelsArray[0] = 1;
        filledPixels = 1;
    }
    else
    {
        for (i = 0; i < scale; i++)
        {
            if (pixels >= 8)
            {
                pixelsArray[i] = 8;
            }
            else
            {
                pixelsArray[i] = pixels;
                break;
            }
            pixels -= 8;
        }
    }

    return filledPixels;
}

// These two functions seem as if they were made for testing the health bar.
static int16_t UNUSED Debug_TestHealthBar(struct TestingBar *barInfo, int32_t *currValue, uint16_t *dest, int32_t unused)
{
    int16_t ret, var;

    ret = CalcNewBarValue(barInfo->maxValue,
                    barInfo->oldValue,
                    barInfo->receivedValue,
                    currValue, B_HEALTHBAR_PIXELS / 8, 1);
    Debug_TestHealthBar_Helper(barInfo, currValue, dest);

    if (barInfo->maxValue < B_HEALTHBAR_PIXELS)
        var = *currValue >> 8;
    else
        var = *currValue;

    DummiedOutFunction(barInfo->maxValue, var, unused);

    return ret;
}

static void Debug_TestHealthBar_Helper(struct TestingBar *barInfo, int32_t *currValue, uint16_t *dest)
{
    uint8_t pixels[6];
    uint16_t src[6];
    uint8_t i;

    CalcBarFilledPixels(barInfo->maxValue, barInfo->oldValue,
                barInfo->receivedValue, currValue, pixels, B_HEALTHBAR_PIXELS / 8);

    for (i = 0; i < 6; i++)
        src[i] = (barInfo->unkC_0 << 12) | (barInfo->unk10 + pixels[i]);

    CpuCopy16(src, dest, sizeof(src));
}

static uint8_t GetScaledExpFraction(int32_t oldValue, int32_t receivedValue, int32_t maxValue, uint8_t scale)
{
    int32_t newVal, result;
    s8 oldToMax, newToMax;

    scale *= 8;
    newVal = oldValue - receivedValue;

    if (newVal < 0)
        newVal = 0;
    else if (newVal > maxValue)
        newVal = maxValue;

    oldToMax = oldValue * scale / maxValue;
    newToMax = newVal * scale / maxValue;
    result = oldToMax - newToMax;

    return abs(result);
}

uint8_t GetScaledHPFraction(int16_t hp, int16_t maxhp, uint8_t scale)
{
    uint8_t result = hp * scale / maxhp;

    if (result == 0 && hp > 0)
        return 1;

    return result;
}

bool isHPAtOrBelow30Percent(struct Pokemon *mon)
{
    uint16_t hp = GetMonData(mon, MON_DATA_HP);
    uint16_t maxHp = GetMonData(mon, MON_DATA_MAX_HP);

    if (hp == maxHp)
    {
        return false;
    }
    else
    {
        uint8_t fraction = GetScaledHPFraction(hp, maxHp, B_HEALTHBAR_PIXELS);

        if (fraction > (B_HEALTHBAR_PIXELS * 30 / 100)) // more than 30 % hp
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
}

uint8_t GetHPBarLevel(int16_t hp, int16_t maxhp)
{
    uint8_t result;

    if (hp == maxhp)
    {
        result = HP_BAR_FULL;
    }
    else
    {
        uint8_t fraction = GetScaledHPFraction(hp, maxhp, B_HEALTHBAR_PIXELS);
        if (fraction > (B_HEALTHBAR_PIXELS * 50 / 100)) // more than 50 % hp
            result = HP_BAR_GREEN;
        else if (fraction > (B_HEALTHBAR_PIXELS * 20 / 100)) // more than 20% hp
            result = HP_BAR_YELLOW;
        else if (fraction > 0)
            result = HP_BAR_RED;
        else
            result = HP_BAR_EMPTY;
    }

    return result;
}

static uint8_t *AddTextPrinterAndCreateWindowOnHealthbox(const uint8_t *str, uint32_t x, uint32_t y, uint32_t bgColor, uint32_t *windowId)
{
    uint16_t winId;
    uint8_t color[3];
    struct WindowTemplate winTemplate = sHealthboxWindowTemplate;

    winId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(winId, PIXEL_FILL(bgColor));

    color[0] = bgColor;
    color[1] = 1;
    color[2] = 3;

    AddTextPrinterParameterized4(winId, FONT_SMALL, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);

    *windowId = winId;
    return (uint8_t *)(GetWindowAttribute(winId, WINDOW_TILE_DATA));
}

static void RemoveWindowOnHealthbox(uint32_t windowId)
{
    RemoveWindow(windowId);
}

static void FillHealthboxObject(void *dest, uint32_t valMult, uint32_t numTiles)
{
    CpuFill32(0x11111111 * valMult, dest, numTiles * TILE_SIZE_4BPP);
}

static void HpTextIntoHealthboxObject(void *dest, uint8_t *windowTileData, uint32_t windowWidth)
{
    CpuCopy32(windowTileData + 256, dest, windowWidth * TILE_SIZE_4BPP);
}

static void TextIntoHealthboxObject(void *dest, uint8_t *windowTileData, int32_t windowWidth)
{
    CpuCopy32(windowTileData + 256, dest + 256, windowWidth * TILE_SIZE_4BPP);
// + 256 as that prevents the top 4 blank rows of sHealthboxWindowTemplate from being copied
    if (windowWidth > 0)
    {
        do
        {
            CpuCopy32(windowTileData + 20, dest + 20, 12);
            dest += 32, windowTileData += 32;
            windowWidth--;
        } while (windowWidth != 0);
    }
}

static void SafariTextIntoHealthboxObject(void *dest, uint8_t *windowTileData, uint32_t windowWidth)
{
    CpuCopy32(windowTileData, dest, windowWidth * TILE_SIZE_4BPP);
    CpuCopy32(windowTileData + 256, dest + 256, windowWidth * TILE_SIZE_4BPP);
}
