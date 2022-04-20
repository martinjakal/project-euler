#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 50
// https://projecteuler.net/problem=50
// Consecutive prime sum
// Result: 997651

using namespace math;

int findPrimeWithLongestPrimeSum(int limit)
{
    const auto primes = sieveOfEratosthenes(limit);
    const int primeCnt = static_cast<int>(primes.size());

    // Generate consecutive sum of primes.
    std::vector<int> primeSums(primeCnt + 1, 0);
    for (int i = 0; i < primeCnt; ++i)
        primeSums[i + 1] = primeSums[i] + primes[i];

    int maxLength = 0;
    int bestPrime = 0;

    // Iterate through possible consecutive sums and check if the difference is prime.
    for (int i = 0; i < primeCnt; ++i)
    {
        for (int j = i - maxLength; j >= 0; --j)
        {
            int number = primeSums[i] - primeSums[j];
            int length = i - j;

            if (number >= limit)
                break;

            if (length > maxLength && isPrime(number))
            {
                maxLength = length;
                bestPrime = number;
            }
        }
    }

    return bestPrime;
}

int main()
{
    int limit = 1'000'000;

    auto result = findPrimeWithLongestPrimeSum(limit);
    std::cout << result << std::endl;

    return 0;
}
