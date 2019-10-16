#ifdef _TESTS

#include "ray.hh"
#include "op_overloading.hh"
#include "catch.hpp"

TEST_CASE("SPHERE: A sphere's default transformation", "[multi-file:sphere]")
{
    Sphere s;
    REQUIRE(s.getTransform() == Matrix::identity(4));
}

TEST_CASE("SPHERE: Changing a sphere's transformation",
        "[multi-file:sphere]")
{
    Sphere s;
    Matrix t = Matrix::translation(2, 3, 4);
    s.setTransform(t);
    REQUIRE(s.getTransform() == t);
}

TEST_CASE("SPHERE: Intersecting a scaled sphere with a ray",
        "[multi-file:sphere]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s;
    s.setTransform(Matrix::scaling(2, 2, 2));
    auto xs = r.intersect(s);
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 3));
    REQUIRE(isEqual(xs[1].getT(), 7));
}

TEST_CASE("SPHERE: Intersecting a translated sphere with a ray",
        "[multi-file:sphere]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s;
    s.setTransform(Matrix::translation(5, 0, 0));
    auto xs = r.intersect(s);
    REQUIRE(xs.size() == 0);
}

#endif
