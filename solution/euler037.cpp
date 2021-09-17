#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 37
// https://projecteuler.net/problem=37
// Truncatable primes
// Result: 748317

using namespace math;

int sumTruncatablePrimes()
{
    const int maxPrimeCnt = 11;
    int primeCnt = 0;
    int sumPrimes = 0;

    for (int i = 11; primeCnt < maxPrimeCnt; i += 2)
    {        
        if (isTruncatablePrime(i))
        {
            sumPrimes += i;
            ++primeCnt;
        }
    }

    return sumPrimes;
}

int main()
{
    auto result = sumTruncatablePrimes();
    std::cout << result << std::endl;

    return 0;
}
