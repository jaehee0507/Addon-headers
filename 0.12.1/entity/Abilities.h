#pragma once

class CompoundTag;

class Abilities {
    public:
    bool invulnerable;
    bool flying;
    bool mayfly;
    bool instabuild;
    float flyingSpeed;
    float walkingSpeed;
    
    public:
    Abilities();
    void addSaveData(CompoundTag*) const;
    float getFlyingSpeed() const;
    float getWalkingSpeed() const;
    bool isFlying() const;
    void loadSaveData(CompoundTag const&);
    void setFlyingSpeed(float);
    void setWalkingSpeed(float);
};