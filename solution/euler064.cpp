#include <cmath>
#include <iostream>

// Project Euler - Problem 64
// https://projecteuler.net/problem=64
// Odd period square roots
// Result: 1322

int calcSquareRootPeriod(int number)
{
    const int root = static_cast<int>(std::sqrt(number));
    int period = 0;
    int n = 0;
    int d = 1;
    int a = root;

    while (a != 2 * root)
    {
        n = d * a - n;
        d = (number - n * n) / d;
        a = (root + n) / d;
        ++period;
    }

    return period;
}

int countOddPeriodsOfSquareRoots(int limit)
{
    int oddPeriodCnt = 0;

    for (int i = 2; i <= limit; ++i)
    {
        if (std::sqrt(i) == static_cast<int>(std::sqrt(i)))
            continue;

        if (calcSquareRootPeriod(i) % 2 != 0)
            ++oddPeriodCnt;
    }

    return oddPeriodCnt;
}

int main()
{
    int limit = 10000;

    auto result = countOddPeriodsOfSquareRoots(limit);
    std::cout << result << std::endl;

    return 0;
}
