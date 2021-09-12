#include <iostream>

// Project Euler - Problem 33
// https://projecteuler.net/problem=33
// Digit cancelling fractions
// Result: 100 

int cancelledFractionsDenominator()
{
    int totalNumerator = 1;
    int totalDenominator = 1;

    for (int d = 11; d < 100; ++d)
    {
        for (int n = 10; n < d; ++n)
        {
            double cancelledFraction = 0;

            if (n / 10 == d / 10)
                cancelledFraction = static_cast<double>(n % 10) / (d % 10);
            else if (n / 10 == d % 10)
                cancelledFraction = static_cast<double>(n % 10) / (d / 10);
            else if (n % 10 == d / 10 && d % 10 != 0) // check zero division
                cancelledFraction = static_cast<double>(n / 10) / (d % 10);
            else if (n % 10 == d % 10 && d % 10 != 0) // check trivial case
                cancelledFraction = static_cast<double>(n / 10) / (d / 10);

            if (cancelledFraction == static_cast<double>(n) / d)
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
    auto result = cancelledFractionsDenominator();
    std::cout << result << std::endl;

    return 0;
}
