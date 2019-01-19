#include "camera.hh"

Camera::Camera(int width_, int height_,
        Vector3 pos_, Vector3 u_, Vector3 v_, float fov_)
{
    width = width_;
    height = height_;
    pos = pos_;
    u = u_;
    v = v_;
    fov = fov_;
}

int Camera::getWidth() const
{
    return width;
}

int Camera::getHeight() const
{
    return height;
}

Vector3 Camera::getPos() const
{
    return pos;
}

Vector3 Camera::getU() const
{
    return u;
}

Vector3 Camera::getV() const
{
    return v;
}

float Camera::getFOV() const
{
    return fov;
}

void Camera::setWidth(const int& width_)
{
    width = width_;
}

void Camera::setHeight(const int& height_)
{
    height = height_;
}

void Camera::setPos(const Vector3& pos_)
{
    pos = pos_;
}

void Camera::setU(const Vector3& u_)
{
    u = u_;
}

void Camera::setV(const Vector3& v_)
{
    v = v_;
}

void Camera::setFOV(const float& fov_)
{
    fov = fov_;
}