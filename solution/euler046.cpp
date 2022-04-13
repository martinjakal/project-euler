#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 46
// https://projecteuler.net/problem=46
// Goldbach's other conjecture
// Result: 5777

using namespace math;

bool canSplitAsPrimeAndTwoSquares(int number)
{
    int i = 0;
    int twoSquares = 0;

    while (twoSquares < number)
    {
        ++i;
        twoSquares = 2 * i * i;

        if (isPrime(number - twoSquares))
            return true;
    }

    return false;
}

int findMinNumberBreakingGoldbachOther()
{
    for (int number = 3; ; number += 2) // must be odd and composite
    {
        if (!isPrime(number) && !canSplitAsPrimeAndTwoSquares(number))
            return number;
    }
}

int main()
{
    auto result = findMinNumberBreakingGoldbachOther();
    std::cout << result << std::endl;

    return 0;
}
