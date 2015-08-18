#pragma once

#include "ScreenRenderer.h"

//Size : 76
class GuiComponent {
    public:
    //void** vtable
    ScreenRenderer screenRenderer;
    
    public:
    GuiComponent();
    virtual ~GuiComponent();
};