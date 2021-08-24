#include <iostream>
#include <numeric>

#include <helper/Primes.hpp>

// Project Euler - Problem 10
// https://projecteuler.net/problem=10
// Summation of primes
// Result: 142913828922

unsigned long long sumOfPrimes(int limit)
{
    auto primes = sieveOfEratosthenes(limit);
    return std::accumulate(primes.begin(), primes.end(), 0ULL);
}

int main()
{
    int limit = 2000000;
    auto result = sumOfPrimes(limit);
    std::cout << result << std::endl;

    return 0;
}
