#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 58
// https://projecteuler.net/problem=58
// Spiral primes
// Result: 26241

using namespace math;

int diagLengthWithPrimesBelowRatio(double ratio)
{
    double primeRatio = 1;
    int primeCnt = 0;
    int diagCnt = 1;
    int number = 1;
    int step = 0;

    while (primeRatio >= ratio)
    {
        step += 2;
        diagCnt += 4;

        for (int i = 0; i < 4; ++i)
        {
            number += step;

            if (isPrime(number))
                ++primeCnt;
        }

        primeRatio = static_cast<double>(primeCnt) / diagCnt;
    }

    return step + 1;
}

int main()
{
    double ratio = 0.1;
    auto result = diagLengthWithPrimesBelowRatio(ratio);
    std::cout << result << std::endl;

    return 0;
}
