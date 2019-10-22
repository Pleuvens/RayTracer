#pragma once

#include "canvas.hh"
#include "matrix.hh"
#include "ray.hh"
#include "world.hh"

class Camera {
    public:
        Camera(const int vsize, const int hsize, const float fov);

        inline int getHSize(void) const { return _hsize; }
        inline int getVSize(void) const { return _vsize; }
        inline float getFOV(void) const { return _fov; }
        inline Matrix getTransform(void) const { return _transform; }
        inline float getHalfWidth(void) const { return _half_width; }
        inline float getHalfHeight(void) const { return _half_height; }
        inline float getAspect(void) const { return _aspect; }
        inline float getPixelSize(void) const { return _pixel_size; }

        inline void setHSize(const int hsize) { _hsize = hsize; }
        inline void setVSize(const int vsize) {  _vsize = vsize; }
        inline void setFOV(const float fov) { _fov = fov; }
        inline void setTransform(const Matrix& m) { _transform = m; }
        inline void setHalfWidth(const float half_w) { _half_width = half_w; }
        inline void setHalfHeight(const float half_h) { _half_height = half_h; }
        inline void setAspect(const float aspect) { _aspect = aspect; }
        inline void setPixelSize(const float pixel_size) { _pixel_size = pixel_size; }

        Ray rayForPixel(const int py, const int px);
        Canvas render(World w);

    private:
        int _vsize;
        int _hsize;
        float _fov;
        Matrix _transform;
        float _half_width;
        float _half_height;
        float _aspect;
        float _pixel_size;
};
