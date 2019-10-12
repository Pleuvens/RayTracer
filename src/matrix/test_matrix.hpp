#ifdef _TESTS

#include <cmath>

#include "catch.hpp"
#include "constants.hh"
#include "op_overloading.hh"
#include "matrix.hh"

TEST_CASE("MATRIX: construct matrix", "[multi-file:matrix]") {
    Matrix m(4, 4, {   1,    2,    3,    4,
                     5.5,  6.5,  7.5,  8.5,
                       9,   19,   11,   12,
                    13.5, 14.5, 15.5, 16.5});
    Matrix m1(2, 2, {-3,  5,
                      1, -2});
    Matrix m2(3, 3, {-3,  5,  0,
                      1, -2, -7,
                      0,  1,  1});
    REQUIRE((isEqual(m.getValue(0, 0), 1)
            && isEqual(m.getValue(0, 3), 4)
            && isEqual(m.getValue(1, 0), 5.5)
            && isEqual(m.getValue(1, 2), 7.5)
            && isEqual(m.getValue(2, 2), 11)
            && isEqual(m.getValue(3, 0), 13.5)
            && isEqual(m.getValue(3, 2), 15.5)));
    REQUIRE((isEqual(m1.getValue(0, 0), -3)
            && isEqual(m1.getValue(0, 1), 5)
            && isEqual(m1.getValue(1, 0), 1)
            && isEqual(m1.getValue(1, 1), -2)));
    REQUIRE((isEqual(m2.getValue(0, 0), -3)
            && isEqual(m2.getValue(1, 1), -2)
            && isEqual(m2.getValue(2, 2), 1)));
}

TEST_CASE("MATRIX: matrix compare", "[multi-file:matrix]")
{
    Matrix m(4, 4, {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 8, 7, 6,
                    5, 4, 3, 2});
    Matrix m1(4, 4, {1, 2, 3, 4,
                     5, 6, 7, 8,
                     9, 8, 7, 6,
                     5, 4, 3, 2});
    Matrix m2(4, 4, {2, 3, 4, 5,
                     6, 7, 8, 9,
                     8, 7, 6, 5,
                     4, 3, 2, 1});
    REQUIRE(m == m1);
    REQUIRE(m != m2);
}

TEST_CASE("MATRIX: multiplying two matrix", "[multi-file:matrix]")
{
    Matrix m(4, 4, {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 8, 7, 6,
                    5, 4, 3, 2});
    Matrix m1(4, 4, {-2, 1, 2,  3,
                      3, 2, 1, -1,
                      4, 3, 6,  5,
                      1, 2, 7,  8});
    Matrix res(4, 4, {20, 22,  50,  48,
                      44, 54, 114, 108,
                      40, 58, 110, 102,
                      16, 26,  46,  42});
    REQUIRE((m * m1) == res);
}

TEST_CASE("MATRIX: multiplying a matrix by a tuple", "[multi-file:matrix]")
{
    Matrix m(4, 4, {1, 2, 3, 4,
                    2, 4, 4, 2,
                    8, 6, 4, 1,
                    0, 0, 0, 1});
    Tuple t(1, 2, 3, 1);
    Tuple res(18, 24, 33, 1);
    REQUIRE((m * t) == res);
}

TEST_CASE("MATRIX: multiplying a matrix by the identity matrix", "[multi-file:matrix]")
{
    Matrix m(4, 4, {0, 1,  2,  4,
                    1, 2,  4,  8,
                    2, 4,  8, 16,
                    4, 8, 16, 32});
    REQUIRE((m * Matrix::identity(4)) == m);
}

TEST_CASE("MATRIX: multiplying the identity matrix by a tuple", "[multi-file:matrix]")
{
    Tuple t(1, 2, 3, 4);
    REQUIRE((Matrix::identity(4) * t) == t);
}

TEST_CASE("MATRIX: transposing a matrix", "[multi-file:matrix]")
{
    Matrix m(4, 4, {0, 9, 3, 0,
                    9, 8, 0, 8,
                    1, 8, 5, 3,
                    0, 0, 5, 8});
    Matrix res(4, 4, {0, 9, 1, 0,
                      9, 8, 8, 0,
                      3, 0, 5, 5,
                      0, 8, 3, 8});
    REQUIRE(m.transpose() == res);
}

TEST_CASE("MATRIX: transposing the identity matrix", "[multi-file:matrix]")
{
    REQUIRE(Matrix::identity(4).transpose() == Matrix::identity(4));
}

TEST_CASE("MATRIX: Calculating the determinant of a 2x2 matrix", "[multi-file:matrix]")
{
    Matrix m(2, 2, { 1, 5,
                    -3, 2});
    REQUIRE(isEqual(m.determinant(), 17));
}

TEST_CASE("MATRIX: submatrix of a 3x3 matrix", "[multi-file:matrix]")
{
    Matrix m(3, 3, { 1, 5,  0,
                    -3, 2,  7,
                     0, 6, -3});
    Matrix res(2, 2, {-3, 2,
                       0, 6});
    REQUIRE(m.submatrix(0, 2) == res);
}

TEST_CASE("MATRIX: submatrix of a 4x4 matrix", "[multi-file:matrix]")
{
    Matrix m(4, 4, {-6, 1,  1, 6,
                    -8, 5,  8, 6,
                    -1, 0,  8, 2,
                    -7, 1, -1, 1});
    Matrix res(3, 3, {-6,  1, 6,
                      -8,  8, 6,
                      -7, -1, 1});
    REQUIRE(m.submatrix(2, 1) == res);
}

TEST_CASE("MATRIX: Calculating a minor of a 3x3 matrix", "[multi-file:matrix]")
{
    Matrix m(3, 3, {3,  5,  0,
                    2, -1, -7,
                    6, -1,  5});
    Matrix subm = m.submatrix(1, 0);
    REQUIRE(isEqual(subm.determinant(), m.minor(1, 0)));
}

TEST_CASE("MATRIX: Calculating a cofactor of a 3x3 matrix", "[multi-file:matrix]")
{
    Matrix m(3, 3, {3,  5,  0,
                    2, -1, -7,
                    6, -1,  5});
    REQUIRE(isEqual(m.cofactor(0, 0), m.minor(0, 0)));
    REQUIRE(isEqual(m.cofactor(1, 0), -m.minor(1,0)));
}

TEST_CASE("MATRIX: Calculating the determinant of a 3x3 matrix", "[multi-file:matrix]")
{
    Matrix m(3, 3, { 1, 2,  6,
                    -5, 8, -4,
                     2, 6,  4});
    REQUIRE((isEqual(m.cofactor(0, 0), 56) && isEqual(m.cofactor(0, 1), 12)
                && isEqual(m.cofactor(0, 2), -46)));
    REQUIRE(isEqual(m.determinant(), -196));
}

TEST_CASE("MATRIX: Calculating the determinant of a 4x4 matrix", "[multi-file:matrix]")
{
    Matrix m(4, 4, {-2, -8,  3,  5,
                    -3,  1,  7,  3,
                     1,  2, -9,  6,
                     -6, 7,  7, -9});
    REQUIRE((isEqual(m.cofactor(0, 0), 690) && isEqual(m.cofactor(0, 1), 447)
                && isEqual(m.cofactor(0, 2), 210) && isEqual(m.cofactor(0, 3), 51)));
    REQUIRE(isEqual(m.determinant(), -4071));
}

TEST_CASE("MATRIX: Testing invertibility of matrix", "[multi-file:matrix]")
{
    Matrix invertible(4, 4, {6,  4, 4,  4,
                             5,  5, 7,  6,
                             4, -9, 3, -7,
                             9,  1, 7, -6});
    Matrix noninvertible(4, 4, {-4,  2, -2, -3,
                                 9,  6,  2,  6,
                                 0, -5,  1, -5,
                                 0,  0,  0,  0});

    REQUIRE_NOTHROW(invertible.invert());
    REQUIRE_THROWS(noninvertible.invert());
}

TEST_CASE("MATRIX: Inverse of a matrix", "multi-file:matrix]")
{
    Matrix m(4, 4, {-5,  2,  6, -8,
                     1, -5,  1,  8,
                     7,  7, -6, -7,
                     1, -3,  7,  4});
    Matrix res(4, 4, { 0.21805,  0.45113,  0.24060, -0.04511,
                      -0.80827, -1.45677, -0.44361,  0.52068,
                      -0.07895, -0.22368, -0.05263,  0.19737,
                      -0.52256, -0.81391, -0.30075,  0.30639});
    Matrix invm = m.invert();
    
    Matrix m1(4, 4, { 8, -5,  9,  2,
                      7,  5,  6,  1,
                     -6,  0,  9,  6,
                     -3,  0, -9, -4});
    Matrix res1(4, 4, {-0.15385, -0.15385, -0.28205, -0.53846,
                       -0.07692,  0.12308,  0.02564,  0.03077,
                        0.35897,  0.35897,  0.43590,  0.92308,
                       -0.69231, -0.69231, -0.76923, -1.92308});
    Matrix m2(4, 4, { 9,  3,  0,  9,
                     -5, -2, -6, -3,
                     -4,  9,  6,  4,
                     -7,  6,  6,  2});
    Matrix res2(4, 4, {-0.04074, -0.07778,  0.14444, -0.22222,
                       -0.07778,  0.03333,  0.36667, -0.33333,
                       -0.02901, -0.14630, -0.10926,  0.12963,
                        0.17778,  0.06667, -0.26667,  0.33333});
    REQUIRE((isEqual(m.determinant(), 532) && isEqual(m.cofactor(2, 3), -160)
            && isEqual(invm.getValue(3, 2), -160 / 532)
            && isEqual(m.cofactor(3, 2), 105)
            && isEqual(invm.getValue(2, 3), (105 / 532))
            && invm == res));
    REQUIRE(m1.invert() == res1);
    REQUIRE(m2.invert() == res2);
}

TEST_CASE("MATRIX: Mutliplying a product by its inverse", "[multi-file:matrix]")
{
    Matrix a(4, 4, { 3, -9,  7,  3,
                     3, -8,  2, -9,
                    -4,  4,  4,  1,
                    -6,  5, -1,  1});
    Matrix b(4, 4, {8,  2, 2, 2,
                    3, -1, 7, 0,
                    7,  0, 5, 4,
                    6, -2, 0, 5});
    Matrix c = a * b;
    REQUIRE(c * b.invert() == a);
}

#endif
