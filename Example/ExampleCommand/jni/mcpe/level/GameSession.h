#pragma once

#include <memory>

class Level;
class GameMode;
class ServerNetworkHandler;
class ClientNetworkHandler;
class LegacyClientNetworkHandler;
class NetEventCallback;
class RakNetPacketSender;

//Size : 24
class GameSession {
    public:
    Level* level;                                           //0
    GameMode* gameMode;                                     //4
    ServerNetworkHandler* serverHandler;                     //8
    LegacyClientNetworkHandler* clientHandler;              //12
    NetEventCallback* netCallback;                          //16
    RakNetPacketSender* packetSender;                       //20
    
    public:
    GameSession(std::unique_ptr<ServerNetworkHandler>, RakNetPacketSender&, std::unique_ptr<ClientNetworkHandler>, std::unique_ptr<Level>, std::unique_ptr<GameMode>);
    GameSession(std::unique_ptr<LegacyClientNetworkHandler>, RakNetPacketSender&);
    ~GameSession();
    void tick();
    void setLevel(std::unique_ptr<Level>);
    void setGameMode(std::unique_ptr<GameMode>);
    void getNetEventCallback();
};
