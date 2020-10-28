#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>

template <typename T> class vec2 {
public:
    vec2() : x_(T()), y_(T()) {}
    vec2(T x, T y) : x_(x), y_(y) {}

    T &operator[] (int index) {
        if (index < 0 || index >= 2)
            throw std::out_of_range("Vector 2 access");
        return !index ? x_ : y_;
    }
    const T &operator[] (int index) const {
        if (index < 0 || index >= 2)
            throw std::out_of_range("Vector 2 access");
        return !index ? x_ : y_;
    }

    vec2<T> operator+(const vec2<T>& v) const
    {
        return vec2<T>(x_ + v.x_, y_ + v.y_);
    }

    vec2<T> operator-(const vec2<T>& v) const
    {
        return vec2<T>(x_ - v.x_, y_ - v.y_);
    }

    vec2<T> operator*(const vec2<T>& v) const
    {
        return vec2<T>(x_ * v.x_, y_ * v.y_);
    }

    std::ostream& operator<<(std::ostream& out) const {
        out << x_ << " " << y_ ;
        return out;
    }
private:
    T x_;
    T y_;
};

template <typename T> class vec3 {
public:
    vec3() : x_(T()), y_(T()), z_(T()) {}
    vec3(T x, T y, T z) : x_(x), y_(y), z_(z) {}

    T &operator[] (int index) {
        if (index < 0 || index >= 3)
            throw std::out_of_range("Vector 3 access");
        return !index ? x_ : index == 1 ? y_ : z_;
    }
    const T &operator[] (int index) const {
        if (index < 0 || index >= 3)
            throw std::out_of_range("Vector 3 access");
        return !index ? x_ : index == 1 ? y_ : z_;
    }

    vec3<T> operator+(const vec3<T>& v) const
    {
        return vec3<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_);
    }

    vec3<T> operator-(const vec3<T>& v) const
    {
        return vec3<T>(x_ - v.x_, y_ - v.y_, z_ - v.z_);
    }

    vec3<T> operator*(const vec3<T>& v) const
    {
        return vec3<T>(x_ * v.x_, y_ * v.y_, z_ * v.z_);
    }

    vec3<T> operator*(T v) const
    {
        return vec3<T>(x_ * v, y_ * v, z_ * v);
    }

    std::ostream& operator<<(std::ostream& out) const {
        out << x_ << " " << y_ << " " << z_;
        return out;
    }

    float norm() const {
        return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    }

    vec3<T> normalize() const {
        float norm = std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
        return vec3<T> (x_ / norm, y_ / norm, z_ / norm);
    }
    
    static vec3<T> cross(const vec3<T> lhs, const vec3<T> rhs)
    {
        return vec3<T>(lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_,
                lhs.z_ * rhs.x_ - lhs.x_ * rhs.z_,
                lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_);
    }

    static T sum(const vec3<T> lhs, const vec3<T> rhs) {
        return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_;
    }

    static vec3<T> reflect(const vec3<T>& L, const vec3<T>& N) {
        return (N * 2.f * (L * N) - L);
    }

    static T dot_product(const vec3<T>& u, const vec3<T>& v) {
        return v.x_ * u.x_ + u.y_ * v.y_ + u.z_ * v.z_;
    }

    static vec3<T> refract(const vec3<T>& I, const vec3<T>& N, float refractive_index) {
        float cosi = - std::max(1.f, std::min(1.f, vec3<T>::sum(I, N)));
        float etai = 1;
        float etat = refractive_index;
        vec3<T> n = N;
        if (cosi < 0) {
            cosi = -cosi;
            std::swap(etai, etat);
            n = N * -1;
        }
        float eta = etai / etat;
        float k  = 1 - eta * eta * (1 - cosi * cosi);
        return k < 0 ? vec3<T>(1, 0, 0)
            : (I * eta + n * (eta * cosi - sqrtf(k))).normalize();
    }

private:
    T x_;
    T y_;
    T z_;
};

template <typename T> class vec4 {
public:
    vec4() : x_(T()), y_(T()), z_(T()), w_(T()) {}
    vec4(T x, T y, T z, T w) : x_(x), y_(y), z_(z), w_(w) {}

    T &operator[] (int index) {
        if (index < 0 || index >= 4)
            throw std::out_of_range("Vector 4 access");
        return !index ? x_ : index == 1 ? y_ : index == 2 ? z_ : w_;
    }
    const T &operator[] (int index) const {
        if (index < 0 || index >= 4)
            throw std::out_of_range("Vector 4 access");
        return !index ? x_ : index == 1 ? y_ : index == 2 ? z_ : w_;
    }

    vec4<T> operator+(const vec4<T>& v) const
    {
        return vec4<T>(x_ + v.x_, y_ + v.y_, z_ + v.z_, w_ + v.w_);
    }

    vec4<T> operator-(const vec4<T>& v) const
    {
        return vec4<T>(x_ - v.x_, y_ - v.y_, z_ - v.z_, w_ - v.w_);
    }

    vec4<T> operator*(const vec4<T>& v) const
    {
        return vec4<T>(x_ * v.x_, y_ * v.y_, z_ * v.z_, w_ * v.w_);
    }

    std::ostream& operator<<(std::ostream& out) const {
        out << x_ << " " << y_ << " " << z_ << " " << w_;
        return out;
    }
private:
    T x_;
    T y_;
    T z_;
    T w_;
};

using Vec2f = vec2<float>;
using Vec3f = vec3<float>;
using Vec3i = vec3<int>;
using Vec4f = vec4<float>;
