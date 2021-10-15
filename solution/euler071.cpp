#include <iostream>
#include <numeric>

// Project Euler - Problem 71
// https://projecteuler.net/problem=71
// Ordered fractions
// Result: 428570

int maxNumeratorOrderedFractions(int limit)
{
    int maxNumerator = 0;
    double maxFraction = 0;

    for (int d = 1; d <= limit; ++d)
    {
        // Numerator starts at max numerator because n / d > n / (d + 1).
        for (int n = maxNumerator; n < 3.0 * d / 7; ++n)
        {
            double fraction = static_cast<double>(n) / d;

            if (fraction > maxFraction && std::gcd(n, d) == 1)
            {
                maxNumerator = n;
                maxFraction = fraction;
            }
        }
    }

    return maxNumerator;
}

int main()
{
    int limit = 1000000;
    auto result = maxNumeratorOrderedFractions(limit);   
    std::cout << result << std::endl;

    return 0;
}
