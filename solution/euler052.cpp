#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 52
// https://projecteuler.net/problem=52
// Permuted multiples
// Result: 142857

using namespace math;

int findMinNumberWithPermutedMultiples()
{
    for (int number = 1; ; ++number)
    {
        bool canPermuteMultiples = true;

        for (int i = 2; i <= 6; ++i)
        {
            if (!isPermutation(number, i * number))
            {
                canPermuteMultiples = false;
                break;
            }
        }

        if (canPermuteMultiples)
            return number;
    }
}

int main()
{
    auto result = findMinNumberWithPermutedMultiples();
    std::cout << result << std::endl;

    return 0;
}
