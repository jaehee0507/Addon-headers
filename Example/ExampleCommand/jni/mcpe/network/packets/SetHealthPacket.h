#pragma once

#include "../Packet.h"

class SetHealthPacket : public Packet {
    public:
    int health;                //16
    
    public:
    virtual ~SetHealthPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
