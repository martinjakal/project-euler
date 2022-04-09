#include <iostream>
#include <unordered_map>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 21
// https://projecteuler.net/problem=21
// Amicable numbers
// Result: 31626

using namespace math;

int sumAmicableNumbers(int limit)
{
    std::unordered_map<int, int> divisorsCache;
    int sumAmicable = 0;

    for (int i = 1; i < limit; ++i)
        divisorsCache[i] = sumProperDivisors(i);

    for (int a = 1; a < limit; ++a)
    {
        // Find second number and its divisors.
        int b = divisorsCache.find(a)->second;
        auto posB = divisorsCache.find(b);

        // Check if numbers are amicable and distinct.
        if (posB != divisorsCache.end() && posB->second == a && a != b)
            sumAmicable += a;
    }

    return sumAmicable;
}

int main()
{
    int limit = 10000;
    auto result = sumAmicableNumbers(limit);
    std::cout << result << std::endl;

    return 0;
}
