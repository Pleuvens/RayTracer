#ifdef _TESTS

#include "ray.hh"
#include "point.hh"
#include "vector.hh"
#include "intersection.hh"
#include "sphere.hh"
#include "catch.hpp"
#include "op_overloading.hh"

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
    Sphere s = Sphere();
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 4.0));
    REQUIRE(isEqual(xs[1].getT(), 6.0));
}

TEST_CASE("RAY: ray intersects a sphere at a tangent", "[multi-file:ray]")
{
    Ray r(Point(0, 1, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 5.0));
    REQUIRE(isEqual(xs[1].getT(), 5.0));
}

TEST_CASE("RAY: ray misses a sphere", "[multi-file:ray]")
{
    Ray r(Point(0, 2, -5), Vector(0, 0, 1));
    Sphere s = Sphere();
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 0);
}

TEST_CASE("RAY: ray originates inside a sphere", "[multi-file:ray]")
{
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    Sphere s = Sphere();
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), -1.0));
    REQUIRE(isEqual(xs[1].getT(), 1.0));
}

TEST_CASE("RAY: ray is behind a sphere", "[multi-file:ray]")
{
    Ray r(Point(0, 0, 5), Vector(0, 0, 1));
    Sphere s = Sphere();
    std::vector<Intersection> xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), -6.0));
    REQUIRE(isEqual(xs[1].getT(), -4.0));
}

#endif
