#include <iostream>
#include <numeric>

// Project Euler - Problem 91
// https://projecteuler.net/problem=91
// Right triangles with integer coordinates
// Result: 14234

int countRightTrianglesInSquareGrid(int limit)
{
    int triangles = 3 * limit * limit; // right angle vertex is placed on axis

    // Solution of linear Diophantine equation with symmetry.
    for (int x = 1; x <= limit; ++x)
    {
        for (int y = 1; y <= limit; ++y)
        {
            int div = std::gcd(x, y);
            triangles += 2 * std::min(y * div / x, (limit - x) * div / y);
        }
    }

    return triangles;
}

int main()
{
    int limit = 50;
    auto result = countRightTrianglesInSquareGrid(limit);
    std::cout << result << std::endl;

    return 0;
}
