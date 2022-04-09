#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 23
// https://projecteuler.net/problem=23
// Non-abundant sums
// Result: 4179871

using namespace math;

int sumNumbersWithoutAbundantSums()
{
    const int limit = 28123;
    std::vector<int> abundant;
    std::vector<bool> canWriteAsSum(limit + 1, false);
    int sumWithoutAbundantSums = 0;

    for (int i = 1; i <= limit; ++i)
    {
        if (isAbundant(i))
            abundant.push_back(i);
    }

    // Mark numbers which can be written as the sum of two abundant numbers.
    for (int i = 0; i < abundant.size(); ++i)
    {
        for (int j = i; j < abundant.size(); ++j)
        {
            int sum = abundant[i] + abundant[j];

            if (sum > limit)
                break;    

            canWriteAsSum[sum] = true;
        }
    }

    for (int i = 0; i < canWriteAsSum.size(); ++i)
    {
        if (!canWriteAsSum[i])
            sumWithoutAbundantSums += i;
    }

    return sumWithoutAbundantSums;
}

int main()
{
    auto result = sumNumbersWithoutAbundantSums();
    std::cout << result << std::endl;

    return 0;
}
