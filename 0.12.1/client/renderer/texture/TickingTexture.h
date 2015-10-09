#pragma once

#include "TextureUVCoordinateSet.h"

class Textures;

class TickingTexture {
    public:
    //void** vtable;                                   //0
    TextureUVCoordinateSet texturePosition;            //4
    char filler1[4];                                   //36
    unsigned char* buffer;                             //40
    int pixelCount;                                    //44
    
    public:
    TickingTexture(TextureUVCoordinateSet const&, int);
    virtual ~TickingTexture();
    virtual void tick() = 0;
    virtual void bindTexture(Textures*);
    void getGPUTexture(Textures*) const;
};
