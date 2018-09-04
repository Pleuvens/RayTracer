#pragma once

class Vector3 
{
    public:
        Vector3();
        
        float getX();
        float getY();
        float getZ();

        void setX(float value);
        void setY(float value);
        void setZ(float value);

        void inverse();
        void normalize();
        float distance(Vector3 const& b);
        Vector3 fromPoints(Vector3 const& p1, Vector3 const& p2);

        /*
        Vector3 operator+(float d, Vector3 const& v);
        Vector3 operator+(Vector3 const& v, float d);
        Vector3 operator-(Vector3 const& v, float d);
        Vector3 operator+(float d, Vector3 const& v);
        */

        Vector3 operator+(Vector3 const& a, Vector3 const& b);
        Vector3 operator+=(Vector3 const& b);
        Vector3 operator-(Vector3 const& a, Vector3 const& b);
        Vector3 operator-=(Vector3 const& b);
        Vector3 operator*(Vector3 const& a, Vector3 const& b);
        Vector3 operator*=(Vector3 const& b);
        Vector3 operator*(float lambda, Vector3 const& v);
        Vector3 operator*(Vector3 const& v, float lambda);

    protected:
        float x;
        float y;
        float z;
};