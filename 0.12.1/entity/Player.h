#pragma once

#include "Mob.h"
#include "Abilities.h"
#include "../item/ItemInstance.h"
#include "../attributes/Attribute.h"
#include "../util/TilePos.h"
#include "../network/RakNetGUID.h"

class PacketSender;
namespace mce {
    class UUID;
}
class Inventory;
class PlayerChunkSource;
class SkinInfoData;
class BatchPacket;
class ChunkSource;
class Tick;
class TileEntity;
class TelemetryEventPacket;
class Packet;
class ChestTileEntity;
class FurnaceTileEntity;
class EnchantingTableEntity;
class BrewingStandTileEntity;
class FoodItem;

//Size : 3592
class Player : public Mob {
    public:
    bool isCarryingItem;                        //3326
    char filler1[25];                           //3327
    int score;                                  //3352
    char filler2[8];                            //3356
    std::string name;                           //3364
    Abilities abilities;                        //3368
    char filler3[8];                            //3384
    RakNet::RakNetGUID guid;                    //3392
    char filler4[54];                           //3402
    Inventory* inventory;                       //3456
    char filler5[4];                            //3460
    PlayerChunkSource* chunkSource;             //3464
    char filler6[4];                            //3468
    TilePos spawnPos;                           //3472
    char filler7[32];                           //3484
    SkinInfoData* skinData;                     //3516
    char filler8[12];                           //3520
    ItemInstance item;                          //3532
    char filler9[4];                            //3552
    short sleepingTime;                         //3556
    char filler10[10];                          //3558
    BatchPacket* batchPacket;                   //3568
    char filler11[16];                          //3572
    bool _isSleeping;                           //3584
    GameType* gamemode;                         //3588
    
    public:
    static float DEFAULT_FLY_SPEED;
    static float DEFAULT_PLAYER_HEIGHT_OFFSET;
    static float DEFAULT_WALK_SPEED;
    static Attribute EXHAUSTION;
    static Attribute EXPERIENCE;
    static Attribute HUNGER;
    static Attribute LEVEL;
    static Attribute SATURATION;
    
    public:
    Player(Level&, PacketSender&, GameType, RakNet::RakNetGUID const&, std::unique_ptr<SkinInfoData>, mce::UUID);
    virtual ~Player();
    virtual void remove();
    virtual void checkTileCollisions();
    virtual void getAddPacket();
    virtual void normalTick();
    virtual void rideTick();
    virtual void getRidingHeight();
    virtual bool isInWall();
    virtual void getHeadHeight() const;
    virtual bool isImmobile();
    virtual bool isPushable();
    virtual bool isShootable();
    virtual bool isCreativeModeAllowed();
    virtual void hurt(EntityDamageSource const&, int);
    virtual void handleEntityEvent(EntityEvent);
    virtual void awardKillScore(Entity*, int);
    virtual int getEntityTypeId() const;
    virtual void getPortalCooldown() const;
    virtual void getPortalWaitTime() const;
    virtual void lavaHurt();
    virtual void readAdditionalSaveData(CompoundTag const*);
    virtual void addAdditionalSaveData(CompoundTag*);
    virtual void sendMotionPacketIfNeeded();
    virtual void die(EntityDamageSource const&);
    virtual bool isSleeping();
    virtual float getSpeed();
    virtual void travel(float, float);
    virtual void aiStep();
    virtual ItemInstance* getCarriedItem();
    virtual void getItemUseDuration();
    virtual void dropAllGear(int);
    virtual void drop(ItemInstance const*, bool);
    virtual void sendInventory() const;
    virtual void dropDeathLoot(int);
    virtual void dropRareDeathLoot();
    virtual void jumpFromGround();
    virtual void updateAi();
    virtual void getExperienceReward() const;
    virtual void useNewAi();
    virtual void registerAttributes();
    virtual void prepareRegion(ChunkSource&);
    virtual void destroyRegion();
    virtual void suspendRegion();
    virtual void tickWorld(Tick const&);
    virtual void moveView();
    virtual void setName(std::string const&);
    virtual void checkMovementStatistiscs(float, float, float);
    virtual void respawn();
    virtual bool isInTrialMode();
    virtual void hasResource(int);
    virtual void completeUsingItem();
    virtual void drop(ItemInstance const*);
    virtual void startCrafting(int, TilePos const&);
    virtual void startStonecutting(TilePos const&);
    virtual void startDestroying();
    virtual void stopDestroying();
    virtual void openContainer(ChestTileEntity*);
    virtual void openFurnace(FurnaceTileEntity*);
    virtual void openEnchanter(EnchantingTableEntity*);
    virtual void openAnvil(TilePos const&);
    virtual void openBrewingStand(BrewingStandTileEntity*);
    virtual void displayChatMessage(std::string const&, std::string const&);
    virtual void displayClientMessage(std::string const&);
    virtual void displayLocalizableMessage(std::string const&, std::vector<std::string> const&);
    virtual void animateRespawn();
    virtual void startSleepInBed(int, int, int);
    virtual void stopSleepInBed(bool, bool);
    virtual void getSleepTimer();
    virtual void openTextEdit(TileEntity*);
    virtual bool isLocalPlayer();
    virtual void stopLoading();
    virtual void setPlayerGameTypePacketReceived(GameType);
    virtual void setPlayerGameType(GameType);
    virtual void eat(FoodItem const*, ItemInstance const*);
    virtual void crit(Entity&);
    virtual void getTelemetry() const;
    virtual void sendTelemetryPacket(TelemetryEventPacket const&);
    virtual void closeContainer();
    void _init();
    void addBatchPacket(Packet*);
    void addExperience(int);
    void addLevels(int);
    void animateRespawn(Player*, Level*);
    void attack(Entity*);
    bool canDestroy(Tile*);
    void canUseCarriedItemWhileMoving() const;
    void causeFoodExhaustion(float);
    void checkBed(bool);
    void eat(int, float);
    void filterValidUserName(std::string const&);
    void fixSpawnPosition(TilePos&, std::vector<TileSource*>) const;
    void getDestroySpeed(Tile*);
    void getDimension() const;
    void getEnchantmentSeed() const;
    void getItemInUse();
    void getLevelProgress() const;
    void getLoadedChunksCount();
    void getNewEnchantmentSeed();
    int getPlayerLevel() const;
    int getScore();
    ItemInstance* getSelectedItem() const;
    SkinInfoData* getSkin() const;
    void getSleepRotation();
    void getSpawnPosition();
    void getStandingPositionOnBlock(TilePos const&);
    void getTicksUsingItem();
    void getViewRadius() const;
    void getXpNeededForNextLevel() const;
    void getXpTakeDelay() const;
    void handleJumpEffects();
    void hasRespawnPosition() const;
    void interact(Entity*);
    bool IsCreative() const;
    bool isHungry() const;
    bool isHurt();
    bool isInCreativeMode();
    bool isSleepingLongEnough();
    bool IsSurvival() const;
    bool isUsingItem() const;
    bool isValidUserName(std::string const&);
    void reallyDrop(std::unique_ptr<ItemEntity>);
    void recheckSpawnPosition();
    void releaseUsingItem();
    void resetPlayerLevel();
    void resetPos(bool);
    void setAllPlayersSleeping();
    void setBedOffset(int);
    void setDefaultHeadHeight();
    void setRespawnDimensionId(DimensionId);
    void setRespawnPosition(TilePos const&);
    void setSkin(bool, std::string const&);
    void setTeleportDestination(Vec3 const&);
    void setXpTakeDelay(int);
    void spawnEatParticles(ItemInstance const*, int);
    void startUsingItem(ItemInstance, int);
    void stopUsingItem();
    void take(Entity*, int);
    void tileEntityDestroyed(int);
    void touch(Entity*);
    void updateTeleportDestPos();
    void useItem(ItemInstance&) const;
};
