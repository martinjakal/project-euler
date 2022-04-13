#include <iostream>
#include <string>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 48
// https://projecteuler.net/problem=48
// Self powers
// Result: 9110846700

auto sumSelfPowers(int maxPower, int lastDigits) -> std::string
{
    BigInteger sumPowers;

    for (int i = 1; i <= maxPower; ++i)
        sumPowers += BigInteger(i) ^ BigInteger(i);

    return sumPowers.print().substr(sumPowers.digitCnt() - lastDigits);
}

int main()
{
    int maxPower = 1000;
    int lastDigits = 10;

    auto result = sumSelfPowers(maxPower, lastDigits);
    std::cout << result << std::endl;

    return 0;
}
