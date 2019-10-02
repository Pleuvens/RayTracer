#include "matrix.hh"
#include "constants.hh"

Matrix::Matrix(const int height, const int width)
    : _height(height), _width(width)
{
    _matrix = std::vector<float>(_height * _width, 0);
}

bool Matrix::isCoordValid(const int y, const int x) const
{
    return y >= 0 && y < _height && x >= 0 && x < _width;
}

Matrix Matrix::identity(const int size)
{
    Matrix res = Matrix(size, size);
    for (int i = 0; i < size; i++)
        res.setValue(i, i) = 1;
    return res;
}

float Matrix::getValue(const int y, const int x) const
{
    if (!isCoordValid(y, x))
        throw "Invalid coordinates";
    return _matrix[y * _width + x];
}

void Matrix::getValue(const int y, const int x, const float value)
{
    if (!isCoordValid(y, x))
        throw "Invalid coordinates";
    _matrix[y * _width + x] = value;
}

Matrix Matrix::transpose(void)
{
    Matrix res = Matrix(_width, _height);
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
            res.setValue(x, y) = getValue(y, x);
    }
}

bool Matrix::operator==(const Matrix& m) const
{
    if (_height != m._height || _width != m._width)
        return false;
    for (int i = 0; i < _height * _width; i++)
    {
        if (_matrix[i] - m._matrix[i] > EPSILON)
            return false;
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m) const
{
    if (_height != m._height || _width != m._width)
        return true;
    for (int i = 0; i < _height * _width; i++)
    {
        if (_matrix[i] - m._matrix[i] > EPSILON)
            return true;
    }
    return false;
}

Matrix Matrix::operator*(const Matrix& m)
{
    if (_width != m._height)
        throw "MATRIX: Invalid matrix size";
    Matrix res = Matrix(_height, m._width);
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < m._width; x++)
        {
            for (int z = 0; z < _width; z++)
                res.setValue(y, x) += getValue(y, z) * m.getValue(z, x);
        }
    }
    return res;
}

Matrix Matrix::operator*(const Tuple& t)
{
    if (_width != TUPLE_HEIGHT)
        throw "MATRIX: Invalid matrix size";
    Tuple res = Tuple(0, 0, 0, 0);
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < TUPLE_HEIGHT; x++)
        {
            for (int z = 0; z < _width; z++)
                res.setValue(x) += getValue(y, z) * t.getValue(z);
        }
    }
    return res;
}
