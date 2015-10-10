#pragma once

#include "../Packet.h"
#include "../../util/EntityUniqueID.h"

class RemoveBlockPacket : public Packet {
    public:
    EntityUniqueID eid;
    int x;
    int z;
    unsigned char y;
    
    public:
    virtual ~RemoveBlockPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
