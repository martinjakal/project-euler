#include <algorithm>
#include <iostream>
#include <string>

// Project Euler - Problem 24
// https://projecteuler.net/problem=24
// Lexicographic permutations
// Result: 2783915460

auto nthPermutation(std::string characters, int position) -> std::string
{
    int permutationCnt = 1;

    while (permutationCnt != position && std::next_permutation(characters.begin(), characters.end()))
        ++permutationCnt;

    return characters;
}

int main()
{
    std::string digits = "0123456789";
    int position = 1000000;
    auto result = nthPermutation(digits, position);
    std::cout << result << std::endl;

    return 0;
}
