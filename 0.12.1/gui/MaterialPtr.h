#pragma once

namespace mce {
    
    //Size : 12
    class MaterialPtr {
        public:
        char filler1[12];
        
        public:
        MaterialPtr();
        MaterialPtr(mce::MaterialPtr &&);
    };
    
}
