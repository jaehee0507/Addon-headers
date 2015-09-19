#pragma once

class TilePos;
class Vec2;

class Vec3 {
    public:
    float x;
    float y;
    float z;
    
    public:
    static Vec3 MAX;
    static Vec3 MIN;
    static Vec3 NEG_UNIT_X;
    static Vec3 NEG_UNIT_Y;
    static Vec3 NEG_UNIT_Z;
    static Vec3 ONE;
    static Vec3 UNIT_X;
    static Vec3 UNIT_Y;
    static Vec3 UNIT_Z;
    static Vec3 ZERO;
    
    public:
    Vec3(TilePos const&);
    void directionFromRotation(Vec2 const&);
    void directionFromRotation(float, float);
};
