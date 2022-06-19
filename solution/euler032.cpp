#include <iostream>
#include <numeric>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 32
// https://projecteuler.net/problem=32
// Pandigital products
// Result: 45228

using namespace math;

// The numbers a, b, c in the expression a * b = c can have 9 digits total
// only if the digits are distributed as 1d * 4d = 4d or 2d * 3d = 4d.
int sumPandigitalProducts()
{
    std::vector<int> products;

    for (int i = 1; i < 100; ++i)
    {
        for (int j = 100; j < 10000; ++j)
        {
            int product = i * j;

            if (product > 9999)
                break;

            int concatenated = concat(concat(i, j), product);

            if (isPandigital(concatenated) && std::find(products.begin(), products.end(), product) == products.end())
                products.push_back(product);
        }
    }

    return std::accumulate(products.begin(), products.end(), 0);
}

int main()
{
    auto result = sumPandigitalProducts(); 
    std::cout << result << std::endl;

    return 0;
}
