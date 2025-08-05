#include "global.h"
#include "option_plus_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "event_data.h"
#include "overworld.h"

enum
{
    MENU_MAIN,
    MENU_BATTLE,
    MENU_WORLD,
    MENU_SURF,
    MENU_COUNT,
};

// Menu items
enum
{
    MENUITEM_MAIN_TEXTSPEED,
    MENUITEM_MAIN_SOUND,
    MENUITEM_MAIN_BUTTONMODE,
    MENUITEM_MAIN_FRAMETYPE,
    MENUITEM_CUSTOM_FONT,
    MENUITEM_MAIN_STAT_EDITOR,
    MENUITEM_MAIN_NICKNAME,
    MENUITEM_MAIN_CANCEL,
    MENUITEM_MAIN_COUNT,
};

// Battle Menu Items
enum
{
    MENUITEM_BATTLE_HARDMODE,
    MENUITEM_MAIN_BATTLESCENE,
    MENUITEM_MAIN_BATTLESTYLE,
    MENUITEM_CUSTOM_HP_BAR,
    MENUITEM_CUSTOM_EXP_BAR,
    MENUITEM_BATTLE_ITEMANIMATE,
    MENUITEM_BATTLE_TYPEEFFECT,
    MENUITEM_BATTLE_CANCEL,
    MENUITEM_BATTLE_COUNT,
};

// World Menu Items
enum
{
    MENUITEM_WORLD_MONOVERWORLD,
    MENUITEM_WORLD_BIKEMUSIC,
    MENUITEM_WORLD_AUTORUN,
    MENUITEM_WORLD_IMPROVEDFISHING,
    MENUITEM_WORLD_OVERWORLDSPEED,
    MENUITEM_WORLD_CANCEL,
    MENUITEM_WORLD_COUNT,
};

// Surf Menu Items
enum
{
    MENUITEM_SURF_SURFOVERWORLD,
    MENUITEM_SURF_SURFMUSIC,
    MENUITEM_SURF_FASTSURF,
    MENUITEM_SURF_DIVESPEED,
    MENUITEM_SURF_CANCEL,
    MENUITEM_SURF_COUNT,
};

// Window Ids
enum
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {//WIN_TOPBAR
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {//WIN_OPTIONS
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    {//WIN_DESCRIPTION
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
    },
    {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
    },
};

struct OptionMenu
{
    u8 submenu;
    u8 sel[MENUITEM_MAIN_COUNT];
    u8 sel_battle[MENUITEM_BATTLE_COUNT];
    u8 sel_world[MENUITEM_WORLD_COUNT];
    u8 sel_surf[MENUITEM_SURF_COUNT];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
    u8 arrowTaskId;
};

#define Y_DIFF 16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN 5
#define NUM_OPTIONS_FROM_BORDER 1

// local functions
static void MainCB2(void);
static void VBlankCB(void);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 chosen, bool8 active);
static void DrawOptionMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightOptionMenuItem(void);
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static int ProcessInput_Options_Four(int selection);
static int ProcessInput_Options_Ten(int selection);
static int ProcessInput_Options_Eleven(int selection);
static int ProcessInput_Sound(int selection);
static int ProcessInput_FrameType(int selection);
static const u8 *const OptionTextDescription(void);
static const u8 *const OptionTextRight(u8 menuItem);
static u8 MenuItemCount(void);
static u8 MenuItemCancel(void);
static void DrawDescriptionText(void);
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active);
static void DrawOptionMenuChoiceStrings(int selection, int y, bool8 active, const u8 *const choiceStrings[], int maxChoices);
static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active);
static void ReDrawAll(void);
static void DrawChoices_TextSpeed(int selection, int y);
static void DrawChoices_BattleScene(int selection, int y);
static void DrawChoices_BattleStyle(int selection, int y);
static void DrawChoices_Sound(int selection, int y);
static void DrawChoices_ButtonMode(int selection, int y);
static void DrawChoices_BarSpeed(int selection, int y); //HP and EXP
static void DrawChoices_StatEditor(int selection, int y);
static void DrawChoices_Nickname(int selection, int y);
static void DrawChoices_AutoRun(int selection, int y);
static void DrawChoices_FastSurf(int selection, int y);
static void DrawChoices_DiveSpeed(int selection, int y);
static void DrawChoices_OverworldSpeed(int selection, int y);
static void DrawChoices_ImprovedFishing(int selection, int y);
static void DrawChoices_BikeMusic(int selection, int y);
static void DrawChoices_SurfMusic(int selection, int y);
static void DrawChoices_MonOverworld(int selection, int y);
static void DrawChoices_SurfOverworld(int selection, int y);
static void DrawChoices_ItemAnimate(int selection, int y);
static void DrawChoices_TypeEffect(int selection, int y);
static void DrawChoices_HardMode(int selection, int y);
static void DrawChoices_FrameType(int selection, int y);
static void DrawChoices_Font(int selection, int y);
static void DrawBgWindowFrames(void);

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const data
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};
static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

#define TEXT_COLOR_OPTIONS_WHITE                1
#define TEXT_COLOR_OPTIONS_GRAY_FG              2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW          3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG        4
#define TEXT_COLOR_OPTIONS_ORANGE_FG            5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW        6
#define TEXT_COLOR_OPTIONS_RED_FG               7
#define TEXT_COLOR_OPTIONS_RED_SHADOW           8
#define TEXT_COLOR_OPTIONS_GREEN_FG             9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW         10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG        11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW    12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG          13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW      14

// Menu draw and input functions
struct // MENU_MAIN - General
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_TEXTSPEED]    = {DrawChoices_TextSpeed,   ProcessInput_Options_Three},
    [MENUITEM_MAIN_SOUND]        = {DrawChoices_Sound,       ProcessInput_Options_Two},
    [MENUITEM_MAIN_BUTTONMODE]   = {DrawChoices_ButtonMode,  ProcessInput_Options_Ten},
    [MENUITEM_MAIN_FRAMETYPE]    = {DrawChoices_FrameType,   ProcessInput_FrameType},
    [MENUITEM_CUSTOM_FONT]       = {DrawChoices_Font,        ProcessInput_Options_Two}, 
    [MENUITEM_MAIN_STAT_EDITOR]  = {DrawChoices_StatEditor,  ProcessInput_Options_Two},
    [MENUITEM_MAIN_NICKNAME]     = {DrawChoices_Nickname,    ProcessInput_Options_Two},
    [MENUITEM_MAIN_CANCEL]       = {NULL, NULL},
};

struct // MENU_BATTLE
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsBattle[MENUITEM_BATTLE_COUNT] =
{
    [MENUITEM_CUSTOM_HP_BAR]        = {DrawChoices_BarSpeed,    ProcessInput_Options_Eleven},
    [MENUITEM_CUSTOM_EXP_BAR]       = {DrawChoices_BarSpeed,    ProcessInput_Options_Eleven},
    [MENUITEM_MAIN_BATTLESCENE]     = {DrawChoices_BattleScene, ProcessInput_Options_Two},
    [MENUITEM_MAIN_BATTLESTYLE]     = {DrawChoices_BattleStyle, ProcessInput_Options_Two},
    [MENUITEM_BATTLE_ITEMANIMATE]   = {DrawChoices_ItemAnimate, ProcessInput_Options_Four},
    [MENUITEM_BATTLE_TYPEEFFECT]    = {DrawChoices_TypeEffect,  ProcessInput_Options_Two},
    [MENUITEM_BATTLE_HARDMODE]      = {DrawChoices_HardMode,    ProcessInput_Options_Three},
    [MENUITEM_BATTLE_CANCEL]        = {NULL, NULL},
};

struct // MENU_WORLD
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsWorld[MENUITEM_WORLD_COUNT] =
{
    [MENUITEM_WORLD_AUTORUN]            = {DrawChoices_AutoRun,         ProcessInput_Options_Two},
    [MENUITEM_WORLD_OVERWORLDSPEED]     = {DrawChoices_OverworldSpeed,  ProcessInput_Options_Four},
    [MENUITEM_WORLD_IMPROVEDFISHING]    = {DrawChoices_ImprovedFishing, ProcessInput_Options_Two},
    [MENUITEM_WORLD_BIKEMUSIC]          = {DrawChoices_BikeMusic,       ProcessInput_Options_Two},
    [MENUITEM_WORLD_MONOVERWORLD]       = {DrawChoices_MonOverworld,    ProcessInput_Options_Two},
    [MENUITEM_WORLD_CANCEL]             = {NULL, NULL},
};

struct // MENU_SURF
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsSurf[MENUITEM_SURF_COUNT] =
{
    [MENUITEM_SURF_SURFOVERWORLD]   = {DrawChoices_SurfOverworld,   ProcessInput_Options_Two},
    [MENUITEM_SURF_FASTSURF]        = {DrawChoices_FastSurf,        ProcessInput_Options_Two},
    [MENUITEM_SURF_DIVESPEED]       = {DrawChoices_DiveSpeed,       ProcessInput_Options_Three},
    [MENUITEM_SURF_SURFMUSIC]       = {DrawChoices_SurfMusic,       ProcessInput_Options_Two},
    [MENUITEM_SURF_CANCEL]          = {NULL, NULL},
};

// Menu left side option names text
static const u8 sText_StatEditor[]  = _("STAT EDITOR");
static const u8 sText_Nickname[]    = _("NICKNAME IN MENU");
static const u8 sText_Font[]        = _("FONT");
static const u8 *const sOptionMenuItemsNamesMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_MAIN_SOUND]       = gText_Sound,
    [MENUITEM_MAIN_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_MAIN_FRAMETYPE]   = gText_Frame,
    [MENUITEM_CUSTOM_FONT]      = sText_Font,
    [MENUITEM_MAIN_STAT_EDITOR] = sText_StatEditor,
    [MENUITEM_MAIN_NICKNAME]    = sText_Nickname,
    [MENUITEM_MAIN_CANCEL]      = gText_OptionMenuSave,
};

static const u8 sText_HpBar[]       = _("HP BAR SPEED");
static const u8 sText_ExpBar[]      = _("EXP BAR SPEED");
static const u8 sText_HardMode[]    = _("BATTLE MODE");
static const u8 sText_TypeEffect[]  = _("TYPE EFFECTS");
static const u8 sText_ItemAnimate[] = _("ITEM ANIMATION");
static const u8 *const sOptionMenuItemsNamesBattle[MENUITEM_BATTLE_COUNT] =
{
    [MENUITEM_CUSTOM_HP_BAR]        = sText_HpBar,
    [MENUITEM_CUSTOM_EXP_BAR]       = sText_ExpBar,
    [MENUITEM_MAIN_BATTLESCENE]     = gText_BattleScene,
    [MENUITEM_MAIN_BATTLESTYLE]     = gText_BattleStyle,
    [MENUITEM_BATTLE_ITEMANIMATE]   = sText_ItemAnimate,
    [MENUITEM_BATTLE_TYPEEFFECT]    = sText_TypeEffect,
    [MENUITEM_BATTLE_HARDMODE]      = sText_HardMode,
    [MENUITEM_BATTLE_CANCEL]        = gText_OptionMenuSave,
};

static const u8 sText_MonOverworld[]        = _("POKéMON FOLLOWER");
static const u8 sText_BikeMusic[]           = _("BIKE MUSIC");
static const u8 sText_AutoRun[]             = _("AUTO RUN");
static const u8 sText_OverworldSpeed[]      = _("WORLD SPEED");
static const u8 sText_ImprovedFishing[]     = _("IMPROVED FISHING");
static const u8 *const sOptionMenuItemsNamesWorld[MENUITEM_WORLD_COUNT] =
{
    [MENUITEM_WORLD_MONOVERWORLD]       = sText_MonOverworld,
    [MENUITEM_WORLD_BIKEMUSIC]          = sText_BikeMusic,
    [MENUITEM_WORLD_AUTORUN]            = sText_AutoRun,
    [MENUITEM_WORLD_OVERWORLDSPEED]     = sText_OverworldSpeed,
    [MENUITEM_WORLD_IMPROVEDFISHING]    = sText_ImprovedFishing,
    [MENUITEM_WORLD_CANCEL]             = gText_OptionMenuSave,
};

static const u8 sText_SurfOverworld[]   = _("POKéMON SURFER");
static const u8 sText_FastSurf[]        = _("FAST SURF");
static const u8 sText_SurfMusic[]       = _("SURF MUSIC");
static const u8 sText_DiveSpeed[]       = _("DIVE SPEED");

static const u8 *const sOptionMenuItemsNamesSurf[MENUITEM_SURF_COUNT] =
{
    [MENUITEM_SURF_SURFOVERWORLD]   = sText_SurfOverworld,
    [MENUITEM_SURF_SURFMUSIC]       = sText_SurfMusic,
    [MENUITEM_SURF_FASTSURF]        = sText_FastSurf,
    [MENUITEM_SURF_DIVESPEED]       = sText_DiveSpeed,
    [MENUITEM_SURF_CANCEL]          = gText_OptionMenuSave,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
    case MENU_MAIN:     return sOptionMenuItemsNamesMain[menuItem];
    case MENU_BATTLE:   return sOptionMenuItemsNamesBattle[menuItem];
    case MENU_WORLD:    return sOptionMenuItemsNamesWorld[menuItem];
    case MENU_SURF:     return sOptionMenuItemsNamesSurf[menuItem];
    }
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch (sOptions->submenu)
    {
    case MENU_MAIN:
        switch(selection)
        {
        case MENUITEM_MAIN_TEXTSPEED:       return TRUE;
        case MENUITEM_MAIN_SOUND:           return TRUE;
        case MENUITEM_MAIN_BUTTONMODE:      return TRUE;
        case MENUITEM_MAIN_FRAMETYPE:       return TRUE;
        case MENUITEM_CUSTOM_FONT:          return TRUE;
        case MENUITEM_MAIN_STAT_EDITOR:
        {
            if (!FlagGet(FLAG_ENABLE_STAT_EDITOR))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

        }
        case MENUITEM_MAIN_NICKNAME:        return TRUE;
        case MENUITEM_MAIN_CANCEL:          return TRUE;
        case MENUITEM_MAIN_COUNT:           return TRUE;
        }
    case MENU_BATTLE:
        switch(selection)
        {
        case MENUITEM_CUSTOM_HP_BAR:          return TRUE;
        case MENUITEM_CUSTOM_EXP_BAR:         return TRUE;
        case MENUITEM_MAIN_BATTLESCENE:       return TRUE;
        case MENUITEM_MAIN_BATTLESTYLE:
        {
            if (FlagGet(FLAG_HARD) || FlagGet(FLAG_NUZLOCKE))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

        }
        case MENUITEM_BATTLE_ITEMANIMATE:     return TRUE;
        case MENUITEM_BATTLE_TYPEEFFECT:      return TRUE;
        case MENUITEM_BATTLE_HARDMODE:
        {
            if (!FlagGet(FLAG_DEFEATED_METEOR_FALLS_STEVEN))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

        }
        case MENUITEM_BATTLE_CANCEL:          return TRUE;
        case MENUITEM_BATTLE_COUNT:           return TRUE;
        }
    case MENU_WORLD:
        switch(selection)
        {
        case MENUITEM_WORLD_AUTORUN:         return TRUE;
        case MENUITEM_WORLD_OVERWORLDSPEED:  return TRUE;
        case MENUITEM_WORLD_IMPROVEDFISHING: return TRUE;
        case MENUITEM_WORLD_BIKEMUSIC:       return TRUE;
        case MENUITEM_WORLD_MONOVERWORLD:    return TRUE;
        case MENUITEM_WORLD_CANCEL:          return TRUE;
        case MENUITEM_WORLD_COUNT:           return TRUE;
        }
    case MENU_SURF:
        switch(selection)
        {
        case MENUITEM_SURF_FASTSURF:        return TRUE;
        case MENUITEM_SURF_DIVESPEED:       return TRUE;
        case MENUITEM_SURF_SURFMUSIC:       return TRUE;
        case MENUITEM_SURF_SURFOVERWORLD:   return TRUE;
        case MENUITEM_SURF_CANCEL:          return TRUE;
        case MENUITEM_SURF_COUNT:           return TRUE;
        }
    }
}

// Descriptions
static const u8 sText_Empty[]                       = _("");
static const u8 sText_Desc_Save[]                   = _("Save your settings.");
static const u8 sText_Desc_TextSpeed[]              = _("Choose one of the three text-display\nspeeds.");
static const u8 sText_Desc_SoundMono[]              = _("Sound is the same in all speakers.\nRecommended for original hardware.");
static const u8 sText_Desc_SoundStereo[]            = _("Play the left and right audio channel\nseperately. Great with headphones.");
static const u8 sText_Desc_StatEditor_Hide[]        = _("Hide IV/EV Editor in the Party Menu.\nAny stat changes made will remain.");
static const u8 sText_Desc_StatEditor_Show[]        = _("Show IV/EV Editor in the Party Menu.\nAny stat changes made will remain.");
static const u8 sText_Desc_Nickname_Hide[]          = _("Original Experience. Don't allow\nchanging Nickname in the Party Menu.");
static const u8 sText_Desc_Nickname_Show[]          = _("Change Nickname in the Party Menu.\nTraded Pokemon require Name Rater.");
static const u8 sText_Desc_FrameType[]              = _("Choose the frame surrounding the\nwindows.");
static const u8 sText_Desc_FontType_Hoenn[]         = _("Original Experience.\nStandard POKéMON EMERALD Font.");
static const u8 sText_Desc_FontType_Kanto[]         = _("POKéMON FIRERED/LEAFGREEN Font.\nMay not show correctly for all text.");
static const u8 sText_Desc_ButtonMode[]             = _("All buttons work as normal.\nLR Mode inactive.");
static const u8 sText_Desc_ButtonMode_LA[]          = _("The {L_BUTTON} button acts as another\n{A_BUTTON} button for one-handed play.");
static const u8 sText_Desc_ButtonMode_LR[]          = _("{L_BUTTON} and {R_BUTTON} mainly act as {LEFT_ARROW} and {RIGHT_ARROW}.\nActive on all Button Modes excl. L=A.");
static const u8 sText_Desc_ButtonMode_Context[]     = _("The {L_BUTTON} button contextually changes\nRUN, BIKE, SURF, or DIVE settings.");
static const u8 sText_Desc_ButtonMode_World[]       = _("The {L_BUTTON} button steps through each\nWORLD SPEED option.");
static const u8 sText_Desc_ButtonMode_World2x[]     = _("The {L_BUTTON} button toggles\nWORLD SPEED at 2x on and off.");
static const u8 sText_Desc_ButtonMode_World4x[]     = _("The {L_BUTTON} button toggles\nWORLD SPEED at 4x on and off.");
static const u8 sText_Desc_ButtonMode_World8x[]     = _("The {L_BUTTON} button toggles\nWORLD SPEED at 8x on and off.");
static const u8 sText_Desc_ButtonMode_FastMode[]    = _("The {L_BUTTON} button toggles WORLD SPEED,\nRUN, SURF, and DIVE to max or off.");
static const u8 sText_Desc_ButtonMode_Follower[]    = _("The {L_BUTTON} button toggles\nPOKéMON FOLLOWERS on and off.");
static const u8 *const sOptionMenuItemDescriptionsMain[MENUITEM_MAIN_COUNT][10] =
{
    [MENUITEM_MAIN_TEXTSPEED]       = {sText_Desc_TextSpeed,            sText_Empty,                    sText_Empty},
    [MENUITEM_MAIN_SOUND]           = {sText_Desc_SoundMono,            sText_Desc_SoundStereo,         sText_Empty},
    [MENUITEM_MAIN_FRAMETYPE]       = {sText_Desc_FrameType,            sText_Empty,                    sText_Empty},
    [MENUITEM_CUSTOM_FONT]          = {sText_Desc_FontType_Hoenn,       sText_Desc_FontType_Kanto,      sText_Empty},
    [MENUITEM_MAIN_STAT_EDITOR]     = {sText_Desc_StatEditor_Hide,      sText_Desc_StatEditor_Show,     sText_Empty},
    [MENUITEM_MAIN_NICKNAME]        = {sText_Desc_Nickname_Hide,        sText_Desc_Nickname_Show,       sText_Empty},
    [MENUITEM_MAIN_CANCEL]          = {sText_Desc_Save,                 sText_Empty,                    sText_Empty},
    [MENUITEM_MAIN_BUTTONMODE]      = {sText_Desc_ButtonMode,           sText_Desc_ButtonMode_LA,       sText_Desc_ButtonMode_LR,
                                       sText_Desc_ButtonMode_Context,   sText_Desc_ButtonMode_World,    sText_Desc_ButtonMode_World2x,
                                       sText_Desc_ButtonMode_World4x,   sText_Desc_ButtonMode_World8x,  sText_Desc_ButtonMode_FastMode,
                                       sText_Desc_ButtonMode_Follower},
};

// Battle
static const u8 sText_Desc_BattleHPBar[]            = _("Choose how fast the HP BAR will get\ndrained in battles.");
static const u8 sText_Desc_BattleExpBar[]           = _("Choose how fast the EXP BAR will get\nfilled in battles.");
static const u8 sText_Desc_BattleScene_On[]         = _("Show the POKéMON battle animations.");
static const u8 sText_Desc_BattleScene_Off[]        = _("Skip the POKéMON battle animations.");
static const u8 sText_Desc_BattleStyle_Shift[]      = _("Get the option to switch your\nPOKéMON after the enemy's faints.");
static const u8 sText_Desc_BattleStyle_Set[]        = _("No free switch after fainting the\nenemy's POKéMON.");
static const u8 sText_Desc_ItemAnimateNormal[]      = _("Original in-battle item animation.\nNo change from original Emerald.");
static const u8 sText_Desc_ItemAnimateReduced[]     = _("Reduced in-battle item animation.\nRemoved the shaking animation.");
static const u8 sText_Desc_ItemAnimateMinimal[]     = _("Minimal in-battle item animation.\nOnly the final ring animation.");
static const u8 sText_Desc_ItemAnimateNone[]        = _("No in-battle item animation.\nAnimation skipped.");
static const u8 sText_Desc_TypeEffect_On[]          = _("Show move type effect in battle.\nGreen: Super, Red: Not very, Grey: No");
static const u8 sText_Desc_TypeEffect_Off[]         = _("Original experience, does not show\nmove type effectiveness in battle.");
static const u8 sText_Desc_HardMode_Off[]           = _("Original experience.\nNo extra restrictions in battle.");
static const u8 sText_Desc_HardMode_Hard[]          = _("SET mode, no items in battle,\nGYM level caps.");
static const u8 sText_Desc_HardMode_Hardcore[]      = _("Hard mode, but POKéMON can't\nbe revived.");
static const u8 *const sOptionMenuItemDescriptionsBattle[MENUITEM_BATTLE_COUNT][4] =
{
    [MENUITEM_CUSTOM_HP_BAR]            = {sText_Desc_BattleHPBar},
    [MENUITEM_CUSTOM_EXP_BAR]           = {sText_Desc_BattleExpBar},
    [MENUITEM_MAIN_BATTLESCENE]         = {sText_Desc_BattleScene_On,       sText_Desc_BattleScene_Off},
    [MENUITEM_MAIN_BATTLESTYLE]         = {sText_Desc_BattleStyle_Shift,    sText_Desc_BattleStyle_Set,     sText_Empty},
    [MENUITEM_BATTLE_ITEMANIMATE]       = {sText_Desc_ItemAnimateNormal,    sText_Desc_ItemAnimateReduced,  sText_Desc_ItemAnimateMinimal,  sText_Desc_ItemAnimateNone},
    [MENUITEM_BATTLE_TYPEEFFECT]        = {sText_Desc_TypeEffect_On,        sText_Desc_TypeEffect_Off,      sText_Empty},
    [MENUITEM_BATTLE_HARDMODE]          = {sText_Desc_HardMode_Off,         sText_Desc_HardMode_Hard,       sText_Desc_HardMode_Hardcore},
    [MENUITEM_BATTLE_CANCEL]            = {sText_Desc_Save,                 sText_Empty,                    sText_Empty,                    sText_Empty},
};

static const u8 sText_Desc_AutoRun_On[]                 = _("Use RUNNING SHOES automatically.\nHold {B_BUTTON} button to walk.");
static const u8 sText_Desc_AutoRun_Off[]                = _("Use RUNNING SHOES as normal.\nHold {B_BUTTON} button to run.");
static const u8 sText_Desc_OverworldSpeed_1x[]          = _("Standard player and NPC speed.\nNo change from original Emerald.");
static const u8 sText_Desc_OverworldSpeed_2x[]          = _("2x standard player and NPC speed.\nHold {R_BUTTON} button for standard speed.");
static const u8 sText_Desc_OverworldSpeed_4x[]          = _("4x standard player and NPC speed.\nHold {R_BUTTON} button for standard speed.");
static const u8 sText_Desc_OverworldSpeed_8x[]          = _("8x standard player and NPC speed.\nHold {R_BUTTON} button for standard speed.");
static const u8 sText_Desc_ImprovedFishing_On[]         = _("Improved Fishing.\nFish are not able to escape.");
static const u8 sText_Desc_ImprovedFishing_Off[]        = _("Fish as usual.\nFish may escape if not reeled in.");
static const u8 sText_Desc_BikeOff[]                    = _("Disables the BIKE music when you\nstart riding the BIKE.");
static const u8 sText_Desc_BikeOn[]                     = _("Enables the BIKE music when you\nstart riding the BIKE.");
static const u8 sText_Desc_MonOverworldOff[]            = _("Disables following for the first\nPOKéMON in your party.");
static const u8 sText_Desc_MonOverworldOn[]             = _("Enables following for the first\nPOKéMON in your party.");
static const u8 *const sOptionMenuItemDescriptionsWorld[MENUITEM_WORLD_COUNT][4] =
{
    [MENUITEM_WORLD_AUTORUN]            = {sText_Desc_AutoRun_On,           sText_Desc_AutoRun_Off},
    [MENUITEM_WORLD_OVERWORLDSPEED]     = {sText_Desc_OverworldSpeed_1x,    sText_Desc_OverworldSpeed_2x,   sText_Desc_OverworldSpeed_4x,   sText_Desc_OverworldSpeed_8x},
    [MENUITEM_WORLD_IMPROVEDFISHING]    = {sText_Desc_ImprovedFishing_On,   sText_Desc_ImprovedFishing_Off},
    [MENUITEM_WORLD_BIKEMUSIC]          = {sText_Desc_BikeOn,               sText_Desc_BikeOff},
    [MENUITEM_WORLD_MONOVERWORLD]       = {sText_Desc_MonOverworldOn,       sText_Desc_MonOverworldOff},
    [MENUITEM_WORLD_CANCEL]             = {sText_Desc_Save,                 sText_Empty},
};

static const u8 sText_Desc_FastSurf_On[]                = _("SURF faster than normal.\nHold {B_BUTTON} to SURF at normal speed.");
static const u8 sText_Desc_FastSurf_Off[]               = _("SURF at normal speed.\nHold {B_BUTTON} to SURF faster.");
static const u8 sText_Desc_DiveSpeed_Slow[]             = _("Original experience, underwater speed\nis unchanged from original game.");
static const u8 sText_Desc_DiveSpeed_Med[]              = _("Travel underwater faster.\nSame speed as SURF.");
static const u8 sText_Desc_DiveSpeed_Fast[]             = _("Travel underwater much faster.\nSame speed as FAST SURF.");
static const u8 sText_Desc_SurfOff[]                    = _("Disables the SURF music when you\nstart surfing on a POKéMON.");
static const u8 sText_Desc_SurfOn[]                     = _("Enables the SURF music when you\nstart surfing on a POKéMON.");
static const u8 sText_Desc_SurfOverworld_On[]           = _("SURF using the relevant POKéMON\ninstead of the generic surfer.");
static const u8 sText_Desc_SurfOverworld_Off[]          = _("Original experience.\nShow the original generic surfer.");
static const u8 *const sOptionMenuItemDescriptionsSurf[MENUITEM_SURF_COUNT][3] =
{
    [MENUITEM_SURF_FASTSURF]            = {sText_Desc_FastSurf_On,          sText_Desc_FastSurf_Off},
    [MENUITEM_SURF_DIVESPEED]           = {sText_Desc_DiveSpeed_Slow,       sText_Desc_DiveSpeed_Med,   sText_Desc_DiveSpeed_Fast},
    [MENUITEM_SURF_SURFMUSIC]           = {sText_Desc_SurfOn,               sText_Desc_SurfOff},
    [MENUITEM_SURF_SURFOVERWORLD]       = {sText_Desc_SurfOverworld_On,     sText_Desc_SurfOverworld_Off},
    [MENUITEM_SURF_CANCEL]              = {sText_Desc_Save,                 sText_Empty},
};

// Disabled Descriptions
static const u8 sText_Desc_Disabled_StatEditor[]    = _("STAT EDITOR locked. Beat the game\nand speak to Prof. Birch to unlock.");
static const u8 *const sOptionMenuItemDescriptionsDisabledMain[MENUITEM_MAIN_COUNT] =
{
    [MENUITEM_MAIN_TEXTSPEED]   = sText_Empty,
    [MENUITEM_MAIN_SOUND]       = sText_Empty,
    [MENUITEM_MAIN_BUTTONMODE]  = sText_Empty,
    [MENUITEM_MAIN_FRAMETYPE]   = sText_Empty,
    [MENUITEM_CUSTOM_FONT]        = sText_Empty,
    [MENUITEM_MAIN_STAT_EDITOR] = sText_Desc_Disabled_StatEditor,
    [MENUITEM_MAIN_NICKNAME] = sText_Empty,
    [MENUITEM_MAIN_CANCEL]      = sText_Empty,
};

// Disabled Battle
static const u8 sText_Desc_Disabled_BattleStyle[]   = _("BATTLE STYLE cannot be changed if\nHARD or HARDCORE difficulty active.");
static const u8 sText_Desc_Disabled_Hardmode[]      = _("BATTLE MODE setting locked. Defeat \nSTEVEN in METEOR FALLS to unlock.");
static const u8 *const sOptionMenuItemDescriptionsDisabledBattle[MENUITEM_BATTLE_COUNT] =
{
    [MENUITEM_CUSTOM_HP_BAR]      = sText_Empty,
    [MENUITEM_CUSTOM_EXP_BAR]     = sText_Empty,
    [MENUITEM_MAIN_BATTLESCENE] = sText_Empty,
    [MENUITEM_MAIN_BATTLESTYLE] = sText_Desc_Disabled_BattleStyle,
    [MENUITEM_BATTLE_HARDMODE] = sText_Desc_Disabled_Hardmode,
    [MENUITEM_BATTLE_CANCEL]      = sText_Empty,
    
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection;

    switch (sOptions->submenu)
    {
    case MENU_MAIN:
        if (!CheckConditions(menuItem))
            return sOptionMenuItemDescriptionsDisabledMain[menuItem];
        selection = sOptions->sel[menuItem];
        if (menuItem == MENUITEM_MAIN_TEXTSPEED || menuItem == MENUITEM_MAIN_FRAMETYPE)
            selection = 0;
        return sOptionMenuItemDescriptionsMain[menuItem][selection];
    case MENU_BATTLE:
        if (!CheckConditions(menuItem))
            return sOptionMenuItemDescriptionsDisabledBattle[menuItem];
        selection = sOptions->sel_battle[menuItem];
        if (menuItem == MENUITEM_CUSTOM_HP_BAR || menuItem == MENUITEM_CUSTOM_EXP_BAR)
            selection = 0;
        return sOptionMenuItemDescriptionsBattle[menuItem][selection];
    case MENU_WORLD:
        if (!CheckConditions(menuItem))
            return sOptionMenuItemDescriptionsDisabledMain[menuItem];
        selection = sOptions->sel_world[menuItem];
        return sOptionMenuItemDescriptionsWorld[menuItem][selection];
    case MENU_SURF:
        if (!CheckConditions(menuItem))
            return sOptionMenuItemDescriptionsDisabledMain[menuItem];
        selection = sOptions->sel_surf[menuItem];
        return sOptionMenuItemDescriptionsSurf[menuItem][selection];
    }
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
    case MENU_MAIN:     return MENUITEM_MAIN_COUNT;
    case MENU_BATTLE:   return MENUITEM_BATTLE_COUNT;
    case MENU_WORLD:    return MENUITEM_WORLD_COUNT;
    case MENU_SURF:     return MENUITEM_SURF_COUNT;
    }
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
    case MENU_MAIN:     return MENUITEM_MAIN_CANCEL;
    case MENU_BATTLE:   return MENUITEM_BATTLE_CANCEL;
    case MENU_WORLD:    return MENUITEM_WORLD_CANCEL;
    case MENU_SURF:     return MENUITEM_SURF_CANCEL;
    }
}

// Main code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const u8 sText_TopBar_Main[]             = _("GENERAL");
static const u8 sText_TopBar_Main_Left[]        = _("{L_BUTTON} WORLD");
static const u8 sText_TopBar_Main_Right[]       = _("BATTLE {R_BUTTON}");
static const u8 sText_TopBar_Battle[]           = _("BATTLE");
static const u8 sText_TopBar_Battle_Left[]      = _("{L_BUTTON} GENERAL");
static const u8 sText_TopBar_Overworld[]        = _("WORLD");
static const u8 sText_TopBar_Overworld_Left[]   = _("{L_BUTTON} SURF");
static const u8 sText_TopBar_Overworld_Right[]  = _("GENERAL {R_BUTTON}");
static const u8 sText_TopBar_Surf[]             = _("SURF");
static const u8 sText_TopBar_Surf_Right[]       = _("WORLD {R_BUTTON}");
static void DrawTopBarText(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(15));
    switch (sOptions->submenu)
    {
        case MENU_MAIN:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, sText_TopBar_Main, 241), 1, color, 0, sText_TopBar_Main);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 10, 1, color, 0, sText_TopBar_Main_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, sText_TopBar_Main_Right, 230), 1, color, 0, sText_TopBar_Main_Right);
            break;
        case MENU_BATTLE:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, sText_TopBar_Battle, 241), 1, color, 0, sText_TopBar_Battle);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 10, 1, color, 0, sText_TopBar_Battle_Left);
            break;
        case MENU_WORLD:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, sText_TopBar_Overworld, 241), 1, color, 0, sText_TopBar_Overworld);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 10, 1, color, 0, sText_TopBar_Overworld_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, sText_TopBar_Overworld_Right, 230), 1, color, 0, sText_TopBar_Overworld_Right);
            break;
        case MENU_SURF:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, sText_TopBar_Surf, 241), 1, color, 0, sText_TopBar_Surf);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, sText_TopBar_Surf_Right, 230), 1, color, 0, sText_TopBar_Surf_Right);
            break;
    }
    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void) //left side text
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < MenuItemCount(); i++)
        DrawLeftSideOptionText(i, (i * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
        
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawLeftSideOptionText(int selection, int y)
{
    u8 color_yellow[3];
    u8 color_gray[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_OPTIONS_ORANGE_FG;
    color_yellow[2] = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    if (CheckConditions(selection))
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
}

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 chosen, bool8 active)
{
    u8 color_red[3];
    u8 color_gray[3];

    if (active)
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_DARK_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_DARK_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }


    if (chosen)
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    switch (sOptions->submenu)
    {
        case MENU_MAIN:
            if (sItemFunctionsMain[id].drawChoices != NULL)
                sItemFunctionsMain[id].drawChoices(sOptions->sel[id], y);
            break;
        case MENU_BATTLE:
            if (sItemFunctionsBattle[id].drawChoices != NULL)
                sItemFunctionsBattle[id].drawChoices(sOptions->sel_battle[id], y);
            break;
        case MENU_WORLD:
            if (sItemFunctionsWorld[id].drawChoices != NULL)
                sItemFunctionsWorld[id].drawChoices(sOptions->sel_world[id], y);
            break;
        case MENU_SURF:
            if (sItemFunctionsSurf[id].drawChoices != NULL)
                sItemFunctionsSurf[id].drawChoices(sOptions->sel_surf[id], y);
            break;
    }
}

static void HighlightOptionMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

void CB2_InitOptionPlusMenu(void)
{
    u32 i, taskId;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ResetBgPositions();
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, 0, sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, 16, sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        sOptions = AllocZeroed(sizeof(*sOptions));

        //Main Menu/General
        sOptions->sel[MENUITEM_MAIN_TEXTSPEED]   = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel[MENUITEM_MAIN_SOUND]       = gSaveBlock2Ptr->optionsSound;
        sOptions->sel[MENUITEM_MAIN_BUTTONMODE]  = gSaveBlock2Ptr->optionsButtonMode;
        sOptions->sel[MENUITEM_MAIN_FRAMETYPE]   = gSaveBlock2Ptr->optionsWindowFrameType;
        sOptions->sel[MENUITEM_CUSTOM_FONT]      = FlagGet(FLAG_SWAP_FONT);
        sOptions->sel[MENUITEM_MAIN_STAT_EDITOR] = FlagGet(FLAG_SHOW_STAT_EDITOR);
        sOptions->sel[MENUITEM_MAIN_NICKNAME]    = FlagGet(FLAG_ENABLE_NICKNAME);
        
        //Battle
        sOptions->sel_battle[MENUITEM_CUSTOM_HP_BAR]    = gSaveBlock2Ptr->optionsHpBarSpeed;
        sOptions->sel_battle[MENUITEM_CUSTOM_EXP_BAR]   = gSaveBlock2Ptr->optionsExpBarSpeed;
        sOptions->sel_battle[MENUITEM_MAIN_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel_battle[MENUITEM_BATTLE_ITEMANIMATE]   = gSaveBlock2Ptr->optionsBattleItemAnimation;
        sOptions->sel_battle[MENUITEM_BATTLE_TYPEEFFECT]    = FlagGet(FLAG_HIDE_TYPE_EFFECT_BATTLE);
        if (FlagGet(FLAG_HARD) || FlagGet(FLAG_NUZLOCKE))
        {
            sOptions->sel_battle[MENUITEM_MAIN_BATTLESTYLE] = OPTIONS_BATTLE_STYLE_SET;
        }
        else
        {
            sOptions->sel_battle[MENUITEM_MAIN_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        }

        if (FlagGet(FLAG_NUZLOCKE))
            sOptions->sel_battle[MENUITEM_BATTLE_HARDMODE]    = 2;
        else if(FlagGet(FLAG_HARD))
            sOptions->sel_battle[MENUITEM_BATTLE_HARDMODE]    = 1;
        else
            sOptions->sel_battle[MENUITEM_BATTLE_HARDMODE]    = 0;

        //World
        sOptions->sel_world[MENUITEM_WORLD_AUTORUN]             = !FlagGet(FLAG_ENABLE_AUTORUN);            // Used the inverse to align with ON/OFF Buttons
        sOptions->sel_world[MENUITEM_WORLD_IMPROVEDFISHING]     = !FlagGet(FLAG_ENABLE_FISHCANTESCAPE);     // Used the inverse to align with ON/OFF Buttons
        sOptions->sel_world[MENUITEM_WORLD_BIKEMUSIC]           = FlagGet(FLAG_DISABLE_BIKEMUSIC);
        sOptions->sel_world[MENUITEM_WORLD_MONOVERWORLD]        = !FlagGet(FLAG_ENABLE_FOLLOWER);
        sOptions->sel_world[MENUITEM_WORLD_OVERWORLDSPEED]      = VarGet(VAR_OVERWORLD_SPEEDUP);

        //Surf
        sOptions->sel_surf[MENUITEM_SURF_FASTSURF]            = !FlagGet(FLAG_ENABLE_FASTSURF);           // Used the inverse to align with ON/OFF Buttons
        sOptions->sel_surf[MENUITEM_SURF_DIVESPEED]           = gSaveBlock2Ptr->optionsDiveSpeed;
        sOptions->sel_surf[MENUITEM_SURF_SURFOVERWORLD]       = !FlagGet(FLAG_ENABLE_SURFOVERWORLD);      // Used the inverse to align with ON/OFF Buttons
        sOptions->sel_surf[MENUITEM_SURF_SURFMUSIC]           = FlagGet(FLAG_DISABLE_SURFMUSIC);

        sOptions->submenu = MENU_MAIN;

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        DrawTopBarText();
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawDescriptionText();
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
        break;
    case 10:
        taskId = CreateTask(Task_OptionMenuFadeIn, 0);

        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_MAIN_COUNT - 1, 110, 110, 0);
        //sOptions->arrowTaskId = TASK_NONE;

        for (i = 0; i < min(OPTIONS_ON_SCREEN, MenuItemCount()); i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightOptionMenuItem();

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    case 11:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 12:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    int i = 0;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN , MenuItemCount());
    if (JOY_NEW(A_BUTTON) && !(gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A && JOY_NEW(L_BUTTON)))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor[sOptions->submenu] == 0)
                sOptions->visibleCursor[sOptions->submenu]--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor[sOptions->submenu] < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = optionsToDraw-2;
                ScrollAll(0);
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-1;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]--;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == optionsToDraw-2) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor[sOptions->submenu] == MenuItemCount() - 1)
                sOptions->visibleCursor[sOptions->submenu]++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor[sOptions->submenu] >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-2;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - optionsToDraw-1;
                ScrollAll(1);
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 0;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]++;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        if (sOptions->submenu == MENU_MAIN)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsMain[cursor].processInput != NULL)
                {
                    sOptions->sel[cursor] = sItemFunctionsMain[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_BATTLE)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_battle[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsBattle[cursor].processInput != NULL)
                {
                    sOptions->sel_battle[cursor] = sItemFunctionsBattle[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_battle[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_WORLD)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_world[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsWorld[cursor].processInput != NULL)
                {
                    sOptions->sel_world[cursor] = sItemFunctionsWorld[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_world[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_SURF)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_surf[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsWorld[cursor].processInput != NULL)
                {
                    sOptions->sel_surf[cursor] = sItemFunctionsSurf[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_surf[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        switch (sOptions->submenu)
        {
            case MENU_MAIN:
                sOptions->submenu = MENU_BATTLE;
                break;
            case MENU_WORLD:
                sOptions->submenu = MENU_MAIN;
                break;
            case MENU_SURF:
                sOptions->submenu = MENU_WORLD;
                break;
            default:
                break;
        }

        /*
        if (sOptions->submenu != MENU_BATTLE)
            sOptions->submenu++;
        */
       
        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(L_BUTTON))
    {
        switch (sOptions->submenu)
        {
            case MENU_MAIN:
                sOptions->submenu = MENU_WORLD;
                break;
            case MENU_BATTLE:
                sOptions->submenu = MENU_MAIN;
                break;
            case MENU_WORLD:
                sOptions->submenu = MENU_SURF;
                break;
            default:
                break;
        }
        /*
        if (sOptions->submenu != 0)
            sOptions->submenu--;
        */
        
        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    //Main Menu/General
    gSaveBlock2Ptr->optionsTextSpeed                        = sOptions->sel[MENUITEM_MAIN_TEXTSPEED];
    gSaveBlock2Ptr->optionsSound                            = sOptions->sel[MENUITEM_MAIN_SOUND];
    gSaveBlock2Ptr->optionsButtonMode                       = sOptions->sel[MENUITEM_MAIN_BUTTONMODE];
    gSaveBlock2Ptr->optionsWindowFrameType                  = sOptions->sel[MENUITEM_MAIN_FRAMETYPE];
    sOptions->sel[MENUITEM_CUSTOM_FONT]         == 0        ? FlagClear(FLAG_SWAP_FONT)                 : FlagSet(FLAG_SWAP_FONT);
    sOptions->sel[MENUITEM_MAIN_STAT_EDITOR]    == 0        ? FlagClear(FLAG_SHOW_STAT_EDITOR)          : FlagSet(FLAG_SHOW_STAT_EDITOR);
    sOptions->sel[MENUITEM_MAIN_NICKNAME]       == 0        ? FlagClear(FLAG_ENABLE_NICKNAME)           : FlagSet(FLAG_ENABLE_NICKNAME);

    //Battle
    gSaveBlock2Ptr->optionsHpBarSpeed                       = sOptions->sel_battle[MENUITEM_CUSTOM_HP_BAR];
    gSaveBlock2Ptr->optionsExpBarSpeed                      = sOptions->sel_battle[MENUITEM_CUSTOM_EXP_BAR];
    gSaveBlock2Ptr->optionsBattleSceneOff                   = sOptions->sel_battle[MENUITEM_MAIN_BATTLESCENE];
    gSaveBlock2Ptr->optionsBattleStyle                      = sOptions->sel_battle[MENUITEM_MAIN_BATTLESTYLE];
    gSaveBlock2Ptr->optionsBattleItemAnimation              = sOptions->sel_battle[MENUITEM_BATTLE_ITEMANIMATE];
    sOptions->sel_battle[MENUITEM_BATTLE_TYPEEFFECT] == 0   ? FlagClear(FLAG_HIDE_TYPE_EFFECT_BATTLE)   : FlagSet(FLAG_HIDE_TYPE_EFFECT_BATTLE);
    
    switch (sOptions->sel_battle[MENUITEM_BATTLE_HARDMODE])
    {
        case 2:
            FlagSet(FLAG_HARD);
            FlagSet(FLAG_NUZLOCKE);
            break;
        case 1:
            FlagSet(FLAG_HARD);
            FlagClear(FLAG_NUZLOCKE);
            break;
        case 0:
        default:
            FlagClear(FLAG_NUZLOCKE);
            FlagClear(FLAG_HARD);
            break;        
    }
    //World
    sOptions->sel_world[MENUITEM_WORLD_AUTORUN]             == 0 ? FlagSet(FLAG_ENABLE_AUTORUN)         : FlagClear(FLAG_ENABLE_AUTORUN);           // Used the inverse to align with other similar options.
    sOptions->sel_world[MENUITEM_WORLD_IMPROVEDFISHING]     == 0 ? FlagSet(FLAG_ENABLE_FISHCANTESCAPE)  : FlagClear(FLAG_ENABLE_FISHCANTESCAPE);    // Used the inverse to align with other similar options.
    sOptions->sel_world[MENUITEM_WORLD_BIKEMUSIC]           == 0 ? FlagClear(FLAG_DISABLE_BIKEMUSIC)    : FlagSet(FLAG_DISABLE_BIKEMUSIC);
    sOptions->sel_world[MENUITEM_WORLD_MONOVERWORLD]        == 0 ? FlagSet(FLAG_ENABLE_FOLLOWER)        : FlagClear(FLAG_ENABLE_FOLLOWER);          // Used the inverse to align with other similar options.
    *GetVarPointer(VAR_OVERWORLD_SPEEDUP)                   = sOptions->sel_world[MENUITEM_WORLD_OVERWORLDSPEED];

    //Surf
    sOptions->sel_surf[MENUITEM_SURF_FASTSURF]              == 0 ? FlagSet(FLAG_ENABLE_FASTSURF)        : FlagClear(FLAG_ENABLE_FASTSURF);          // Used the inverse to align with other similar options.
    gSaveBlock2Ptr->optionsDiveSpeed                        = sOptions->sel_surf[MENUITEM_SURF_DIVESPEED];
    sOptions->sel_surf[MENUITEM_SURF_SURFMUSIC]             == 0 ? FlagClear(FLAG_DISABLE_SURFMUSIC)    : FlagSet(FLAG_DISABLE_SURFMUSIC);
    sOptions->sel_surf[MENUITEM_SURF_SURFOVERWORLD]         == 0 ? FlagSet(FLAG_ENABLE_SURFOVERWORLD)   : FlagClear(FLAG_ENABLE_SURFOVERWORLD);     // Used the inverse to align with other similar options.

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor[sOptions->submenu] + NUM_OPTIONS_FROM_BORDER, pos = optionsToDraw - 1;
    else
        menuItem = sOptions->menuCursor[sOptions->submenu] - NUM_OPTIONS_FROM_BORDER, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF);
    DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    scrollCount = MenuItemCount() - optionsToDraw;

    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(1));

    // Clear moved items
    if (direction == 0)
    {
        y = optionsToDraw - scrollCount;
        if (y < 0)
            y = optionsToDraw;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MenuItemCount() - 1 - i, pos = optionsToDraw - 1 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF);
        DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****GENERIC****
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

static int XOptions_ProcessInput(int x, int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ProcessInput_Options_Two(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int ProcessInput_Options_Three(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static int ProcessInput_Options_Four(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

static int ProcessInput_Options_Ten(int selection)
{
    return XOptions_ProcessInput(10, selection);
}

static int ProcessInput_Options_Eleven(int selection)
{
    return XOptions_ProcessInput(11, selection);
}

// Process Input functions ****SPECIFIC****
static int ProcessInput_Sound(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
    }

    return selection;
}

static int ProcessInput_FrameType(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}

// Draw Choices functions ****GENERIC****
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 chosen = FALSE;
    if (style != 0)
        chosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, chosen, active);
}

static const u8 sText_Less[] = _("{LEFT_ARROW}");
static const u8 sText_More[] = _("{RIGHT_ARROW}");
// Draw Choices Strings functions ****GENERIC****
static void DrawOptionMenuChoiceStrings(int selection, int y, bool8 active, const u8 *const choiceStrings[], int maxChoices)
{
    int xMid = GetMiddleX(sText_Less, choiceStrings[selection], sText_More);

    // Draw left/right arrows for less and more indicators
    if (selection != 0)
        DrawOptionMenuChoice(sText_Less, 104, y, 0, 1);
    else
        DrawOptionMenuChoice(sText_Less, 104, y, 0, 0);

    DrawOptionMenuChoice(choiceStrings[selection], xMid, y, 0, active);

    if (selection != (maxChoices - 1))
        DrawOptionMenuChoice(sText_More, GetStringRightAlignXOffset(1, sText_More, 200), y, 0, 1);
    else
        DrawOptionMenuChoice(sText_More, GetStringRightAlignXOffset(1, sText_More, 200), y, 0, 0);
}


static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], active);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], active);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
    u8 i;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (MenuItemCount() <= OPTIONS_ON_SCREEN) // Draw or delete the scrolling arrows based on options in the menu
    {
        if (sOptions->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
    }
    else
    {
        if (sOptions->arrowTaskId == TASK_NONE)
            sOptions->arrowTaskId = sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);

    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < optionsToDraw; i++)
    {
        DrawChoices(menuItem+i, i * Y_DIFF);
        DrawLeftSideOptionText(menuItem+i, (i * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****SPECIFIC****
static const u8 *const sTextSpeedStrings[] = {gText_TextSpeedSlow, gText_TextSpeedMid, gText_TextSpeedFast};
static void DrawChoices_TextSpeed(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_TEXTSPEED);
    DrawOptionMenuChoiceStrings(selection, y, active, sTextSpeedStrings, 3);
}

static const u8 *const sBattleSceneStrings[] = {gText_BattleSceneOn, gText_BattleSceneOff};
static void DrawChoices_BattleScene(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_BATTLESCENE);
    DrawOptionMenuChoiceStrings(selection, y, active, sBattleSceneStrings, 2);
}

static const u8 *const sBattleStyleStrings[] = {gText_BattleStyleShift, gText_BattleStyleSet};
static void DrawChoices_BattleStyle(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_BATTLESTYLE);
    DrawOptionMenuChoiceStrings(selection, y, active, sBattleStyleStrings, 2);
}

static const u8 sText_TypeEffect_On[]   = _("ON");
static const u8 sText_TypeEffect_Off[]  = _("OFF");
static const u8 *const sTypeEffectStrings[] = {sText_TypeEffect_On, sText_TypeEffect_Off};
static void DrawChoices_TypeEffect(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BATTLE_TYPEEFFECT);
    DrawOptionMenuChoiceStrings(selection, y, active, sTypeEffectStrings, 2);
}

static const u8 sText_HardMode_Off[]        = _("NORMAL");
static const u8 sText_HardMode_Hard[]       = _("HARD");
static const u8 sText_HardMode_Hardcore[]   = _("HARDCORE");
static const u8 *const sHardModeStrings[] = {sText_HardMode_Off, sText_HardMode_Hard, sText_HardMode_Hardcore};
static void DrawChoices_HardMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BATTLE_HARDMODE);
    DrawOptionMenuChoiceStrings(selection, y, active, sHardModeStrings, 3);
}

static const u8 sText_ItemAnimate_Normal[]   = _("NORMAL");
static const u8 sText_ItemAnimate_Reduced[]  = _("REDUCED");
static const u8 sText_ItemAnimate_Minimal[]  = _("MINIMAL");
static const u8 sText_ItemAnimate_None[]     = _("NONE");
static const u8 *const sItemAnimateStrings[] = {sText_ItemAnimate_Normal, sText_ItemAnimate_Reduced, sText_ItemAnimate_Minimal, sText_ItemAnimate_None};
static void DrawChoices_ItemAnimate(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BATTLE_ITEMANIMATE);
    DrawOptionMenuChoiceStrings(selection, y, active, sItemAnimateStrings, 4);
}

static const u8 *const sSoundStrings[] = {gText_SoundMono, gText_SoundStereo};
static void DrawChoices_Sound(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_SOUND);
    DrawOptionMenuChoiceStrings(selection, y, active, sSoundStrings, 2);
}

static const u8 sText_ButtonType_Settings[]         = _("L=SETTINGS");
static const u8 sText_ButtonType_OverworldSpeed[]   = _("L=SPEED");
static const u8 sText_ButtonType_OverworldSpeed2x[] = _("L=SPEED 2x");
static const u8 sText_ButtonType_OverworldSpeed4x[] = _("L=SPEED 4x");
static const u8 sText_ButtonType_OverworldSpeed8x[] = _("L=SPEED 8x");
static const u8 sText_ButtonType_FastMode[]         = _("L=FAST MODE");
static const u8 sText_ButtonType_Follower[]         = _("L=FOLLOWER");
static const u8 *const sButtonModeStrings[] =
    {
    gText_ButtonTypeNormal,
    gText_ButtonTypeLEqualsA,
    gText_ButtonTypeLR,
    sText_ButtonType_Settings,
    sText_ButtonType_OverworldSpeed,
    sText_ButtonType_OverworldSpeed2x,
    sText_ButtonType_OverworldSpeed4x,
    sText_ButtonType_OverworldSpeed8x,
    sText_ButtonType_FastMode,
    sText_ButtonType_Follower
    };
static void DrawChoices_ButtonMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_BUTTONMODE);
    DrawOptionMenuChoiceStrings(selection, y, active, sButtonModeStrings, 10);
}

static const u8 sText_Normal[]  = _("NORMAL");
static const u8 sText_Instant[] = _("INSTANT");
static const u8 sText_Dummy[]   = _("+1"); // Used to center the numeric identifier
static void DrawChoices_BarSpeed(int selection, int y) //HP and EXP
{
    bool8 active = CheckConditions(MENUITEM_CUSTOM_EXP_BAR);
    int xMid;

    // Draw left/right arrows for less and more indicators
    if (selection != 0)
        DrawOptionMenuChoice(sText_Less, 104, y, 0, 1);
    else
        DrawOptionMenuChoice(sText_Less, 104, y, 0, 0);

    if (selection != 10)
        DrawOptionMenuChoice(sText_More, GetStringRightAlignXOffset(1, sText_More, 200), y, 0, 1);
    else
        DrawOptionMenuChoice(sText_More, GetStringRightAlignXOffset(1, sText_More, 200), y, 0, 0);
    
    if (selection == 0)
    {
        xMid = GetMiddleX(sText_Less, sText_Normal, sText_More);
        DrawOptionMenuChoice(sText_Normal, xMid, y, 0, active);
    }
    else if (selection < 10)
    {
        u8 textPlus[] = _("+1{0x77}{0x77}{0x77}{0x77}{0x77}"); // 0x77 is to clear INSTANT text
        textPlus[1] = CHAR_0 + selection;
        
        xMid = GetMiddleX(sText_Less, sText_Dummy, sText_More);
        DrawOptionMenuChoice(textPlus, xMid, y, 0, active);
    }
    else
    {
        xMid = GetMiddleX(sText_Less, sText_Instant, sText_More);
        DrawOptionMenuChoice(sText_Instant, xMid, y, 0, active);
    }
}

static void DrawChoices_FrameType(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_FRAMETYPE);
    u8 text[16];
    u8 n = selection + 1;
    u16 i;
    int xMid;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    text[i] = EOS;

    xMid = GetMiddleX(sText_Less, text, sText_More);

    // Draw left/right arrows for less and more indicators
    if (selection != 0)
        DrawOptionMenuChoice(sText_Less, 104, y, 0, 1);
    else
        DrawOptionMenuChoice(sText_Less, 104, y, 0, 0);

    DrawOptionMenuChoice(text, xMid, y, 0, active);
    if (selection != 19)
        DrawOptionMenuChoice(sText_More, GetStringRightAlignXOffset(1, sText_More, 200), y, 0, 1);
    else
        DrawOptionMenuChoice(sText_More, GetStringRightAlignXOffset(1, sText_More, 200), y, 0, 0);
}

static const u8 sText_OptionFont_Hoenn[]    = _("HOENN");
static const u8 sText_OptionFont_Kanto[]    = _("KANTO");
static const u8 *const sFontStrings[] = {sText_OptionFont_Hoenn, sText_OptionFont_Kanto};

static void DrawChoices_Font(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CUSTOM_FONT);
    DrawOptionMenuChoiceStrings(selection, y, active, sFontStrings, 2);
}

static const u8 sText_StatEditorHide[]   = _("HIDE");
static const u8 sText_StatEditorShow[]   = _("SHOW");
static const u8 *const sStatEditorStrings[] = {sText_StatEditorHide, sText_StatEditorShow};
static void DrawChoices_StatEditor(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_STAT_EDITOR);
    DrawOptionMenuChoiceStrings(selection, y, active, sStatEditorStrings, 2);
}

static const u8 sText_NicknameHide[]   = _("HIDE");
static const u8 sText_NicknameShow[]   = _("SHOW");
static const u8 *const sNicknamStrings[] = {sText_NicknameHide, sText_NicknameShow};
static void DrawChoices_Nickname(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_MAIN_NICKNAME);
    DrawOptionMenuChoiceStrings(selection, y, active, sNicknamStrings, 2);
}

static const u8 sText_AutoRun_On[]   = _("ON");
static const u8 sText_AutoRun_Off[]   = _("OFF");
static const u8 *const sAutoRunStrings[] = {sText_AutoRun_On, sText_AutoRun_Off};
static void DrawChoices_AutoRun(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_WORLD_AUTORUN);
    DrawOptionMenuChoiceStrings(selection, y, active, sAutoRunStrings, 2);
}

static const u8 sText_OverworldSpeedUp_Original[]   = _("ORIGINAL");
static const u8 sText_OverworldSpeedUp_Fast[]       = _("2x");
static const u8 sText_OverworldSpeedUp_Faster[]     = _("4x");
static const u8 sText_OverworldSpeedUp_Fastest[]    = _("8x");
static const u8 *const sOverworldSpeedupStrings[] = {sText_OverworldSpeedUp_Original, sText_OverworldSpeedUp_Fast, sText_OverworldSpeedUp_Faster, sText_OverworldSpeedUp_Fastest};
static void DrawChoices_OverworldSpeed(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_WORLD_OVERWORLDSPEED);
    DrawOptionMenuChoiceStrings(selection, y, active, sOverworldSpeedupStrings, 4);
}

static const u8 sText_ImprovedFishing_On[]   = _("ON");
static const u8 sText_ImprovedFishing_Off[]   = _("OFF");
static const u8 *const sImprovedFishingStrings[] = {sText_ImprovedFishing_On, sText_ImprovedFishing_Off};
static void DrawChoices_ImprovedFishing(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_WORLD_IMPROVEDFISHING);
    DrawOptionMenuChoiceStrings(selection, y, active, sImprovedFishingStrings, 2);
}

static const u8 sText_BikeMusic_On[]   = _("ON");
static const u8 sText_BikeMusic_Off[]   = _("OFF");
static const u8 *const sBikeMusicStrings[] = {sText_BikeMusic_On, sText_BikeMusic_Off};
static void DrawChoices_BikeMusic(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_WORLD_BIKEMUSIC);
    DrawOptionMenuChoiceStrings(selection, y, active, sBikeMusicStrings, 2);
}

static const u8 sText_MonOverworld_On[] = _("ON");
static const u8 sText_MonOverworld_Off[] = _("OFF");
static const u8 *const sMonOverworldStrings[] = {sText_MonOverworld_On, sText_MonOverworld_Off};
static void DrawChoices_MonOverworld(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_WORLD_MONOVERWORLD);
    DrawOptionMenuChoiceStrings(selection, y, active, sMonOverworldStrings, 2);
}

static const u8 sText_FastSurf_On[]   = _("ON");
static const u8 sText_FastSurf_Off[]   = _("OFF");
static const u8 *const sFastSurfStrings[] = {sText_FastSurf_On, sText_FastSurf_Off};
static void DrawChoices_FastSurf(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_SURF_FASTSURF);
    DrawOptionMenuChoiceStrings(selection, y, active, sFastSurfStrings, 2);
}

static const u8 sText_DiveSpeed_Slow[] = _("SLOW");
static const u8 sText_DiveSpeed_Med[] = _("MEDIUM");
static const u8 sText_DiveSpeed_Fast[] = _("FAST");
static const u8 *const sDiveSpeedStrings[] = {sText_DiveSpeed_Slow, sText_DiveSpeed_Med, sText_DiveSpeed_Fast};
static void DrawChoices_DiveSpeed(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_SURF_DIVESPEED);
    DrawOptionMenuChoiceStrings(selection, y, active, sDiveSpeedStrings, 3);
}

static const u8 sText_SurfMusic_On[]   = _("ON");
static const u8 sText_SurfMusic_Off[]   = _("OFF");
static const u8 *const sSurfMusicStrings[] = {sText_SurfMusic_On, sText_SurfMusic_Off};
static void DrawChoices_SurfMusic(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_SURF_SURFMUSIC);
    DrawOptionMenuChoiceStrings(selection, y, active, sSurfMusicStrings, 2);
}

static const u8 sText_SurfOverworld_On[]    = _("ON");
static const u8 sText_SurfOverworld_Off[]   = _("OFF");
static const u8 *const sSurfOverworldStrings[] = {sText_SurfOverworld_On, sText_SurfOverworld_Off};
static void DrawChoices_SurfOverworld(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_SURF_SURFOVERWORLD);
    DrawOptionMenuChoiceStrings(selection, y, active, sSurfOverworldStrings, 2);
}

// Background tilemap
#define TILE_TOP_CORNER_L 0x1A2 // 418
#define TILE_TOP_EDGE     0x1A3 // 419
#define TILE_TOP_CORNER_R 0x1A4 // 420
#define TILE_LEFT_EDGE    0x1A5 // 421
#define TILE_RIGHT_EDGE   0x1A7 // 423
#define TILE_BOT_CORNER_L 0x1A8 // 424
#define TILE_BOT_EDGE     0x1A9 // 425
#define TILE_BOT_CORNER_R 0x1AA // 426

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Option Texts window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);

    // Description window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1, 15,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28, 15,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
