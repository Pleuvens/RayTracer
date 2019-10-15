#pragma once

#include <vector>
#include <optional>

#include "sphere.hh"

class Intersection {
    public:
        Intersection(const float t, const Sphere& obj);

        static std::vector<Intersection>
            intersections(std::initializer_list<Intersection> list);
        static std::optional<Intersection> hit(std::vector<Intersection> xs);
        
        inline float getT(void) const { return _t; }
        inline Sphere getObject(void) const { return _object; }
        
        inline void setT(const float t) { _t = t; }
        inline void setObject(const Sphere& obj) { _object = obj; }

        bool operator==(const Intersection& i) const; 
    private:
        float _t;
        Sphere _object;
};
