#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 25
// https://projecteuler.net/problem=25
// 1000-digit Fibonacci number
// Result: 4782

int findFibonacciTermWithDigits(int digits)
{
    int termIdx = 2;
    BigInteger f0(0);
    BigInteger f1(1);
    BigInteger f2(1);

    while (f2.digitCnt() != digits)
    {
        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
        ++termIdx;
    }

    return termIdx;
}

int main()
{
    int digits = 1000;

    auto result = findFibonacciTermWithDigits(digits);
    std::cout << result << std::endl;

    return 0;
}
