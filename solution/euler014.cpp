#include <algorithm>
#include <iostream>
#include <vector>

// Project Euler - Problem 14
// https://projecteuler.net/problem=14
// Longest Collatz sequence
// Result: 837799

int findLongestCollatzSequence(int limit)
{
    std::vector<int> stepsCache(limit + 1, 1);

    for (int i = 1; i < limit; ++i)
    {
        unsigned long long number = i;

        while (number != 1)
        {
            if (number % 2 == 0)
                number /= 2;
            else
                number = 3 * number + 1;

            if (number < i) // sequence length for smaller terms is precalculated
            {
                stepsCache[i] += stepsCache[static_cast<int>(number)];
                break;
            }
            else
                ++stepsCache[i];
        }
    }

    auto longestSequence = std::max_element(stepsCache.begin(), stepsCache.end());
    return static_cast<int>(std::distance(stepsCache.begin(), longestSequence));
}

int main()
{
    int limit = 1'000'000;
    auto result = findLongestCollatzSequence(limit);
    std::cout << result << std::endl;

    return 0;
}
