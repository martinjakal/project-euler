#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Project Euler - Problem 68
// https://projecteuler.net/problem=68
// Magic 5-gon ring
// Result: 6531031914842725

auto findArrangementInMagic5GonRing() -> std::string
{
    const int length = 5;
    std::vector<int> outer = { 6, 7, 8, 9, 10 };
    std::vector<int> inner = { 1, 2, 3, 4, 5 };
    std::string maxSolution = "0";

    // Higher numbers must be placed in the outer loop for the solution to be maximized.
    // Valid solution starts with the lowest number in the outer loop.
    do
    {
        do
        {
            int sumGroup = outer[0] + inner[0] + inner[1];
            bool validArrangement = true;

            for (int i = 1; i < length; ++i)
            {
                if (outer[i] + inner[i] + inner[(i + 1) % length] != sumGroup)
                {
                    validArrangement = false;
                    break;
                }
            }

            if (!validArrangement)
                continue;

            std::string solution;

            for (int i = 0; i < length; ++i)
                solution += std::to_string(outer[i]) + std::to_string(inner[i]) + std::to_string(inner[(i + 1) % length]);

            if (solution > maxSolution)
            {
                maxSolution = solution;
            }
        } while (std::next_permutation(inner.begin(), inner.end()));
    } while (std::next_permutation(outer.begin() + 1, outer.end())); // keep the lowest outer number in place

    return maxSolution;
}

int main()
{
    auto result = findArrangementInMagic5GonRing();
    std::cout << result << std::endl;

    return 0;
}
