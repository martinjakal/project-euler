#include <iostream>
#include <numeric>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 10
// https://projecteuler.net/problem=10
// Summation of primes
// Result: 142913828922

using namespace math;

unsigned long long sumPrimes(int limit)
{
    const auto primes = sieveOfEratosthenes(limit);
    return std::accumulate(primes.begin(), primes.end(), 0ull);
}

int main()
{
    int limit = 2'000'000;

    auto result = sumPrimes(limit);
    std::cout << result << std::endl;

    return 0;
}
