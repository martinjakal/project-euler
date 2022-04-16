#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 34
// https://projecteuler.net/problem=34
// Digit factorials
// Result: 40730

using namespace math;

int sumDigitFactorials(int number, const std::vector<int>& factorials)
{
    int sum = 0;

    while (number > 9)
    {
        sum += factorials[number % 10];
        number /= 10;
    }

    return sum + factorials[number];
}

// Adding extra digit (assume it is a 9) is equal to: lhs * 10 + 9, rhs + 9!.
// Lhs grows faster and becames greater than rhs at 7 digits.
// Therefore the upper bound for the number is 7 * 9! = 2540160.
int sumFactorions()
{
    const int limit = 2'540'160;
    int sumFact = 0;

    std::vector<int> factorialsCache;
    for (int i = 0; i < 10; ++i)
        factorialsCache.push_back(factorial(i));

    for (int i = 3; i < limit; ++i)
    {
        if (sumDigitFactorials(i, factorialsCache) == i)
            sumFact += i;
    }

    return sumFact;
}

int main()
{
    auto result = sumFactorions();
    std::cout << result << std::endl;

    return 0;
}
