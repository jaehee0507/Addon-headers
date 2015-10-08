#pragma once

#include "../Packet.h"
#include "../../item/ItemInstance.h"

class DropItemPacket : public Packet {
    public:
    char idk;                    //13
    ItemInstance item;           //16
    
    public:
    virtual ~DropItemPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
