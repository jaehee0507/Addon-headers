#pragma once

#include "Button.h"

namespace Touch {
    
    //Size : 188
    class TButton : public Button {
        public:
        NinePatchLayer* ninePatchLayer1;
        NinePatchLayer* ninePatchLayer2;
        
        public:
        TButton(int, int, int, int, int, const std::string &, MinecraftClient *, bool, int);
        TButton(int, int, int, const std::string &, MinecraftClient *, int);
        TButton(int, const std::string &, MinecraftClient *, bool, int);
        virtual ~TButton();
        virtual void renderBg(MinecraftClient *, int, int);
        void init(MinecraftClient *);
        void init(MinecraftClient *, const std::string &, const IntRectangle &, const IntRectangle &, int, int, int, int);
    };
    
}