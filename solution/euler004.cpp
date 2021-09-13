#include <iostream>

#include <helper/NumberProperties.hpp>

// Project Euler - Problem 4
// https://projecteuler.net/problem=4
// Largest palindrome product
// Result: 906609

int maxPalindromeProduct(int limit)
{
    int maxProduct = 0;

    for (int i = 1; i < limit; ++i)
    {
        for (int j = i; j < limit; ++j)
        {
            int product = i * j;

            if (product > maxProduct && isPalindrome(product))
                maxProduct = product;
        }
    }
 
    return maxProduct;
}

int main()
{
    int limit = 1000;
    auto result = maxPalindromeProduct(limit);    
    std::cout << result << std::endl;

    return 0;
}
