#pragma once

#include "TButton.h"

namespace Touch {
    
    //Size : 200
    class HeaderButton : public TButton {
        public:
        char filler1[12];
        
        public:
        HeaderButton(int, MinecraftClient&, std::string const&, bool, bool);
        virtual ~HeaderButton();
        virtual void setMsg(std::string const&);
    };
    
}
