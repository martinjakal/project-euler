#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 47
// https://projecteuler.net/problem=47
// Distinct primes factors
// Result: 134043

using namespace math;

int consecutivePrimeFactors(int factorCnt)
{
    int consecutive = 0;

    for (int number = 1; ; ++number)
    {
        consecutive = countDistinctFactors(number) == factorCnt ? ++consecutive : 0;

        if (consecutive == factorCnt)
            return number - factorCnt + 1;
    }
}

int main()
{   
    int factors = 4;
    auto result = consecutivePrimeFactors(factors);
    std::cout << result << std::endl;

    return 0;    
}
