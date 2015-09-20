#pragma once

#include "../Packet.h"
#include "../../util/Vec3.h"

class RespawnPacket : public Packet {
    public:
    Vec3 destination;                //16
    
    public:
    virtual ~RespawnPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
