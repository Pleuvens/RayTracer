#pragma once

#include "vector.hh"

class Material {
public:
    Material() : refractive_index_(1), albedo_(Vec4f(1.0, 0, 0, 0)), diffuse_(),
        specular_() {}
    Material(float refractive_index, const Vec4f& albedo, const Vec3f& diffuse,
            float specular) 
        : refractive_index_(refractive_index), albedo_(albedo),
        diffuse_(diffuse), specular_(specular) {}

    float refractive_index_;
    Vec4f albedo_;
    Vec3f diffuse_;
    float specular_;
};

class Sphere {
public:
    Sphere(const Vec3f &center, const float radius, const Material& material)
        : center_(center), radius_(radius), material_(material) {}

    bool ray_intersect(const Vec3f &origin, const Vec3f &dir, float& t0) const {
        Vec3f L = center_ - origin;
        float tca = Vec3f::sum(L, dir);
        float d2 = Vec3f::sum(L, L) - tca * tca;
        if (d2 > radius_ * radius_)
            return false;
        float thc = sqrtf(radius_ * radius_ - d2);
        t0 = tca - thc;
        float t1 = tca + thc;
        if (t0 < 0)
            t0 = t1;
        if (t0 < 0)
            return false;
        return true;
    }

    Vec3f center_;
    float radius_;
    Material material_;
};
