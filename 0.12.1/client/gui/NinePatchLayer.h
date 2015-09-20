#pragma once

#include "GuiElement.h"

class NinePatchDescription;
class Tessellator;
class Textures;

//Size : 520
class NinePatchLayer : public GuiElement {
    public:
    //Size : 36
    class CachedQuad {
        public:
        char filler1[36];
    };
    
    public:
    char filler1[400];
    
    public:
    NinePatchLayer(NinePatchDescription const&, std::string const&, Textures*, float, float);
    virtual ~NinePatchLayer();
    void buildQuad(int);
    void d(Tessellator&, NinePatchLayer::CachedQuad const&);
    void draw(Tessellator&, float, float);
    void exclude(int);
    void getPatchInfo(int, int, float&, float&, float&, float&);
    void setExcluded(int);
    void setSize(float, float);
};
