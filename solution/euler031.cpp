#include <iostream>
#include <vector>

#include <helper/Constants.hpp>

// Project Euler - Problem 31
// https://projecteuler.net/problem=31
// Coin sums
// Result: 73682

int countCoinSums(int amount)
{
    std::vector<int> ways(amount + 1, 0);
    ways[0] = 1;

    for (int i = 0; i < static_cast<int>(coins.size()); ++i)
    {
        // Add number of ways to create the remainder for each coin value.
        for (int j = coins[i]; j <= amount; ++j)
            ways[j] += ways[j - coins[i]];
    }

    return ways[amount];
}

int main()
{
    int amount = 200;

    auto result = countCoinSums(amount);
    std::cout << result << std::endl;

    return 0;
}
