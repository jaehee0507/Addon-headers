#pragma once

#include <vector>
#include <memory>

class Level;
class ChunkSource;
class Dimension;
class TileSourceListener;
class FullTile;
class TileID;
class TilePos;
class Vec3;
class AABB;
class Material;
class TileEntity;
class LightLayer;
class ChunkPos;
class Entity;
class EntityType;
class Bounds;
class Mob;
class Brightness;
class Tile;
class TileTickingQueue;
class LevelChunk;
class HitResult;

//Size : 68
class TileSource {
    public:
    //void** vtable;                                            //0
    char filler1[8];                                            //4
    Level* level;                                               //12
    ChunkSource* chunkSource;                                   //16
    Dimension* dimesion;                                        //20
    std::vector<TileSourceListener*> tilelistenerVec;           //24
    char filler2[32];                                           //36
    
    public:
    TileSource(Level&, Dimension&, ChunkSource&, bool, bool);
    virtual ~TileSource();;
    void _neighborChanged(TilePos const&, TilePos const&, TileID);
    void _tileChanged(TilePos const&, FullTile, FullTile, int);
    bool canSeeSky(int, int, int);
    bool canSeeSky(TilePos const&);
    bool checkIsTopRainTilePos(TilePos const&);
    void clearCachedLastChunk();
    void clip(HitResult&, Vec3 const&, Vec3 const&, bool, bool);
    bool containsAny(TilePos const&, TilePos const&);
    bool containsAnyLiquid(AABB const&);
    bool containsFireTile(AABB const&);
    bool containsLiquid(AABB const&, Material const*);
    bool containsMaterial(AABB const&, Material const*);
    void fetchAABBs(AABB const&, bool);
    void fetchCollisionShapes(TileSource&, AABB const&, float*, bool);
    void findNextTopSolidTileUnder(TilePos&);
    void fireAreaChanged(TilePos const&, TilePos const&);
    void fireBrightnessChanged(TilePos const&);
    void fireTileChanged(TilePos const&, FullTile, FullTile, int);
    void fireTileEntityChanged(TileEntity&);
    void fireTileEntityRemoved(std::unique_ptr<TileEntity>);
    void fireTileEvent(int, int, int, int, int);
    void fireTilesDirty(int, int, int, int, int, int);
    void getBiome(TilePos const&);
    int getBrightness(int, int, int);
    int getBrightness(LightLayer const&, int, int, int);
    int getBrightness(LightLayer const&, TilePos const&);
    int getBrightness(TilePos const&);
    void getChunk(ChunkPos const&);
    void getChunk(int, int);
    void getChunkAt(int, int, int);
    void getChunkAt(TilePos const&);
    void getData(int, int, int);
    void getData(TilePos const&);
    void getDimension() const;
    void getDimensionConst() const;
    void getDimensionId() const;
    void getEntities(Entity*, AABB const&);
    void getEntities(EntityType, AABB const&, Entity*);
    void getExtraData(TilePos const&);
    void getGrassColor(TilePos const&);
    void getHeightmap(int, int);
    void getHeightmap(TilePos const&);
    void getHeightmapPos(TilePos const&);
    Level* getLevel() const;
    Level* getLevelConst() const;
    void getLightColor(TilePos const&, int);
    Material* getMaterial(int, int, int);
    Material* getMaterial(TilePos const&);
    void getMobsAt(EntityType, TilePos const&);
    void getNearestEntityOfType(Entity*, AABB const&, EntityType);
    void getNearestEntityOfType(Entity*, Vec3 const&, float, EntityType);
    void getRawBrightness(int, int, int, bool);
    void getRawBrightness(TilePos const&, bool);
    void getSeenPercent(Vec3 const&, AABB const&);
    void getSkyDarken();
    void getTickQueue(TilePos const&);
    TileID getTile(int, int, int);
    TileID getTile(TilePos const&);
    FullTile getTileAndData(int, int, int);
    FullTile getTileAndData(TilePos const&);
    void getTileEntity(int, int, int);
    void getTileEntity(TilePos const&);
    Tile* getTilePtr(int, int, int);
    Tile* getTilePtr(TilePos const&);
    void getTopRainTilePos(TilePos const&);
    void getTopSolidBlock(int, int, bool);
    void getTopSolidBlock(TilePos const&, bool);
    void getWritableChunk(ChunkPos const&);
    bool hasChunksAt(AABB const&);
    bool hasChunksAt(Bounds const&);
    bool hasChunksAt(int, int, int, int);
    bool hasChunksAt(TilePos const&, int);
    bool hasChunksAt(TilePos const&, TilePos const&);
    bool hasNeighborSignal(int, int, int);
    bool hasTile(int, int, int);
    bool hasTile(TilePos const&);
    bool isEmptyTile(int, int, int);
    bool isEmptyTile(TilePos const&);
    bool isHumidAt(TilePos const&);
    bool isIceAt(TilePos const&);
    bool isOwnerThread() const;
    bool isSnowTemperature(TilePos const&);
    bool isSolidBlockingTile(int, int, int);
    bool isSolidBlockingTile(TilePos const&);
    bool isSolidRenderTile(int, int, int);
    bool isSolidRenderTile(TilePos const&);
    bool isTopSolidBlocking(int, int, int);
    bool isTopSolidBlocking(Tile*, unsigned char);
    bool isTopSolidBlocking(TilePos const&);
    bool isUnobstructedByEntities(AABB const&, Entity*);
    bool isWaterAt(TilePos const&);
    void mayPlace(TileID, TilePos const&, signed char, Mob*, bool, Entity*);
    void onChunkDiscarded(LevelChunk&);
    void removeTile(int, int, int);
    void runLightUpdates(LightLayer const&, TilePos const&, TilePos const&);
    void setBrightness(LightLayer const&, int, int, int, Brightness);
    void setBrightness(LightLayer const&, TilePos const&, Brightness);
    void setExtraData(TilePos const&, unsigned short);
    void setGrassColor(int, TilePos const&, int);
    void setTickingQueue(TileTickingQueue&);
    void setTile(int, int, int, TileID, int);
    void setTileAndData(int, int, int, FullTile, int);
    void setTileAndData(TilePos const&, FullTile, int);
    void setTileAndDataNoUpdate(int, int, int, FullTile);
    void setTileNoUpdate(int, int, int, TileID);
    void shouldFireEvents(LevelChunk&) const;
    void shouldFreeze(TilePos const&, bool);
    void shouldFreezeIgnoreNeighbors(TilePos const&);
    void shouldThaw(TilePos const&, bool);
    void tileEvent(int, int, int, int, int);
    void tileEvent(TilePos const&, int, int);
    void updateLightIfOtherThan(LightLayer const&, TilePos const&, Brightness);
    void updateNeighborsAt(TilePos const&, TileID);
};
