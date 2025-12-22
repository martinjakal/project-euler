#include <iostream>
#include <optional>

// Project Euler - Problem 33
// https://projecteuler.net/problem=33
// Digit cancelling fractions
// Result: 100

auto cancelFraction(int numerator, int denominator) -> std::optional<double>
{
    const int n1 = numerator / 10;
    const int n0 = numerator % 10;
    const int d1 = denominator / 10;
    const int d0 = denominator % 10;

    return n1 == d1              ? 1.0 * n0 / d0
           : n1 == d0            ? 1.0 * n0 / d1
           : n0 == d1 && d0 != 0 ? 1.0 * n1 / d0
                                 :  // check zero division
               n0 == d0 && d0 != 0 ? 1.0 * n1 / d1
                                   :  // check trivial case
               std::optional<double>{};
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

            if (cancelled.has_value() && cancelled.value() == static_cast<double>(n) / d)
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
