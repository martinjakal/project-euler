#include <iostream>
#include <unordered_map>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 51
// https://projecteuler.net/problem=51
// Prime digit replacements
// Result: 121313

using namespace math;

using PrimeFamilyCandidate = std::pair<int, int>;

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

// Prime family candidate consits of number and its digit to be replaced specified number of times 
// (-1 if no such replacement exists). In general the digit should not be equal to the last digit 
// to be able to create larger families.
auto makeCandidate(int number, int count) -> PrimeFamilyCandidate
{
    PrimeFamilyCandidate candidate(number, -1);
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
            candidate.second = d.first;
    }

    return candidate;
}

int minMemberOfEightPrimeFamily()
{
    for (int i = 0;; ++i)
    {
        if (!isPrime(i))
            continue;

        auto candidate = makeCandidate(i, 3); // 3 digits must be replaced to possibly make size 8 prime family
        if (candidate.second == -1)
            continue;

        int familySize = 0;

        for (int digit = 0; digit < 10; ++digit)
        {
            int replaced = replaceDigits(candidate.first, candidate.second, digit);

            if (digit == 0 && countDigits(replaced) != countDigits(candidate.first)) // check for leading zeros when replacing with 0
                continue;

            if (isPrime(replaced))
                ++familySize;
        }

        if (familySize == 8)
            return candidate.first;
    }
}

int main()
{
    auto result = minMemberOfEightPrimeFamily();
    std::cout << result << std::endl;

    return 0;
}
