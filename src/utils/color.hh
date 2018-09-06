#pragma once

class Color
{
    public:
        Color(float r_, float v_, float b_);

        float getR();
        float getV();
        float getB();

        void setR(float r_);
        void setV(float v_);
        void setB(float b_);

        void clamp();
        int scale(float c);

        Color operator+(Color const& a, Color const& b);
        void operator+=(Color const& b);
        Color operator-(Color const& a, Color const& b);
        void operator-=(Color const& b);
        Color operator*(Color const& a, Color const& b);
        void operator*=(Color const& b);
        Color operator*(Color const& c, float lambda);
        Color operator*(float lambda, Color const& c);
        void operator*=(float lambda);

    protected:
        float r;
        float v;
        float b;
};