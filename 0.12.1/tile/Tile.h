#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../util/Brightness.h"
#include "../util/TileID.h"
#include "../util/AABB.h"
#include "../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../client/renderer/texture/TextureAtlasTextureItem.h"

class Material;
class TextureAtlas;
class TileSource;
class Entity;
class TilePos;
class Random;
class Player;
class Vec3;
class Mob;
class ItemInstance;
class FullTile;
enum EntityType {};
enum TileType {};

//Size : 140
class Tile {
    public:
    class SoundType {
        public:
        float volume;
        float frequency;
        std::string name;
        std::string idk1;
        std::string idk2;
        
        public:
        SoundType(std::string const&, float, float);
        ~SoundType();
    };
    
    public:
    static Tile* activatorRail;
    static Tile* anvil;
    static Tile* bed;
    static Tile* bookshelf;
    static Tile* brewing_stand;
    static Tile* brownMushroom;
    static Tile* brownMushroomBlock;
    static Tile* cactus;
    static Tile* cake;
    static Tile* calmLava;
    static Tile* calmWater;
    static Tile* carrots;
    static Tile* clay;
    static Tile* cloth;
    static Tile* coalBlock;
    static Tile* coalOre;
    static Tile* cobbleWall;
    static Tile* cocoa;
    static Tile* deadBush;
    static Tile* diamondBlock;
    static Tile* diamondOre;
    static Tile* dirt;
    static Tile* door_iron;
    static Tile* door_wood;
    static Tile* emeraldBlock;
    static Tile* emeraldOre;
    static Tile* enchantingTable;
    static Tile* endPortalFrame;
    static Tile* endStone;
    static Tile* farmland;
    static Tile* fence;
    static Tile* fenceGateAcacia;
    static Tile* fenceGateBigOak;
    static Tile* fenceGateBirch;
    static Tile* fenceGateJungle;
    static Tile* fenceGateOak;
    static Tile* fenceGateSpruce;
    static Tile* fire;
    static Tile* furnace;
    static Tile* glass;
    static Tile* glowingObsidian;
    static Tile* goldBlock;
    static Tile* goldOre;
    static Tile* goldenRail;
    static Tile* grass;
    static Tile* grassPathBlock;
    static Tile* gravel;
    static Tile* hardenedClay;
    static Tile* hayBlock;
    static Tile* ice;
    static Tile* info_reserved6;
    static Tile* info_updateGame1;
    static Tile* info_updateGame2;
    static Tile* invisible_bedrock;
    static Tile* ironBlock;
    static Tile* ironFence;
    static Tile* ironOre;
    static Tile* ladder;
    static Tile* lapisBlock;
    static Tile* lapisOre;
    static Tile* lava;
    static Tile* leaves;
    static Tile* leaves2;
    static Tile* lightGem;
    static Tile* litPumpkin;
    static Tile* log;
    static Tile* log2;
    static Tile* melon;
    static Tile* melonStem;
    static Tile* mobSpawner;
    static Tile* monsterStoneEgg;
    static Tile* mossStone;
    static Tile* mycelium;
    static Tile* netherBrick;
    static Tile* netherFence;
    static Tile* netherReactor;
    static Tile* netherrack;
    static Tile* obsidian;
    static Tile* packedIce;
    static Tile* podzol;
    static Tile* portal;
    static Tile* potatoes;
    static Tile* pumpkin;
    static Tile* pumpkinStem;
    static Tile* quartzBlock;
    static Tile* quartzOre;
    static Tile* rail;
    static Tile* redBrick;
    static Tile* redFlower;
    static Tile* redMushroom;
    static Tile* redMushroomBlock;
    static Tile* redStoneOre;
    static Tile* redstoneBlock;
    static Tile* reeds;
    static Tile* rock;
    static Tile* sand;
    static Tile* sandStone;
    static Tile* sapling;
    static Tile* sign;
    static Tile* skull;
    static Tile* snow;
    static Tile* soulSand;
    static Tile* sponge;
    static Tile* stainedClay;
    static Tile* stairs_brick;
    static Tile* stairs_netherBricks;
    static Tile* stairs_quartz;
    static Tile* stairs_sandStone;
    static Tile* stairs_stone;
    static Tile* stairs_stoneBrickSmooth;
    static Tile* stairs_wood;
    static Tile* stoneBrick;
    static Tile* stoneBrickSmooth;
    static Tile* stoneSlab;
    static Tile* stoneSlabHalf;
    static Tile* stonecutterBench;
    static Tile* tallgrass;
    static Tile* thinGlass;
    static Tile* topSnow;
    static Tile* torch;
    static Tile* trapdoor;
    static Tile* unbreakable;
    static Tile* vine;
    static Tile* wallSign;
    static Tile* water;
    static Tile* waterlily;
    static Tile* web;
    static Tile* wood;
    static Tile* woodSlab;
    static Tile* woodSlabHalf;
    static Tile* woodStairsAcacia;
    static Tile* woodStairsBigOak;
    static Tile* woodStairsBirch;
    static Tile* woodStairsDark;
    static Tile* woodStairsJungle;
    static Tile* workBench;
    static Tile* yellowFlower;
    
    public:
    static SoundType SOUND_CLOTH;
    static SoundType SOUND_GLASS;
    static SoundType SOUND_GRASS;
    static SoundType SOUND_GRAVEL;
    static SoundType SOUND_LADDER;
    static SoundType SOUND_METAL;
    static SoundType SOUND_NORMAL;
    static SoundType SOUND_SAND;
    static SoundType SOUND_SILENT;
    static SoundType SOUND_STONE;
    static SoundType SOUND_WOOD;
    
    public:
    static const char* TILE_DESCRIPTION_PREFIX;
    static TextureAtlas* _terrainTextureAtlas;
    
    public:
    static Brightness lightBlock[255];
    static float lightEmission[255];
    static bool shouldTick[255];
    static bool solid[255];
    static float translucency[255];
    static Tile* tiles[255];
    
    public:
    //void** vtable;                                            //0
    char filler1[4];                                            //4
    AABB aabb;                                                  //8
    TextureUVCoordinateSet texture;                             //36
    TileID tileId;                                              //68
    Tile::SoundType soundType;                                  //72
    char filler2[16];                                           //92
    Material* material;                                         //108
    float friction;                                             //112
    float hardness;                                             //116
    float explosionResistance;                                  //120
    int category;                                               //124
    char filler3[8];                                            //128
    std::string blockName;                                      //136
    
    public:
    Tile(int, Material const*);
    Tile(int, TextureUVCoordinateSet, Material const*);
    Tile(int, std::string const&, Material const*);
    virtual ~Tile();
    virtual void onFertilized(TileSource*, int, int, int);
    virtual void getVisualShape(TileSource*, int, int, int, AABB&, bool);
    virtual void getVisualShape(unsigned char, AABB&, bool);
    virtual void getCollisionShape(AABB&, TileSource&, int, int, int);
    virtual void isObstructingChests(TileSource*, int, int, int);
    virtual void shouldRenderFace(TileSource*, int, int, int, signed char, AABB const&) const;
    virtual void getTexture(signed char);
    virtual void getTexture(signed char, int);
    virtual void getTexture(TileSource*, int, int, int, signed char);
    virtual void getTessellatedUVs();
    virtual void getCarriedTexture(signed char, int);
    virtual void getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
    virtual void addAABBs(TileSource*, int, int, int, AABB const*, std::vector<AABB>&);
    virtual void addCollisionShapes(TileSource&, int, int, int, AABB const*, std::vector<AABB>&);
    virtual void getRenderLayer(TileSource*, TilePos const&) const;
    virtual void getThickness() const;
    virtual bool isCropTile() const;
    virtual bool isContainerTile() const;
    virtual bool isCraftingTile() const;
    virtual bool isInteractiveTile() const;
    virtual bool isPathfindable(Entity*, TilePos const&, int, int, int);
    virtual bool mayPick();
    virtual bool mayPick(TileSource*, int, bool);
    virtual bool mayPlace(TileSource*, int, int, int, signed char);
    virtual bool mayPlace(TileSource*, int, int, int);
    virtual void tryToPlace(TileSource*, TilePos const&, unsigned char);
    virtual void tick(TileSource*, int, int, int, Random*);
    virtual void animateTick(TileSource*, int, int, int, Random*);
    virtual void destroy(TileSource*, int, int, int, int, Entity*);
    virtual void playerWillDestroy(Player*, int, int, int, int);
    virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
    virtual void onPlace(TileSource*, int, int, int);
    virtual void onRemove(TileSource*, int, int, int);
    virtual TilePos* getSecondPart(TileSource&, TilePos const&, TilePos&);
    virtual void onGraphicsModeChanged(bool, bool);
    virtual int getResource(Random*, int, int);
    virtual int getResourceCount(Random*, int, int);
    virtual float getDestroyProgress(Player*);
    virtual void spawnResources(TileSource*, int, int, int, int, float, int);
    virtual void spawnBurnResources(TileSource*, float, float, float);
    virtual void getExplosionResistance(Entity*);
    virtual void clip(TileSource*, int, int, int, Vec3 const&, Vec3 const&, bool, int);
    virtual bool wasExploded(TileSource*, int, int, int, Entity*);
    virtual void use(Player*, int, int, int);
    virtual void stepOn(Entity*, int, int, int);
    virtual void fallOn(TileSource*, int, int, int, Entity*, float);
    virtual void getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int);
    virtual void prepareRender(TileSource*, int, int, int);
    virtual void attack(Player*, int, int, int);
    virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&);
    virtual void getColor(int);
    virtual void getColor(TileSource*, int, int, int);
    virtual bool isSeasonTinted(TileSource*, TilePos const&) const;
    virtual bool isSignalSource();
    virtual void getSignal(TileSource*, int, int, int);
    virtual void getSignal(TileSource*, int, int, int, int);
    virtual void getDirectSignal(TileSource*, int, int, int, int);
    virtual bool entityInside(TileSource*, int, int, int, Entity*);
    virtual void playerDestroy(Player*, int, int, int, int);
    virtual bool canSurvive(TileSource*, int, int, int);
    virtual void getExperienceDrop(Random*) const;
    virtual void canBeBuiltOver(TileSource&, int, int, int) const;
    virtual void setNameId(std::string const&);
    virtual std::string getName(ItemInstance const*) const;
    virtual void triggerEvent(TileSource*, int, int, int, int, int);
    virtual int getTextureNum(int);
    virtual void getMobToSpawn(TileSource&, TilePos const&) const;
    virtual void getIconYOffset() const;
    virtual void shouldStopFalling(Entity*);
    virtual void calcGroundFriction(Mob*, TilePos const&) const;
    virtual void canHaveExtraData() const;
    virtual void setVisualShape(float, float, float, float, float, float);
    virtual void setSoundType(Tile::SoundType const&);
    virtual void setLightBlock(Brightness);
    virtual void setLightEmission(float);
    virtual void setExplodeable(float);
    virtual void setDestroyTime(float);
    virtual void setFriction(float);
    virtual void setTicking(bool);
    virtual void getSpawnResourcesAuxValue(int);
    virtual void init();
    virtual bool _canBeSilkTouched() const;
    virtual ItemInstance* getSilkTouchItemInstance(int);
    void _getTypeToSpawn(TileSource&, EntityType, TilePos const&) const;
    void addAABB(AABB const&, AABB const*, std::vector<AABB>&);
    void destroyEffect(TileSource&, TilePos const&, Vec3 const&);
    static void getLightEmission(TileID);
    void getShadeBrightness() const;
    static TextureAtlasTextureItem getTextureItem(std::string const&);
    static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);
    static Material* getTileMaterial(int);
    static void initTiles();
    static bool isFaceVisible(TileSource*, int, int, int, signed char);
    bool isLiquidTile() const;
    bool isObstructingChests(TileSource*, TilePos const&);
    static bool isTileType(FullTile const&, TileType);
    void popResource(TileSource*, int, int, int, ItemInstance const&);
    void setCategory(int);
    static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
    static void teardownTiles();
    void transformToValidBlockId(TileID);
    void transformToValidBlockId(TileID, int, int, int);
};

