#pragma once

class Vec3;
class ChunkPos;

class TilePos {
    public:
    float x;
    float y;
    float z;
    
    public:
    static TilePos ZERO;
    static TilePos ONE;
    static TilePos MIN;
    static TilePos MAX;
    
    public:
    TilePos(Vec3 const&);
    TilePos(ChunkPos const&, int);
    TilePos(float, float, float);
    void neighbor(signed char) const;
    void relative(signed char, int) const;
};
