#include <algorithm>
#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 56
// https://projecteuler.net/problem=56
// Powerful digit sum
// Result: 972

int maxDigitSumPowers(int limit)
{
    int maxDigitSum = 0;

    for (int a = 1; a < limit; ++a)
    {
        BigInteger number(a);

        for (int b = 1; b < limit; ++b)
        {
            number *= a;
            maxDigitSum = std::max(number.digitSum(), maxDigitSum);
        }
    }

    return maxDigitSum;
}

int main()
{
    int limit = 100;
    auto result = maxDigitSumPowers(limit);
    std::cout << result << std::endl;

    return 0;
}
