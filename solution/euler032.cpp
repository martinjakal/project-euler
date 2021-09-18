#include <iostream>
#include <string>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 32
// https://projecteuler.net/problem=32
// Pandigital products
// Result: 45228

using namespace math;

// If the numbers a, b, c in multiplication a * b = c should have 9 digits total,
// the only options are 1d * 4d = 4d or 2d * 3d = 4d.
int sumPandigitalProducts()
{
    std::vector<int> productStore;
    int sumProducts = 0;

    for (int i = 1; i < 100; ++i)
    {
        for (int j = 100; j < 10000; ++j)
        {
            int product = i * j;

            if (product > 9999)
                break;

            if (isPandigital(std::stoi(std::to_string(i) + std::to_string(j) + std::to_string(product))) 
                && std::find(productStore.begin(), productStore.end(), product) == productStore.end())
            {
                productStore.push_back(product);
                sumProducts += product;
            }
        }
    }

    return sumProducts;
}

int main()
{
    auto result = sumPandigitalProducts(); 
    std::cout << result << std::endl;

    return 0;
}
