#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 16
// https://projecteuler.net/problem=16
// Power digit sum
// Result: 1366

int sumPowerDigits(int base, int power)
{
    return static_cast<int>((BigInteger(base) ^ BigInteger(power)).digitSum());
}

int main()
{
    int base = 2;
    int power = 1000;
    auto result = sumPowerDigits(base, power);
    std::cout << result << std::endl;

    return 0;
}
