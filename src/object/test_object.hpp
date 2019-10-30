#ifdef _TESTS

#include "constants.hh"
#include "sphere.hh"

#include "catch.hpp"

TEST_CASE("OBJECT: The default transformation", "[multi-file:object]")
{
    Sphere o;
    REQUIRE(o.getTransform() == Matrix::identity(4));
    REQUIRE(o.getMaterial() == Material());
}

TEST_CASE("OBJECT: Assigning a transformation", "[multi-file:object]")
{
    Sphere o;
    o.setTransform(Matrix::translation(2, 3, 4));
    REQUIRE(o.getTransform() == Matrix::translation(2, 3, 4));
}

TEST_CASE("OBJECT: Assigning a material", "[multi-file:object]")
{
    Sphere o;
    Material m;
    o.setMaterial(m);
    REQUIRE(o.getMaterial() == m);
}

TEST_CASE("OBJECT: Intersecting a scaled shape with a ray", "[multi-file:object]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s;
    s.setTransform(Matrix::scaling(2, 2, 2));
    auto xs = s.intersect(r);
    REQUIRE(s.getSavedRay()->getOrigin() == Point(0, 0, -2.5));
    REQUIRE(s.getSavedRay()->getDirection() == Vector(0, 0, 0.5));
}

TEST_CASE("OBJECT: Intersecting a translated shape with a ray", "[multi-file:object]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere s;
    s.setTransform(Matrix::translation(5, 0, 0));
    auto xs = s.intersect(r);
    REQUIRE(s.getSavedRay()->getOrigin() == Point(-5, 0, -5));
    REQUIRE(s.getSavedRay()->getDirection() == Vector(0, 0, 1));
}

TEST_CASE("OBJECT: Computing the normal on a translated shape", "[multi-file:object]")
{
    Sphere s;
    s.setTransform(Matrix::translation(0, 1, 0));
    auto n = s.normalAt(Point(0, 1.70711, -0.70711));
    REQUIRE(n == Vector(0, 0.70711, -0.70711));
}

TEST_CASE("OBJECT: Computing the normal on a transformed shape", "[multi-file:object]")
{
    Sphere s;
    Matrix m = Matrix::scaling(1, 0.5, 1) * Matrix::rotationZ(PI / 5);
    s.setTransform(m);
    auto n = s.normalAt(Point(0, std::sqrt(2) / 2, -std::sqrt(2) / 2));
    REQUIRE(n == Vector(0, 0.97014, -0.24254));
}

#endif
