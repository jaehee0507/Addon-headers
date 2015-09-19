#pragma once

//Size : 16
class Color {
    public:
    float red;
    float green;
    float blue;
    float alpha;
    
    public:
    static const Color BLACK;
    static const Color BLUE;
    static const Color CYAN;
    static const Color GREEN;
    static const Color GREY;
    static const Color NIL;
    static const Color PURPLE;
    static const Color RED;
    static const Color WHITE;
    static const Color YELLOW;
    static const Color SHADE_DOWN;
    static const Color SHADE_NORTH_SOUTH;
    static const Color SHADE_UP;
    static const Color SHADE_WEST_EAST;
    
    public:
    static Color* fromHSB(float, float, float);
};