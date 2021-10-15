#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 52
// https://projecteuler.net/problem=52
// Permuted multiples
// Result: 142857

using namespace math;

int digitPermutedMultiples()
{
    for (int number = 1; ; ++number)
    {
        bool isValid = true;

        for (int i = 2; i <= 6; ++i)
        {
            if (!isPermutation(number, i * number))
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
            return number;
    }
}

int main()
{
    auto result = digitPermutedMultiples();
    std::cout << result << std::endl;

    return 0;
}
