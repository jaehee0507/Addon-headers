#pragma once

#include <string>
#include "../Packet.h"

class DisconnectPacket : public Packet {
    public:
    std::string message;                //16
    
    public:
    virtual ~DisconnectPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
