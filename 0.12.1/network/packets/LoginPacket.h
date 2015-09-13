#pragma once

#include <string>
#include "../Packet.h"

class LoginPacket : public Packet {
    public:
    std::string name;                //16
    char filler1[44];                //20
    bool isSkinSlim;                 //64
    char filler2[3];                 //65
    std::string skindata;            //68
    
    public:
    virtual ~LoginPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
