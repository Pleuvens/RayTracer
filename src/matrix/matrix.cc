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
        throw "MATRIX: Invalid coordinates";
    return _matrix[y * _width + x];
}

void Matrix::getValue(const int y, const int x, const float value)
{
    if (!isCoordValid(y, x))
        throw "MATRIX: Invalid coordinates";
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
    return res;
}

Matrix Matrix::submatrix(const int row, const int column)
{
    Matrix res = Matrix(_height - 1, width - 1);
    int yOffset = 0;
    for (int y = 0; y < _height - 1; y++)
    {
        if (y == row)
            yOffset++;
        int xOffset = 0;
        for (int x = 0; x < _width - 1; x++)
        {
            if (x == column)
                xOffset++;
            res.setValue(y, x) = getValue(y + yOffset, x + xOffset);
        }
    }
    return res;
}

float Matrix::determinant(void)
{
    if (_width != _height)
        throw "MATRIX: not square matrix";
    if (_width < 2)
        throw "MATRIX: 1x1 matrix";
    if (_width == 2)
        return _matrix[0] * _matrix[3] - _matrix[1] * _matrix[2];
    float det = 0;
    for (int x = 0; x < _width; x++)
    {
        det += getValue(0, x) * cofactor(0, x);
    }
    return det;
}

float Matrix::minor(const int row, const int column)
{
    if (_width != _height)
        throw "MATRIX: not square matrix";
    if (_width != 3)
        throw "MATRIX: not 3x3 matrix";
    return submatrix(row, column).determinant();
}

float Matrix::cofactor(const int row, const int column)
{
    if ((row + column) % 2)
        return minor(row, column);
    return -minor(row, column);
}

Matrix Matrix::invert(void)
{
    if (!determinant())
        throw "MATRIX: matrix not invertible";
    Matrix res = Matrix(_height, _width);
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            res.setValue(x, y, cofactor(y, x) / determinant());
        }
    }
    return res;
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
