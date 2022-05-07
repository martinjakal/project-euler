#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 47
// https://projecteuler.net/problem=47
// Distinct primes factors
// Result: 134043

using namespace math;

int findConsecNumberWithDistinctFactors(int factorsCnt)
{
    for (int number = 1, consecutiveCnt = 0; ; ++number)
    {
        if (countDistinctFactors(number) == factorsCnt)
            ++consecutiveCnt;
        else
            consecutiveCnt = 0;

        if (consecutiveCnt == factorsCnt)
            return number - factorsCnt + 1;
    }
}

int main()
{
    int factors = 4;

    auto result = findConsecNumberWithDistinctFactors(factors);
    std::cout << result << std::endl;

    return 0;
}
