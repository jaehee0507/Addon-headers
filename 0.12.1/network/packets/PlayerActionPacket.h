#pragma once

#include "../Packet.h"

class PlayerActionPacket : public Packet {
    public:
    int x;                             //16
    int y;                             //20
    int z;                             //24
    char filler1[4];                   //28
    int action;                        //32
    char filler2[12];                  //36
    
    
    public:
    virtual ~PlayerActionPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
