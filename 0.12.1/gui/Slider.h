#pragma once

#include "GuiElement.h"

class Options {
    public:
    class Option;
};

//Size : 176
class Slider : public GuiElement {
    public:
    char filler1[20];            //120
    float progress;              //140
    char filler2[32];            //144
    
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
