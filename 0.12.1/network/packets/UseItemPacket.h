#pragma once

#include "../../item/ItemInstance.h"
#include "../../util/TilePos.h"
#include "../Packet.h"

class UseItemPacket : public Packet {
    public:
    TilePos tilepos;                  //16
    char face;                        //28
    char filler1[27];                 //29
    ItemInstance item;                //56
    
    public:
    virtual ~UseItemPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
