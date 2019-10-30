#ifdef _TESTS

#include <algorithm>

#include "world.hh"

#include "catch.hpp"

TEST_CASE("WORLD: Creating a world", "[multi-file:world]")
{
    World w;
    REQUIRE(w.getObjectsSize() == 0);
    REQUIRE(w.getLightsSize() == 0);
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
    REQUIRE(w.getLightsSize() == 1);
    REQUIRE(w.contains(std::make_shared<PointLight>(light)));
    REQUIRE(w.contains(std::make_shared<Sphere>(s1)));
    REQUIRE(w.contains(std::make_shared<Sphere>(s2)));
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

TEST_CASE("WORLD: Shading an intersection", "[multi-file:world]")
{
    World w = World::defaultWorld();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    auto shape = w.getObject(0);
    Intersection i(4, shape);
    auto comps = r.prepareComputations(i);
    auto c = w.shadeHit(comps, 1);
    REQUIRE(c == Color(0.38066, 0.47583, 0.2855));
}

TEST_CASE("WORLD: The color when a ray misses", "[multi-file:world]")
{
    World w = World::defaultWorld();
    Ray r(Point(0, 0, -5), Vector(0, 1, 0));
    Color c = w.colorAt(r, 1);
    REQUIRE(c == Color(0, 0, 0));
}

TEST_CASE("WORLD: The color when a ray hits", "[multi-file:world")
{
    World w = World::defaultWorld();
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Color c = w.colorAt(r, 1);
    REQUIRE(c == Color(0.38066, 0.47583, 0.2855));
}

TEST_CASE("WORLD: The color with an intersection behind the ray",
        "[multi-file:world]")
{
    World w = World::defaultWorld();
    auto outer = w.getObject(0);
    Material m = outer->getMaterial();
    m.setAmbient(1);
    outer->setMaterial(m);
    auto inner = w.getObject(1);
    Material m2 = inner->getMaterial();
    m2.setAmbient(1);
    inner->setMaterial(m2);
    Ray r(Point(0, 0, 0.75), Vector(0, 0, -1));
    Color c = w.colorAt(r, 1);
    REQUIRE(c == inner->getMaterial().getColor());
}

TEST_CASE("WORLD: There is no shadow when nothing is collinear with point and light",
        "[multi-file:world]")
{
    World w = World::defaultWorld();
    Point p(0, 10, 0);
    REQUIRE(!w.isShadowed(p));
}

TEST_CASE("WORLD: The shadow when an object is between the point and the light",
        "[multi-file:world]")
{
    World w = World::defaultWorld();
    Point p(10, -10, 10);
    REQUIRE(w.isShadowed(p));
}

TEST_CASE("WORLD: There is no shadow when an object is behind the light", 
        "[multi-file:world]")
{
    World w = World::defaultWorld();
    Point p(-20, 20, -20);
    REQUIRE(!w.isShadowed(p));
}

TEST_CASE("WORLD: There is no shadow when an object is behind the point", 
        "[multi-file:world]")
{
    World w = World::defaultWorld();
    Point p(-2, 2, -2);
    REQUIRE(!w.isShadowed(p));
}

TEST_CASE("WORLD: shadeHit is given an intersection in shadow", "[multi-file:world]")
{
    World w;
    w.addLight(std::make_shared<PointLight>(PointLight(Point(0, 0, -10),
                    Color(1, 1, 1))));
    Sphere s1;
    Sphere s2;
    s2.setTransform(Matrix::translation(0, 0, 10));
    w.addObject(std::make_shared<Sphere>(s1));
    w.addObject(std::make_shared<Sphere>(s2));
    Ray r(Point(0, 0, 5), Vector(0, 0, 1));
    Intersection i(4, std::make_shared<Sphere>(s2));
    auto comps = r.prepareComputations(i);
    Color c = w.shadeHit(comps, 1);
    REQUIRE(c == Color(0.1, 0.1, 0.1));
}

TEST_CASE("WORLD: The reflected color for a nonreflective material",
        "[multi-file:world]")
{
    World w = World::defaultWorld();
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    auto s = w.getObject(1);
    Material m = s->getMaterial();
    m.setAmbient(1);
    s->setMaterial(m);
    Intersection i(1, s);
    auto comps = r.prepareComputations(i);
    Color color = w.reflectedColor(comps, 1);
    REQUIRE(color == Color(0, 0, 0));
}

#endif
