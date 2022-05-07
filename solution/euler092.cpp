#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 92
// https://projecteuler.net/problem=92
// Square digit chains
// Result: 8581146

using namespace math;

int sumSquareDigits(int number)
{
    int sum = 0;

    while (number != 0)
    {
        int digit = number % 10;
        sum += digit * digit;
        number /= 10;
    }

    return sum;
}

int countSquareDigitChainsEndingAt89(int limit)
{
    const int maxSumSquareDigits = countDigits(limit - 1) * 9 * 9;
    std::vector<int> chains(maxSumSquareDigits + 1);
    chains[1] = 1;

    // Calculate chains for all possible sums of square digits.
    for (int i = 2; i <= maxSumSquareDigits; ++i)
    {
        int number = i;

        while (chains[i] != 1 && chains[i] != 89)
        {
            number = sumSquareDigits(number);

            // Chain for smaller terms is precalculated (also covers chain ending at 1).
            if (number < i)
                chains[i] = chains[number];
            else if (number == 89)
                chains[i] = number;
        }
    }

    int chainsAt89 = 0;
    for (int i = 1; i < limit; ++i)
    {
        if (chains[sumSquareDigits(i)] == 89)
            ++chainsAt89;
    }

    return chainsAt89;
}

int main()
{
    int limit = 10'000'000;

    auto result = countSquareDigitChainsEndingAt89(limit);
    std::cout << result << std::endl;

    return 0;
}
