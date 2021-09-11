#include "NumberProperties.hpp"

#include <cmath>

bool isTriangular(unsigned long long number)
{
    double n = (sqrt(8 * number + 1) - 1) / 2;
    return n == static_cast<int>(n);
}

bool isPentagonal(unsigned long long number)
{
    double n = (sqrt(24 * number + 1) + 1) / 6;
    return n == static_cast<int>(n);
}
