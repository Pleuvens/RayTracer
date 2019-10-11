#include <cmath>
#include "constants.hpp"

bool operator==(const float lhs, const float rhs) const
{
    return std::abs(lhs - rhs) < EPSILON;
}

bool operator!=(const float lhs, const float rhs) const
{
    return std::abs(lhs - rhs) > EPSILON;
}
