#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 46
// https://projecteuler.net/problem=46
// Goldbach's other conjecture
// Result: 5777

using namespace math;

int minGoldbachOther()
{
    for (int number = 3; ; number += 2)
    {
        if (isPrime(number))
            continue;

        bool valid = false;

        for (int i = 1, twoSquares = 2 * i * i; twoSquares < number; ++i, twoSquares = 2 * i * i)
        {
            if (isPrime(number - twoSquares)) // check if: prime + two squares = number
            {
                valid = true;
                break;
            }
        }

        if (!valid)
            return number;
    }
}

int main()
{
    auto result = minGoldbachOther();
    std::cout << result << std::endl;
    
    return 0;
}
