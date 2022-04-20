#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 52
// https://projecteuler.net/problem=52
// Permuted multiples
// Result: 142857

using namespace math;

bool canPermuteMultiples(int number)
{
    for (int i = 2; i <= 6; ++i)
    {
        if (!isPermutation(number, i * number))
            return false;
    }

    return true;
}

int findMinNumberWithPermutedMultiples()
{
    for (int number = 1; ; ++number)
    {
        if (canPermuteMultiples(number))
            return number;
    }
}

int main()
{
    auto result = findMinNumberWithPermutedMultiples();
    std::cout << result << std::endl;

    return 0;
}
