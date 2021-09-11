#include <iostream>

// Project Euler - Problem 39
// https://projecteuler.net/problem=39
// Integer right triangles
// Result: 840  

int rightTrianglesCount(int perimeter)
{
    int triangles = 0;

    for (int a = 1; a < perimeter / 3; ++a)
    {
        for (int b = a + 1; b < perimeter - a - b; ++b)
        {
            int c = perimeter - a - b;

            if (a * a + b * b == c * c)
                ++triangles;
        }
    }

    return triangles;
}

int maxRightTriangles(int limit)
{
    int maxSolutions = 0;
    int maxPerimeter = 0;

    for (int perimeter = 3; perimeter <= limit; ++perimeter)
    {
        int solutions = rightTrianglesCount(perimeter);

        if (solutions > maxSolutions)
        {
            maxSolutions = solutions;
            maxPerimeter = perimeter;
        }
    }

    return maxPerimeter;
}

int main()
{
    int limit = 1000;
    auto result = maxRightTriangles(limit);
    std::cout << result << std::endl; 

    return 0;
}
