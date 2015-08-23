#pragma once

#include <memory>
#include "App.h"

class Vibration;
class ExternalFileLevelStorageSource;
class ServerCommandParser;
class GameSession;
class RakNetInstance;
class RakNetPacketSender;
class TerrainAtlas;
class GameMode;
class GameType;
class Timer;
class Mob;
class Player;
class Level;
class LevelSettings;
class LegacyClientNetworkHandler;
class SoundEngine;
class NetEventCallback;

//Size : 108
class Minecraft : public App {
    public:
    char filler1[12];                               //28
    std::string serverName;                         //40
    ExternalFileLevelStorageSource* levelSource;    //44
    char filler2[20];                               //48
    ServerCommandParser* commandParser;             //68
    char filler3[16];                               //72
    GameSession* gameSession;                       //88
    char filler4[4];                                //92
    RakNetInstance* raknetInstance;                 //96
    RakNetPacketSender* packetSender;               //100
    char filler5[4];                                //104
    
    public:
    static TerrainAtlas* _itemsTextureAtlas;
    static TerrainAtlas* _terrainTextureAtlas;
    
    public:
    Minecraft(int, char**);
    virtual ~Minecraft();
    virtual void onAppSuspended();
    virtual void onAppResumed();
    virtual void update();
    virtual void init();
    virtual void teardown();
    virtual void setGameMode(GameType);
    virtual void startFrame();
    virtual void updateGraphics(Timer const&);
    virtual void endFrame();
    virtual void tick(int, int);
    virtual void leaveGame(bool);
    virtual void setupCommandParser(ServerCommandParser&);
    virtual void play(std::string const&, float, float, float, float, float);
    virtual void playUI(std::string const&, float, float);
    virtual void updateSoundLocation(Mob*, float);
    virtual bool isServerVisible();
    virtual void sendLocalMessage(std::string const&, std::string const&);
    virtual Player* getPlayer();
    virtual void onInternetUpdate();
    virtual void onPrepChangeDimension(Player&);
    virtual void onDimensionChanged(Player&);
    virtual void createLocalClientNetworkHandler();
    virtual Vibration* getVibration();
    virtual void createSkin(bool);
    virtual SoundEngine* getSoundPlayer();
    void createGameMode(GameType, Level&);
    void createLevel(std::string const&, std::string const&, LevelSettings const&);
    ServerCommandParser* getCommandParser();
    GameMode* getGameMode();
    Level* getLevel();
    ExternalFileLevelStorageSource* getLevelSource();
    NetEventCallback* getNetEventCallback();
    RakNetPacketSender* getPacketSender();
    void getServerNetworkHandler();
    void hostMultiplayer(std::unique_ptr<Level>, std::unique_ptr<GameMode>, int, int);
    void init(std::string const&);
    bool isModded();
    bool isOnlineClient();
    void lockForControl();
    void onClientStartedLevel(std::unique_ptr<Level>);
    void removeAllPlayers();
    void resetGameSession();
    void restartMultiplayerHost(int, int);
    void setLeaveGame();
    void startClientGame(std::unique_ptr<LegacyClientNetworkHandler>);
    void unlockControl();
};
