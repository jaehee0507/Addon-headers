#pragma once

#include "../Packet.h"

class SetTimePacket : public Packet {
    public:
    int time;                //16
    bool dayCycleActive;     //20
    
    public:
    virtual ~SetTimePacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
