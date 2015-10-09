#pragma once

#include "GuiElement.h"
#include "Color.h"

//Size : 156
class Label : public GuiElement {
    public:
    std::string text;            //120
    char filler1[4];             //124
    Color color;                 //128
    char filler2[8];             //144
    bool isWidthSet;             //152
    bool idk;                    //153
    bool isCentered;             //154
    
    public:
    Label(MinecraftClient&, std::string const&, Color const&, int, int, int, bool);
    virtual ~Label();
    virtual void render(MinecraftClient*, int, int);
    virtual void setupPositions();
    virtual void pointerPressed(MinecraftClient*, int, int);
    virtual void pointerReleased(MinecraftClient*, int, int);
    virtual std::string getText() const;
    virtual void setText(std::string const&);
    virtual void setTextRaw(std::string const&);
    virtual void setWidth(int);
    virtual void setColor(Color const&);
    void setCentered(bool);
};
