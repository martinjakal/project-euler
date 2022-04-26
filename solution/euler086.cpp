#include <cmath>
#include <iostream>

// Project Euler - Problem 86
// https://projecteuler.net/problem=86
// Cuboid route
// Result: 1818

int findCuboidDimWithSolutions(int targetSolutions)
{
    int solutions = 0;
    int dimM = 0;

    while (solutions < targetSolutions)
    {
        ++dimM;

        // The length is obtained as a square of (a + b)^2 + c^2. This expression becomes 5 * M^2
        // for maximum length M and gives the limit 2 * M for a + b.
        for (int ab = 1; ab <= 2 * dimM; ++ab)
        {
            double length = std::sqrt(ab * ab + dimM * dimM);

            if (length == static_cast<int>(length))
            {
                solutions += ab / 2;

                if (ab > dimM) // skip solutions where a > M or b > M
                    solutions -= ab - dimM - 1;
            }
        }
    }

    return dimM;
}

int main()
{
    int solutions = 1'000'000;

    auto result = findCuboidDimWithSolutions(solutions);
    std::cout << result << std::endl;

    return 0;
}
