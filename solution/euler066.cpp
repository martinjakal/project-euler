#include <cmath>
#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 66
// https://projecteuler.net/problem=66
// Diophantine equation
// Result: 661

// Continued franctions are used to solve Pell's equations.
int analyzeCoeffsOfDiophantineEquations(int limit)
{
    BigInteger maxX = 0;
    int bestD = 0;

    for (int D = 2; D <= limit; ++D)
    {
        const BigInteger root = static_cast<int>(std::sqrt(D));
        if (root * root == D)
            continue;

        BigInteger n = 0;
        BigInteger d = 1;
        BigInteger a = root;

        BigInteger x0 = 1;
        BigInteger y0 = 0;
        BigInteger x1 = a;
        BigInteger y1 = 1;

        while (x1 * x1 - y1 * y1 * D != 1)
        {
            n = d * a - n;
            d = (n * n * -1 + D) / d;
            a = (root + n) / d;

            BigInteger x2 = x1 * a + x0;
            BigInteger y2 = y1 * a + y0;
            x0 = x1;
            y0 = y1;
            x1 = x2;
            y1 = y2;
        }

        if (x1 > maxX)
        {
            maxX = x1;
            bestD = D;
        }
    }

    return bestD;
}

int main()
{
    int limit = 1000;

    auto result = analyzeCoeffsOfDiophantineEquations(limit);
    std::cout << result << std::endl;

    return 0;
}
