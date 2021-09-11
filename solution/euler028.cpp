#include <iostream>

// Project Euler - Problem 28
// https://projecteuler.net/problem=28
// Number spiral diagonals
// Result: 669171001

int sumSpiralDiagonal(int length)
{
    int sum = 1;
    int number = 1;

    for (int step = 2; step < length; step += 2)
    {
        for (int i = 0; i < 4; ++i)
        {
            number += step;
            sum += number;
        }
    }

    return sum;
}

int main()
{
    int length = 1001;
    auto result = sumSpiralDiagonal(length);
    std::cout << result << std::endl;

    return 0;
}