#include <algorithm>
#include <iostream>
#include <vector>

// Project Euler - Problem 14
// https://projecteuler.net/problem=14
// Longest Collatz sequence
// Result: 837799

int maxCollatzSteps(int limit)
{
    std::vector<int> stepsStore(limit + 1, 0);

    for (int i = 1; i < limit; ++i)
    {
        unsigned long long number = i;
        int steps = 1;

        while (number != 1)
        {
            if (number % 2 == 0)
                number /= 2;
            else
                number = 3 * number + 1;

            // Sequence length for smaller terms is stored already.
            if (number < i)
            {
                steps += stepsStore[static_cast<int>(number)];
                break;
            }
            else
                ++steps;
        }

        stepsStore[i] = steps;
    }

    return std::distance(stepsStore.begin(), std::max_element(stepsStore.begin(), stepsStore.end()));
}

int main()
{
    int limit = 1000000;
    auto result = maxCollatzSteps(limit);
    std::cout << result << std::endl;

    return 0;
}
