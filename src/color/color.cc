#include <cmath>
#include <iostream>
#include "color.hh"
#include "op_overloading.hh"
#include "test_color.hpp"

Color::Color(float red, float green, float blue)
    : _red(red), _green(green), _blue(blue)
{}

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

bool Color::operator==(const Color& c) const
{
    return isEqual(_red, c._red) && isEqual(_green, c._green) && isEqual(_blue, c._blue);
}

bool Color::operator!=(const Color& c) const
{
    return isNotEqual(_red, c._red) || isNotEqual(_green, c._green)
        || isNotEqual(_blue, c._blue);
}

std::ostream& operator<<(std::ostream& os, const Color& c)
{
    os << Color::scale(c.getRed()) << ' ' << Color::scale(c.getGreen()) << ' '
        << Color::scale(c.getBlue());
    return os;
}
