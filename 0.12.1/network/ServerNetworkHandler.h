#pragma once

#include "NetEventCallback.h"
#include "../level/LevelListener.h"

class ServerPlayer;
class SkinInfoFactory;

class ServerNetworkHandler : public NetEventCallback, public LevelListener {
    public:
    ServerNetworkHandler(Minecraft*, Level&, GameMode*, IRakNetInstance&, PacketSender&, SkinInfoFactory&, Player*);;
    virtual void onPlayerReady(Player&);;
    virtual ~ServerNetworkHandler();;
    virtual void onNewClient(RakNet::RakNetGUID const&);;
    virtual void onDisconnect(RakNet::RakNetGUID const&, std::string const&);;
    virtual bool allowIncomingPacketId(RakNet::RakNetGUID const&, int);;
    virtual void handle(RakNet::RakNetGUID const&, LoginPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, TextPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, MoveEntityPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, MovePlayerPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, RemoveBlockPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, EntityEventPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, MobEquipmentPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, MobArmorEquipmentPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, InteractPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, UseItemPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, PlayerActionPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, DropItemPacket*);
    virtual void handle(RakNet::RakNetGUID const&, ContainerClosePacket*);;
    virtual void handle(RakNet::RakNetGUID const&, ContainerSetSlotPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, ContainerSetContentPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, CraftingEventPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, AnimatePacket*);;
    virtual void handle(RakNet::RakNetGUID const&, TileEntityDataPacket*);;
    virtual void handle(RakNet::RakNetGUID const&, PlayerInputPacket*);;
    virtual void addBatchPacket(Packet*);;
    virtual void sendAndClearBatchedPackets();;
    virtual void onPlayerVerified(RestCallTagData const&);;
    virtual void onPlayerVerifiedFailed(RestCallTagData const&);;
    virtual void onEntityAdded(Entity&);;
    virtual void onEntityRemoved(Entity&);;
    virtual void onNewChunkFor(Player&, LevelChunk&);;
    void _sendAdditionalLevelData(ServerPlayer*, RakNet::RakNetGUID const&);
    void _sendLevelData(ServerPlayer*, RakNet::RakNetGUID const&);
    void allowIncomingConnections(std::string);
    void createNewPlayer(RakNet::RakNetGUID const&, LoginPacket*);
    void disallowIncomingConnections();
    void disconnectClient(RakNet::RakNetGUID const&, std::string const&);
    void displayGameMessage(std::string const&, std::string const&);
    void getPlayer(RakNet::RakNetGUID const&);
    void getPlayer(RakNet::RakNetGUID const&, EntityUniqueID const&);
    void numberOfConnections();
    void onReady_ClientGeneration(Player*, RakNet::RakNetGUID const&);
    void sendLoginMessageLocal(int, RakNet::RakNetGUID const&, LoginPacket*);
    void sendLoginMessageMCO(int, RakNet::RakNetGUID const&, LoginPacket*);
};
