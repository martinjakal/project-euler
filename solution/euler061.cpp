#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Project Euler - Problem 61
// https://projecteuler.net/problem=61
// Cyclical figurate numbers
// Result: 28684

auto generateFigurateNumbersInRange(int minRange, int maxRange) -> std::vector<std::vector<int>>
{
    std::vector<std::vector<int>> figurateNumbers(6);

    for (int i = 1, n = 0; n < maxRange; ++i, n = i * (i + 1) / 2) // triangle
    {
        if (n >= minRange)
            figurateNumbers[0].push_back(n);
    }

    for (int i = 1, n = 0; n < maxRange; ++i, n = i * i) // square
    {
        if (n >= minRange)
            figurateNumbers[1].push_back(n);
    }

    for (int i = 1, n = 0; n < maxRange; ++i, n = i * (3 * i - 1) / 2) // pentagonal
    {
        if (n >= minRange)
            figurateNumbers[2].push_back(n);
    }

    for (int i = 1, n = 0; n < maxRange; ++i, n = i * (2 * i - 1)) // hexagonal
    {
        if (n >= minRange)
            figurateNumbers[3].push_back(n);
    }

    for (int i = 1, n = 0; n < maxRange; ++i, n = i * (5 * i - 3) / 2) // heptagonal
    {
        if (n >= minRange)
            figurateNumbers[4].push_back(n);
    }

    for (int i = 1, n = 0; n < maxRange; ++i, n = i * (3 * i - 2)) // octagonal
    {
        if (n >= minRange)
            figurateNumbers[5].push_back(n);
    }

    return figurateNumbers;
}

bool findNextLink(const std::vector<std::vector<int>>& figurate, int idx, std::vector<int>& chain)
{
    for (auto number : figurate[idx])
    {
        if (chain.back() % 100 != number / 100 || std::find(chain.begin(), chain.end(), number) != chain.end())
            continue;

        chain.push_back(number);

        // If the chain contains distinct number from each set, check the final loop.
        if (chain.size() == figurate.size() && number % 100 == chain.front() / 100)
            return true;

        // Advance to the next set of numbers if there is any.
        if (chain.size() < figurate.size() && findNextLink(figurate, idx + 1, chain))
            return true;

        chain.pop_back();
    }

    return false;
}

int sumCyclicalFigurateNumbers()
{
    constexpr int minRange = 1000;
    constexpr int maxRange = 10'000;
    auto figurateNumbers = generateFigurateNumbersInRange(minRange, maxRange);

    std::sort(figurateNumbers.begin(), figurateNumbers.end());

    // Different permutations of number sets are checked. Starting from the first set, backtracking is used to find
    // the chain of distinct numbers from the following sets connected by digits.
    do
    {
        std::vector<int> chain;

        for (auto number : figurateNumbers[0])
        {
            chain.push_back(number);

            if (findNextLink(figurateNumbers, 1, chain))
                return std::accumulate(chain.begin(), chain.end(), 0);

            chain.pop_back();
        }
    } while (std::next_permutation(figurateNumbers.begin(), figurateNumbers.end()));

    return 0;
}

int main()
{
    auto result = sumCyclicalFigurateNumbers();
    std::cout << result << std::endl;

    return 0;
}
