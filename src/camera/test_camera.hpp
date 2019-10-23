#ifdef _TESTS

#include "camera.hh"
#include "op_overloading.hh"

#include "catch.hpp"

TEST_CASE("CAMERA: Constructing a camera", "[multi-file:camera]")
{
    Camera c(160, 120, PI / 2);
    REQUIRE(c.getHSize() == 120);
    REQUIRE(c.getVSize() == 160);
    REQUIRE(isEqual(c.getFOV(), PI / 2));
    REQUIRE(c.getTransform() == Matrix::identity(4));
}

TEST_CASE("CAMERA: The pixel size for a horizontal canvas", "[multi-file:camera]")
{
    Camera c(125, 200, PI / 2);
    REQUIRE(isEqual(c.getPixelSize(), 0.01));
}

TEST_CASE("CAMERA: The pixel size for a vertical canvas", "[multi-file:camera]")
{
    Camera c(200, 125, PI / 2);
    REQUIRE(isEqual(c.getPixelSize(), 0.01));
}

TEST_CASE("CAMERA: Constructing a ray through the center of the canvas",
        "[multi-file:camera]")
{
    Camera c(101, 201, PI / 2);
    Ray r = c.rayForPixel(50, 100);
    REQUIRE(r.getOrigin() == Point(0, 0, 0));
    REQUIRE(r.getDirection() == Vector(0, 0, -1));
}

TEST_CASE("CAMERA: Constructing a ray through the corner of the canvas",
        "[multi-file:camera]")
{
    Camera c(101, 201, PI / 2);
    Ray r = c.rayForPixel(0, 0);
    REQUIRE(r.getOrigin() == Point(0, 0, 0));
    REQUIRE(r.getDirection() == Vector(0.33259, 0.66519, -0.66851));
}

TEST_CASE("CAMERA: Constructing a ray when the camera is transformed",
        "[multi-file:camera]")
{
    Camera c(101, 201, PI / 2);
    c.setTransform(Matrix::rotationY(PI / 4) * Matrix::translation(0, -2, 5));
    Ray r = c.rayForPixel(50, 100);
    REQUIRE(r.getOrigin() == Point(0, 2, -5));
    const float value = std::sqrt(2) / 2;
    REQUIRE(r.getDirection() == Vector(value, 0, -value));
}

TEST_CASE("CAMERA: Rendering a world with a camera", "[multi-file:camera]")
{
    World w = World::defaultWorld();
    Camera c(11, 11, PI / 2);
    Point from(0, 0, -5);
    Point to(0, 0, 0);
    Vector up(0, 1, 0);
    c.setTransform(Matrix::viewTransform(from, to, up));
    auto image = c.render(w);
    REQUIRE(image.getPixel(5, 5) == Color(0.38066, 0.47583, 0.2855));
}

#endif
