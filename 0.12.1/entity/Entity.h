#pragma once

#include <string>
#include <vector>
#include "SyncedEntityData.h"
#include "../util/AABB.h"

class TileSource;
class Level;
class Vec3;
class Vec2;
class Material;
class Player;
class EntityDamageSource;
class EntityEvent;
class ItemInstance;
class CompoundTag;
class EntityLink;
class DimensionId;
class ChangeDimensionPacket;
class EntityPos;
class TilePos;
class Random;
class EntityUniqueID;

//Size : 360
class Entity {
    public:
    //void** vtable;                        //0
    char filler1[4];                        //4
    SyncedEntityData data;                  //8
    float posX;                             //24
    float posY;                             //28
    float posZ;                             //32
    char filler2[12];                       //36
    TileSource* tileSource;                 //48
    char filler3[8];                        //52
    Level* level;                           //60
    float prevPosX;                         //64
    float prevPosY;                         //68
    float prevPosZ;                         //72
    float motionX;                          //76
    float motionY;                          //80
    float motionZ;                          //84
    float rotationYaw;                      //88
    float rotationPitch;                    //92
    float prevRotationYaw;                  //96
    float prevRotationPitch;                //100
    char filler4[56];                       //104
    AABB boundingBox;                       //160
    char filler5[4];                        //188
    float width;                            //192
    float height;                           //196
    char filler6[44];                       //200
    int fireResistance;                     //244
    char filler7[24];                       //248
    std::vector<Entity*> ridingEntities;    //272
    char filler8[76];                       //284
    
    public:
    Entity(Level&);
    Entity(TileSource&);
    virtual ~Entity();
    virtual void _postInit();
    virtual void reset();
    virtual void getOwnerEntityType();
    virtual void remove();
    virtual void setPos(float, float, float);
    virtual void setPos(Vec3 const&);
    virtual void getPos() const;
    virtual void getPosOld() const;
    virtual void getPosExtrapolated(float) const;
    virtual void getVelocity() const;
    virtual void setRot(float, float);
    virtual void move(float, float, float);
    virtual void checkTileCollisions();
    virtual void moveTo(float, float, float, float, float);
    virtual void moveRelative(float, float, float);
    virtual void lerpTo(Vec3 const&, Vec2 const&, int);
    virtual void lerpMotion(float, float, float);
    virtual void turn(float, float);
    virtual void interpolateTurn(float, float);
    virtual void getAddPacket();
    virtual void normalTick();
    virtual void baseTick();
    virtual void rideTick();
    virtual void positionRider(Entity&) const;
    virtual void getRidingHeight();
    virtual void getRideHeight() const;
    virtual void getRideUseAnimation() const;
    virtual void startRiding(Entity&);
    virtual void addRider(Entity&);
    virtual void removeRider(Entity&);
    virtual void intersects(float, float, float, float, float, float);
    virtual bool isFree(float, float, float, float);
    virtual bool isFree(float, float, float);
    virtual bool isInWall();
    virtual bool isInvisible();
    virtual bool canShowNameTag();
    virtual void setNameTagVisible(bool);
    virtual std::string getNameTag() const;
    virtual bool setNameTag(std::string const&);
    virtual bool isInWater() const;
    virtual bool isInWaterOrRain();
    virtual bool isInLava();
    virtual bool isUnderLiquid(Material const*) const;
    virtual void getShadowRadius() const;
    virtual void makeStuckInWeb();
    virtual void getHeadHeight() const;
    virtual void getShadowHeightOffs();
    virtual bool isSkyLit(float);
    virtual void getBrightness(float);
    virtual void interactPreventDefault();
    virtual void interactWithPlayer(Player*);
    virtual bool canInteractWith(Player*);
    virtual std::string getInteractText(Player*);
    virtual void playerTouch(Player*);
    virtual void push(Entity*);
    virtual void push(float, float, float);
    virtual bool isImmobile();
    virtual bool isSilent();
    virtual bool isPickable();
    virtual bool isPushable();
    virtual bool isShootable();
    virtual bool isSneaking() const;
    virtual bool isAlive();
    virtual bool isOnFire() const;
    virtual bool isCreativeModeAllowed();
    virtual bool isSurfaceMob() const;
    virtual void shouldRenderAtSqrDistance(float);
    virtual void hurt(EntityDamageSource const&, int);
    virtual void animateHurt();
    virtual void doFireHurt(int);
    virtual void onLightningHit();
    virtual void handleEntityEvent(EntityEvent);
    virtual void getPickRadius();
    virtual void spawnAtLocation(int, int);
    virtual void spawnAtLocation(int, int, float);
    virtual void spawnAtLocation(ItemInstance const&, float);
    virtual void awardKillScore(Entity*, int);
    virtual void setEquippedSlot(int, int, int);
    virtual void setEquippedSlot(int, ItemInstance const&);
    virtual void save(CompoundTag&);
    virtual void saveWithoutId(CompoundTag&);
    virtual void load(CompoundTag const&);
    virtual void loadLinks(CompoundTag const&, std::vector<EntityLink>&);
    virtual void getEntityTypeId() const = 0;
    virtual void queryEntityRenderer();
    virtual void getSourceUniqueID();
    virtual void setOnFire(int);
    virtual void getHandleWaterAABB() const;
    virtual void handleInsidePortal();
    virtual void getPortalCooldown() const;
    virtual void getPortalWaitTime() const;
    virtual void getDimensionId() const;
    virtual void changeDimension(DimensionId);
    virtual void changeDimension(ChangeDimensionPacket&);
    virtual void getControllingPlayer() const;
    virtual void checkFallDamage(float, bool);
    virtual void causeFallDamage(float);
    virtual void setSize(float, float);
    virtual void setPos(EntityPos*);
    virtual void outOfWorld();
    virtual void markHurt();
    virtual void burn(int);
    virtual void lavaHurt();
    virtual void readAdditionalSaveData(CompoundTag*) = 0;
    virtual void addAdditionalSaveData(CompoundTag*) = 0;
    virtual void playStepSound(int, int, int, int);
    virtual void checkInsideTiles(float);
    virtual void pushOutOfTiles(float, float, float);
    virtual void _updateWaterState();
    virtual void _doWaterSplashEffect();
    virtual void _updatePortalState();
    virtual void onTileCollision(int);
    virtual void playSound(std::string const&, float, float);
    virtual void onSynchedDataUpdate(int);
    virtual void canAddRider(Entity&) const;
    virtual void sendMotionPacketIfNeeded();
    virtual void stopRiding(bool);
    virtual void buildDebugInfo(std::string&) const;
    void _findRider(Entity&) const;
    void _init();
    void _manageRiders(TileSource&);
    void _sendLinkPacket(EntityLink const&) const;
    void _tryPlaceAt(Vec3 const&);
    void _updateOwnerChunk();
    void buildForward() const;
    void distanceSqrToBlockPosCenter(TilePos const&);
    float distanceTo(Entity*);
    float distanceTo(float, float, float);
    float distanceToSqr(Entity*);
    float distanceToSqr(float, float, float);
    void enableAutoSendPosRot(bool);
    void exitRide(Entity const&, float);
    void getCenter(float);
    void getInterpolatedPosition(float) const;
    void getInterpolatedPosition2(float) const;
    void getInterpolatedRotation(float) const;
    void getLinks() const;
    void getPortalWaitTime() const;
    void getRandomPointInAABB(Random&);
    void getRotation() const;
    void getStatusFlag(int) const;
    void getUniqueID() const;
    void getViewVector(float) const;
    void getViewVector2(float) const;
    void hasUniqueID() const;
    bool isControlledByLocalInstance() const;
    bool isInClouds() const;
    bool isRide() const;
    bool isRider(Entity&) const;
    bool isRiding() const;
    void moveTo(Vec3 const&, Vec2 const&);
    bool operator==(Entity&);
    void removeAllRiders();
    void saveLinks() const;
    void sendMotionToServer();
    void setRegion(TileSource&);
    void setRot(Vec2 const&);
    void setStatusFlag(int, bool);
    void setUniqueID(EntityUniqueID);
    void shouldRender() const;
    void tick(TileSource&);
};
