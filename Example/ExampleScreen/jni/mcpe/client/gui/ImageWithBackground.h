#pragma once

#include "LargeImageButton.h"

//Size : 256
class ImageWithBackground : public LargeImageButton {
    public:
    char filler1[12];           //244
    
    public:
    ImageWithBackground(int);
    virtual ~ImageWithBackground();
    virtual void render(MinecraftClient*, int, int);
    virtual void renderBg(MinecraftClient*, int, int);
    void init(Textures*, int, int, IntRectangle, IntRectangle, int, int, std::string const&);
    void setSize(float, float);
};
