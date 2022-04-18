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
    const int limit = 28'123;

    std::vector<int> abundant;

    for (int i = 1; i <= limit; ++i)
    {
        if (isAbundant(i))
            abundant.push_back(i);
    }

    // Mark numbers which can be written as the sum of two abundant numbers.
    const int abundantCnt = static_cast<int>(abundant.size());
    std::vector<bool> canWriteAsSum(limit + 1, false);

    for (int i = 0; i < abundantCnt; ++i)
    {
        for (int j = i; j < abundantCnt; ++j)
        {
            int sum = abundant[i] + abundant[j];

            if (sum > limit)
                break;

            canWriteAsSum[sum] = true;
        }
    }

    int sumWithoutAbundantSums = 0;

    for (int i = 1; i <= limit; ++i)
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
