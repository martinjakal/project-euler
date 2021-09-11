#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 25
// https://projecteuler.net/problem=25
// 1000-digit Fibonacci number
// Result: 4782

int fibTermDigits(int digits)
{
    int termIdx = 3;
    BigInteger fn0(1);
    BigInteger fn1(1);
    BigInteger fn2(fn0 + fn1);

    while (fn2.digitCnt() != digits)
    {
        fn0 = fn1;
        fn1 = fn2;
        fn2 = fn0 + fn1;
        ++termIdx;
    }

    return termIdx;
}

int main()
{
    int digits = 1000;
    auto result = fibTermDigits(digits);
    std::cout << result << std::endl;

    return 0;
}
