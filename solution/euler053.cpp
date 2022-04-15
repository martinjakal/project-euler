#include <iostream>

// Project Euler - Problem 53
// https://projecteuler.net/problem=53
// Combinatoric selections
// Result: 4075

int countCombinatoricSelections(int limit, int target)
{
    int solutions = 0;

    for (int n = 1; n <= limit; ++n)
    {
        // Check r only up to n/2 because the solutions are symmetrical: (n r) = (n n-r).
        for (int r = 1; r <= n / 2; ++r)
        {
            double combinations = 1;

            for (int i = 0; i < r; ++i)
            {
                combinations *= 1.0 * n - i;
                combinations /= 1.0 * r - i;
            }

            if (combinations > target)
            {
                if (n != 2 * r)
                    solutions += 2;
                else
                    ++solutions;
            }
        }
    }

    return solutions;
}

int main()
{
    int limit = 100;
    int target = 1'000'000;

    auto result = countCombinatoricSelections(limit, target);
    std::cout << result << std::endl;

    return 0;
}
