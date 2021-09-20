#include <iostream>
#include <string>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 38
// https://projecteuler.net/problem=38
// Pandigital multiples
// Result: 932718654

using namespace math;

int maxPandigitalProduct()
{
    std::string maxProduct = "0";

    // Only numbers with max 4 digits can create 9 digit concatenated product.
    for (int i = 1; i < 10000; ++i) 
    {
        std::string product;

        for (int n = 1; product.size() < 9; ++n)
            product += std::to_string(i * n);

        if (product.size() == 9 && isPandigital(std::stoi(product)) && product > maxProduct)
            maxProduct = product;
    }

    return std::stoi(maxProduct);
}

int main()
{
    auto result = maxPandigitalProduct();
    std::cout << result << std::endl;

    return 0;
}
