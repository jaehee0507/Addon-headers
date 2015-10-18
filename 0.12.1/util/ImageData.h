#pragma once

class ImageData {
    public:
    int width;                     //0
    int height;                    //4
    unsigned char* pixels;         //8
    char filler1[8];               //12
};
