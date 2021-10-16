#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 65
// https://projecteuler.net/problem=65
// Convergents of e
// Result: 272

int digitSumConvergentOfE(int maxIter)
{
    BigInteger a = 1;
    BigInteger b = 2;

    for (int i = 2, k = 1; i <= maxIter; ++i)
    {
        BigInteger c;

        // The pattern for multiplication is (1, 1, 2k, 1...).
        if (i % 3 == 0)
        {
            c = a + b * 2 * k;
            ++k;
        }
        else
            c = a + b;

        a = b;
        b = c;
    }

    return b.digitSum();
}

int main()
{
    int maxIteration = 100;
    auto result = digitSumConvergentOfE(maxIteration); 
    std::cout << result << std::endl;
    
    return 0;
}
