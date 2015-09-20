#pragma once

#include <memory>
#include "Entity.h"

class LookControl;
class MoveControl;
class PathNavigation;
class Sensing;
class BaseAttributeMap;
class Attribute;
class MobEffectInstance;
class ItemEntity;
class MobEffect;
class AttributeBuffType;
class ListTag;

//Size : 3326
class Mob : public Entity {
    public:
    char filler1[104];                                  //360
    float yHeadRot;                                     //464
    char filler2[2660];                                 //468
    std::string texture;                                //3128
    char filler3[68];                                   //3132
    LookControl* lookControl;                           //3200
    MoveControl* moveControl;                           //3204
    char filler4[8];                                    //3208
    PathNavigation* navigation;                         //3216
    Sensing* sensing;                                   //3220
    char filler5[84];                                   //3224
    BaseAttributeMap* attributes;                       //3308
    char filler6[14];                                   //3312
    
    public:
    Mob(Level&);
    Mob(TileSource&);
    virtual ~Mob();
    virtual void lerpTo(Vec3 const&, Vec2 const&, int);
    virtual void normalTick();
    virtual void baseTick();
    virtual void rideTick();
    virtual void getHeadHeight() const;
    virtual bool isImmobile();
    virtual bool isPickable();
    virtual bool isPushable();
    virtual bool isShootable();
    virtual bool isSneaking() const;
    virtual bool isAlive();
    virtual void hurt(EntityDamageSource const&, int);
    virtual void animateHurt();
    virtual void doFireHurt(int);
    virtual void handleEntityEvent(EntityEvent);
    virtual int getEntityTypeId() const = 0;
    virtual void setOnFire(int);
    virtual void causeFallDamage(float);
    virtual void outOfWorld();
    virtual void readAdditionalSaveData(CompoundTag const*);
    virtual void addAdditionalSaveData(CompoundTag*);
    virtual void playStepSound(int, int, int, int);
    virtual void buildDebugInfo(std::string&) const;
    virtual void postInit();
    virtual void knockback(Entity*, int, float, float);
    virtual void die(EntityDamageSource const&);
    virtual void resolveDeathLoot(int);
    virtual bool canSee(Entity*);
    virtual void onLadder();
    virtual void spawnAnim();
    virtual std::string getTexture();
    virtual bool isSleeping();
    virtual void setSneaking(bool);
    virtual bool isSprinting() const;
    virtual void setSprinting(bool);
    virtual int getVoicePitch();
    virtual void playAmbientSound();
    virtual void getAmbientSoundInterval();
    virtual void getItemInHandIcon(ItemInstance const*, int);
    virtual float getSpeed();
    virtual void getJumpPower() const;
    virtual void heal(int);
    virtual void hurtEffects(EntityDamageSource const&, int);
    virtual void getMeleeWeaponDamageBonus(Mob*);
    virtual void getMeleeKnockbackBonus();
    virtual void actuallyHurt(int, EntityDamageSource const*);
    virtual bool isInvertedHealAndHarm() const;
    virtual void pick(float, float, bool);
    virtual void travel(float, float);
    virtual void updateWalkAnim();
    virtual void aiStep();
    virtual void pushEntities();
    virtual void lookAt(Entity*, float, float);
    virtual bool isLookingAtAnEntity();
    virtual bool canSpawn();
    virtual void finalizeMobSpawn();
    virtual void shouldDespawn() const;
    virtual void getAttackAnim(float);
    virtual bool isBaby() const;
    virtual ItemInstance* getCarriedItem();
    virtual void setCarriedItem(ItemInstance const&);
    virtual void getItemUseDuration();
    virtual void swing();
    virtual void ate();
    virtual void getMaxHeadXRot();
    virtual void getLastHurtByMob();
    virtual void setLastHurtByMob(Mob*);
    virtual void getLastHurtByPlayer();
    virtual void setLastHurtByPlayer(Player*);
    virtual void getLastHurtMob();
    virtual void setLastHurtMob(Entity*);
    virtual void getTarget();
    virtual void setTarget(Mob*);
    virtual void canAttack(Mob*, bool);
    virtual void isAlliedTo(Mob*);
    virtual void doHurtTarget(Entity*);
    virtual void canBeControlledByRider();
    virtual void teleportTo(float, float, float);
    virtual void getMutableAttribute(Attribute const&);
    virtual void getAttribute(Attribute const&) const;
    virtual void getEquipmentCount() const;
    virtual void getArmorValue();
    virtual void getArmorCoverPercentage();
    virtual void hurtArmor(int);
    virtual void setArmor(int, ItemInstance const*);
    virtual void getArmor(int) const;
    virtual void getAllArmor() const;
    virtual void getAllArmor();
    virtual void getArmorTypeHash();
    virtual void dropHeldItem();
    virtual void dropAllArmor();
    virtual void dropAllGear(int);
    virtual void drop(ItemInstance const*, bool);
    virtual void sendInventory() const;
    virtual void removeWhenFarAway();
    virtual void getDeathLoot();
    virtual void dropDeathLoot(int);
    virtual void dropRareDeathLoot();
    virtual void jumpFromGround();
    virtual void pickUpItem(ItemEntity&);
    virtual void updateAi();
    virtual void newServerAiStep();
    virtual void serverAiMobStep();
    virtual int getSoundVolume();
    virtual void getAmbientSound();
    virtual std::string getHurtSound();
    virtual std::string getDeathSound();
    virtual std::string getStepSound();
    virtual void getDamageAfterArmorAbsorb(EntityDamageSource const&, int);
    virtual void getDamageAfterMagicAbsorb(EntityDamageSource const&, int);
    virtual void getExperienceReward() const;
    virtual void useNewAi();
    virtual void getWalkingSpeedModifier();
    virtual void canBeAffected(MobEffectInstance const&);
    virtual void onEffectAdded(MobEffectInstance&);
    virtual void onEffectUpdated(MobEffectInstance const&);
    virtual void onEffectRemoved(MobEffectInstance&);
    virtual void registerAttributes();
    void _ctor();
    void _doSprintParticleEffect();
    void _init();
    void _sendDirtyMobData();
    void _updateSprintingState();
    void addEffect(MobEffectInstance const&);
    void checkDespawn();
    void checkDespawn(Mob*);
    void getActiveEffectCount() const;
    void getAllEffects();
    BaseAttributeMap* getAttributes();
    void getCurrentSwingDuration();
    void getEffect(MobEffect*) const;
    int getHealth();
    LookControl* getLookControl();
    int getMaxHealth();
    MoveControl* getMoveControl();
    PathNavigation* getNavigation();
    Sensing* getSensing();
    float getYHeadRot();
    bool hasAnyEffects();
    bool hasAttributeBuff(AttributeBuffType) const;
    bool hasEffect(MobEffect*) const;
    void healEffects(int);
    void loadArmor(ListTag const*);
    void reallyDrop(std::unique_ptr<ItemEntity>);
    void removeAllEffects();
    void removeEffect(int);
    void removeEffectNoUpdate(int);
    void removeEffectParticles();
    void resetAttributes();
    void saveArmor();
    void serializationSetHealth(int);
    void setInvisible(bool);
    void setJumping(bool);
    void setSpeed(float);
    void setYHeadRot(float);
    void setYya(float);
    void tickAttributes();
    void tickEffects();
    void updateInvisibilityStatus();
    void updateMobId(EntityUniqueID&);
};
