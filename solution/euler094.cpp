#include <iostream>

// Project Euler - Problem 94
// https://projecteuler.net/problem=94
// Almost equilateral triangles
// Result: 518408346

// In triangle with integral sides a-a-b, we get 4 * a^2 = b^2 + 4 * h^2.
// Because b = a +/- 1, we get Pell's equation x^2 - 3 * y^2 = 1,
// where x = (3a +/- 1) / 2 and y = h.
auto sumPerimetersOfAlmostEquilateralTriangles(unsigned long long limit) -> unsigned long long
{
    unsigned long long sumPerimeters = 0;
    unsigned long long x = 1;
    unsigned long long y = 0;

    for (unsigned long long perimeter = 0; ;)
    {
        unsigned long long xNext = 2 * x + 3 * y;
        unsigned long long yNext = x + 2 * y;
        x = xNext;
        y = yNext;

        unsigned long long a = 2 * x;
        unsigned long long b;

        if ((a + 1) % 3 == 0) // decide if 2x + 1 = 3a or 2x - 1 = 3a
        {
            a = (a + 1) / 3;
            b = a + 1;
        }
        else
        {
            a = (a - 1) / 3;
            b = a - 1;
        }

        perimeter = a + a + b;

        if (perimeter > limit)
            break;

        double half = 1.0 * perimeter / 2;
        double area = (half - a) * sqrt(half * (half - b)); // Heron's formula

        if (area != 0 && area == static_cast<unsigned long long>(area))
            sumPerimeters += perimeter;
    }

    return sumPerimeters;
}

int main()
{
    unsigned long long limit = 1'000'000'000;
    auto result = sumPerimetersOfAlmostEquilateralTriangles(limit);
    std::cout << result << std::endl;

    return 0;
}
