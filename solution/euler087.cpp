#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 87
// https://projecteuler.net/problem=87
// Prime power triples
// Result: 1097343

using namespace math;

auto raiseToPower(const std::vector<int>& data, int power) -> std::vector<int>
{
    std::vector<int> result;
    std::transform(data.begin(), data.end(), std::back_inserter(result),
        [power](int num) { return static_cast<int>(std::pow(num, power)); });
    return result;
}

int countPrimePowerTriples(int limit)
{
    const int sieveLimit = static_cast<int>(std::sqrt(limit)); // each number is written as sum of powers greater than 1
    const auto primes = sieveOfEratosthenes(sieveLimit);
    const auto primes2 = raiseToPower(primes, 2);
    const auto primes3 = raiseToPower(primes, 3);
    const auto primes4 = raiseToPower(primes, 4);

    std::unordered_set<int> primePowerTriples;

    for (auto p2 : primes2)
    {
        for (auto p3 : primes3)
        {
            int sumTwo = p2 + p3;

            if (sumTwo >= limit)
                break;

            for (auto p4 : primes4)
            {
                int sumThree = sumTwo + p4;

                if (sumThree >= limit)
                    break;

                primePowerTriples.insert(sumThree);
            }
        }
    }

    return static_cast<int>(primePowerTriples.size());
}

int main()
{
    int limit = 50'000'000;

    auto result = countPrimePowerTriples(limit);
    std::cout << result << std::endl;

    return 0;
}
