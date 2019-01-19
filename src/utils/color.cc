#include "color.hh"

Color::Color(float r_, float v_, float b_)
{
    r = r_;
    v = v_;
    b = b_;
}

static float scale(float c)
{
  c *= 255;
  if (c > 255)
    return 255;
  if (c < 0)
    return 0;
  return c;
}

float Color::getR() const
{
    return r;
}

float Color::getV() const
{
    return v;
}

float Color::getB() const
{
    return b;
}

void Color::setR(const float& r_)
{
    r = r_;
}

void Color::setV(const float& v_)
{
    v = v_;
}

void Color::setB(const float& b_)
{
    b = b_;
}

Color& Color::clamp()
{
    if (r > 1)
        r = 1;
    if (r < 0)
        r =  0;
    if (v > 1)
        v = 1;
    if (v < 0)
        v =  0;
    if (b > 1)
        b = 1;
    if (b < 0)
        b =  0;
    return *this;
}

Color Color::operator+(const Color& c)
{
    Color res = Color(r + c.r, v + c.v, b + c.b);
    return res.clamp();
}

Color Color::operator+=(const Color& c)
{
    r += c.r;
    v += c.v;
    b += c.b;
    return clamp();
}

Color Color::operator-(const Color& c)
{
    Color res = Color(r - c.r, v - c.v, b - c.b);
    return res.clamp();
}

Color Color::operator-=(const Color& c)
{
    r -= c.r;
    v -= c.v;
    b -= c.b;
    return clamp();
}

Color Color::operator*(const Color& c)
{
    Color res = Color(r * c.r, v * c.v, b * c.b);
    return res.clamp();
}

Color Color::operator*(const float& lambda)
{
    Color res = Color(r * lambda, v * lambda, b * lambda);
    return res.clamp();
}

Color Color::operator*=(const Color& c)
{
    r *= c.r;
    v *= c.v;
    b *= c.b;
    return clamp();
}

Color Color::operator*=(const float& lambda)
{
    r *= lambda;
    v *= lambda;
    b *= lambda;
    return clamp();
}