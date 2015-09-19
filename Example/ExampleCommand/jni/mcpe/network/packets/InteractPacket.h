#pragma once

#include "../Packet.h"
#include "../../util/EntityUniqueID.h"

class InteractPacket : public Packet {
    public:
    char action;                //13
    EntityUniqueID target;      //16
    
    public:
    virtual ~InteractPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
