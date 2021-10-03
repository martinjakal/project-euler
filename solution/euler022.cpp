#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

#include <helper/FileReader.hpp>

// Project Euler - Problem 22
// https://projecteuler.net/problem=22
// Names scores
// Result: 871198282

using namespace reader;

int sumNameScores(std::vector<std::string>& names)
{
    const std::unordered_map<char, int> alphabet = { { 'A', 1 }, { 'B', 2 }, { 'C', 3 }, { 'D', 4 }, { 'E', 5 },
        { 'F', 6 }, { 'G', 7 }, { 'H', 8 }, { 'I', 9 }, { 'J', 10 }, { 'K', 11 }, { 'L', 12 }, { 'M', 13 },
        { 'N', 14 }, { 'O', 15 }, { 'P', 16 }, { 'Q', 17 }, { 'R', 18 }, { 'S', 19 }, { 'T', 20 },
        { 'U', 21 }, { 'V', 22 }, { 'W', 23 }, { 'X', 24 }, { 'Y', 25 }, { 'Z', 26 } };

    std::sort(names.begin(), names.end());
    auto letterSum = [alphabet](int sum, char letter) { return sum + alphabet.find(letter)->second; };
    int score = 0;
    int nameIdx = 0;
    
    for (const auto& name : names)
        score += std::accumulate(name.begin(), name.end(), 0, letterSum) * ++nameIdx;

    return score;
}

int main()
{
    std::string filename = "input/euler022input.txt";
    auto words = readInputWords(filename);
    auto result = sumNameScores(words);
    std::cout << result << std::endl;

    return 0;
}
