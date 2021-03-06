#ifdef _TESTS

#include "constants.hh"
#include "intersection.hh"
#include "op_overloading.hh"
#include "plane.hh"
#include "point.hh"
#include "ray.hh"
#include "sphere.hh"
#include "vector.hh"

#include "catch.hpp"

TEST_CASE("RAY: Creating a ray", "[multi-file:ray]")
{
    Point origin(1, 2, 3);
    Vector direction(4, 5, 6);
    Ray r(origin, direction);
    REQUIRE(r.getOrigin() == origin);
    REQUIRE(r.getDirection() == direction);
}

TEST_CASE("RAY: Computing a point from a distance", "[multi-file:ray]")
{
    Ray r(Point(2, 3, 4), Vector(1, 0, 0));
    Point res(2, 3, 4);
    Point res2(3, 3, 4);
    Point res3(1, 3, 4);
    Point res4(4.5, 3, 4);
    REQUIRE(r.position(0) == res);
    REQUIRE(r.position(1) == res2);
    REQUIRE(r.position(-1) == res3);
    REQUIRE(r.position(2.5) == res4);
}

TEST_CASE("RAY: ray intersects a sphere at two points", "[multi-file:ray]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s;
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 4.0));
    REQUIRE(isEqual(xs[1].getT(), 6.0));
}

TEST_CASE("RAY: ray intersects a sphere at a tangent", "[multi-file:ray]")
{
    Ray r(Point(0, 1, -5), Vector(0, 0, 1));
    Sphere s;
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 5.0));
    REQUIRE(isEqual(xs[1].getT(), 5.0));
}

TEST_CASE("RAY: ray misses a sphere", "[multi-file:ray]")
{
    Ray r(Point(0, 2, -5), Vector(0, 0, 1));
    Sphere s;
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 0);
}

TEST_CASE("RAY: ray originates inside a sphere", "[multi-file:ray]")
{
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere s;
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), -1.0));
    REQUIRE(isEqual(xs[1].getT(), 1.0));
}

TEST_CASE("RAY: ray is behind a sphere", "[multi-file:ray]")
{
    Ray r(Point(0, 0, 5), Vector(0, 0, 1));
    Sphere s;
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), -6.0));
    REQUIRE(isEqual(xs[1].getT(), -4.0));
}

TEST_CASE("RAY: sets the object on the intersection", "[multi-file:ray]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s;
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(xs[0].getObject() == s);
    REQUIRE(xs[1].getObject() == s);
}

TEST_CASE("RAY: Translating a ray", "[multi-file:ray]")
{
    Ray r(Point(1, 2, 3), Vector(0, 1, 0));
    Matrix m(Matrix::translation(3, 4, 5));
    Ray r2 = r.transform(m);
    REQUIRE(r2.getOrigin() == Point(4, 6, 8));
    REQUIRE(r2.getDirection() == Vector(0, 1, 0));
}

TEST_CASE("RAY: Scaling a ray", "[multi-file:ray]")
{
    Ray r(Point(1, 2, 3), Vector(0, 1, 0));
    Matrix m(Matrix::scaling(2, 3, 4));
    Ray r2 = r.transform(m);
    REQUIRE(r2.getOrigin() == Point(2, 6, 12));
    REQUIRE(r2.getDirection() == Vector(0, 3, 0));
}

TEST_CASE("RAY: Precomputing the state of an intersection",
        "[multi-file:ray]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape;
    Intersection i(4, std::make_shared<Sphere>(shape));
    auto comps = r.prepareComputations(i);
    REQUIRE(isEqual(comps.getT(), i.getT()));
    REQUIRE(comps.getObject() == i.getObject());
    REQUIRE(comps.getPoint() == Point(0, 0, -1));
    REQUIRE(comps.getEyeVector() == Vector(0, 0, -1));
    REQUIRE(comps.getNormalVector() == Vector(0, 0, -1));
}

TEST_CASE("RAY: The hit, when an intersection occurs on the outside",
        "[multi-file:ray]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape;
    Intersection i(4, std::make_shared<Sphere>(shape));
    auto comps = r.prepareComputations(i);
    REQUIRE(!comps.isInside());
}

TEST_CASE("RAY: The hit, when an intersection occurs on the inside",
        "[multi-file:ray]")
{
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere shape;
    Intersection i(1, std::make_shared<Sphere>(shape));
    auto comps = r.prepareComputations(i);
    REQUIRE(comps.getPoint() == Point(0, 0, 1));
    REQUIRE(comps.getEyeVector() == Vector(0, 0, -1));
    REQUIRE(comps.isInside());
    REQUIRE(comps.getNormalVector() == Vector(0, 0, -1));
}

TEST_CASE("RAY: The hit should offset the point", "[multi-file:ray]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape;
    shape.setTransform(Matrix::translation(0, 0, 1));
    Intersection i(5, std::make_shared<Sphere>(shape));
    auto comps = r.prepareComputations(i);
    REQUIRE(comps.getOverPoint().getZ() < -EPSILON / 2);
    REQUIRE(comps.getPoint().getZ() > comps.getOverPoint().getZ());
}

TEST_CASE("RAY: Precomputing the reflection vector", "[multi-file:ray]")
{
    Plane shape;
    Ray r(Point(0, 1, -1), Vector(0, -std::sqrt(2) / 2, std::sqrt(2) / 2));
    Intersection i(std::sqrt(2), std::make_shared<Plane>(shape));
    auto comps = r.prepareComputations(i);
    REQUIRE(comps.getReflectVector() == Vector(0, std::sqrt(2) / 2, std::sqrt(2) / 2));
}

#endif
