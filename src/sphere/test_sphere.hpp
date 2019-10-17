#ifdef _TESTS

#include "ray.hh"
#include "op_overloading.hh"
#include "constants.hh"
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

TEST_CASE("SPHERE: The normal on a sphere at a point on the x axis",
        "[multi-file:sphere]")
{
    Sphere s;
    Point p(1, 0, 0);
    auto n = s.normalAt(p);
    REQUIRE(n == Vector(1, 0, 0));
}

TEST_CASE("SPHERE: The normal on a sphere at a point on the y axis",
        "[multi-file:sphere]")
{
    Sphere s;
    Point p(0, 1, 0); 
    auto n = s.normalAt(p);
    REQUIRE(n == Vector(0, 1, 0));
}

TEST_CASE("SPHERE: The normal on a sphere at a point on the z axis",
        "[multi-file:sphere]")
{
    Sphere s;
    Point p(0, 0, 1);
    auto n = s.normalAt(p);
    REQUIRE(n == Vector(0, 0, 1));
}

TEST_CASE("SPHERE: The normal on a sphere at a nonaxial point", "[multi-file:sphere]")
{
    Sphere s;
    const float value = std::sqrt(3) / 3;
    Point p(value, value, value);
    auto n = s.normalAt(p);
    REQUIRE(n == Vector(value, value, value));
}

TEST_CASE("SPHERE: The normal is a normalized vector", "[multi-file:sphere]")
{
    Sphere s;
    const float value = std::sqrt(3) / 3;
    Point p(value, value, value);
    auto n = s.normalAt(p);
    REQUIRE(n == n.normalize());
}

TEST_CASE("SPHERE: Computing the normal on a translated sphere", "[multi-file:sphere]")
{
    Sphere s;
    s.setTransform(Matrix::translation(0, 1, 0));
    Point p(0, 1.70711, -0.70711);
    auto n = s.normalAt(p);
    REQUIRE(n == Vector(0, 0.70711, -0.70711));
}

TEST_CASE("SPHERE: Computing the normal on a transformed sphere", "[multi-file:sphere]")
{
    Sphere s;
    auto m = Matrix::scaling(1, 0.5, 1) * Matrix::rotationZ(PI / 5);
    s.setTransform(m);
    const float value = std::sqrt(2) / 2;
    Point p(0, value, -value);
    auto n = s.normalAt(p);
    REQUIRE(n == Vector(0, 0.97014, -0.24254));
}

#endif
