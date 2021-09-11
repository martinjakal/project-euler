#include <iostream>

#include <helper/NumberProperties.hpp>

// Project Euler - Problem 45
// https://projecteuler.net/problem=45
// Triangular, pentagonal, and hexagonal
// Result: 1533776805

// Generate hexagonal number and verify the pentagonal property.
// Skip triangular check because each hexagonal number is triangular.
unsigned long long findPentaHexaNumber(int prevNumber)
{
    for (int i = 1; ; ++i)
    {
        auto hexagonal = 2ULL * i * i - i;

        if (hexagonal > prevNumber && isPentagonal(hexagonal))
            return hexagonal;          
    }
}

int main()
{
    int prevNumber = 40755;
    auto result = findPentaHexaNumber(prevNumber);
    std::cout << result << std::endl;

    return 0;
}
