#pragma once

#include <string>
#include "IntRectangle.h"

class ImageDef {
    public:
    std::string textureName;            //0
    int xPosition;                      //4
    int yPosition;                      //8
    float width;                        //12
    float height;                       //16
    IntRectangle intRectangle;          //20
    bool crop;                          //36
};
