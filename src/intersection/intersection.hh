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
        inline Point getPoint(void) const { return _point; }
        inline Point getOverPoint(void) const { return _over_point; }
        inline Vector getEyeVector(void) const { return _eye_v; }
        inline Vector getNormalVector(void) const { return _normal_v; }
        inline bool isInside(void) const { return _inside; }
        
        inline void setT(const float t) { _t = t; }
        inline void setObject(const Sphere& obj) { _object = obj; }
        inline void setPoint(const Point& p) { _point = p; }
        inline void setOverPoint(const Point& p) { _over_point = p; }
        inline void setEyeVector(const Vector& v) { _eye_v = v; }
        inline void setNormalVector(const Vector& v) { _normal_v = v; }
        inline void setInside(const bool b) { _inside = b; }

        bool operator==(const Intersection& i) const; 
        bool operator<(const Intersection& i) const; 
        bool operator<=(const Intersection& i) const; 
        bool operator>(const Intersection& i) const; 
        bool operator>=(const Intersection& i) const; 
    private:
        float _t;
        Sphere _object;
        Point _point;
        Vector _eye_v;
        Vector _normal_v;
        bool _inside;
        Point _over_point;
};
