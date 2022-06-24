#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 70
// https://projecteuler.net/problem=70
// Totient permutation
// Result: 8319823

using namespace math;

// Euler's totient function is used: phi(n) = n * product (1 - 1 / p), where p is a prime which divides n.
// To minimize n / phi(n), the number of primes in the product must be minimized. At least two primes must be used,
// because if n is a prime, then phi(n) = n - 1 and n - 1 is never a permutation of n.
// Also phi(m * n) = phi(m) * phi(n) * d / phi(d), where d = gcd(m, n).
// If m and n are primes, then phi(m * n) = phi(m) * phi(n).
int findNumberWithMinTotientPermutation(int limit)
{
    const auto primes = sieveOfEratosthenes(limit / 2);
    double minRatio = std::numeric_limits<double>::max();
    int bestNumber = 0;

    for (std::size_t i = 0; i < primes.size(); ++i)
    {
        for (std::size_t j = i; j < primes.size() && 1ull * primes[i] * primes[j] < limit; ++j)
        {
            int number = primes[i] * primes[j];
            int totient = (primes[i] - 1) * (primes[j] - 1);

            if (!isPermutation(number, totient))
                continue;

            double ratio = static_cast<double>(number) / totient;

            if (ratio < minRatio)
            {
                minRatio = ratio;
                bestNumber = number;
            }
        }
    }

    return bestNumber;
}

int main()
{
    int limit = 10'000'000;

    auto result = findNumberWithMinTotientPermutation(limit);
    std::cout << result << std::endl;

    return 0;
}
