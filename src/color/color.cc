#include "color.hh"
#include "constants.hh"
#include "catch.hpp"

Color::Color(float red, float green, float blue)
    : _red(red), _green(green), _blue(blue)
{}

TEST_CASE("COLOR: constructor", "[multi-file:color]") {
    Color c = Color(-0.5, 0.4, 1.7);
    REQUIRE(((c.getRed() - 0.5) < EPSILON && (c.getGreen() - 0.4) < EPSILON
            && (c.getBlue() - 1.7) < EPSILON) == true);
}
