#pragma once

#include "TickingTextureType.h"

class TickingTexture;
class TextureAtlas;
class Textures;

class TickingTextureFactory {
    public:
    static TickingTexture* createDynamicTexture(TickingTextureType, TextureAtlas const*, Textures*);
};
