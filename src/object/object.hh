#pragma once

#include <memory>
#include <vector>

#include "material.hh"
#include "matrix.hh"
#include "point.hh"
#include "vector.hh"

class Intersection; 
class Ray;

class Object {
    public:
        Object();

        Object(Object&& o) noexcept = default;

        ~Object() = default;

        Object(Object& o) = default;
        Object(const Object& o) = default;
        Object& operator=(Object& o);
        Object& operator=(const Object& o);

        using Ray_p = std::shared_ptr<Ray>;

        inline const Matrix& getTransform(void) const noexcept { return _transform; }
        inline const Material& getMaterial(void) const noexcept { return _material; }
        inline Ray_p getSavedRay(void) const noexcept { return _saved_ray; }

        inline void setTransform(const Matrix& m) noexcept { _transform = m; }
        inline void setMaterial(const Material& m) noexcept { _material = m; }
        inline void setSavedRay(Ray_p r) noexcept { _saved_ray = r; }

        Vector normalAt(Point p) const;
        std::vector<Intersection> intersect(Ray ray);
        virtual std::vector<Intersection> localIntersect(Ray ray) = 0;
        virtual Vector localNormalAt(Point p) const = 0;

        bool operator==(const Object& s) const noexcept { (void)s; return true; }

    protected:
        Matrix _transform;
        Material _material;
        Ray_p _saved_ray;
};

class TestShape : public Object {
    public:
        TestShape() = default;
        TestShape(TestShape&& ts) = default;
        TestShape(TestShape& ts) = default;
        TestShape(const TestShape& ts) = default;
        TestShape& operator=(TestShape& ts) = default;
        TestShape& operator=(const TestShape& ts) = default;
        ~TestShape() = default;

        std::vector<Intersection> localIntersect(Ray ray);
        Vector localNormalAt(Point p) const;
};
