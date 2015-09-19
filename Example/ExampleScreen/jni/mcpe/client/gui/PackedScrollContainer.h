#pragma once

#include "GuiElementContainer.h"

class ScrollingPane;

//Size : 184
class PackedScrollContainer : public GuiElementContainer {
    public:
    char filler1[4];                    //140
    float offset_1;                     //144
    float offset_2;                     //148
    float offset_3;                     //152
    int selectedBoxSize;                //156
    int flag;                           //160
    ScrollingPane* scrollPane;          //164
    char filler3[12];                   //168
    bool windowResizedFlag;             //180
    
    public:
    PackedScrollContainer(bool, bool);
    virtual ~PackedScrollContainer();
    virtual void tick(MinecraftClient*);
    virtual void render(MinecraftClient*, int, int);
    virtual void setupPositions();
    virtual void pointerPressed(MinecraftClient*, int, int);
    virtual void setTextboxText(std::string const&);
    void addFlagToScrollingPane(int);
    void handleMouseInput(float);
    void scrollViewTo(GuiElement const&);
    void scrollViewToSelected();
    void setScrollBarOffset(float, float, float);
    void setSelectedBoxSize(int);
    void setWindowResizedFlag(bool);
};
