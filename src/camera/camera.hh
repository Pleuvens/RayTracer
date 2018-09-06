#pragma once

#include "../utils/vector3.hh"

class Camera 
{
    public:
        Camera(int width_, int height_,
        Vector3 pos_, Vector3 u_, Vector3 v_, float fov_);

        int getWidth();
        int getHeight();
        Vector3 getPos();
        Vector3 getU();
        Vector3 getV();
        float getFOV();

        void setWidth(int width_);
        void setHeight(int height_);
        void setPos(Vector3 pos_);
        void setU(Vector3 u_);
        void setV(Vector3 v_);
        void setFOV(float fov_);

    protected:
        int width;
        int height;
        Vector3 pos;
        Vector3 u;
        Vector3 v;
        float fov;
};