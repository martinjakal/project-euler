#include <iostream>

// Project Euler - Problem 63
// https://projecteuler.net/problem=63
// Powerful digit counts
// Result: 49

// The following trick is used: if a ^ b = c, then (a / 10) ^ b = c / (10 ^ b) and rhs < 1.
// For example, 9 ^ 3 = 729 and 0.9 ^ 3 = 0.729. The result gets lower after each multiplication
// by a / 10. When the result gets below 0.1, it means the denominator (power of 10)
// has more digits than the numerator (power of a).
int countNthPowerNumbers()
{
    int nthPowerCnt = 0;

    for (int digit = 1; digit < 10; ++digit)
    {
        const double diff = 0.1 * digit;

        for (double number = diff; number >= 0.1; number *= diff)
            ++nthPowerCnt;
    }

    return nthPowerCnt;
}

int main()
{
    auto result = countNthPowerNumbers();
    std::cout << result << std::endl;

    return 0;
}
