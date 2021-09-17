#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

#include <helper/FileReader.hpp>
#include <helper/MathPackage.hpp>

// Project Euler - Problem 42
// https://projecteuler.net/problem=42
// Coded triangle numbers
// Result: 162

using namespace math;

int triangleWordsCnt(const std::vector<std::string>& words)
{
    const std::unordered_map<char, int> alphabet = { { 'A', 1 }, { 'B', 2 }, { 'C', 3 }, { 'D', 4 }, { 'E', 5 }, 
        { 'F', 6 }, { 'G', 7 }, { 'H', 8 }, { 'I', 9 }, { 'J', 10 }, { 'K', 11 }, { 'L', 12 }, { 'M', 13 },
        { 'N', 14 }, { 'O', 15 }, { 'P', 16 }, { 'Q', 17 }, { 'R', 18 }, { 'S', 19 }, { 'T', 20 }, 
        { 'U', 21 }, { 'V', 22 }, { 'W', 23 }, { 'X', 24 }, { 'Y', 25 }, { 'Z', 26 } };

    auto letterSum = [alphabet](int sum, char letter) { return sum + alphabet.find(letter)->second; };
    int triangleWords = 0;

    for (const auto& word : words)
    {
        if (isTriangular(std::accumulate(word.begin(), word.end(), 0, letterSum)))
            ++triangleWords;
    }

    return triangleWords;
}

int main()
{
    std::string filename = "input/euler042input.txt";
    auto words = readInputWords(filename);
    auto result = triangleWordsCnt(words);
    std::cout << result << std::endl;

    return 0;
}
