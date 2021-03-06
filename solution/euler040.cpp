#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// Project Euler - Problem 40
// https://projecteuler.net/problem=40
// Champernowne's constant
// Result: 210 

int calcProductOfDigitsChampernowne(const std::vector<int>& digits)
{
    const std::size_t maxDigit = *std::max_element(digits.begin(), digits.end());

    std::string champernowne;
    for (int i = 1; champernowne.size() < maxDigit; ++i)
        champernowne += std::to_string(i);

    return std::accumulate(digits.begin(), digits.end(), 1,
        [&](int product, int digit) { return product * (champernowne[digit - 1] - '0'); });
}

int main()
{
    std::vector<int> digits = { 1, 10, 100, 1000, 10'000, 100'000, 1'000'000 };

    auto result = calcProductOfDigitsChampernowne(digits);
    std::cout << result << std::endl;

    return 0;
}
