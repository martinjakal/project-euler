#include <iostream>

// Project Euler - Problem 85
// https://projecteuler.net/problem=85
// Counting rectangles
// Result: 2772

// For grid with size n * m, there are n * (n + 1) * m * (m + 1) / 4 rectangles.
int gridRectangleCount(int limit)
{
    // Max size of n (when m = 1) is a solution of n^2 + n = 2 * limit.
    const int maxSize = (-1 + sqrt(1 + 4 * 2 * limit)) / 2;
    int minDiff = limit;
    int bestWidth = 0;
    int bestHeight = 0;

    for (int w = 1; w <= maxSize; ++w)
    {
        for (int h = w; h <= maxSize - w + 1; ++h)
        {
            int rectangles = w * (w + 1) * h * (h + 1) / 4;
            int diff = std::abs(limit - rectangles);

            if (diff < minDiff)
            {
                minDiff = diff;
                bestWidth = w;
                bestHeight = h;
            }
        }
    }

    return bestWidth * bestHeight;
}

int main()
{
    int limit = 2000000;
    auto result = gridRectangleCount(limit);
    std::cout << result << std::endl;

    return 0;
}
