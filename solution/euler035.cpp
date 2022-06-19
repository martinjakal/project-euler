#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 35
// https://projecteuler.net/problem=35
// Circular primes
// Result: 55

using namespace math;

int countCircularPrimes(int limit)
{
    int circularCnt = 0;

    for (int i = 2; i < limit; ++i)
        circularCnt += isCircularPrime(i);

    return circularCnt;
}

int main()
{
    int limit = 1'000'000;

    auto result = countCircularPrimes(limit);
    std::cout << result << std::endl; 

    return 0;
}
