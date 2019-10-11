#ifdef _TESTS

#include <cmath>

#include "catch.hpp"
#include "constants.hh"
#include "op_overloading.hpp"
#include "matrix.hh"

TEST_CASE("MATRIX: construct matrix", "[multi-file:matrix]") {
    Matrix m({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 19, 11, 12, 13.5, 14.5, 15.5, 16.5});
    REQUIRE((m.getValue(0, 0) == 1
            && m.getValue(0, 3) == 4
            && m.getValue(1, 0) == 5.5
            && m.getValue(1, 2) == 7.5
            && m.getValue(2, 2) == 11
            && m.getValue(3, 0) == 13.5
            && m.getValue(3, 2) == 15.5) == true);
}

#endif
