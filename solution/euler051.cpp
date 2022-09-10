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
    if (number == 0)
        return oldDigit == 0 ? newDigit : 0;

    int replaced = 0;
    int rank = 1;

    while (number != 0)
    {
        int curDigit = number % 10;
        replaced += rank * (curDigit == oldDigit ? newDigit : curDigit);
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
    for (int i = 2; ; ++i)
    {
        if (!isPrime(i))
            continue;

        // Exactly 3 digits must be replaced to possibly make size 8 prime family.
        auto digitToRepl = findDigitForReplacement(i, 3);
        if (!digitToRepl.has_value())
            continue;

        int number = i;
        int familySize = 0;

        for (int digit = 0; digit < 10; ++digit)
        {
            auto replaced = replaceDigits(number, digitToRepl.value(), digit);

            // Check for leading zeros when replacing with 0.
            if (digit == 0 && countDigits(replaced) != countDigits(number))
                continue;

            familySize += isPrime(replaced);
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
