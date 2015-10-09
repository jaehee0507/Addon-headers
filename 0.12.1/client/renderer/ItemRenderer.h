#pragma once

#include "EntityRenderer.h"
#include "ItemRenderChunkType.h"

class Tessellator;
class ItemInstance;
class Textures;

//Size : 224
class ItemRenderer : public EntityRenderer {
    public:
    static ItemRenderer* singletonPtr;
    
    public:
    ItemRenderer();
    virtual ~ItemRenderer();
    virtual void render(Entity&, Vec3 const&, float, float);
    void blit(float, float, float, float, float, float);
    void fillRect(Tessellator&, float, float, float, float, int);
    void getAtlasPos(ItemInstance const*);
    void iconBlit(float, float, TextureUVCoordinateSet const&, float, float, float, float, int, float, bool);
    void render(Entity&, Vec3 const&, float, float);
    void renderGuiItemCorrect(Font*, Textures*, ItemInstance const*, int, int);
    void renderGuiItemDecorations(ItemInstance const*, float, float);
    void renderGuiItemInChunk(ItemRenderChunkType, Textures*, ItemInstance const*, float, float, float, float, float);
    void renderGuiItemNew(Textures*, ItemInstance const*, int, float, float, float, float, float, bool);
    static ItemRenderer* singleton();
};
