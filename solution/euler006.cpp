#include <iostream>

// Project Euler - Problem 6
// https://projecteuler.net/problem=6
// Sum square difference
// Result: 25164150

int calcSumSquareDifference(int limit)
{
    int sumOfSquares = 0;
    int squareOfSum = 0;

    for (int i = 1; i <= limit; ++i)
    {
        sumOfSquares += i * i;
        squareOfSum += i;
    }

    return squareOfSum * squareOfSum - sumOfSquares;
}

int main()
{
    int limit = 100;

    auto result = calcSumSquareDifference(limit);
    std::cout << result << std::endl;

    return 0;
}
