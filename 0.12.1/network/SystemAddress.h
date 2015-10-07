#pragma once

namespace RakNet {
    
    class SystemAddress {
        public:
        char filler1[20];
        
        public:
        SystemAddress();
        SystemAddress(char const*);
        SystemAddress(char const*, unsigned short);
        void CopyPort(RakNet::SystemAddress const&);
        bool EqualsExcludingPort(RakNet::SystemAddress const&) const;
        void FixForIPVersion(RakNet::SystemAddress const&);
        SystemAddress FromString(char const*, char, int);
        SystemAddress FromStringExplicitPort(char const*, unsigned short, int);
        void GetIPPROTO() const;
        void GetIPVersion() const;
        unsigned short GetPort() const;
        void GetPortNetworkOrder() const;
        bool IsLANAddress();
        bool IsLoopback() const;
        void SetBinaryAddress(char const*, char);
        void SetPort(unsigned short);
        void SetPortHostOrder(unsigned short);
        void SetPortNetworkOrder(unsigned short);
        void SetToLoopback();
        void SetToLoopback(unsigned char);
        void ToInteger(RakNet::SystemAddress const&);
        const char* ToString(bool, char) const;
        void ToString(bool, char*, char) const;
        void ToString_Old(bool, char*, char) const;
        bool operator!=(RakNet::SystemAddress const&) const;
        bool operator<(RakNet::SystemAddress const&) const;
        SystemAddress& operator=(RakNet::SystemAddress const&);
        bool operator==(RakNet::SystemAddress const&) const;
        bool operator>(RakNet::SystemAddress const&) const;
        static int size();
    };
    
}
