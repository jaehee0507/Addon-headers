#pragma once

#include "../Packet.h"
#include "../../util/EntityUniqueID.h"
#include "../../item/ItemInstance.h"

class Mob;

class MobArmorEquipmentPacket : public Packet {
    public:
    EntityUniqueID target;      //16
    ItemInstance helmet;        //24
    ItemInstance tunic;         //44
    ItemInstance pants;         //64
    ItemInstance shoes;         //84
    bool idk;                   //104
    char filler1[7];            //105
    
    public:
    MobArmorEquipmentPacket(Mob const&);
    virtual ~MobArmorEquipmentPacket();
    virtual int getId() const;
    virtual void write(RakNet::BitStream*) const;
    virtual void read(RakNet::BitStream*);
    virtual void handle(RakNet::RakNetGUID const&, NetEventCallback*) const;
};
