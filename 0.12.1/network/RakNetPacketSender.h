#pragma once

#include "PacketSender.h"

class IRakNetInstance;
class NetEventCallback;

class RakNetPacketSender : public PacketSender {
    public:
    char filler1[20];
    
    public:
    RakNetPacketSender(IRakNetInstance&);
    virtual ~RakNetPacketSender();
    virtual void send(Packet const&);
    virtual void send(RakNet::RakNetGUID const&, Packet const&);
    virtual void sendBroadcast(RakNet::RakNetGUID const&, Packet const&);
    void addLoopbackCallback(NetEventCallback&);
    void removeLoopbackCallback(NetEventCallback&);
};
