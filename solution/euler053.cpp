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
        // Check r only up to n/2 because solutions are symmetrical (n r) = (n n-r).
        for (int r = 1; r <= n / 2; ++r)
        {
            double result = 1;

            for (int i = 0; i < r; ++i)
            {
                result *= static_cast<double>(n) - i;
                result /= static_cast<double>(r) - i;
            }

            if (result > target)
                solutions += n == 2 * r ? 1 : 2;
        }
    }

    return solutions;
}

int main()
{
    int limit = 100;
    int target = 1000000;
    auto result = countCombinatoricSelections(limit, target);
    std::cout << result << std::endl;

    return 0;
}
