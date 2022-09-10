#include <iostream>

// Project Euler - Problem 100
// https://projecteuler.net/problem=100
// Arranged probability
// Result: 756872327473

// The coefficients are obtained as a solution of diophantine equation 2x^2 - 2x - y^2 + y = 0
// where x = blue and y = total.
auto calcBlueDiscsArrangement(unsigned long long limit) -> unsigned long long
{
    auto blue = 1ull;
    auto total = 1ull;

    while (total <= limit)
    {
        auto blueNext = 3 * blue + 2 * total - 2;
        auto totalNext = 4 * blue + 3 * total - 3;
        blue = blueNext;
        total = totalNext;
    }

    return blue;
}

int main()
{
    auto limit = 1'000'000'000'000ull;

    auto result = calcBlueDiscsArrangement(limit);
    std::cout << result << std::endl;

    return 0;
}
