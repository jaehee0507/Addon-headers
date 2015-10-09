#pragma once

#include "TextureFile.h"

class TextureUVCoordinateSet {
    public:
    float startX;
    float startY;
    float endX;
    float endY;
    float width;
    float height;
    int index;
    TextureFile fileType;
    
    public:
    TextureUVCoordinateSet(float, float, float, float, float, float, int, TextureFile);
    TextureUVCoordinateSet();
    void fix();
};
