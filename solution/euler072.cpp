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
auto sumEulerTotients(int limit) -> unsigned long long
{
    auto primes = sieveOfEratosthenes(limit);
    std::vector<int> totients(limit + 1);

    for (int i = 0; i < static_cast<int>(totients.size()); ++i)
        totients[i] = i;

    for (auto p : primes)
    {
        for (int i = p; i < static_cast<int>(totients.size()); i += p)
            totients[i] *= static_cast<double>(p - 1) / p;
    }

    return std::accumulate(totients.begin() + 2, totients.end(), 0ULL);
}

int main()
{
    int limit = 1000000;
    auto result = sumEulerTotients(limit);
    std::cout << result << std::endl;

    return 0;
}
