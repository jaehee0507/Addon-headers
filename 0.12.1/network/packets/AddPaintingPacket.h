#pragma once

#include <string>

#include "../Packet.h"
#include "../../util/EntityUniqueID.h"

class AddPaintingPacket : public Packet {
    public:
    EntityUniqueID painting;      //16
    int x;                        //24
    int y;                        //28
    int z;                        //32
    int direction;                //36
    std::string title;            //40
    
    public:
    virtual ~AddPaintingPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
