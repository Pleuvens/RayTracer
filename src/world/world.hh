#pragma once

#include <vector>

#include "intersection.hh"
#include "point_light.hh"
#include "ray.hh"
#include "sphere.hh"

class World {
    public:
        World() = default;

        static World defaultWorld(void);
        
        inline std::vector<Sphere> getObjects(void) const { return _objects; }
        inline std::vector<PointLight> getLights(void) const { return _lights; }

        inline void setObjects(std::vector<Sphere> objs) { _objects = objs; }
        inline void setLights(std::vector<PointLight> lights) { _lights = lights; }

        std::vector<Intersection> intersect(Ray r);
        Color shadeHit(const Intersection& comps);
        Color colorAt(Ray r);
        bool isShadowed(Point point);

    private:
        std::vector<Sphere> _objects;
        std::vector<PointLight> _lights;
};

// _objects.insert(_objects.end(), v.begin(), v.end())
