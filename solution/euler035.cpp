#include <iostream>

#include <helper/Primes.hpp>

// Project Euler - Problem 35
// https://projecteuler.net/problem=35
// Circular primes
// Result: 55

int countCircularPrimes(int limit)
{
    int circPrimesCnt = 0;

    for (int i = 2; i < limit; ++i)
    {
        if (isCircularPrime(i))
            ++circPrimesCnt;
    }

    return circPrimesCnt;
}

int main()
{
    int limit = 1000000;
    auto result = countCircularPrimes(limit);
    std::cout << result << std::endl; 

    return 0;
}
