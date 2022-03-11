#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

// Project Euler - Problem 88
// https://projecteuler.net/problem=88
// Product-sum numbers
// Result: 7587457

void findProductSumNumbers(std::vector<int>& data, int start = 2, int depth = 0, int sum = 0, int prod = 1)
{
    int count = depth + prod - sum;
    data[count] = std::min(prod, data[count]);

    for (int i = start; i < data.size(); i++)
    {
        int nextSum = sum + i;
        int nextProd = prod * i;

        if (nextProd - nextSum >= data.size())
            break;

        findProductSumNumbers(data, i, depth + 1, nextSum, nextProd);
    }
}

auto findProductSumNumbers(int limit) -> std::vector<int>
{
    std::vector<int> productSums(limit + 1, std::numeric_limits<int>::max());
    productSums[1] = 1;
    findProductSumNumbers(productSums);
    return productSums;
}

int sumProductSumNumbers(int limit)
{
    const auto productSumNumbers = findProductSumNumbers(limit);

    std::unordered_set<int> sums;
    for (int i = 2; i <= limit; i++)
        sums.insert(productSumNumbers[i]);

    return std::accumulate(sums.begin(), sums.end(), 0);
}

int main()
{
    int limit = 12000;
    auto result = sumProductSumNumbers(limit);
    std::cout << result << std::endl;

    return 0;
}
