#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 12
// https://projecteuler.net/problem=12
// Highly divisible triangular number
// Result: 76576500

using namespace math;

int findTriangleNumWithDivisors(int divisors)
{
    int triangle = 0;

    for (int i = 1; static_cast<int>(getDivisors(triangle).size()) <= divisors; ++i)
        triangle = i * (i + 1) / 2;

    return triangle;
}

int main()
{
    int divisors = 500;

    auto result = findTriangleNumWithDivisors(divisors);
    std::cout << result << std::endl;

    return 0;
}
