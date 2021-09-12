#include <cmath>
#include <iostream>

// Project Euler - Problem 30
// https://projecteuler.net/problem=30
// Digit fifth powers
// Result: 443839

// Adding extra digit (assume it is a 9) is equal to: lhs * 10 + 9, rhs + 9^5.
// Lhs grows faster and becames greater than rhs at 6 digits.
// The upper bound for the number becomes 6 * 9^5 = 354294.
int sumFifthPowerDigits()
{
    const int limit = 354294;
    const int power = 5;
    int sumFifthPower = 0;

    for (int i = 2; i < limit; ++i)
    {
        int number = i;
        int digitSum = 0;

        while (number > 0)
        {
            digitSum += static_cast<int>(pow(number % 10, power));
            number /= 10;
        }

        if (digitSum == i)
            sumFifthPower += digitSum;
    }

    return sumFifthPower;
}

int main()
{
    auto result = sumFifthPowerDigits();
    std::cout << result << std::endl;
    
    return 0;
}
