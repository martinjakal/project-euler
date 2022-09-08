#include <iostream>

// Project Euler - Problem 3
// https://projecteuler.net/problem=3
// Largest prime factor
// Result: 6857

auto findMaxPrimeFactor(unsigned long long number) -> unsigned long long
{
    auto maxFactor = 0ull;

    for (auto factor = 2ull; number > 1; ++factor)
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
    auto number = 600'851'475'143ull;

    auto result = findMaxPrimeFactor(number);
    std::cout << result << std::endl;

    return 0;
}
