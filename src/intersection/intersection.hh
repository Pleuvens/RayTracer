#pragma once

#include <memory>
#include <vector>
#include <optional>

#include "object.hh"

class Intersection {
    using Object_p = std::shared_ptr<Object>;
    public:
        Intersection() = default;

        Intersection(const float t, Object_p obj);

        Intersection(Intersection&& i) noexcept = default;

        ~Intersection() = default;

        Intersection(Intersection& i);
        Intersection(const Intersection& i);
        Intersection& operator=(Intersection& i);
        Intersection& operator=(const Intersection& i);

        static std::vector<Intersection>
            intersections(std::initializer_list<Intersection> list);
        static std::optional<Intersection> hit(std::vector<Intersection> xs);
        
        inline float getT(void) const { return _t; }
        inline const Object_p& getObject(void) const { return _object; }
        inline Point getPoint(void) const { return _point; }
        inline Point getOverPoint(void) const { return _over_point; }
        inline Point getUnderPoint(void) const { return _under_point; }
        inline Vector getEyeVector(void) const { return _eye_v; }
        inline Vector getNormalVector(void) const { return _normal_v; }
        inline bool isInside(void) const { return _inside; }
        inline Vector getReflectVector(void) const { return _reflect_v; }
        inline float getN1(void) const { return _n1; }
        inline float getN2(void) const { return _n2; }
        
        inline void setT(const float t) { _t = t; }
        inline void setObject(Object_p obj) { _object = obj; }
        inline void setPoint(const Point& p) { _point = p; }
        inline void setOverPoint(const Point& p) { _over_point = p; }
        inline void setUnderPoint(const Point& p) { _under_point = p; }
        inline void setEyeVector(const Vector& v) { _eye_v = v; }
        inline void setNormalVector(const Vector& v) { _normal_v = v; }
        inline void setInside(const bool b) { _inside = b; }
        inline void setReflectVector(const Vector& v) { _reflect_v = v; }
        inline void setN1(const float v) { _n1 = v; }
        inline void setN2(const float v) { _n2 = v; }

        bool operator==(const Intersection& i) const; 
        bool operator<(const Intersection& i) const; 
        bool operator<=(const Intersection& i) const; 
        bool operator>(const Intersection& i) const; 
        bool operator>=(const Intersection& i) const; 
    private:
        float _t;
        Object_p _object;
        Point _point;
        Vector _eye_v;
        Vector _normal_v;
        bool _inside;
        Point _over_point;
        Point _under_point;
        Vector _reflect_v;
        float _n1;
        float _n2;
};
