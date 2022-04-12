#include <algorithm>
#include <iostream>
#include <string>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 41
// https://projecteuler.net/problem=41
// Pandigital prime
// Result: 7652413

using namespace math;

// Pandigital primes can only have max 7 digits, because digit sums for 8 (36) and 9 (45)
// digits are divisible by 3, meaning the number is also divisible by 3.
int findMaxPandigitalPrime()
{
    std::string digits;
    int maxPandigitalPrime = 0;

    for (int i = 1; i < 8; ++i)
    {
        digits += std::to_string(i);

        do
        {
            int number = std::stoi(digits);

            if (isPrime(number) && number > maxPandigitalPrime)
            {
                maxPandigitalPrime = number;
            }
        } while (std::next_permutation(digits.begin(), digits.end()));
    }

    return maxPandigitalPrime;
}

int main()
{
    auto result = findMaxPandigitalPrime();
    std::cout << result << std::endl;

    return 0;
}
