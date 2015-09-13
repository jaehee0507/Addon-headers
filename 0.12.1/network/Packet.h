#pragma once

namespace RakNet {
    class BitStream;
    class RakNetGUID;
}
class NetEventCallback;

class Packet {
    public:
    //void* vtable;            //0
    char filler1[9];           //4
    
    public:
    Packet();
    virtual ~Packet();
    virtual int getId() const = 0;
    virtual void write(RakNet::BitStream*) const = 0;
    virtual void read(RakNet::BitStream*) = 0;
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const = 0;
};
