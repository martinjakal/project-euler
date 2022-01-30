#include <iostream>

// Project Euler - Problem 100
// https://projecteuler.net/problem=100
// Arranged probability
// Result: 756872327473

auto takeTwoBlueDiscsProbability(unsigned long long limit) -> unsigned long long
{
    unsigned long long blue = 1;
    unsigned long long total = 1;

    // The coefficients are obtained as solution of diophantine equation 2x^2 - 2x - y^2 + y = 0,
    // where x = blue and y = total.
    while (total < limit)
    {
        unsigned long long blueNext = 3 * blue + 2 * total - 2;
        unsigned long long totalNext = 4 * blue + 3 * total - 3;
        blue = blueNext;
        total = totalNext;
    }

    return blue;
}

int main()
{
    unsigned long long limit = 1'000'000'000'000;
    auto result = takeTwoBlueDiscsProbability(limit);
    std::cout << result << std::endl;

    return 0;
}
