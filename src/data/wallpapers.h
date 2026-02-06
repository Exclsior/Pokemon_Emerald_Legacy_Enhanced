enum {
    WALLPAPER_FOREST,
    WALLPAPER_CITY,
    WALLPAPER_DESERT,
    WALLPAPER_SAVANNA,
    WALLPAPER_CRAG,
    WALLPAPER_VOLCANO,
    WALLPAPER_SNOW,
    WALLPAPER_CAVE,
    WALLPAPER_BEACH,
    WALLPAPER_SEAFLOOR,
    WALLPAPER_RIVER,
    WALLPAPER_SKY,
    WALLPAPER_POLKADOT,
    WALLPAPER_POKECENTER,
    WALLPAPER_MACHINE,
    WALLPAPER_PLAIN,
    WALLPAPER_FRIENDS, // The one received as a gift from Walda's parents.
    // Special wallpapers (Walda-style with fixed colors)
    // Pokemon 1
    WALLPAPER_SPECIAL_ZIGZAGOON,
    WALLPAPER_SPECIAL_LUVDISC,
    WALLPAPER_SPECIAL_TOGEPI,
    WALLPAPER_SPECIAL_AZUMARILL,
    WALLPAPER_SPECIAL_PIKACHU,
    WALLPAPER_SPECIAL_DUSCLOPS,
    // Pokemon 2
    WALLPAPER_SPECIAL_LUDICOLO,
    WALLPAPER_SPECIAL_WHISCASH,
    WALLPAPER_SPECIAL_MINUN,
    // Other
    WALLPAPER_SPECIAL_CLASSIC1,
    // Pokemon 2
    WALLPAPER_SPECIAL_DIGLETT,
    WALLPAPER_SPECIAL_PICHU,
    // Team
    WALLPAPER_SPECIAL_AQUA1,
    WALLPAPER_SPECIAL_MAGMA1,
    WALLPAPER_SPECIAL_AQUA2,
    WALLPAPER_SPECIAL_MAGMA2,
    // Contest
    WALLPAPER_SPECIAL_CUTE,
    WALLPAPER_SPECIAL_SMART,
    WALLPAPER_SPECIAL_COOL,
    WALLPAPER_SPECIAL_TOUGH,
    WALLPAPER_SPECIAL_BEAUTY,
    // Legends
    WALLPAPER_SPECIAL_LEGENDARY,
    WALLPAPER_SPECIAL_LATIAS,
    WALLPAPER_SPECIAL_LATIOS,
    // Other
    WALLPAPER_SPECIAL_BLOCK,
    WALLPAPER_SPECIAL_POKECENTER,
    WALLPAPER_SPECIAL_CIRCLES,
    // Secret
    WALLPAPER_SPECIAL_EXCLSIOR,
    WALLPAPER_SPECIAL_VERITAS,
    // Other
    WALLPAPER_SPECIAL_CLASSIC2,
    WALLPAPER_COUNT
};
#define MAX_DEFAULT_WALLPAPER WALLPAPER_SAVANNA
#define WALLPAPER_SPECIAL_START WALLPAPER_SPECIAL_ZIGZAGOON
#define WALLPAPER_SPECIAL_COUNT (WALLPAPER_COUNT - WALLPAPER_SPECIAL_START)

static const u16 sWallpaperPalettes_Forest[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/forest/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/forest/bg.gbapal"),
};
static const u32 sWallpaperTiles_Forest[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/forest/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Forest[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/forest/tilemap.bin.lz");

static const u16 sWallpaperPalettes_City[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/city/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/city/bg.gbapal"),
};
static const u32 sWallpaperTiles_City[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/city/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_City[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/city/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Desert[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/desert/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/desert/bg.gbapal"),
};
static const u32 sWallpaperTiles_Desert[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/desert/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Desert[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/desert/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Savanna[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/savanna/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/savanna/bg.gbapal"),
};
static const u32 sWallpaperTiles_Savanna[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/savanna/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Savanna[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/savanna/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Crag[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/crag/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/crag/bg.gbapal"),
};
static const u32 sWallpaperTiles_Crag[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/crag/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Crag[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/crag/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Volcano[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/volcano/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/volcano/bg.gbapal"),
};
static const u32 sWallpaperTiles_Volcano[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/volcano/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Volcano[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/volcano/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Snow[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/snow/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/snow/bg.gbapal"),
};
static const u32 sWallpaperTiles_Snow[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/snow/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Snow[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/snow/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Cave[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/cave/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/cave/bg.gbapal"),
};
static const u32 sWallpaperTiles_Cave[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/cave/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Cave[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/cave/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Beach[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/beach/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/beach/bg.gbapal"),
};
static const u32 sWallpaperTiles_Beach[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/beach/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Beach[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/beach/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Seafloor[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/seafloor/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/seafloor/bg.gbapal"),
};
static const u32 sWallpaperTiles_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/seafloor/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/seafloor/tilemap.bin.lz");

static const u16 sWallpaperPalettes_River[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/river/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/river/bg.gbapal"),
};
static const u32 sWallpaperTiles_River[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/river/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_River[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/river/tilemap.bin.lz");
static const u16 sWallpaperPalettes_Sky[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/sky/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/sky/bg.gbapal"),
};
static const u32 sWallpaperTiles_Sky[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/sky/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Sky[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/sky/tilemap.bin.lz");

static const u16 sWallpaperPalettes_PolkaDot[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/polkadot/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/polkadot/bg.gbapal"),
};
static const u32 sWallpaperTiles_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/polkadot/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/polkadot/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Machine[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/machine/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/machine/bg.gbapal"),
};
static const u32 sWallpaperTiles_Machine[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/machine/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Machine[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/machine/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Plain[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/plain/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/plain/bg.gbapal"),
};
static const u32 sWallpaperTiles_Plain[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/plain/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Plain[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/plain/tilemap.bin.lz");

// 12x18 tilemap
static const u32 sWallpaperTilemap_Unused[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/unused.bin");

// Shadow color, text color
static const u16 sBoxTitleColors[WALLPAPER_COUNT][2] =
{
    [WALLPAPER_FOREST]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CITY]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_DESERT]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SAVANNA]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CRAG]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_VOLCANO]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SNOW]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CAVE]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_BEACH]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SEAFLOOR]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_RIVER]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SKY]        = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POLKADOT]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POKECENTER] = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_MACHINE]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_PLAIN]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_FRIENDS]    = {RGB(7, 7, 7), RGB_WHITE},
    // Special wallpapers (shadow #515151 = RGB(10,10,10), text #FFFFFF = RGB_WHITE)
    // Pokemon 1
    [WALLPAPER_SPECIAL_ZIGZAGOON]     = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_LUVDISC]       = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_TOGEPI]        = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_AZUMARILL]     = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_PIKACHU]       = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_DUSCLOPS]      = {RGB(10, 10, 10), RGB_WHITE},
    // Pokemon 2
    [WALLPAPER_SPECIAL_LUDICOLO]      = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_WHISCASH]      = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_MINUN]         = {RGB(10, 10, 10), RGB_WHITE},
    // Other
    [WALLPAPER_SPECIAL_CLASSIC1]      = {RGB(10, 10, 10), RGB_WHITE},
    // Pokemon 2
    [WALLPAPER_SPECIAL_DIGLETT]       = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_PICHU]         = {RGB(10, 10, 10), RGB_WHITE},
    // Team
    [WALLPAPER_SPECIAL_AQUA1]         = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_MAGMA1]        = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_AQUA2]         = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_MAGMA2]        = {RGB(10, 10, 10), RGB_WHITE},
    // Contest
    [WALLPAPER_SPECIAL_CUTE]          = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_SMART]         = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_COOL]          = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_TOUGH]         = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_BEAUTY]        = {RGB(10, 10, 10), RGB_WHITE},
    // Legends
    [WALLPAPER_SPECIAL_LEGENDARY]     = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_LATIAS]        = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_LATIOS]        = {RGB(10, 10, 10), RGB_WHITE},
    // Other
    [WALLPAPER_SPECIAL_BLOCK]         = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_POKECENTER]    = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_CIRCLES]       = {RGB(10, 10, 10), RGB_WHITE},
    // Secret
    [WALLPAPER_SPECIAL_EXCLSIOR]     = {RGB(10, 10, 10), RGB_WHITE},
    [WALLPAPER_SPECIAL_VERITAS]       = {RGB(10, 10, 10), RGB_WHITE},
    // Other
    [WALLPAPER_SPECIAL_CLASSIC2]      = {RGB(10, 10, 10), RGB_WHITE},
};

#define WALLPAPER_ENTRY(name) {sWallpaperTiles_##name, sWallpaperTilemap_##name, sWallpaperPalettes_##name[0]}
// A few wallpapers are not defined in this file
#define WALLPAPER_ENTRY_G(name) {gWallpaperTiles_##name, gWallpaperTilemap_##name, gWallpaperPalettes_##name[0]}

static const struct Wallpaper sWallpapers[WALLPAPER_COUNT - 1] =
{
    [WALLPAPER_FOREST]     = WALLPAPER_ENTRY(Forest),
    [WALLPAPER_CITY]       = WALLPAPER_ENTRY(City),
    [WALLPAPER_DESERT]     = WALLPAPER_ENTRY(Desert),
    [WALLPAPER_SAVANNA]    = WALLPAPER_ENTRY(Savanna),
    [WALLPAPER_CRAG]       = WALLPAPER_ENTRY(Crag),
    [WALLPAPER_VOLCANO]    = WALLPAPER_ENTRY(Volcano),
    [WALLPAPER_SNOW]       = WALLPAPER_ENTRY(Snow),
    [WALLPAPER_CAVE]       = WALLPAPER_ENTRY(Cave),
    [WALLPAPER_BEACH]      = WALLPAPER_ENTRY(Beach),
    [WALLPAPER_SEAFLOOR]   = WALLPAPER_ENTRY(Seafloor),
    [WALLPAPER_RIVER]      = WALLPAPER_ENTRY(River),
    [WALLPAPER_SKY]        = WALLPAPER_ENTRY(Sky),
    [WALLPAPER_POLKADOT]   = WALLPAPER_ENTRY(PolkaDot),
    [WALLPAPER_POKECENTER] = WALLPAPER_ENTRY(Pokecenter),
    [WALLPAPER_MACHINE]    = WALLPAPER_ENTRY(Machine),
    [WALLPAPER_PLAIN]      = WALLPAPER_ENTRY(Plain),
};

static const u8 sArrow_Gfx[] = INCBIN_U8("graphics/pokemon_storage/arrow.4bpp");

static const u16 sWallpaperPalettes_Zigzagoon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/zigzagoon/bg.gbapal"),
};
static const u32 sWallpaperTiles_Zigzagoon[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/zigzagoon/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/zigzagoon/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Screen[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/screen/bg.gbapal"),
};
static const u32 sWallpaperTiles_Screen[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/screen/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Screen[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/screen/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Diagonal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/diagonal/bg.gbapal"),
};
static const u32 sWallpaperTiles_Diagonal[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/diagonal/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Block[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/block/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/block/bg.gbapal"),
};
static const u32 sWallpaperTiles_Block[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/block/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Block[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/block/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter2[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter2[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Frame[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/frame/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/frame/bg.gbapal"),
};
static const u32 sWallpaperTiles_Frame[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/frame/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Frame[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/frame/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Blank[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/zigzagoon/bg.gbapal"),
};
static const u32 sWallpaperTiles_Blank[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/blank/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Blank[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/blank/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Circles[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/circles/bg.gbapal"),
};
static const u32 sWallpaperTiles_Circles[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/circles/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Circles[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/circles/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Azumarill[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/azumarill/bg.gbapal"),
};
static const u32 sWallpaperTiles_Azumarill[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/azumarill/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/azumarill/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pikachu[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pikachu/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pikachu[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/pikachu/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pikachu/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Legendary[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/legendary/bg.gbapal"),
};
static const u32 sWallpaperTiles_Legendary[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Legendary[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/legendary/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Dusclops[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/dusclops/bg.gbapal"),
};
static const u32 sWallpaperTiles_Dusclops[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/dusclops/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/dusclops/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Ludicolo[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ludicolo/bg.gbapal"),
};
static const u32 sWallpaperTiles_Ludicolo[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/ludicolo/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/ludicolo/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Whiscash[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/whiscash/bg.gbapal"),
};
static const u32 sWallpaperTiles_Whiscash[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/whiscash/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/whiscash/tilemap.bin.lz");

static const u32 sWallpaperIcon_Aqua[]         = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/aqua.4bpp.lz");
static const u32 sWallpaperIcon_Heart[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/heart.4bpp.lz");
static const u32 sWallpaperIcon_FiveStar[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/five_star.4bpp.lz");
static const u32 sWallpaperIcon_Brick[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/brick.4bpp.lz");
static const u32 sWallpaperIcon_FourStar[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/four_star.4bpp.lz");
static const u32 sWallpaperIcon_Asterisk[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/asterisk.4bpp.lz");
static const u32 sWallpaperIcon_Dot[]          = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/dot.4bpp.lz");
static const u32 sWallpaperIcon_LineCircle[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/line_circle.4bpp.lz");
static const u32 sWallpaperIcon_PokeBall[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/pokeball.4bpp.lz");
static const u32 sWallpaperIcon_Maze[]         = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/maze.4bpp.lz");
static const u32 sWallpaperIcon_Footprint[]    = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/footprint.4bpp.lz");
static const u32 sWallpaperIcon_BigAsterisk[]  = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/big_asterisk.4bpp.lz");
static const u32 sWallpaperIcon_Circle[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/circle.4bpp.lz");
static const u32 sWallpaperIcon_Koffing[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/koffing.4bpp.lz");
static const u32 sWallpaperIcon_Ribbon[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/ribbon.4bpp.lz");
static const u32 sWallpaperIcon_FourCircles[]  = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/four_circles.4bpp.lz");
static const u32 sWallpaperIcon_Lotad[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/lotad.4bpp.lz");
static const u32 sWallpaperIcon_Crystal[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/crystal.4bpp.lz");
static const u32 sWallpaperIcon_Pichu[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/pichu.4bpp.lz");
static const u32 sWallpaperIcon_Diglett[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/diglett.4bpp.lz");
static const u32 sWallpaperIcon_Luvdisc[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/luvdisc.4bpp.lz");
static const u32 sWallpaperIcon_StarInCircle[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/star_in_circle.4bpp.lz");
static const u32 sWallpaperIcon_Spinda[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/spinda.4bpp.lz");
static const u32 sWallpaperIcon_Latis[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/latis.4bpp.lz");
static const u32 sWallpaperIcon_Minun[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/minun.4bpp.lz");
static const u32 sWallpaperIcon_Togepi[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/togepi.4bpp.lz");
static const u32 sWallpaperIcon_Magma[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/magma.4bpp.lz");

static const struct Wallpaper sWaldaWallpapers[] =
{
    WALLPAPER_ENTRY(Zigzagoon),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY_G(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY_G(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(Azumarill),
    WALLPAPER_ENTRY(Pikachu),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(Dusclops),
    WALLPAPER_ENTRY(Ludicolo),
    WALLPAPER_ENTRY(Whiscash),
};

static const u32 *const sWaldaWallpaperIcons[] =
{
    sWallpaperIcon_Aqua,
    sWallpaperIcon_Heart,
    sWallpaperIcon_FiveStar,
    sWallpaperIcon_Brick,
    sWallpaperIcon_FourStar,
    sWallpaperIcon_Asterisk,
    sWallpaperIcon_Dot,
    gWallpaperIcon_Cross,
    sWallpaperIcon_LineCircle,
    sWallpaperIcon_PokeBall,
    sWallpaperIcon_Maze,
    sWallpaperIcon_Footprint,
    sWallpaperIcon_BigAsterisk,
    sWallpaperIcon_Circle,
    sWallpaperIcon_Koffing,
    sWallpaperIcon_Ribbon,
    gWallpaperIcon_Bolt,
    sWallpaperIcon_FourCircles,
    sWallpaperIcon_Lotad,
    sWallpaperIcon_Crystal,
    sWallpaperIcon_Pichu,
    sWallpaperIcon_Diglett,
    sWallpaperIcon_Luvdisc,
    sWallpaperIcon_StarInCircle,
    sWallpaperIcon_Spinda,
    sWallpaperIcon_Latis,
    gWallpaperIcon_Plusle,
    sWallpaperIcon_Minun,
    sWallpaperIcon_Togepi,
    sWallpaperIcon_Magma,
};

// Special wallpaper configuration (uses Walda-style rendering with fixed values)
struct SpecialWallpaperConfig {
    u8 patternId;
    u8 iconId;
    u16 bgColor;  // RGB555 format
    u16 fgColor;  // RGB555 format
};

static const struct SpecialWallpaperConfig sSpecialWallpapers[WALLPAPER_SPECIAL_COUNT] = {
    // Pokemon 1: Zigzagoon, Luvdisc, Togepi, Azumarill, Pikachu, Dusclops
    [WALLPAPER_SPECIAL_ZIGZAGOON - WALLPAPER_SPECIAL_START]   = {0,  11, RGB(28, 26, 21), RGB(21, 15, 11)}, // #e0d0a8, #a87858
    [WALLPAPER_SPECIAL_LUVDISC - WALLPAPER_SPECIAL_START]     = {2,  22, RGB(9, 27, 31),  RGB(31, 11, 17)}, // #4fd9ff, #f85888
    [WALLPAPER_SPECIAL_TOGEPI - WALLPAPER_SPECIAL_START]      = {3,  28, RGB(31, 31, 31), RGB(28, 26, 20)}, // #f8f8f8, #e0d0a0
    [WALLPAPER_SPECIAL_AZUMARILL - WALLPAPER_SPECIAL_START]   = {10, 6,  RGB(11, 21, 28), RGB(31, 31, 31)}, // #58a8e0, #f8f8f8
    [WALLPAPER_SPECIAL_PIKACHU - WALLPAPER_SPECIAL_START]     = {11, 1,  RGB(26, 14, 11), RGB(31, 11, 17)}, // #d07058, #f85888
    [WALLPAPER_SPECIAL_DUSCLOPS - WALLPAPER_SPECIAL_START]    = {13, 8,  RGB(11, 10, 14), RGB(17, 18, 19)}, // #5c5270, #8e969e
    // Pokemon 2: Ludicolo, Whiscash, Minun
    [WALLPAPER_SPECIAL_LUDICOLO - WALLPAPER_SPECIAL_START]    = {14, 18, RGB(16, 25, 12), RGB(25, 25, 12)}, // #80c860, #c8c860
    [WALLPAPER_SPECIAL_WHISCASH - WALLPAPER_SPECIAL_START]    = {15, 12, RGB(26, 25, 11), RGB(13, 15, 22)}, // #d0ca5d, #6878b0
    [WALLPAPER_SPECIAL_MINUN - WALLPAPER_SPECIAL_START]       = {4,  27, RGB(29, 27, 21), RGB(12, 17, 27)}, // #e9ddad, #638fdd
    // Other: Classic 1
    [WALLPAPER_SPECIAL_CLASSIC1 - WALLPAPER_SPECIAL_START]    = {4,  9,  RGB(0, 0, 0),    RGB(31, 31, 31)}, // #000000, #ffffff
    // Pokemon 2: Diglett, Pichu
    [WALLPAPER_SPECIAL_DIGLETT - WALLPAPER_SPECIAL_START]     = {7,  21, RGB(20, 13, 8),  RGB(28, 22, 18)}, // #a66a42, #e0b192
    [WALLPAPER_SPECIAL_PICHU - WALLPAPER_SPECIAL_START]       = {3,  20, RGB(1, 0, 0),    RGB(30, 28, 7)},  // #080700, #f6e03a
    // Team: Aqua 1, Magma 1, Aqua 2, Magma 2
    [WALLPAPER_SPECIAL_AQUA1 - WALLPAPER_SPECIAL_START]       = {1,  0,  RGB(21, 25, 30), RGB(6, 12, 24)},  // #a8c8f0, #3060c0
    [WALLPAPER_SPECIAL_MAGMA1 - WALLPAPER_SPECIAL_START]      = {7,  29, RGB(24, 10, 10), RGB(20, 0, 0)},   // #c05656, #a00000
    [WALLPAPER_SPECIAL_AQUA2 - WALLPAPER_SPECIAL_START]       = {10, 0,  RGB(9, 11, 15),  RGB(31, 31, 31)}, // #4d5d7d, #f8f8f8
    [WALLPAPER_SPECIAL_MAGMA2 - WALLPAPER_SPECIAL_START]      = {2,  29, RGB(9, 2, 2),    RGB(20, 0, 0)},   // #4d1616, #a00000
    // Contest: Cute, Smart, Cool, Tough, Beauty (Pattern 5=Ribbon, Icon 15=Ribbon)
    [WALLPAPER_SPECIAL_CUTE - WALLPAPER_SPECIAL_START]        = {5,  15, RGB(28, 18, 21), RGB(23, 11, 14)}, // #e090a8, #b95875
    [WALLPAPER_SPECIAL_SMART - WALLPAPER_SPECIAL_START]       = {5,  15, RGB(12, 25, 13), RGB(12, 19, 12)}, // #64ce6e, #609a66
    [WALLPAPER_SPECIAL_COOL - WALLPAPER_SPECIAL_START]        = {5,  15, RGB(28, 7, 7),   RGB(21, 9, 9)},   // #e53d3d, #ab4b4b
    [WALLPAPER_SPECIAL_TOUGH - WALLPAPER_SPECIAL_START]       = {5,  15, RGB(27, 21, 0),  RGB(21, 17, 2)},  // #d9ab01, #a98916
    [WALLPAPER_SPECIAL_BEAUTY - WALLPAPER_SPECIAL_START]      = {5,  15, RGB(3, 24, 29),  RGB(6, 15, 24)},  // #1bc7e9, #357bc0
    // Legends: Legendary, Latias, Latios
    [WALLPAPER_SPECIAL_LEGENDARY - WALLPAPER_SPECIAL_START]   = {12, 25, RGB(11, 11, 24), RGB(24, 11, 11)}, // #5959c1, #c15959
    [WALLPAPER_SPECIAL_LATIAS - WALLPAPER_SPECIAL_START]      = {7,  25, RGB(29, 12, 14), RGB(6, 12, 24)},  // #ed6374, #3060c0
    [WALLPAPER_SPECIAL_LATIOS - WALLPAPER_SPECIAL_START]      = {7,  25, RGB(6, 12, 24),  RGB(29, 12, 14)}, // #3060c0, #ed6374
    // Other: Block, Pokecenter, Circles
    [WALLPAPER_SPECIAL_BLOCK - WALLPAPER_SPECIAL_START]       = {4,  3,  RGB(21, 17, 14), RGB(12, 0, 0)},   // #ae8976, #610000
    [WALLPAPER_SPECIAL_POKECENTER - WALLPAPER_SPECIAL_START]  = {6,  9,  RGB(29, 29, 29), RGB(29, 12, 14)}, // #ede9ee, #ed6576
    [WALLPAPER_SPECIAL_CIRCLES - WALLPAPER_SPECIAL_START]     = {9,  24, RGB(28, 26, 20), RGB(11, 8, 6)},   // #e0d0a0, #584030
    // Secret
    [WALLPAPER_SPECIAL_EXCLSIOR - WALLPAPER_SPECIAL_START]   = {6,  25, RGB(6, 12, 24),  RGB(29, 12, 14)}, // #3060c0, #ed6374
    [WALLPAPER_SPECIAL_VERITAS - WALLPAPER_SPECIAL_START]     = {6,  0,  RGB(2, 7, 17),   RGB(0, 1, 8)},    // #163e8f, #000840
    // Other: Classic 2
    [WALLPAPER_SPECIAL_CLASSIC2 - WALLPAPER_SPECIAL_START]    = {4,  9,  RGB(22, 24, 17), RGB(16, 17, 14)}, // #b5c08c, #858f76
};
