#pragma once

#include <string>
#include <vector>
#include "../Packet.h"

class TextPacket : public Packet {
    public:
    char type;                             //13
    char filler1[2];                       //14
    std::string text1;                     //16
    std::string text2;                     //20
    std::vector<std::string> text3;        //24
    
    public:
    virtual ~TextPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
    void createTranslated(std::string const&, std::vector<std::string> const&);
};
