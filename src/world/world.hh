#pragma once

#include <memory>
#include <vector>

#include "intersection.hh"
#include "point_light.hh"
#include "ray.hh"
#include "object.hh"

class World {
    public:
        World() = default;
    
        using Object_p = std::shared_ptr<Object>;
        using Light_p = std::shared_ptr<PointLight>;

        static World defaultWorld(void);

        inline size_t getObjectsSize() const noexcept { return _objects.size(); }
        inline size_t getLightsSize() const noexcept { return _lights.size(); }
        
        Object_p getObject(const int index) const;
        Light_p getLight(const int index) const;

        bool contains(Object_p o) const noexcept;
        bool contains(Light_p l) const noexcept;

        void addObject(Object_p o) noexcept;
        void addLight(Light_p l) noexcept;

        std::vector<Intersection> intersect(Ray r);
        Color shadeHit(Intersection comps, int remaining);
        Color colorAt(Ray r, int remaining);
        bool isShadowed(Point point);
        Color reflectedColor(Intersection i, int remaining);
        Color refractedColor(Intersection i, int remaining);

    private:
        std::vector<Object_p> _objects;
        std::vector<Light_p> _lights;
};
