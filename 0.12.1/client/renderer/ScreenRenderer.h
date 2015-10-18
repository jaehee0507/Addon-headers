#pragma once

#include "MaterialPtr.h"

class Font;
class Color;
class IntRectangle;

//Size : 72
class ScreenRenderer {
    public:
    mce::MaterialPtr ui_textured;                //0
    mce::MaterialPtr ui_fill_color;              //12
    mce::MaterialPtr ui_fill_gradient;           //24
    mce::MaterialPtr ui_texture_and_color;       //36
    mce::MaterialPtr ui_textured_and_glcolor;    //48
    mce::MaterialPtr ui_fill_stencil;            //60
    
    public:
    static ScreenRenderer* singletonPtr;
    
    public:
    ScreenRenderer();
    void drawCenteredString(Font*, std::string const&, int, int, Color const&);
    void drawString(Font*, std::string const&, int, int, Color const&);
    void blit(IntRectangle const&);
    void blit(int, int, int, int, int, int, int, int, mce::MaterialPtr*);
    void blit(float, float, int, int, float, float, int, int);
    void blitRaw(float, float, float, float, float, float, float, float, float);
    void fill(float, float, float, float, Color const&) const;
    void fill(int, int, int, int, Color const&) const;
    void fillStencil(float, float, float, float) const;
    void fillGradient(float, float, float, float, Color const&, Color const&);
    void fillGradient(int, int, int, int, Color const&, Color const&);
    void fillHorizontalGradient(float, float, float, float, Color const&, Color const&);
    void fillHorizontalGradient(int, int, int, int, Color const&, Color const&);
    void drawRect(int, int, int, int, Color const&, int);
    void drawRect(int, int, int, int, Color const&, Color const&, Color const&, Color const&, int);
    static ScreenRenderer* singleton();
};
