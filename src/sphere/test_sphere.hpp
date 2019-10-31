#ifdef _TESTS

#include "ray.hh"
#include "op_overloading.hh"
#include "constants.hh"
#include "catch.hpp"

TEST_CASE("SPHERE: The normal on a sphere at a point on the x axis",
        "[multi-file:sphere]")
{
    Sphere s;
    Point p(1, 0, 0);
    auto n = s.localNormalAt(p);
    REQUIRE(n == Vector(1, 0, 0));
}

TEST_CASE("SPHERE: The normal on a sphere at a point on the y axis",
        "[multi-file:sphere]")
{
    Sphere s;
    Point p(0, 1, 0); 
    auto n = s.localNormalAt(p);
    REQUIRE(n == Vector(0, 1, 0));
}

TEST_CASE("SPHERE: The normal on a sphere at a point on the z axis",
        "[multi-file:sphere]")
{
    Sphere s;
    Point p(0, 0, 1);
    auto n = s.localNormalAt(p);
    REQUIRE(n == Vector(0, 0, 1));
}

TEST_CASE("SPHERE: The normal on a sphere at a nonaxial point", "[multi-file:sphere]")
{
    Sphere s;
    const float value = std::sqrt(3) / 3;
    Point p(value, value, value);
    auto n = s.localNormalAt(p);
    REQUIRE(n == Vector(value, value, value));
}

TEST_CASE("SPHERE: The normal is a normalized vector", "[multi-file:sphere]")
{
    Sphere s;
    const float value = std::sqrt(3) / 3;
    Point p(value, value, value);
    auto n = s.localNormalAt(p);
    REQUIRE(n == n.normalize());
}

TEST_CASE("SPHERE: Computing the normal on a translated sphere", "[multi-file:sphere]")
{
    Sphere s;
    s.setTransform(Matrix::translation(0, 1, 0));
    Point p(0, 1.70711, -0.70711);
    auto n = s.localNormalAt(p);
    REQUIRE(n == Vector(0, 0.70711, -0.70711));
}

TEST_CASE("SPHERE: Computing the normal on a transformed sphere", "[multi-file:sphere]")
{
    Sphere s;
    auto m = Matrix::scaling(1, 0.5, 1) * Matrix::rotationZ(PI / 5);
    s.setTransform(m);
    const float value = std::sqrt(2) / 2;
    Point p(0, value, -value);
    auto n = s.localNormalAt(p);
    REQUIRE(n == Vector(0, 0.97014, -0.24254));
}

#endif
