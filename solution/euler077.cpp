#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 77
// https://projecteuler.net/problem=77
// Prime summations
// Result: 71

using namespace math;

int findFirstNumberWithEnoughPrimePartitions(int limit)
{
    std::vector<int> primes;

    for (int number = 1;; ++number)
    {
        std::vector<int> ways(number + 1, 0);
        ways[0] = 1;

        if (isPrime(number))
            primes.push_back(number);

        for (int i = 0; i < static_cast<int>(primes.size()); ++i)
        {
            for (int j = primes[i]; j < static_cast<int>(ways.size()); ++j)
                ways[j] += ways[j - primes[i]];
        }

        if (ways.back() > limit)
            return number;
    }
}

int main()
{
    int limit = 5000;

    auto result = findFirstNumberWithEnoughPrimePartitions(limit);
    std::cout << result << std::endl;

    return 0;
}
