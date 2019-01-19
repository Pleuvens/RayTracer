#pragma once

class Vector3 
{
    public:
        Vector3(float x_, float y_, float z_);
        
        float getX() const;
        float getY() const;
        float getZ() const;

        void setX(float value);
        void setY(float value);
        void setZ(float value);

        void inverse();
        void normalize();
        float distance(Vector3 const& b);
        Vector3 fromPoints(Vector3 const& p1, Vector3 const& p2);

        Vector3 operator+(const Vector3& b);
        Vector3 operator+=(const Vector3& b);
        Vector3 operator-(const Vector3& b);
        Vector3 operator-=(const Vector3& b);
        Vector3 operator*(const Vector3& b);
        Vector3 operator*=(const Vector3& b);
        Vector3 operator*(float lambda);
        Vector3 operator*=(float lambda);

    protected:
        float x;
        float y;
        float z;
};