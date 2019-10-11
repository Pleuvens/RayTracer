#ifdef _TESTS

#include "tuple.hh"
#include "catch.hpp"

TEST_CASE("TUPLE: add 2 tuples", "[multi-file:tuple]") {
    REQUIRE((Tuple(3, -2, 5, 1) + Tuple(-2, 3, 1, 0)) == Tuple(1, 1, 6, 1));
    Tuple t = Tuple(3, -2, 5, 1);
    REQUIRE((t += Tuple(-2, 3, 1, 0)) == Tuple(1, 1, 6, 1));
}

TEST_CASE("TUPLE: negating a tuple", "[multi-file:tuple]") {
    REQUIRE(-Tuple(1, -2, 3, -4) == Tuple(-1, 2, -3, 4));
}

TEST_CASE("TUPLE: multiplying a tuple by a scalar", "[multi-file:tuple]") {
    REQUIRE((Tuple(1, -2, 3, -4) * 3.5) == Tuple(3.5, -7, 10.5, -14));
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE((t * 3.5) == Tuple(3.5, -7, 10.5, -14));
}

TEST_CASE("TUPLE: multiplying a tuple by a fraction", "[multi-file:tuple]") {
    REQUIRE((Tuple(1, -2, 3, -4) * 0.5) == Tuple(0.5, -1, 1.5, -2));
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE((t * 0.5) == Tuple(0.5, -1, 1.5, -2));
}

TEST_CASE("TUPLE: dividing a tuple by a scalar", "[multi-file:tuple]") {
    REQUIRE((Tuple(1, -2, 3, -4) / 2) == Tuple(0.5, -1, 1.5, -2));
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE((t /= 2) == Tuple(0.5, -1, 1.5, -2));
}

#endif
