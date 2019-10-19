#ifdef _TESTS

#include "point_light.hh"
#include "catch.hpp"

TEST_CASE("LIGHTS: A point light has a position and intensity", "[multi-file:light]")
{
    Color intensity(1, 1, 1);
    Point position(0, 0 ,0);
    Light l(position, intensity);
    REQUIRE(l.getPosition() == position);
    REQUIRE(l.getIntensity() == intensity);
}

#endif
