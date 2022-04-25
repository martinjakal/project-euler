#include <cmath>
#include <iostream>

// Project Euler - Problem 85
// https://projecteuler.net/problem=85
// Counting rectangles
// Result: 2772

int findGridAreaContainingRectangles(int targetRectangles)
{
    // Grid with sides n and m contains n * (n + 1) * m * (m + 1) / 4 rectangles.
    // Maximum value of n is obtained for m = 1 as a solution of n * (n + 1) = 2 * target.
    const int maxSize = static_cast<int>((-1 + std::sqrt(1 + 8 * targetRectangles)) / 2);

    int minDiff = targetRectangles;
    int bestArea = 0;

    for (int w = 1; w <= maxSize; ++w)
    {
        for (int h = 1; h <= w; ++h)
        {
            int rectangles = w * (w + 1) * h * (h + 1) / 4;
            int diff = std::abs(targetRectangles - rectangles);

            if (diff < minDiff)
            {
                minDiff = diff;
                bestArea = w * h;
            }
        }
    }

    return bestArea;
}

int main()
{
    int rectangles = 2'000'000;

    auto result = findGridAreaContainingRectangles(rectangles);
    std::cout << result << std::endl;

    return 0;
}
