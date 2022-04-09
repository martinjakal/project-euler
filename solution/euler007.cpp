#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 7
// https://projecteuler.net/problem=7
// 10001st prime
// Result: 104743

using namespace math;

int findNthPrime(int position)
{
    int primeCnt = 0;
    int number = 0;

    while (primeCnt < position)
    {
        ++number;

        if (isPrime(number))
            ++primeCnt;
    }

    return number;
}

int main()
{
    int position = 10001;

    auto result = findNthPrime(position);
    std::cout << result << std::endl;

    return 0;
}
