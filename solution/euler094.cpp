#include <cmath>
#include <iostream>

// Project Euler - Problem 94
// https://projecteuler.net/problem=94
// Almost equilateral triangles
// Result: 518408346

// The expression 4 * a^2 = b^2 + 4 * h^2 is true for triangle with integral sides (a, a, b).
// Because b = a +/- 1, it can be written as Pell's equation x^2 - 3 * y^2 = 1 where x = (3a +/- 1) / 2 and y = h.
auto sumPerimetersOfAlmostEquilateralTriangles(unsigned long long limit) -> unsigned long long
{
    auto sumPerimeters = 0ull;

    for (auto perimeter = 0ull, x = 1ull, y = 0ull;;)
    {
        auto xNext = 2 * x + 3 * y;
        auto yNext = x + 2 * y;
        x = xNext;
        y = yNext;

        auto a = 2 * x;
        int one = (a + 1) % 3 == 0 ? 1 : -1;  // decide if 2x + 1 = 3a or 2x - 1 = 3a
        a = (a + one) / 3;
        auto b = a + one;
        perimeter = a + a + b;

        if (perimeter > limit)
            break;

        double half = static_cast<double>(perimeter) / 2;
        double area = (half - a) * std::sqrt(half * (half - b));  // Heron's formula

        if (area != 0 && area == static_cast<unsigned long long>(area))
            sumPerimeters += perimeter;
    }

    return sumPerimeters;
}

int main()
{
    auto limit = 1'000'000'000ull;

    auto result = sumPerimetersOfAlmostEquilateralTriangles(limit);
    std::cout << result << std::endl;

    return 0;
}
