#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 66
// https://projecteuler.net/problem=66
// Diophantine equation
// Result: 661

// Continued franctions are used to solve Pell's equations.
int solveDiophantineEquations(int limit)
{
    int bestD = 0;
    BigInteger maxX = 0;

    for (int D = 2; D <= limit; ++D)
    {
        const BigInteger a0 = static_cast<int>(sqrt(D));
        if (a0 * a0 == D)
            continue;

        BigInteger m = 0;
        BigInteger d = 1;
        BigInteger a = a0;

        BigInteger x0 = 1;
        BigInteger y0 = 0;
        BigInteger x1 = a;
        BigInteger y1 = 1;

        while (x1 * x1 - y1 * y1 * D != 1)
        {
            m = d * a - m;
            d = (m * m * -1 + D) / d;
            a = (a0 + m) / d;

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
    auto result = solveDiophantineEquations(limit);
    std::cout << result << std::endl;

    return 0;
}
