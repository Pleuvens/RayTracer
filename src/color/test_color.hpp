#ifdef _TESTS

#include "color.hh"
#include "catch.hpp"

TEST_CASE("COLOR: constructor", "[multi-file:color]") {
    Color c = Color(-0.5, 0.4, 1.7);
    REQUIRE((c.getRed() == 0.5 && c.getGreen() == 0.4 && c.getBlue() == 1.7) == true);
}

TEST_CASE("COLOR: add colors", "[multi-file:color]") {
    REQUIRE((Color(0.9, 0.6, 0.75) + Color(0.7, 0.1, 0.25)) == Color(1.6, 0.7, 1.0));
    Color c = Color(0.9, 0.6, 0.75);
    REQUIRE((c += Color(0.7, 0.1, 0.25)) == Color(1.6, 0.7, 1.0));
}

TEST_CASE("COLOR: substract colors", "[multi-file:color]") {
    REQUIRE((Color(0.9, 0.6, 0.75) - Color(0.7, 0.1, 0.25)) == Color(0.2, 0.5, 0.5));
    Color c = Color(0.9, 0.6, 0.75);
    REQUIRE((c -= Color(0.7, 0.1, 0.25)) == Color(0.2, 0.5, 0.5));
}

TEST_CASE("COLOR: multiply colors", "[multi-file:color]") {
    REQUIRE((Color(1, 0.2, 0.4) * Color(0.9, 1, 0.1)) == Color(0.9, 0.2, 0.04));
    Color c = Color(1, 0.2, 0.4);
    REQUIRE((c *= Color(0.9, 1, 0.1)) == Color(0.9, 0.2, 0.04));
}

#endif
