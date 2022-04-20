#include <iostream>
#include <vector>

// Project Euler - Problem 76
// https://projecteuler.net/problem=76
// Counting summations
// Result: 190569291

int countPossibleSums(int amount)
{
    std::vector<int> ways(amount + 1, 0);
    ways[0] = 1;

    for (int i = 1; i < amount; ++i)
    {
        // Add number of ways to create the remainder for each number.
        for (int j = i; j <= amount; ++j)
            ways[j] += ways[j - i];
    }

    return ways[amount];
}

int main()
{
    int amount = 100;

    auto result = countPossibleSums(amount);
    std::cout << result << std::endl;

    return 0;
}
