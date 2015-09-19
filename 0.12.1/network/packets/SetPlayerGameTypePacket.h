#pragma once

#include "../Packet.h"

class SetPlayerGameTypePacket : public Packet {
    public:
    int gamemode;                //16
    
    public:
    virtual ~SetPlayerGameTypePacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
