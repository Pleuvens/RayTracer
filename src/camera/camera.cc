#include <cmath>

#include "camera.hh"
#include "constants.hh"

#include "test_camera.hpp"

Camera::Camera(const int vsize, const int hsize, const float fov)
    : _vsize(vsize), _hsize(hsize), _fov(fov), _transform(Matrix::identity(4))
{
    float half_view = std::tan(fov / 2);
    _aspect = (float)hsize / (float)vsize;
    if (_aspect >= 1)
    {
        _half_width = half_view;
        _half_height = half_view / _aspect;
    } else {
        _half_width = half_view * _aspect;
        _half_height = half_view;
    }
    _pixel_size = (_half_width * 2) / (float)hsize;
}

Ray Camera::rayForPixel(const int py, const int px)
{
    // The offset from the edge of the canvas to the pixel's center
    float yoffset = (py + 0.5) * _pixel_size;
    float xoffset = (px + 0.5) * _pixel_size;

    // the untransformed coordinates of the pixel in world space
    float world_y = _half_height - yoffset;
    float world_x = _half_width - xoffset;

    // using the camera matrix, transform the canvas point and origin
    // then compute the ray's direction vector
    // canvas is at z=-1
    Point pixel = Point(_transform.invert() * Point(world_y, world_x, -1));
    Point origin = Point(_transform.invert() * Point(0, 0, 0));
    Vector direction = Vector(pixel - origin).normalize();
    return Ray(origin, direction);
}

Canvas Camera::render(World w)
{
    Canvas image(_vsize, _hsize);
    for (int y = 0; y < _vsize; y++)
    {
        for(int x = 0; x < _hsize; x++)
        {
            Ray r = rayForPixel(y, x);
            image.setPixel(y, x, w.colorAt(r));
        }
    }
    return image;
}
