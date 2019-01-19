#pragma once

#include "../utils/vector3.hh"

class Camera 
{
    public:
        Camera(int width_, int height_,
        Vector3 pos_, Vector3 u_, Vector3 v_, float fov_);

        int getWidth() const;
        int getHeight() const;
        Vector3 getPos() const;
        Vector3 getU() const;
        Vector3 getV() const;
        float getFOV() const;

        void setWidth(const int& width_);
        void setHeight(const int& height_);
        void setPos(const Vector3& pos_);
        void setU(const Vector3& u_);
        void setV(const Vector3& v_);
        void setFOV(const float& fov_);

    protected:
        int width;
        int height;
        Vector3 pos;
        Vector3 u;
        Vector3 v;
        float fov;
};