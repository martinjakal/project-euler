#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 23
// https://projecteuler.net/problem=23
// Non-abundant sums
// Result: 4179871

using namespace math;

int calcSumNonAbundant(int limit = 28123)
{
    int sumNonAbundant = 0;
    std::vector<int> abundant;
    std::vector<bool> twoAbundant(limit + 1, false);

    for (int i = 1; i <= limit; ++i)
    {
        if (isAbundant(i))
            abundant.push_back(i);
    }

    // Mark numbers which can be written as the sum of two abundant numbers.
    for (int i = 0; i < static_cast<int>(abundant.size()); ++i)
    {
        for (int j = i; j < static_cast<int>(abundant.size()); ++j)
        {
            int sum = abundant[i] + abundant[j];

            if (sum > limit)
                break;    
            
            twoAbundant[sum] = true;
        }
    }

    for (int i = 0; i < static_cast<int>(twoAbundant.size()); ++i)
    {
        if (!twoAbundant[i])
            sumNonAbundant += i;
    }
    
    return sumNonAbundant;
}

int main()
{
    auto result = calcSumNonAbundant();
    std::cout << result << std::endl;

    return 0;
}
