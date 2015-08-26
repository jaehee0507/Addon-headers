#pragma once

#include <string>
#include <functional>

class PacketSender;
class Level;
class SoundPlayer;
class Player;
class InputMode;
class ItemInstance;
class TilePos;
class Vec3;
class Entity;

//Size : 92
class GameMode {
    public:
    //void** vtable;                    //0
    char filler1[32];                   //4
    PacketSender* packetSender;         //36
    Level* level;                       //40
    char filler2[28];                   //44
    SoundPlayer* soundPlayer;           //72
    bool trialMode;                     //76
    char filler3[15];                   //77
    
    public:
    GameMode(PacketSender&, Level&, SoundPlayer&, Vibration&);
    virtual ~GameMode();
    virtual void startDestroyBlock(Player*, int, int, int, signed char);
    virtual void destroyBlock(Player*, int, int, int, signed char);
    virtual void continueDestroyBlock(Player*, int, int, int, signed char);
    virtual void stopDestroyBlock(Player*);
    virtual void startBuildBlock(Player&, int, int, int, signed char);
    virtual void buildBlock(Player&, int, int, int, signed char);
    virtual void continueBuildBlock(Player&, int, int, int, signed char);
    virtual void stopBuildBlock(Player&);
    virtual void tick();
    virtual void getPickRange(Player*, InputMode const&);
    virtual void useItem(Player&, ItemInstance&);
    virtual void useItemOn(Player&, ItemInstance*, TilePos const&, signed char, Vec3 const&);
    virtual void interact(Player*, Entity*);
    virtual void attack(Player*, Entity*);
    virtual void handleInventoryMouseClick(int, int, int, Player*);
    virtual void handleCloseInventory(int, Player*);
    virtual void releaseUsingItem(Player*);
    virtual void setTrialMode(bool);
    virtual void isInTrialMode();
    void _destroyBlockInternal(Player*, int, int, int, signed char);
    void creativeDestroyBlock(Player*, int, int, int, signed char);
    void getHitProgress(float);
    void messagePlayers(std::string);
    void registerUpsellScreenCallback(std::function<void (bool)>);
    void releaseUsingItemInternal(Player*);
};
