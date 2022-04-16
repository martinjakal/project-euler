#include <iostream>
#include <numeric>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 72
// https://projecteuler.net/problem=72
// Counting fractions
// Result: 303963552391

using namespace math;

// Euler's totient function counts relatively prime integers to a number.
unsigned long long countReducedProperFractions(int limit)
{
    const auto primes = sieveOfEratosthenes(limit);
    std::vector<int> totients(limit + 1);
    const int totientCnt = static_cast<int>(totients.size());

    for (int i = 0; i < totientCnt; ++i)
        totients[i] = i;

    for (auto p : primes)
    {
        for (int i = p; i < totientCnt; i += p)
        {
            totients[i] /= p; // no data lost because i % p = 0
            totients[i] *= p - 1;
        }
    }

    return std::accumulate(totients.begin() + 2, totients.end(), 0ull);
}

int main()
{
    int limit = 1'000'000;

    auto result = countReducedProperFractions(limit);
    std::cout << result << std::endl;

    return 0;
}
