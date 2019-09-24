#pragma once

class Tuple {

    public:
        Tuple(const float x, const float y, const float z, const float w);

        inline float getX() const { return _x; }
        inline float getY() const { return _y; }
        inline float getZ() const { return _z; }
        inline float getW() const { return _w; }

        inline void setX(const float x) { _x = x; }
        inline void setY(const float y) { _y = y; }
        inline void setZ(const float z) { _z = z; }
        inline void setW(const float w) { _w = w; }

        Tuple operator+(const Tuple& b);
        Tuple operator+=(const Tuple& b);
        Tuple operator-(const Tuple& b);
        Tuple operator-=(const Tuple& b);
        Tuple operator-();
        Tuple operator*(const float lambda);
        Tuple operator*=(const float lambda);
        Tuple operator/(const float lambda);
        Tuple operator/=(const float lambda);
        bool operator==(const Tuple& b) const;
        bool operator!=(const Tuple& b) const;

    protected:
        float _x;
        float _y;
        float _z;
        float _w;
};
