#pragma once

class Vector3 
{
    public:
        Vector3(float x_, float y_, float z_);
        
        static inline Vector3 fromPoints(const Vector3& p1, const Vector3& p2) {return Vector3(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);}

        float getX() const;
        float getY() const;
        float getZ() const;

        void setX(const float& value);
        void setY(const float& value);
        void setZ(const float& value);

        void inverse();
        void normalize();
        float distance(const Vector3& b);

        Vector3 operator+(const Vector3& b);
        Vector3 operator+=(const Vector3& b);
        Vector3 operator-(const Vector3& b);
        Vector3 operator-=(const Vector3& b);
        Vector3 operator*(const Vector3& b);
        Vector3 operator*=(const Vector3& b);
        Vector3 operator*(const float& lambda);
        Vector3 operator*=(const float& lambda);

    protected:
        float x;
        float y;
        float z;
};