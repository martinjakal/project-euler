#include <iostream>
#include <vector>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 80
// https://projecteuler.net/problem=80
// Square root digital expansion
// Result: 40886

// Algorithm to calculate square root by substraction.
auto squareRoot(int number, int digits) -> BigInteger
{
    // Extra digits ensure the desired digits don't change with more iterations.
    const int extraDigits = 2;
    BigInteger a = 5 * number;
    BigInteger b = 5;

    while (b.digitCnt() < digits + extraDigits)
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

    return b / static_cast<int>(pow(10, extraDigits));
}

int sumSquareRootDigits(int limit, int digits)
{
    int sumDigits = 0;
    std::vector<int> squares;

    for (int i = 1; i * i <= limit; ++i)
        squares.push_back(i * i);

    for (int i = 1; i <= limit; ++i)
    {
        if (std::find(squares.begin(), squares.end(), i) == squares.end())
            sumDigits += squareRoot(i, digits).digitSum();
    }

    return sumDigits;
}

int main()
{
    int limit = 100;
    int digits = 100;
    auto result = sumSquareRootDigits(limit, digits);
    std::cout << result << std::endl;

    return 0;
}
