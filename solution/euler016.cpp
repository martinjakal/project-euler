#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 16
// https://projecteuler.net/problem=16
// Power digit sum
// Result: 1366

auto sumPowerDigits(int base, int power) -> std::size_t
{
    return (BigInteger(base) ^ BigInteger(power)).digitSum();
}

int main()
{
    int base = 2;
    int power = 1000;

    auto result = sumPowerDigits(base, power);
    std::cout << result << std::endl;

    return 0;
}
