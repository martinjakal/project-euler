#include <iostream>
#include <numeric>

// Project Euler - Problem 71
// https://projecteuler.net/problem=71
// Ordered fractions
// Result: 428570

int findLeftNumeratorOfOrderedFractions(int limit)
{
    double maxFraction = 0;
    int numerator = 0;

    for (int d = 1; d <= limit; ++d)
    {
        // Continue from previously found numerator because n / d > n / (d + 1).
        for (int n = numerator; n < 3.0 * d / 7; ++n)
        {
            double fraction = static_cast<double>(n) / d;

            if (fraction > maxFraction && std::gcd(n, d) == 1)
            {
                numerator = n;
                maxFraction = fraction;
            }
        }
    }

    return numerator;
}

int main()
{
    int limit = 1'000'000;

    auto result = findLeftNumeratorOfOrderedFractions(limit);
    std::cout << result << std::endl;

    return 0;
}
