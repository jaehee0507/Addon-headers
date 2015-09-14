#pragma once

#include "../Packet.h"

class PlayStatusPacket : public Packet {
    public:
    int status;                //16
    
    public:
    virtual ~PlayStatusPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
