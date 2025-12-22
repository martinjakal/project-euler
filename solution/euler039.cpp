#include <iostream>

// Project Euler - Problem 39
// https://projecteuler.net/problem=39
// Integer right triangles
// Result: 840

int countIntRightTriangles(int perimeter)
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

int findPerimeterWithMaxIntRightTriangles(int limit)
{
    int maxTriangles = 0;
    int bestPerimeter = 0;

    for (int perimeter = 3; perimeter <= limit; ++perimeter)
    {
        auto triangles = countIntRightTriangles(perimeter);

        if (triangles > maxTriangles)
        {
            maxTriangles = triangles;
            bestPerimeter = perimeter;
        }
    }

    return bestPerimeter;
}

int main()
{
    int limit = 1000;

    auto result = findPerimeterWithMaxIntRightTriangles(limit);
    std::cout << result << std::endl;

    return 0;
}
