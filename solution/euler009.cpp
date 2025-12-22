#include <iostream>

// Project Euler - Problem 9
// https://projecteuler.net/problem=9
// Special Pythagorean triplet
// Result: 31875000

int findPythagoreanTripletProduct(int limit)
{
    for (int a = 1; a < limit / 3; ++a)  // sufficient because a < b < c
    {
        for (int b = a + 1; b < limit - a - b; ++b)
        {
            int c = limit - a - b;

            if (a * a + b * b == c * c)
                return a * b * c;
        }
    }

    return 0;
}

int main()
{
    int limit = 1000;

    auto result = findPythagoreanTripletProduct(limit);
    std::cout << result << std::endl;

    return 0;
}
