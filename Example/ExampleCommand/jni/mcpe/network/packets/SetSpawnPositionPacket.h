#pragma once

#include "../Packet.h"
#include "../../util/TilePos.h"

class SetSpawnPositionPacket : public Packet {
    public:
    TilePos spawnpos;                //16
    
    public:
    virtual ~SetSpawnPositionPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
