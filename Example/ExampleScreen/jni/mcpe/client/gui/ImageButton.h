#pragma once

#include "Button.h"
#include "ImageDef.h"

//Size : 244
class ImageButton : public Button {
    public:
    ImageDef imageDef;          //180
    char filler1[20];           //220
    int yOffset;                //240
    
    public:
    ImageButton(int, std::string const&);
    ImageButton(int, std::string const&, ImageDef const&);
    virtual ~ImageButton();
    virtual void render(MinecraftClient*, int, int);
    virtual void renderBg(MinecraftClient*, int, int);
    virtual void setYOffset(int);
    virtual void setupDefault();
    virtual bool isSecondImage(bool);
    void setImageDef(ImageDef const&, bool);
};
