#pragma once

#include <vector>

#include "sphere.hh"

class Intersection {
    public:
        Intersection(const float t, const Sphere& obj);

        static std::vector<Intersection>
            intersections(std::initializer_list<Intersection> list);
        
        inline float getT(void) const { return _t; }
        inline Sphere getObject(void) const { return _object; }
        
        inline void setT(const float t) { _t = t; }
        inline void setObject(const Sphere& obj) { _object = obj; }
    private:
        float _t;
        Sphere _object;
};
