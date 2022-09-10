#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 57
// https://projecteuler.net/problem=57
// Square root convergents
// Result: 153

int countFractionsWithMoreDigitsInNumerator(int maxIter)
{
    BigInteger numerator = 1;
    BigInteger denominator = 1;
    int moreDigitsNumCnt = 0;

    // Next iteration of p / q continued fraction of the square root of two is obtained as (p + 2q) / (p + q).
    for (int iter = 1; iter <= maxIter; ++iter)
    {
        BigInteger n = numerator;
        BigInteger d = denominator;
        numerator += d * 2;
        denominator += n;
        moreDigitsNumCnt += numerator.digitCnt() > denominator.digitCnt();
    }

    return moreDigitsNumCnt;
}

int main()
{
    int maxIteration = 1000;

    auto result = countFractionsWithMoreDigitsInNumerator(maxIteration);
    std::cout << result << std::endl;

    return 0;
}
