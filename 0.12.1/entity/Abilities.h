#pragma once

class CompoundTag;

class Abilities {
    public:
    bool invulnerable;            //0
    bool flying;                  //1
    bool mayfly;                  //2
    bool instabuild;              //3
    int filler;                   //4
    float flyingSpeed;            //8
    float walkingSpeed;           //12
    
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
