#include <iostream>

// Project Euler - Problem 64
// https://projecteuler.net/problem=64
// Odd period square roots
// Result: 1322

int squareRootPeriod(int number)
{
    const int a0 = static_cast<int>(sqrt(number));
    int period = 0;
    int m = 0;
    int d = 1;
    int a = a0;

    while (a != 2 * a0)
    {
        m = d * a - m;
        d = (number - m * m) / d;
        a = (a0 + m) / d;
        ++period;
    }

    return period;
}

int countOddPeriodsOfSquareRoots(int limit)
{
    int oddPeriodCount = 0;

    for (int i = 2; i <= limit; ++i)
    {
        if (sqrt(i) == static_cast<int>(sqrt(i)))
            continue;

        oddPeriodCount += squareRootPeriod(i) % 2 == 1;
    }

    return oddPeriodCount;
}

int main()
{
    int limit = 10000;
    auto result = countOddPeriodsOfSquareRoots(limit);
    std::cout << result << std::endl;
    
    return 0;
}
