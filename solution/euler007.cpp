#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 7
// https://projecteuler.net/problem=7
// 10001st prime
// Result: 104743

using namespace math;

int nthPrime(int position)
{
    int primeCnt = 0;

    for (int number = 0; ; ++number)
    {
        if (isPrime(number))
            ++primeCnt;

        if (primeCnt == position)
            return number;
    }
}

int main()
{
    int position = 10001;
    auto result = nthPrime(position);
    std::cout << result << std::endl;

    return 0;
}
