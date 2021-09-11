#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 16
// https://projecteuler.net/problem=16
// Power digit sum
// Result: 1366

int powerDigitSum(int base, int power)
{
    return (BigInteger(base) ^ BigInteger(power)).digitSum();
}

int main()
{
    int base = 2;
    int power = 1000;
    auto result = powerDigitSum(base, power);
    std::cout << result << std::endl;

    return 0;
}
