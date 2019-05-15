#pragma once

class Color
{
    public:
        Color();
        Color(float r_, float v_, float b_);

        static int scale(float c);

        float getR() const;
        float getV() const;
        float getB() const;

        void setR(const float& r_);
        void setV(const float& v_);
        void setB(const float& b_);

        Color& clamp();

        Color operator+(const Color& c);
        Color operator+=(const Color& c);
        Color operator-(const Color& c);
        Color operator-=(const Color& c);
        Color operator*(const Color& c);
        Color operator*(const float& lambda);
        Color operator*=(const Color& c);
        Color operator*=(const float& lambda);

    protected:
        float r;
        float v;
        float b;
};
