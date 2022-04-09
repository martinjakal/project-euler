#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 12
// https://projecteuler.net/problem=12
// Highly divisible triangular number
// Result: 76576500

using namespace math;

int findTriangleNumWithDivisors(int divisors)
{
    for (int i = 1; ; ++i)
    {
        int triangle = i * (i + 1) / 2;

        if (getDivisors(triangle).size() > divisors)
            return triangle;
    }
}

int main()
{
    int divisors = 500;

    auto result = findTriangleNumWithDivisors(divisors);
    std::cout << result << std::endl;

    return 0;
}
