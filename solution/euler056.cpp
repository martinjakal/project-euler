#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 56
// https://projecteuler.net/problem=56
// Powerful digit sum
// Result: 972

auto calcMaxDigitSumOfPowers(int limit) -> std::size_t
{
    std::size_t maxDigitSum = 0;

    for (int a = 1; a < limit; ++a)
    {
        const BigInteger base = a;
        BigInteger number = base;

        for (int b = 1; b < limit; ++b)
        {
            number *= base;

            if (number.digitSum() > maxDigitSum)
                maxDigitSum = number.digitSum();
        }
    }

    return maxDigitSum;
}

int main()
{
    int limit = 100;

    auto result = calcMaxDigitSumOfPowers(limit);
    std::cout << result << std::endl;

    return 0;
}
