#include <iostream>
#include <optional>

// Project Euler - Problem 33
// https://projecteuler.net/problem=33
// Digit cancelling fractions
// Result: 100

auto cancelFraction(int numerator, int denominator) -> std::optional<double>
{
    int n1 = numerator / 10;
    int n0 = numerator % 10;
    int d1 = denominator / 10;
    int d0 = denominator % 10;

    if (n1 == d1)
        return 1.0 * n0 / d0;
    else if (n1 == d0)
        return 1.0 * n0 / d1;
    else if (n0 == d1 && d0 != 0) // check zero division
        return 1.0 * n1 / d0;
    else if (n0 == d0 && d0 != 0) // check trivial case
        return 1.0 * n1 / d1;

    return {};
}

int calcDenominatorOfCancelledFractions()
{
    int totalNumerator = 1;
    int totalDenominator = 1;

    for (int d = 11; d < 100; ++d)
    {
        for (int n = 10; n < d; ++n)
        {
            auto cancelled = cancelFraction(n, d);

            if (!cancelled.has_value())
                continue;

            if (cancelled.value() == static_cast<double>(n) / d)
            {
                totalNumerator *= n;
                totalDenominator *= d;
            }
        }
    }

    return totalDenominator / totalNumerator;
}

int main()
{
    auto result = calcDenominatorOfCancelledFractions();
    std::cout << result << std::endl;

    return 0;
}
