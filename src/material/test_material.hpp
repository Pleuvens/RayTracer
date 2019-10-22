#ifdef _TESTS

#include "material.hh"
#include "op_overloading.hh"
#include "catch.hpp"

TEST_CASE("MATERIAL: the default material", "[multi-file:material]")
{
    Material m;
    REQUIRE(m.getColor() == Color(1, 1, 1));
    REQUIRE(isEqual(m.getAmbient(), 0.1));
    REQUIRE(isEqual(m.getDiffuse(), 0.9));
    REQUIRE(isEqual(m.getSpecular(), 0.9));
    REQUIRE(isEqual(m.getShininess(), 200));
}

TEST_CASE("MATERIAL: Lighting with the eye between the light and the surface",
        "[multi-file:material]")
{
    Material m;
    Point p(0, 0, 0);
    Vector eyev(0, 0, -1);
    Vector normalv(0, 0, -1);
    PointLight light(Point(0, 0, -10), Color(1, 1, 1));
    auto result = m.lighting(light, p, eyev, normalv);
    REQUIRE(result == Color(1.9, 1.9, 1.9));
}

TEST_CASE("MATERIAL: Lighting with the eye between light and surface, eye offset 45deg",
        "[multi-file:material]")
{
    Material m;
    Point p(0, 0, 0);
    const float value = std::sqrt(2) / 2;
    Vector eyev(0, value, -value);
    Vector normalv(0, 0, -1);
    PointLight light(Point(0, 0, -10), Color(1, 1, 1));
    auto result = m.lighting(light, p, eyev, normalv);
    REQUIRE(result == Color(1.0, 1.0, 1.0));
}

TEST_CASE("MATERIAL: Lighting with the eye opposite surface, light offset 45deg",
        "[multi-file:material]")
{
    Material m;
    Point p(0, 0, 0);
    Vector eyev(0, 0, -1);
    Vector normalv(0, 0, -1);
    PointLight light(Point(0, 10, -10), Color(1, 1, 1));
    auto result = m.lighting(light, p, eyev, normalv);
    REQUIRE(result == Color(0.7364, 0.7364, 0.7364));
}

TEST_CASE("MATERIAL: Lighting with eye in the path of the reflection vector",
        "[multi-file:material]")
{
    Material m;
    Point p(0, 0, 0);
    const float value = std::sqrt(2) / 2;
    Vector eyev(0, -value, -value);
    Vector normalv(0, 0, -1);
    PointLight light(Point(0, 10, -10), Color(1, 1, 1));
    auto result = m.lighting(light, p, eyev, normalv);
    REQUIRE(result == Color(1.6364, 1.6364, 1.6364));
}

TEST_CASE("MATERIAL: Lighting with the light behind the surface",
        "[multi-file:material]")
{
    Material m;
    Point p(0, 0, 0);
    Vector eyev(0, 0, -1);
    Vector normalv(0, 0, -1);
    PointLight light(Point(0, 0, 10), Color(1, 1, 1));
    auto result = m.lighting(light, p, eyev, normalv);
    REQUIRE(result == Color(0.1, 0.1, 0.1));
}

TEST_CASE("MATERIAL: Lighting with the surface in shadow", "[multi-file:material]")
{
    Material m;
    Point p(0, 0, 0);
    Vector eyev(0, 0, -1);
    Vector normalv(0, 0, -1);
    PointLight light(Point(0, 0, -10), Color(1, 1, 1));
    bool in_shadow = true;
    Color res = m.lighting(light, p, eyev, normalv, in_shadow);
    REQUIRE(res == Color(0.1, 0.1, 0.1));
}

#endif
