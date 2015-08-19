#pragma once

#include "MemoryTracker.h"

typedef unsigned char uchar;

namespace mce {
    class VertexFormat;
    class PrimitiveMode;
    class MaterialPtr;
}
class Vec2;
class Color;
class Vec3;

class Tessellator : public MemoryTracker {
    public:
	//Size : 24
	class CurrentVertexPointers {
            public:
            CurrentVertexPointers(uchar*, mce::VertexFormat const&);
            void nextVertex();
        };
	
    public:
    static Tessellator instance;
	
    public:
    Tessellator(MemoryTracker*);
    virtual ~Tessellator();
    virtual void getStats() const;
    void _allocateIndices(int);
    void _tex(Vec2 const&, int);
    void addOffset(Vec3 const&);
    void addOffset(float, float, float);
    void begin(int);
    void begin(mce::PrimitiveMode, int);
    void beginIndices(int);
    void cancel();
    void clear();
    void color(Color const&);
    void color(float, float, float, float);
    void color(int);
    void color(int, int);
    void color(int, int, int, int);
    void color(uchar, uchar, uchar, uchar);
    void colorABGR(int);
    void draw(mce::MaterialPtr const&);
    void enableColor();
    void end(char const*, bool);
    void getColor();
    void getPolygonCount();
    void init();
    void noColor();
    void normal(Vec3 const&);
    void normal(float, float, float);
    void quad(uint, bool);
    void quad(uint, uint, uint, uint);
    void resetScale();
    void resetTilt();
    void rotationOffset(float, Vec3 const&);
    void scale2d(float, float);
    void scale3d(float, float, float);
    void setOffset(Vec3 const&);
    void setOffset(float, float, float);
    void tex(Vec2 const&);
    void tex(float, float);
    void tex1(Vec2 const&);
    void tex1(float, float);
    void tilt();
    void triangle(uint, uint, uint);
    void trim();
    void vertex(Vec3 const&);
    void vertex(float, float, float);
    void vertexUV(Vec3 const&, float, float);
    void vertexUV(float, float, float, float, float);
    void voidBeginAndEndCalls(bool);
};
