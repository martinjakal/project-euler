#include <iostream>
#include <numeric>

// Project Euler - Problem 73
// https://projecteuler.net/problem=73
// Counting fractions in a range
// Result: 7295372

int countReducedProperFractionsInRange(int limit)
{
    int fractionCnt = 0;

    for (int d = 1; d <= limit; ++d)
    {
        for (int n = d / 3 + 1; n <= (d - 1) / 2; ++n)
        {
            if (std::gcd(n, d) == 1)
                ++fractionCnt;
        }
    }

    return fractionCnt;
}

int main()
{
    int limit = 12'000;

    auto result = countReducedProperFractionsInRange(limit);
    std::cout << result << std::endl;

    return 0;
}
