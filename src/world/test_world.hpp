#ifdef _TESTS

#include <algorithm>

#include "world.hh"

#include "catch.hpp"

TEST_CASE("WORLD: Creating a world", "[multi-file:world]")
{
    World w;
    REQUIRE(w.getObjects().size() == 0);
    REQUIRE(w.getLights().size() == 0);
}

TEST_CASE("WORLD: The default world", "[multi-file:world]")
{
    PointLight light(Point(-10, 10, -10), Color::white());
    Material m1;
    m1.setColor(Color(0.8, 1, 9.6));
    m1.setDiffuse(0.7);
    m1.setSpecular(0.2);
    Sphere s1;
    Sphere s2;
    s1.setMaterial(m1);
    s2.setTransform(Matrix::scaling(0.5, 0.5, 0.5));
    World w = World::defaultWorld();
    REQUIRE(w.getLights().size() == 1);
    REQUIRE(w.getLights()[0] == light);
    REQUIRE(std::find(w.getObjects().begin(), w.getObjects().end(), s1)
            != w.getObjects().end());
    REQUIRE(std::find(w.getObjects().begin(), w.getObjects().end(), s2)
            != w.getObjects().end());
}

TEST_CASE("WORLD: Intersect a world with a ray", "[multi-file:world]")
{
    World w = World::defaultWorld();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto xs = w.intersect(r);
    REQUIRE(xs.size() == 4);
    REQUIRE(isEqual(xs[0].getT(), 4));
    REQUIRE(isEqual(xs[1].getT(), 4.5));
    REQUIRE(isEqual(xs[2].getT(), 5.5));
    REQUIRE(isEqual(xs[3].getT(), 6));
}

#endif
