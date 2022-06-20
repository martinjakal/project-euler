#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 44
// https://projecteuler.net/problem=44
// Pentagon numbers
// Result: 5482660

using namespace math;

int calcMinPentagonalDifference()
{
    std::vector<int> pentagonal;

    for (int i = 1; ; ++i)
    {
        const int number = i * (3 * i - 1) / 2;

        for (auto p : pentagonal)
        {
            int sum = number + p;
            int diff = number - p;

            if (isPentagonal(sum) && isPentagonal(diff))
                return diff;
        }

        pentagonal.push_back(number);
    }
}

int main()
{
    auto result = calcMinPentagonalDifference();
    std::cout << result << std::endl;

    return 0;
}
