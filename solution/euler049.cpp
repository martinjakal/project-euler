#include <iostream>
#include <string>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 49
// https://projecteuler.net/problem=49
// Prime permutations
// Result: 296962999629

using namespace math;

unsigned long long secondPrimePermutationTriple(int digits)
{
    const int rank = static_cast<int>(pow(10, digits));
    bool foundFirst = false;

    for (int n1 = rank / 10 + 1; n1 < rank; n1 += 2)
    {
        if (isPrime(n1))
        {
            for (int step = 2; n1 + 2 * step < rank; step += 2)
            {
                int n2 = n1 + step;
                int n3 = n2 + step;

                if (isPrime(n2) && isPrime(n3) && isPermutation(n1, n2) && isPermutation(n1, n3))
                {
                    if (foundFirst)
                        return std::stoull(std::to_string(n1) + std::to_string(n2) + std::to_string(n3));

                    foundFirst = true;
                }
            }
        }
    }

    return 0;
}

int main()
{
    int digits = 4;
    auto result = secondPrimePermutationTriple(digits);
    std::cout << result << std::endl;

    return 0;
}
