#include <cmath>
#include <iostream>
#include <vector>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 80
// https://projecteuler.net/problem=80
// Square root digital expansion
// Result: 40886

// Algorithm to calculate square root by substraction.
auto squareRootWithPrecision(int number, int digits) -> BigInteger
{
    // Extra digits ensure that the desired digits do not change with more iterations.
    constexpr int extraDigits = 2;
    BigInteger a = 5 * number;
    BigInteger b = 5;

    while (static_cast<int>(b.digitCnt()) < digits + extraDigits)
    {
        if (a >= b)
        {
            a -= b;
            b += 10;
        }
        else
        {
            a *= 100;
            b = (b - 5) * 10 + 5;
        }
    }

    return b / static_cast<int>(std::pow(10, extraDigits));
}

auto sumDigitsOfSquareRoots(int limit, int digits) -> std::size_t
{
    std::size_t sumDigits = 0;

    for (int number = 1; number <= limit; ++number)
    {
        const int root = static_cast<int>(std::sqrt(number));

        if (root * root != number)
            sumDigits += squareRootWithPrecision(number, digits).digitSum();
    }

    return sumDigits;
}

int main()
{
    int limit = 100;
    int digits = 100;

    auto result = sumDigitsOfSquareRoots(limit, digits);
    std::cout << result << std::endl;

    return 0;
}
