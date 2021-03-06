#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 20
// https://projecteuler.net/problem=20
// Factorial digit sum
// Result: 648

auto sumFactorialDigits(int limit) -> std::size_t
{
    BigInteger factorial = 1;

    for (int i = 2; i <= limit; ++i)
        factorial *= BigInteger(i);

    return factorial.digitSum();
}

int main()
{
    int limit = 100;

    auto result = sumFactorialDigits(limit);
    std::cout << result << std::endl;

    return 0;
}
