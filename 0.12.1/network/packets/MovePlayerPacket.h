#pragma once

#include "../Packet.h"
#include "../../util/EntityUniqueID.h"
#include "../../util/Vec3.h"
#include "../../util/Vec2.h"

class MovePlayerPacket : public Packet {
    public:
    EntityUniqueID eid;                //16
    char filler1[4];                   //24
    Vec3 posvec;                       //28
    Vec2 rotvec;                       //40
    float pitch;                       //48
    
    public:
    virtual ~MovePlayerPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
