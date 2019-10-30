#ifdef _TESTS

#include "op_overloading.hh"

#include "catch.hpp"

TEST_CASE("PLANE: The normal of a plane is constant everywhere", "[multi-file:plane]")
{
    Plane p;
    auto n1 = p.localNormalAt(Point(0, 0, 0));
    auto n2 = p.localNormalAt(Point(10, 0, -10));
    auto n3 = p.localNormalAt(Point(-5, 0, 150));
    REQUIRE(n1 == Vector(0, 1, 0));
    REQUIRE(n2 == Vector(0, 1, 0));
    REQUIRE(n3 == Vector(0, 1, 0));
}

TEST_CASE("PLANE: Intersect with a ray parallel to the plane", "[multi-file:plane]")
{
    Plane p;
    Ray r(Point(0, 10, 0), Vector(0, 0, 1));
    auto xs = p.intersect(r);
    REQUIRE(xs.size() == 0);
}

TEST_CASE("PLANE: Intersect with a coplanar ray", "[multi-file:plane]")
{
    Plane p;
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    auto xs = p.intersect(r);
    REQUIRE(xs.size() == 0);
}

TEST_CASE("PLANE: A ray intersecting a plane from above", "[multi-file:plane]")
{
    Plane p;
    Ray r(Point(0, 1, 0), Vector(0, -1, 0));
    auto xs = p.intersect(r);
    REQUIRE(xs.size() == 1);
    REQUIRE(isEqual(xs[0].getT(), 1));
    REQUIRE(xs[0].getObject() == p);
}

TEST_CASE("PLANE: A ray intersecting a plane from below", "[multi-file:plane]")
{
    Plane p;
    Ray r(Point(0, -1, 0), Vector(0, 1, 0));
    auto xs = p.intersect(r);
    REQUIRE(xs.size() == 1);
    REQUIRE(isEqual(xs[0].getT(), 1));
    REQUIRE(xs[0].getObject() == p);
}

#endif
