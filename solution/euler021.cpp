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
    std::unordered_map<int, int> divisorStore;
    int sumAmicable = 0;

    for (int i = 1; i < limit; ++i)
        divisorStore[i] = sumProperDivisors(i);

    for (int a = 1; a < limit; ++a)
    {
        // Find second number and its divisors.
        int b = divisorStore.find(a)->second;
        auto pos = divisorStore.find(b);

        // Check if numbers are amicable and distinct.
        if (pos != divisorStore.end() && a == pos->second && a != b)
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
