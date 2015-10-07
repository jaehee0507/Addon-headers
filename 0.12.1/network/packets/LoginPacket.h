#pragma once

#include <string>
#include "../Packet.h"

class LoginPacket : public Packet {
    public:
    std::string name;                //16
    std::string protocol1;           //20
    std::string protocol2;           //24
    //mce::UUID uuid;                //40
    char filler1[16];                //40
    char filler2[8];                 //56
    bool isSkinSlim;                 //64
    char filler3[3];                 //65
    char* skindata;                  //68
    
    public:
    virtual ~LoginPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
