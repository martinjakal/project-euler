#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 45
// https://projecteuler.net/problem=45
// Triangular, pentagonal, and hexagonal
// Result: 1533776805

using namespace math;

// Generate hexagonal number and verify the pentagonal property.
// Skip triangular check because each hexagonal number is also triangular.
auto findNextPentaHexaNumber(int previous) -> unsigned long long
{
    for (int i = 1;; ++i)
    {
        auto hexagonal = 2ull * i * i - i;

        if (hexagonal > previous && isPentagonal(hexagonal))
            return hexagonal;
    }
}

int main()
{
    int previous = 40'755;

    auto result = findNextPentaHexaNumber(previous);
    std::cout << result << std::endl;

    return 0;
}
