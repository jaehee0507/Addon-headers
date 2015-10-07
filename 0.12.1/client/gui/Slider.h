#pragma once

#include "GuiElement.h"
#include "../settings/Options.h"

//Size : 176
class Slider : public GuiElement {
    public:
    char filler1[20];            //120
    float progress;              //140
    char filler2[12];            //144
    float minValue;              //156
    float maxValue;              //160
    char filler3[12];            //164
    
    public:
    Slider(MinecraftClient&, Options::Option const*, float, float);
    Slider(MinecraftClient&, Options::Option const*, std::vector<int> const&);
    virtual ~Slider();
    virtual void tick(MinecraftClient*);
    virtual void render(MinecraftClient*, int, int);
    virtual void pointerPressed(MinecraftClient*, int, int);
    virtual void pointerReleased(MinecraftClient*, int, int);
    virtual void setOption(MinecraftClient*);
    void processControllerInput(MinecraftClient*, int);
    void updateStepPercentage();
};
