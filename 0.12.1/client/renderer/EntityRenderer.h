#pragma once

#include <string>
#include "EntityShaderManager.h"

class Vec3;
class Options;
class Font;

//Size : 104
class EntityRenderer : public EntityShaderManager {
    public:
    bool idk;                                       //40
    mce::MaterialPtr entity_alphatest2;             //44
    mce::MaterialPtr entity_alphatest_glint;        //56
    mce::MaterialPtr name_tag;                      //68
    mce::MaterialPtr name_tag_depth_tested;         //80
    mce::MaterialPtr name_tag_depth_tested2;        //92
    
    public:
    static EntityRenderDispatcher* entityRenderDispatcher;
    
    public:
    EntityRenderer(bool);
    virtual ~EntityRenderer();
    virtual void render(Entity&, Vec3 const&, float, float) = 0;
    virtual void postRender(Entity&, Vec3 const&, float, float);
    virtual void renderDebug(Entity&, Options&);
    virtual void renderWaterHole(Entity&, Vec3 const&, Vec2 const&, float);
    void _emitFlame(Entity&, float);
    void _emitSmoke(Entity&, float);
    void bindTexture(std::string const&, int);
    Font* getFont();
    void init(EntityRenderDispatcher*);
    bool isFancy();
    void renderDebug(Entity&, Options&);
    void renderText(Entity&, std::string const&, float, float);
    void renderText(std::string const&, Vec3 const&, Color const&, mce::MaterialPtr*, mce::MaterialPtr*);
};
