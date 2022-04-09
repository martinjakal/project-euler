#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 27
// https://projecteuler.net/problem=27
// Quadratic primes
// Result: -59231

using namespace math;

int calcProductOfBestQuadFormulaCoeffs(int maxA, int maxB)
{
    int maxConsecutivePrimes = 0;
    int coeffProduct = 0;

    for (int a = -maxA; a < maxA; ++a)
    {
        for (int b = -maxB; b <= maxB; ++b)
        {
            int consecutivePrimes = 0;
            int n = 0;

            while (isPrime(n * n + a * n + b))
            {
                ++consecutivePrimes;
                ++n;
            }

            if (consecutivePrimes > maxConsecutivePrimes)
            {
                maxConsecutivePrimes = consecutivePrimes;
                coeffProduct = a * b;
            }
        }
    }

    return coeffProduct;
}

int main() 
{
    int maxA = 1000;
    int maxB = 1000;

    auto result = calcProductOfBestQuadFormulaCoeffs(maxA, maxB);
    std::cout << result << std::endl;

    return 0;
}
