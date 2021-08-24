#include <iostream>

// Project Euler - Problem 3
// https://projecteuler.net/problem=3
// Largest prime factor
// Result: 6857

unsigned long long maxPrimeFactor(unsigned long long number)
{
    unsigned long long maxFactor = 0;

    for (unsigned long long factor = 2; number > 1; ++factor)
    {
        while (number % factor == 0)
        {
            number /= factor;
            maxFactor = factor;
        }
    }

    return maxFactor;
}

int main()
{
    unsigned long long number = 600851475143;
    auto result = maxPrimeFactor(number);
    std::cout << result << std::endl;

    return 0;
}
