#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 38
// https://projecteuler.net/problem=38
// Pandigital multiples
// Result: 932718654

using namespace math;

int calcMaxPandigitalProduct()
{
    int maxProduct = 0;

    // Only numbers with max 4 digits can create 9 digit concatenated product.
    for (int i = 1; i < 10000; ++i) 
    {
        int product = 0;

        for (int n = 1; countDigits(product) < 9; ++n)
            product = concat(product, i * n);

        if (product > maxProduct && isPandigital(product, 9))
            maxProduct = product;
    }

    return maxProduct;
}

int main()
{
    auto result = calcMaxPandigitalProduct();
    std::cout << result << std::endl;

    return 0;
}
