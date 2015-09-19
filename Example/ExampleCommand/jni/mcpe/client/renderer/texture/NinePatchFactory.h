#pragma once

class Textures;
class NinePatchLayer;
class IntRectangle;

//Size : 16
class NinePatchFactory {
    public:
    Textures* texture;
    char filler1[12];
    
    public:
    NinePatchFactory(Textures*, std::string const&);
    NinePatchLayer* createSymmetrical(IntRectangle const&, int, int, float, float);
};
