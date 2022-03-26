#include <iostream>
#include <numeric>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 10
// https://projecteuler.net/problem=10
// Summation of primes
// Result: 142913828922

using namespace math;

unsigned long long calcSumOfPrimes(int limit)
{
    std::vector<int> primes = sieveOfEratosthenes(limit);
    return std::accumulate(primes.begin(), primes.end(), 0ull);
}

int main()
{
    int limit = 2'000'000;
    auto result = calcSumOfPrimes(limit);
    std::cout << result << std::endl;

    return 0;
}
