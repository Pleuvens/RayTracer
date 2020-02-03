#pragma once

#include "vector.hh"

class Light {
public:
    Light(const Vec3f& pos, float intensity) : position_(pos), intensity_(intensity) {}

    Vec3f position_;
    float intensity_;
};
