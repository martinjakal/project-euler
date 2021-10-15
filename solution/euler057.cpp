#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 57
// https://projecteuler.net/problem=57
// Square root convergents
// Result: 153

int moreDigitsNumeratorSqrtTwo(int maxIter)
{
    int moreDigitsNumCnt = 0;
    BigInteger numerator(1);
    BigInteger denominator(1);

    // Next iteration of p / q fraction is obtained as (p + 2q) / (p + q).
    for (int i = 1; i <= maxIter; ++i)
    {
        numerator += denominator * 2;
        denominator = numerator - denominator;

        if (numerator.digitCnt() > denominator.digitCnt())
            ++moreDigitsNumCnt;
    }

    return moreDigitsNumCnt;
}

int main()
{
    int maxIter = 1000;
    auto result = moreDigitsNumeratorSqrtTwo(maxIter);
    std::cout << result << std::endl;

    return 0;
}
