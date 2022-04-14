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
    auto primes = sieveOfEratosthenes(limit);
    std::vector<int> primeSums(primes.size() + 1, 0);

    // Generate consecutive sum of primes.
    for (int i = 0; i < primes.size(); ++i)
        primeSums[i + 1] = primeSums[i] + primes[i];

    int bestPrime = 0;
    int maxLength = 0;

    // Iterate through possible consecutive sums and check if the difference is prime.
    for (int i = 0; i < primes.size(); ++i)
    {
        for (int j = i - maxLength; j >= 0; --j)
        {
            int number = primeSums[i] - primeSums[j];
            int length = i - j;

            if (number >= limit)
                break;

            if (length > maxLength && isPrime(number))
            {
                bestPrime = number;
                maxLength = length;
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
