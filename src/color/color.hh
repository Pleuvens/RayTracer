#pragma once

#include <iostream>

class Color {
    public:
        Color() = default;
        Color(float red, float green, float blue);

        Color(Color&& c) = default;

        Color(Color& c) = default;
        Color(const Color& c) = default;
        Color& operator=(Color& c) = default;
        Color& operator=(const Color& c) = default;

        ~Color() = default;

        static Color red(void) { return Color(1, 0, 0); }
        static Color green(void) { return Color(0, 1, 0); }
        static Color blue(void) { return Color(0, 0, 1); }
        static Color black(void) { return Color(0, 0, 0); }
        static Color white(void) { return Color(1, 1, 1); }

        static int scale(float value);

        inline float getRed(void) const { return _red; }
        inline float getGreen(void) const { return _green; }
        inline float getBlue(void) const { return _blue; }

        inline void setRed(const float red) { _red = red; }
        inline void setGreen(const float green) { _green = green; }
        inline void setBlue(const float blue) { _blue = blue; }

        Color operator+(const Color& c);
        Color operator+=(const Color& c);
        friend Color operator-(const Color& lhs, const Color& rhs);
        Color operator-=(const Color& c);
        friend Color operator*(const Color& lhs, const Color& rhs);
        Color operator*=(const Color& c);
        friend Color operator*(const Color& lhs, const float rhs);
        Color operator*=(const float v);
        bool operator==(const Color& c) const;
        bool operator!=(const Color& c) const;
        friend std::ostream& operator<<(std::ostream& os, const Color& c);
    private:
        float _red;
        float _green;
        float _blue;
};
