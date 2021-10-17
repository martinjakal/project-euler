#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>

// Project Euler - Problem 75
// https://projecteuler.net/problem=75
// Singular integer right triangles
// Result: 161667

int singleSolutionRightTriangles(int limit)
{
    std::unordered_map<int, int> solutions;

    // Euclid's formula is used to generate Pythagorean triples.
    // For n = 0, the formula becomes 2 * m^2 <= limit.
    for (int m = 2; m <= sqrt(limit / 2); ++m)
    {
        for (int n = 1; n < m; ++n)
        {
            // Numbers must be coprime and not both odd. 
            if (std::gcd(m, n) != 1 || (m % 2 == 1 && n % 2 == 1))
                continue;

            int length = 2 * m * (m + n);

            // Multiples of triples are solutions too.
            for (int i = 1; i * length <= limit; ++i)
                ++solutions[i * length];
        }
    }

    return std::count_if(solutions.begin(), solutions.end(), [](const std::pair<int, int>& s) { return s.second == 1; });
}

int main()
{
    int limit = 1500000;
    auto result = singleSolutionRightTriangles(limit);
    std::cout << result << std::endl; 

    return 0;
}
