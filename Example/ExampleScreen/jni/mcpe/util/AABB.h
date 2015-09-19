#pragma once

#include <string>

class Vec3;

//Size : 28
class AABB {
    public:
    bool idk;           //0
    float minX;         //4
    float minY;         //8
    float minZ;         //12
    float maxX;         //16
    float maxY;         //20
    float maxZ;         //24
    
    public:
    static AABB EMPTY;
    static AABB MIN;
    
    public:
    AABB();
    AABB(float, float, float, float, float, float);
    AABB(Vec3 const&, float);
    AABB(Vec3 const&, Vec3 const&);
    void centerAt(Vec3 const&);
    void clip(Vec3 const&, Vec3 const&) const;
    void clipXCollide(AABB const&, float) const;
    void clipYCollide(AABB const&, float) const;
    void clipZCollide(AABB const&, float) const;
    void cloneMove(Vec3 const&) const;
    bool contains(Vec3 const&) const;
    void expand(Vec3 const&);
    void expanded(float, float, float) const;
    void flooredCeiledCopy() const;
    void flooredCopy(float, float) const;
    void getBounds() const;
    void getSize() const;
    void grow(Vec3 const&) const;
    void intersects(AABB const&) const;
    void intersectsInner(AABB const&) const;
    bool isEmpty() const;
    bool isNan() const;
    void merge(AABB const&) const;
    void move(float, float, float);
    void set(AABB const&);
    void set(float, float, float, float, float, float);
    void set(Vec3 const&, Vec3 const&);
    void shrink(Vec3 const&);
    std::string toString() const;
    void translated(Vec3 const&) const;
};
