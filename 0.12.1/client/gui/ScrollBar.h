#pragma once

class MinecraftClient;
class IntRectangle;

//Size : 84
class ScrollBar {
    public:
    enum RenderColorType {
        
    };
    
    public:
    char filler1[16];                       //0
    float scale;                            //16
    char filler2[8];                        //20
    float margin1;                          //28
    float margin2;                          //32
    float margin3;                          //36
    char filler3[4];                        //40
    ScrollBar::RenderColorType type;        //44
    char filler4[36];                       //48
    
    public:
    ScrollBar();
    ~ScrollBar();
    void createMouseScrollBars();
    void render(MinecraftClient*, bool);
    void setMarginsPixelOffsets(float, float, float);
    void setRenderColorType(ScrollBar::RenderColorType);
    void update(IntRectangle const&, float, int);
    void updateScale(float);
};
