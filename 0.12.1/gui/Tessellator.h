#pragma once

#include "MemoryTracker.h"

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
            CurrentVertexPointers(unsigned char*, mce::VertexFormat const&);
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
    void addOffset(float, float, float);
    void addOffset(Vec3 const&);
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
    void color(unsigned char, unsigned char, unsigned char, unsigned char);
    void colorABGR(int);
    void draw(mce::MaterialPtr const&);
    void enableColor();
    void end(char const*, bool);
    void getColor();
    void getPolygonCount() const;
    void init();
    void noColor();
    void normal(float, float, float);
    void normal(Vec3 const&);
    void quad(unsigned int, bool);
    void quad(unsigned int, unsigned int, unsigned int, unsigned int);
    void resetScale();
    void resetTilt();
    void rotationOffset(float, Vec3 const&);
    void scale2d(float, float);
    void scale3d(float, float, float);
    void setOffset(float, float, float);
    void setOffset(Vec3 const&);
    void tex(float, float);
    void tex(Vec2 const&);
    void tex1(float, float);
    void tex1(Vec2 const&);
    void tilt();
    void triangle(unsigned int, unsigned int, unsigned int);
    void trim();
    void vertex(float, float, float);
    void vertex(Vec3 const&);
    void vertexUV(float, float, float, float, float);
    void vertexUV(Vec3 const&, float, float);
    void voidBeginAndEndCalls(bool);
};
