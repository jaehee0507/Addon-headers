#pragma once

#include <string>
#include <vector>

namespace Social {
    class GameConnectionInfo;
    class Multiplayer;
}
class NetEventCallback;
class PacketObserver;
class PacketPriority;
class PacketReliability;
namespace RakNet {
    class RakPeer;
    class RakNerGUID;
    class RakNetStatistics;
    class BitStream;
    class AddressOrGUID;
}


class IRakNetInstance {
    public:
    //void** vtable;
    
    public:
    virtual ~IRakNetInstance();
    virtual void host(std::string const&, int, int);
    virtual void connect(char const*, int);
    virtual void connect(Social::GameConnectionInfo, Social::GameConnectionInfo);
    virtual void setIsLoggedIn(bool);
    virtual void init();
    virtual void startPingForHosts(int);
    virtual void pingHost(int, std::string const&);
    virtual void startPingForHosts(int, std::vector<std::string> const&);
    virtual void stopPingForHosts();
    virtual void getServerList();
    virtual void clearServerList();
    virtual void disconnect();
    virtual void announceServer(std::string const&);
    virtual void stopAnnounceServer();
    virtual RakNet::RakPeer* getPeer();
    virtual bool isMyLocalGuid(RakNet::RakNetGUID const&);
    virtual void runEvents(NetEventCallback*);
    virtual bool isServer();
    virtual RakNet::RakNetGUID getServerGuid();
    virtual bool isProbablyBroken();
    virtual void resetIsBroken();
    virtual void getStatistics(RakNet::RakNetStatistics*);
    virtual void setPacketObserver(PacketObserver*);
    virtual void sendRaw(RakNet::BitStream const&, PacketPriority, PacketReliability, RakNet::AddressOrGUID, bool, unsigned int);
    virtual void setMultiplayer(Social::Multiplayer*);
    virtual void getUpnpInfo();
    virtual void getNatPunchInfo();
    virtual void setupGameRoute();
    virtual void setupNatPunch();
    virtual void getNatState();
    virtual int getUpnpState();
    virtual void tick();
};
