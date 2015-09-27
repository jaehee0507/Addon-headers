#pragma once

#include "GuiComponent.h"
#include "Color.h"

class MinecraftClient;
class NinePatchLayer;
class StickDirection;

//Size : 120
class GuiElement : public GuiComponent {
    public:
    bool enabled;                    //76
    bool visible;                    //77
    int xPosition;                   //80
    int yPosition;                   //84
    int width;                       //88
    int height;                      //92
    Color color;                     //96
    NinePatchLayer* ninePatchLayer;  //112
    bool selected;                   //116
    bool focused;                    //117
    
    public:
    GuiElement(bool, bool, int, int, int, int);
    virtual ~GuiElement();
    virtual void tick(MinecraftClient*);
    virtual void render(MinecraftClient*, int, int);
    virtual void topRender(MinecraftClient*, int, int);
    virtual void setupPositions();
    virtual void pointerPressed(MinecraftClient*, int, int);
    virtual void pointerReleased(MinecraftClient*, int, int);
    virtual void focusedMouseClicked(MinecraftClient*, int, int);
    virtual void focusedMouseReleased(MinecraftClient*, int, int);
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual void handleTextChar(MinecraftClient*, std::string const&, bool);
    virtual bool backPressed(MinecraftClient*, bool);
    virtual void setKeyboardHeight(MinecraftClient*, int);
    virtual void pointInside(int, int);
    virtual bool suppressOtherGUI();
    virtual void setTextboxText(std::string const&);
    virtual bool hasFocus() const;
    virtual void setFocus(bool);
    virtual void handleControllerDirectionHeld(int, StickDirection);
    virtual void drawSelected(int);
    virtual void drawPressed(int);
    virtual void drawSliderSelected();
    virtual void onSelectedChanged();
    virtual bool hasChildren() const;
    void clearBackground();
    void isSelected();
    void setActiveAndVisibility(bool);
    void setActiveAndVisibility(bool, bool);
    void setBackground(Color const&);
    void setBackground(MinecraftClient*, std::string const&, IntRectangle const&, int, int);
    void setSelected(bool);
    void setVisible(bool);
};
