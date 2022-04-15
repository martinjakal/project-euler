#include <iostream>
#include <optional>
#include <unordered_map>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 51
// https://projecteuler.net/problem=51
// Prime digit replacements
// Result: 121313

using namespace math;

int replaceDigits(int number, int oldDigit, int newDigit)
{
    int replaced = 0;
    int rank = 1;

    while (number != 0)
    {
        int digit = number % 10;
        replaced += (digit == oldDigit ? newDigit : digit) * rank;
        rank *= 10;
        number /= 10;
    }

    return replaced;
}

// Check if the number contains a digit which can be replaced specified number of times.
// The digit should not be equal to the last digit to be able to create large prime families.
auto findDigitForReplacement(int number, int count) -> std::optional<int>
{
    const int lastDigit = number % 10;
    std::unordered_map<int, int> digitCounts;

    while (number != 0)
    {
        ++digitCounts[number % 10];
        number /= 10;
    }

    for (const auto& d : digitCounts)
    {
        if (d.second == count && d.first != lastDigit)
            return d.first;
    }

    return {};
}

int calcMinMemberOfEightPrimeFamily()
{
    for (int i = 0; ; ++i)
    {
        if (!isPrime(i))
            continue;

        auto digitToRepl = findDigitForReplacement(i, 3); // 3 digits must be replaced to possibly make size 8 prime family
        if (!digitToRepl)
            continue;

        int number = i;
        int familySize = 0;

        for (int digit = 0; digit < 10; ++digit)
        {
            int replaced = replaceDigits(number, digitToRepl.value(), digit);

            if (digit == 0 && countDigits(replaced) != countDigits(number)) // check for leading zeros when replacing with 0
                continue;

            if (isPrime(replaced))
                ++familySize;
        }

        if (familySize == 8)
            return number;
    }
}

int main()
{
    auto result = calcMinMemberOfEightPrimeFamily();
    std::cout << result << std::endl;

    return 0;
}
