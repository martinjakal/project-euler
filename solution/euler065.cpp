#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 65
// https://projecteuler.net/problem=65
// Convergents of e
// Result: 272

int sumDigitsInConvergentOfE(int maxIter)
{
    BigInteger a = 1;
    BigInteger b = 1;

    for (int iter = 1, k = 1; iter <= maxIter; ++iter)
    {
        BigInteger c;

        // The pattern for multiplication is (1, 1, 2k).
        if (iter % 3 == 0)
        {
            c = a + b * 2 * k;
            ++k;
        }
        else
            c = a + b;

        a = b;
        b = c;
    }

    return static_cast<int>(b.digitSum());
}

int main()
{
    int maxIteration = 100;

    auto result = sumDigitsInConvergentOfE(maxIteration);
    std::cout << result << std::endl;

    return 0;
}
