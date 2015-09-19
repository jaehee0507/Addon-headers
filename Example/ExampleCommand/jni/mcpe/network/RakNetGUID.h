#pragma once

namespace RakNet {
    
    class RakNetGUID {
        public:
        long clientid;
        short idk;
        
        public:
        RakNetGUID();
        bool operator!=(RakNet::RakNetGUID const&) const;
        bool operator==(RakNet::RakNetGUID const&) const;
        bool operator>(RakNet::RakNetGUID const&) const;
        bool operator<(RakNet::RakNetGUID const&) const;
        void FromString(char* const);
        void ToString() const;
        void ToString(char*) const;
        void ToUint32(RakNet::RakNetGUID const&);
    };
    
}
