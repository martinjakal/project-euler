#include <cmath>
#include <iostream>

// Project Euler - Problem 30
// https://projecteuler.net/problem=30
// Digit fifth powers
// Result: 443839

// Adding extra digit (assume it is a 9) is equal to: lhs * 10 + 9, rhs + 9^5.
// Lhs grows faster and becames greater than rhs at 6 digits.
// Therefore the upper bound for the number is 6 * 9^5 = 354294.
int sumNumbersWithFifthPowerDigits()
{
    const int limit = 354294;
    const int power = 5;
    int sumFifthPowerDigits = 0;

    for (int i = 2; i < limit; ++i)
    {
        int number = i;
        int digitSum = 0;

        while (number > 0)
        {
            digitSum += static_cast<int>(std::pow(number % 10, power));
            number /= 10;
        }

        if (digitSum == i)
            sumFifthPowerDigits += digitSum;
    }

    return sumFifthPowerDigits;
}

int main()
{
    auto result = sumNumbersWithFifthPowerDigits();
    std::cout << result << std::endl;

    return 0;
}
