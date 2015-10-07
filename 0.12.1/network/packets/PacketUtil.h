#pragma once

#include <string>

class Entity;
class ItemInstance;
namespace mce {
    class UUID;
}
namespace RakNet {
    class BitStream;
}

class PacketUtil {
    public:
    static void readItemInstance(RakNet::BitStream*);
    static void readString(RakNet::BitStream*, std::string&);
    static void readUUID(RakNet::BitStream*);
    static void Rot_charToDegrees(signed char);
    static void Rot_charToEntity(Entity*, signed char, signed char);
    static void Rot_degreesToChar(float);
    static void Rot_entityToChar(Entity const*, signed char&, signed char&);
    static void writeItemInstance(ItemInstance const&, RakNet::BitStream*, bool);
    static void writeString(std::string const&, RakNet::BitStream*);
    static void writeUUID(mce::UUID const&, RakNet::BitStream*);
};
