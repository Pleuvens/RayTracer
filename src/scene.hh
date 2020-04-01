#pragma once

#include <vector>

#include "light.hh"
#include "shapes.hh"
#include "vector.hh"

class Scene {
public:
    Scene() : lights_(std::vector<Light>()), spheres_(std::vector<Sphere>()) {}
    Scene(const std::vector<Light>& lights, const std::vector<Sphere>& spheres)
    : lights_(lights), spheres_(spheres) {}
    
    bool scene_intersect(const Vec3f &origin, const Vec3f &dir,
        Vec3f &hit, Vec3f& normal, Material& material) const;
    Vec3f cast_ray(const Vec3f &origin, const Vec3f &dir, size_t depth) const;
    void render() const;

    std::vector<Light> lights_;
    std::vector<Sphere> spheres_;
};