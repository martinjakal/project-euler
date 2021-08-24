#include <iostream>
#include <vector>

#include <helper/Primes.hpp>

// Project Euler - Problem 7
// https://projecteuler.net/problem=7
// 10001st prime
// Result: 104743

// Range can be estimated by prime-counting function.
// For example, range 10^6 contains 78498 primes.
int nthPrime(int limit, int position)
{
    return sieveOfEratosthenes(limit)[position - 1];
}

int main()
{
    int limit = 1000000;
    int position = 10001;
    auto result = nthPrime(limit, position);
    std::cout << result << std::endl;

    return 0;
}
