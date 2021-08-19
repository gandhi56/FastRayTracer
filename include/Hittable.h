#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

struct HitRecord {
    Point3 p;
    Vec3<double> normal;
    double t;
    bool frontFace;

    inline void set_face_normal(const Ray<double>& r, const Vec3<double>& outwardNormal){
        frontFace = dot(r.direction(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable {
    public:
        virtual bool hit(const Ray<double>& r, double tMin, 
          double tMax, HitRecord& rec) const = 0;
};

#endif