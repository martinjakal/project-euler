#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 8
// https://projecteuler.net/problem=8
// Largest product in a series
// Result: 23514624000

using namespace reader;

unsigned long long maxProductInSeries(const std::string& number, int length)
{
    std::vector<int> digits;
    for (auto digit : number)
        digits.push_back(digit - '0');

    unsigned long long maxProduct = 0;

    for (auto it = digits.begin(); it != digits.end() - length; ++it)
        maxProduct = std::max(std::accumulate(it, it + length, 1ULL, std::multiplies<unsigned long long>()), maxProduct);

    return maxProduct;
}

int main()
{
    std::string filename = "input/euler008input.txt";
    int length = 13;
    auto number = readConcatString(filename);
    auto result = maxProductInSeries(number, length);
    std::cout << result << std::endl;

    return 0;
}
