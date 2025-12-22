#include <iostream>
#include <vector>

// Project Euler - Problem 78
// https://projecteuler.net/problem=78
// Coin partitions
// Result: 55374

int findNumberWithDivisiblePartitions(int mod)
{
    std::vector<int> partitions = {1};
    std::vector<int> pentagonal;

    for (int number = 1, p = 1;; ++number)
    {
        // Generate the next generalized pentagonal number.
        if (pentagonal.empty() || number > pentagonal.back())
        {
            pentagonal.push_back(p * (3 * p - 1) / 2);
            p = p >= 0 ? -p : -p + 1;  // 1, -1, 2, -2, 3, -3 ...
        }

        int ways = 0;

        // Calculate the next partition by Euler's pentagonal number theorem.
        for (std::size_t i = 0, cnt = 0; i < pentagonal.size() && pentagonal[i] <= number; ++i, ++cnt)
        {
            int sign = cnt % 4 < 2 ? 1 : -1;
            ways += sign * partitions[number - pentagonal[i]];
            ways %= mod;
        }

        partitions.push_back(ways);

        if (partitions.back() == 0)
            return number;
    }
}

int main()
{
    int mod = 1'000'000;

    auto result = findNumberWithDivisiblePartitions(mod);
    std::cout << result << std::endl;

    return 0;
}
