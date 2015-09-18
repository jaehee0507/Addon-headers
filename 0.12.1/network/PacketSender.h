#pragma once

class Packet;
namespace RakNet {
    class RakNetGUID;
}

class PacketSender {
    public:
    //void** vtable;
    
    public:
    virtual ~PacketSender();
    virtual void send(Packet const&) = 0;
    virtual void send(RakNet::RakNetGUID const&, Packet const&) = 0;
    virtual void sendBroadcast(RakNet::RakNetGUID const&, Packet const&) = 0;
};
