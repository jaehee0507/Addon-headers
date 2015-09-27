#pragma once

#include <memory>
#include "GuiElement.h"

//Size : 140
class GuiElementContainer : public GuiElement {
    public:
    std::vector<std::shared_ptr<GuiElement>> children;          //120
    char filler1[8];                                            //132
    
    public:
    GuiElementContainer(bool, bool, int, int, int, int);
    virtual ~GuiElementContainer();
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
    virtual bool suppressOtherGUI();
    virtual void setTextboxText(std::string const&);
    virtual bool hasChildren() const;
    virtual void addChild(std::shared_ptr<GuiElement>);
    virtual void removeChild(std::shared_ptr<GuiElement>);
    virtual void clearAll();
    std::vector<std::shared_ptr<GuiElement>> getChildren();
    std::vector<std::shared_ptr<GuiElement>> getChildren() const;
};
