#include <iostream>
#include <vector>

// Project Euler - Problem 31
// https://projecteuler.net/problem=31
// Coin sums
// Result: 73682

int coinSums(int amount)
{
    const std::vector<int> coinValues = { 1, 2, 5, 10, 20, 50, 100, 200 };
    std::vector<int> ways(amount + 1, 0);
    ways[0] = 1;

    for (size_t i = 0; i < coinValues.size(); ++i)
    {
        // Add number of ways to create the remainder for each coin value.
        for (int j = coinValues[i]; j <= amount; ++j)
            ways[j] += ways[j - coinValues[i]];
    }

    return ways[amount];
}

int main()
{
    int amount = 200;
    auto result = coinSums(amount);
    std::cout << result << std::endl;

    return 0;
}
