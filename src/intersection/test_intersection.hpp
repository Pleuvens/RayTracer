#pragma once

#include <vector>

#include "intersection.hh"
#include "op_overloading.hh"
#include "catch.hpp"

TEST_CASE("INTERSECTION: encapsulates t and object", "[multi-file:intersection]")
{
    Sphere s = Sphere();
    Intersection i(3.5, s);
    REQUIRE(isEqual(i.getT(), 3.5));
    REQUIRE(i.getObject() == s);
}

TEST_CASE("INTERSECTION: Aggregating intersections", "[multi-file:intersection]")
{
    Sphere s = Sphere();
    Intersection i1(1, s);
    Intersection i2(2, s);
    std::vector<Intersection> xs = Intersection::intersections({i1, i2});
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 1));
    REQUIRE(isEqual(xs[1].getT(), 2));
}

TEST_CASE("INTERSECTION: The hit, when all intersections have positive t",
        "[multi-file:intersection]")
{
    Sphere s = Sphere();
    Intersection i1(1, s);
    Intersection i2(2, s);
    auto xs = Intersection::intersections({i2, i1});
    auto i = Intersection::hit(xs);
    REQUIRE(i.value() == i1);
}

TEST_CASE("INTERSECTION: The hit, when some intersections have negative t",
        "[multi-file:intersection]")
{
    Sphere s = Sphere();
    Intersection i1(-1, s);
    Intersection i2(1, s);
    auto xs = Intersection::intersections({i2, i1});
    auto i = Intersection::hit(xs);
    REQUIRE(i.value() == i2);
}

TEST_CASE("INTERSECTION: The hit, when all intersections have negative t",
        "[multi-file:intersection]")
{
    Sphere s = Sphere();
    Intersection i1(-2, s);
    Intersection i2(-1, s);
    auto xs = Intersection::intersections({i2, i1});
    auto i = Intersection::hit(xs);
    REQUIRE(i == std::nullopt);
}

TEST_CASE("INTERSECTION: The hit is always the lowest nonnegative intersection",
        "[multi-file:intersection]")
{
    Sphere s = Sphere();
    Intersection i1(5, s);
    Intersection i2(7, s);
    Intersection i3(-3, s);
    Intersection i4(2, s);
    auto xs = Intersection::intersections({i1, i2, i3, i4});
    auto i = Intersection::hit(xs);
    REQUIRE(i.value() == i4);
}
