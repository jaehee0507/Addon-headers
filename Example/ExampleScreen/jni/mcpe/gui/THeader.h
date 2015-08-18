#pragma once

#include "Button.h"

namespace Touch {
    
    //Size : 184
    class THeader : public Button {
        public:
        char filler1[4];
        
        public:
        THeader(int, int, int, int, int, std::string const&);
        THeader(int, int, int, std::string const&);
        THeader(int, std::string const&);
        virtual ~THeader();
        virtual void render(MinecraftClient*, int, int);
        virtual void renderBg(MinecraftClient*, int, int);
    };

}
