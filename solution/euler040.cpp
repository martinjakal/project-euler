#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Project Euler - Problem 40
// https://projecteuler.net/problem=40
// Champernowne's constant
// Result: 210 

int productOfDigitsChampernowne(const std::vector<int>& digits)
{
    const size_t maxDigit = *std::max_element(digits.begin(), digits.end());
    std::string champernowne;
    int product = 1;

    for (int i = 1; champernowne.size() < maxDigit; ++i)
        champernowne.append(std::to_string(i));

    for (auto digit : digits)
        product *= std::stoi(champernowne.substr(digit - 1, 1));

    return product;
}

int main()
{
    std::vector<int> digits = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    auto result = productOfDigitsChampernowne(digits);
    std::cout << result << std::endl;

    return 0;
}
