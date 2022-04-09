#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 8
// https://projecteuler.net/problem=8
// Largest product in a series
// Result: 23514624000

using namespace reader;

unsigned long long findMaxProductInSeries(const std::vector<std::string>& numbers, int length)
{
    std::string concatNumber = std::accumulate(numbers.begin(), numbers.end(), std::string(""));

    std::vector<int> digits;
    for (auto digit : concatNumber)
        digits.push_back(digit - '0');

    unsigned long long maxProduct = 0;

    for (auto it = digits.begin(); it != digits.end() - length; ++it)
    {
        auto product = std::accumulate(it, it + length, 1ull, std::multiplies<unsigned long long>());

        if (product > maxProduct)
            maxProduct = product;
    }

    return maxProduct;
}

int main()
{
    std::string filename = "input/euler008input.txt";
    int length = 13;

    auto input = readStrings(filename, '\0');
    auto result = findMaxProductInSeries(input.front(), length);
    std::cout << result << std::endl;

    return 0;
}
