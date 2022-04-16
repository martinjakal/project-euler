#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 56
// https://projecteuler.net/problem=56
// Powerful digit sum
// Result: 972

int calcMaxDigitSumOfPowers(int limit)
{
    int maxDigitSum = 0;

    for (int a = 1; a < limit; ++a)
    {
        BigInteger number = a;

        for (int b = 1; b < limit; ++b)
        {
            number *= BigInteger(a);

            int digitSum = static_cast<int>(number.digitSum());

            if (digitSum > maxDigitSum)
                maxDigitSum = digitSum;
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
