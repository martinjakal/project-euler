#include <iostream>

// Project Euler - Problem 86
// https://projecteuler.net/problem=86
// Cuboid route
// Result: 1818

int cuboidRouteIntSolutions(int limit)
{
    int solutions = 0;
    int size = 0;

    while (solutions < limit)
    {
        ++size;

        for (int a = 1; a <= size; ++a)
        {
            for (int b = a; b <= size; ++b)
            {
                double length = sqrt(a * a + b * b + size * size + 2 * a * b);

                if (length == static_cast<int>(length))
                    ++solutions;
            }
        }        
    }

    return size;
}

int main()
{
    int limit = 1000000;
    auto result = cuboidRouteIntSolutions(limit);
    std::cout << result << std::endl;

    return 0;
}
