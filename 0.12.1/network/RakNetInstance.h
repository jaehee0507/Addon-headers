#pragma once

#include "IRakNetInstance.h"

class NATState;
class UpnpState;
namespace RakNet {
    class Packet;
}

//Size : 176
class RakNetInstance : public IRakNetInstance {
    public:
    char filler1[48];                     //4
    RakNet::RakPeer* peer;                //52
    char filler2[40];                     //56
    std::vector<std::string> vec;         //96
    char filler3[32];                     //108
    int natState;                         //140
    int upnpState;                        //144
    char filler4[14];                     //148
    bool _isServer;                        //162
    bool isLoggedIn;                      //163
    char filler5[4];                      //164
    PacketObserver* packetObserver;       //168
    Social::MultiPlayer* multiPlayer;     //172
    
    public:
    static void* ServerIdentifier;
    
    public:
    RakNetInstance();
    virtual ~RakNetInstance();
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
    void changeNatState(NATState, int, std::string const&);
    void changeUpnpState(UpnpState, int, std::string const&);
    void handleUnconnectedPong(std::string const&, RakNet::Packet const*, bool);
    void natPongReceived(RakNet::SystemAddress);
    void openNatConnection(RakNet::SystemAddress);
    void stateToString(NATState) const;
    void stateToString(UpnpState) const;
};
