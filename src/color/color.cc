#include <cmath>
#include <iostream>
#include "color.hh"
#include "constants.hh"
#ifdef _TESTS
#include "catch.hpp"
#endif

Color::Color(float red, float green, float blue)
    : _red(red), _green(green), _blue(blue)
{}

#ifdef _TESTS
TEST_CASE("COLOR: constructor", "[multi-file:color]") {
    Color c = Color(-0.5, 0.4, 1.7);
    REQUIRE(((c.getRed() - 0.5) < EPSILON && (c.getGreen() - 0.4) < EPSILON
            && (c.getBlue() - 1.7) < EPSILON) == true);
}
#endif

int Color::scale(float value) {
    int scaledValue = std::round(value * 255);
    if (value < 0)
        scaledValue = 0;
    if (scaledValue > 255)
        scaledValue = 255;
    return scaledValue;
}

Color Color::operator+(const Color& c)
{
    return Color(_red + c._red, _green + c._green, _blue + c._blue);
}

Color Color::operator+=(const Color& c)
{
    _red += c._red;
    _green += c._green;
    _blue += c._blue;
    return *this;
}

#ifdef _TESTS
TEST_CASE("COLOR: add colors", "[multi-file:color]") {
    REQUIRE((Color(0.9, 0.6, 0.75) + Color(0.7, 0.1, 0.25)) == Color(1.6, 0.7, 1.0));
    Color c = Color(0.9, 0.6, 0.75);
    REQUIRE((c += Color(0.7, 0.1, 0.25)) == Color(1.6, 0.7, 1.0));
}
#endif

Color Color::operator-(const Color& c)
{
    return Color(_red - c._red, _green - c._green, _blue - c._blue);
}

Color Color::operator-=(const Color& c)
{
    _red -= c._red;
    _green -= c._green;
    _blue -= c._blue;
    return *this;
}

#ifdef _TESTS
TEST_CASE("COLOR: substract colors", "[multi-file:color]") {
    REQUIRE((Color(0.9, 0.6, 0.75) - Color(0.7, 0.1, 0.25)) == Color(0.2, 0.5, 0.5));
    Color c = Color(0.9, 0.6, 0.75);
    REQUIRE((c -= Color(0.7, 0.1, 0.25)) == Color(0.2, 0.5, 0.5));
}
#endif

Color Color::operator*(const Color& c)
{
    return Color(_red * c._red, _green * c._green, _blue * c._blue);
}

Color Color::operator*=(const Color& c)
{
    _red *= c._red;
    _green *= c._green;
    _blue *= c._blue;
    return *this;
}

#ifdef _TESTS
TEST_CASE("COLOR: multiply colors", "[multi-file:color]") {
    REQUIRE((Color(1, 0.2, 0.4) * Color(0.9, 1, 0.1)) == Color(0.9, 0.2, 0.04));
    Color c = Color(1, 0.2, 0.4);
    REQUIRE((c *= Color(0.9, 1, 0.1)) == Color(0.9, 0.2, 0.04));
}
#endif

bool Color::operator==(const Color& c) const
{
    return std::abs(_red - c._red) < EPSILON && std::abs(_green - c._green) < EPSILON
        && std::abs(_blue - c._blue) < EPSILON;
}

bool Color::operator!=(const Color& c) const
{
    return std::abs(_red - c._red) > EPSILON || std::abs(_green - c._green) > EPSILON
        || std::abs(_blue - c._blue) > EPSILON;
}

std::ostream& operator<<(std::ostream& os, const Color& c)
{
    os << Color::scale(c.getRed()) << ' ' << Color::scale(c.getGreen()) << ' '
        << Color::scale(c.getBlue());
    return os;
}
