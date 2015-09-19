#pragma once

#include "GameMode.h"

//Size : 104
class SurvivalMode : public GameMode {
    public:
    char filler1[8];            //96
    
    public:
    SurvivalMode(PacketSender&, Level&, SoundPlayer&, Vibration&);
    virtual ~SurvivalMode();
    virtual void startDestroyBlock(Player*, int, int, int, signed char);
    virtual void destroyBlock(Player*, int, int, int, signed char);
    virtual void tick();
    virtual void useItem(Player&, ItemInstance&);
    virtual void useItemOn(Player&, ItemInstance*, TilePos const&, signed char, Vec3 const&);
    void showTrialReminder(bool);
};
