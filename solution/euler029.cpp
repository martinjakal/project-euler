#include <iostream>
#include <set>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 29
// https://projecteuler.net/problem=29
// Distinct powers
// Result: 9183

int countDistinctPowers(int maxBase, int maxExp)
{
    std::set<BigInteger> powers;

    for (int base = 2; base <= maxBase; ++base)
    {
        BigInteger number(base);

        for (int exp = 2; exp <= maxExp; ++exp)
        {
            number *= BigInteger(base);
            powers.insert(number);
        }
    }

    return static_cast<int>(powers.size());
}

int main()
{
    int maxBase = 100;
    int maxExp = 100;

    auto result = countDistinctPowers(maxBase, maxExp);
    std::cout << result << std::endl;

    return 0;
}
