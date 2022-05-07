#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

// Project Euler - Problem 88
// https://projecteuler.net/problem=88
// Product-sum numbers
// Result: 7587457

// Each number greater than 1 can be written as product of a_1 to a_n and sum of a_1 to a_n with certain amount of ones.
// For example, 8 = 2 * 4 = 2 + 4 + 1 + 1, so two ones had to be added.
// Keed adding numbers to the current sum and product recursively and update the minimum product sum.
void calcProductSumNumbers(std::vector<int>& data, int start = 2, int count = 0, int sum = 0, int prod = 1)
{
    int value = count + prod - sum; // prod - sum is the amount of ones

    if (prod < data[value])
        data[value] = prod;

    for (int i = start; i < data.size(); ++i)
    {
        int nextSum = sum + i;
        int nextProd = prod * i;

        if (count + nextProd - nextSum >= data.size() - 1) // next depth adds one extra number
            break;

        calcProductSumNumbers(data, i, count + 1, nextSum, nextProd);
    }
}

auto calcProductSumNumbers(int limit) -> std::vector<int>
{
    std::vector<int> productSums(limit + 1, std::numeric_limits<int>::max());
    productSums[1] = 1;
    calcProductSumNumbers(productSums);
    return productSums;
}

int sumMinimumProductSumNumbers(int limit)
{
    const auto productSumNumbers = calcProductSumNumbers(limit);

    std::unordered_set<int> sums;
    for (int i = 2; i <= limit; ++i)
        sums.insert(productSumNumbers[i]);

    return std::accumulate(sums.begin(), sums.end(), 0);
}

int main()
{
    int limit = 12'000;

    auto result = sumMinimumProductSumNumbers(limit);
    std::cout << result << std::endl;

    return 0;
}
