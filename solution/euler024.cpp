#include <algorithm>
#include <iostream>
#include <string>

// Project Euler - Problem 24
// https://projecteuler.net/problem=24
// Lexicographic permutations
// Result: 2783915460

auto nthPermutation(std::string digits, int pos) -> std::string
{
    int permutationCount = 1;

    while (permutationCount != pos && std::next_permutation(digits.begin(), digits.end()))
        ++permutationCount;

    return digits;
}

int main()
{
    std::string digits = "0123456789";
    int position = 1000000;
    auto result = nthPermutation(digits, position);
    std::cout << result << std::endl;

    return 0;
}
