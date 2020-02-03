#pragma once

#include <stdexcept>

template <typename T> class vec3 {
public:
    vec3() : x_(T()), y_(T()), z_(T()) {}
    vec3(T x, T y, T z) : x_(x), y_(y), z_(z) {}

    T &operator[] (int index) {
        if (index < 0 || index >= 3)
            throw std::out_of_range("Vector access");
        return !index ? x_ : index == 1 ? y_ : z_;
    }
    const T &operator[] (int index) const {
        if (index < 0 || index >= 3)
            throw std::out_of_range("Vector access");
        return !index ? x_ : index == 1 ? y_ : z_;
    }
private:
    T x_;
    T y_;
    T z_;
};

using Vec3f = vec3<float>;
