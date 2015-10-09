#pragma once

#include "MaterialPtr.h"

class Entity;
class Color;
class Vec2;
class TextureUVCoordinateSet;
class TileSource;
class TilePos;

//Size : 40
class EntityShaderManager {
    public:
    //void** vtable;                        //0
    mce::MaterialPtr entity;                //4
    mce::MaterialPtr entity_alphatest;      //16
    mce::MaterialPtr entity_static;         //28
    
    public:
    static void* GLINT_SCROLL_SCALE_L1;
    static void* GLINT_SCROLL_SCALE_L2;
    static void* GLINT_TEXTURE;
    
    public:
    EntityShaderManager();
    virtual void ~EntityShaderManager();
    virtual void getOverlayColor(Entity&, float) const;
    void _setupFoilShaderParameters(Color const&, Vec2 const&);
    void _setupFoilShaderParameters(Entity&, TextureUVCoordinateSet const&, float);
    void _setupFoilShaderParameters(Entity&, Vec2 const&, float);
    void _setupFoilShaderParameters(TextureUVCoordinateSet const&);
    void _setupFoilShaderParameters(Vec2 const&);
    void _setupShaderParameters(Color const&, Color const&, float, float, float, float, Vec2 const&, Vec2 const&, float);
    void _setupShaderParameters(Entity&, Color const&, Color const&, Vec2 const&, float, float);
    void _setupShaderParameters(Entity&, Color const&, Color const&, float);
    void _setupShaderParameters(Entity&, Color const&, Color const&, float, float, float, float, Vec2 const&, Vec2 const&, float);
    void _setupShaderParameters(Entity&, Color const&, float);
    void _setupShaderParameters(Entity&, Color const&, float, float, float, float, Vec2 const&, float);
    void _setupShaderParameters(Entity&, float);
    void _setupShaderParameters(TileSource&, TilePos const&, float, Vec2 const&);
    void _setupShaderParameters(float, Color const&);
};
