#include "NumberProperties.hpp"

#include <cmath>
#include <string>

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

bool isPalindrome(int number)
{
    std::string s = std::to_string(number);

    for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j)
    {
        if (s[i] != s[j])
            return false;
    }

    return true;
}
