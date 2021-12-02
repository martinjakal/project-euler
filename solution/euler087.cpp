#include <algorithm>
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
        [power](int num) { return static_cast<int>(pow(num, power)); });
    return result;
}

int countPrimePowerTriples(int limit)
{
    std::unordered_set<int> primePowerTriples;

    std::vector<int> primes = sieveOfEratosthenes(static_cast<int>(sqrt(limit)));
    std::vector<int> primes2 = raiseToPower(primes, 2);
    std::vector<int> primes3 = raiseToPower(primes, 3);
    std::vector<int> primes4 = raiseToPower(primes, 4);

    for (auto p2 : primes2)
    {
        for (auto p3 : primes3)
        {
            int sumFirstTwo = p2 + p3;

            if (sumFirstTwo >= limit)
                break;

            for (auto p4 : primes4)
            {
                int sumAllThree = sumFirstTwo + p4;

                if (sumAllThree >= limit)
                    break;

                primePowerTriples.insert(sumAllThree);
            }
        }
    }

    return primePowerTriples.size();
}

int main()
{
    int limit = 50000000;
    auto result = countPrimePowerTriples(limit);
    std::cout << result << std::endl;
    
    return 0;
}
