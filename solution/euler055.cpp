#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 55
// https://projecteuler.net/problem=55
// Lychrel numbers
// Result: 249

int countLychrelNumbers(int limit, int maxIter)
{
    int lychrelCnt = limit - 1;

    for (int i = 1; i < limit; ++i)
    {
        BigInteger number = i;

        for (int it = 1; it <= maxIter; ++it)
        {
            number += number.reverse();

            if (number.isPalindrome())
            {
                --lychrelCnt;
                break;
            }
        }
    }

    return lychrelCnt;
}

int main()
{
    int limit = 10'000;
    int maxIteration = 50;

    auto result = countLychrelNumbers(limit, maxIteration);
    std::cout << result << std::endl;

    return 0;
}
