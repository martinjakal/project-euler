#include <iostream>

// Project Euler - Problem 63
// https://projecteuler.net/problem=63
// Powerful digit counts
// Result: 49

// Following trick is used: if a ^ b = c, then (a ^ b) / (10 ^ b) = c / (10 ^ b) and c / (10 ^ b) < 1. 
// For example, 9 ^ 3 = 729 and 0.9 ^ 3 = (9 ^ 3) / (10 ^ 3) = 0.729. The result gets lower after 
// each multiplication by a / 10. When the result gets below 0.1, it means the denominator (power of 10) 
// has more digits then numerator (power of a).
int countNthPowerNumbers()
{
    int nthPowerCount = 0;

    for (int i = 1; i < 10; ++i)
    {
        const double change = 0.1 * i;
        double number = change;

        while (number >= 0.1)
        {
            ++nthPowerCount;
            number *= change;
        }
    }

    return nthPowerCount;
}

int main()
{
    auto result = countNthPowerNumbers();
    std::cout << result << std::endl;

    return 0;
}
