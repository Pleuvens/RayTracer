#pragma once

#include <vector>

#include "tuple.hh"

class Matrix {
    public:
        Matrix(const int height, const int width);

        static Matrix identity(const int size);

        inline int getHeight(void) const { return _height; }
        inline int getWidth(void)  const { return _width; }
        float getValue(const int y, const int x, const float value);

        inline void setHeight(const int height) { _height = height; }
        inline void setWidth(const int width) { _width = width; }
        void setValue(const int y, const int x, const float value);

        Matrix transpose(void);

        bool operator==(const Matrix& m) const;
        bool operator!=(const Matrix& m) const;
        Matrix operator*(const Matrix& m);
        Matrix operator*(const Tuple& t);

    private:
        bool isCoordValid(const int y, const int x) const;
        int _height;
        int _width;
        std::vector<float> _matrix;
};
