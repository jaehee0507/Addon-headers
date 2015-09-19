#pragma once

#include "../Packet.h"

class SetDifficultyPacket : public Packet {
    public:
    int difficulty;                //16
    
    public:
    virtual ~SetDifficultyPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
