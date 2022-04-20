#include <cmath>
#include <iostream>
#include <optional>

// Project Euler - Problem 64
// https://projecteuler.net/problem=64
// Odd period square roots
// Result: 1322

auto calcSquareRootPeriod(int number) -> std::optional<int>
{
    const int root = static_cast<int>(std::sqrt(number));
    if (root * root == number)
        return {};

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
        auto period = calcSquareRootPeriod(i);

        if (period.has_value() && period.value() % 2 != 0)
            ++oddPeriodCnt; 
    }

    return oddPeriodCnt;
}

int main()
{
    int limit = 10'000;

    auto result = countOddPeriodsOfSquareRoots(limit);
    std::cout << result << std::endl;

    return 0;
}
