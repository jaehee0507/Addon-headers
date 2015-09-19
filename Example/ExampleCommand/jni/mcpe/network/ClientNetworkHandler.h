#pragma once

#include "NetEventCallback.h"

class PacketSender;
class MinecraftClient;
namespace RakNet {
    class SystemAddress;
}

class ClientNetworkHandler : public NetEventCallback {
    public:
    ClientNetworkHandler(PacketSender&, MinecraftClient&);
    ClientNetworkHandler(PacketSender&, MinecraftClient&, Level&);
    virtual ~ClientNetworkHandler();
    virtual void onDisconnect(RakNet::RakNetGUID const&, std::string const&);
    virtual void onSwitch(RakNet::SystemAddress const&);
    virtual void handle(RakNet::RakNetGUID const&, PlayStatusPacket*);
    virtual void handle(RakNet::RakNetGUID const&, TextPacket*);
    virtual void handle(RakNet::RakNetGUID const&, TakeItemEntityPacket*);
    virtual void handle(RakNet::RakNetGUID const&, SetPlayerGameTypePacket*);
    virtual void handle(RakNet::RakNetGUID const&, LevelEventPacket*);
    virtual void handle(RakNet::RakNetGUID const&, EntityEventPacket*);
    virtual void handle(RakNet::RakNetGUID const&, CraftingDataPacket*);
    virtual void handle(RakNet::RakNetGUID const&, UpdateAttributesPacket*);
    virtual void handle(RakNet::RakNetGUID const&, TelemetryEventPacket*);
    virtual void handle(RakNet::RakNetGUID const&, RespawnPacket*);
};
