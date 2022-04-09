#include <algorithm>
#include <iostream>
#include <string>

// Project Euler - Problem 24
// https://projecteuler.net/problem=24
// Lexicographic permutations
// Result: 2783915460

auto findNthPermutation(std::string digits, int position) -> std::string
{
    int permutationCnt = 1;

    while (permutationCnt != position && std::next_permutation(digits.begin(), digits.end()))
        ++permutationCnt;

    return digits;
}

int main()
{
    std::string digits = "0123456789";
    int position = 1'000'000;

    auto result = findNthPermutation(digits, position);
    std::cout << result << std::endl;

    return 0;
}
