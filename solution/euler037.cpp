#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 37
// https://projecteuler.net/problem=37
// Truncatable primes
// Result: 748317

using namespace math;

int sumTruncatablePrimes()
{
    const int maxTruncatableCnt = 11;

    int truncatableCnt = 0;
    int sumTruncatable = 0;

    for (int i = 11; truncatableCnt < maxTruncatableCnt; i += 2)
    {
        if (isTruncatablePrime(i))
        {
            ++truncatableCnt;
            sumTruncatable += i;
        }
    }

    return sumTruncatable;
}

int main()
{
    auto result = sumTruncatablePrimes();
    std::cout << result << std::endl;

    return 0;
}
