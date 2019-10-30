#pragma once

#undef minor

#include <vector>

#include "point.hh"
#include "tuple.hh"
#include "vector.hh"

class Matrix {
    public:
        Matrix() = default;
        Matrix(const int height, const int width);
        Matrix(const int height, const int width, std::initializer_list<float> list);

        Matrix(Matrix&& m) = default;

        Matrix(Matrix& m) = default;
        Matrix(const Matrix& m) = default;
        Matrix& operator=(Matrix& m) = default;
        Matrix& operator=(const Matrix& m) = default;

        ~Matrix() = default;

        static Matrix identity(const int size);
        static Matrix translation(const float x, const float y, const float z);
        static Matrix scaling(const float x, const float y, const float z);
        static Matrix rotationX(const float r);
        static Matrix rotationY(const float r);
        static Matrix rotationZ(const float r);
        static Matrix shearing(const float x_y, const float x_z,
                               const float y_x, const float y_z,
                               const float z_x, const float z_y);
        static Matrix viewTransform(Point from, Point to, Vector up);

        inline int getHeight(void) const { return _height; }
        inline int getWidth(void)  const { return _width; }
        float getValue(const int y, const int x) const;

        inline void setHeight(const int height) { _height = height; }
        inline void setWidth(const int width) { _width = width; }
        void setValue(const int y, const int x, const float value);

        Matrix transpose(void) const;
        Matrix submatrix(const int row, const int column) const;
        float determinant(void) const;
        float minor(const int row, const int column) const;
        float cofactor(const int row, const int column) const;
        Matrix invert(void) const;

        bool operator==(const Matrix& m) const;
        bool operator!=(const Matrix& m) const;
        Matrix operator*(const Matrix& m);
        friend Tuple operator*(const Matrix& m, const Tuple& t);

    private:
        bool isCoordValid(const int y, const int x) const;
        int _height;
        int _width;
        std::vector<float> _matrix;
};
