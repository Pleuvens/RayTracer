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
