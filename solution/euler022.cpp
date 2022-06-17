#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include <helper/Constants.hpp>
#include <helper/FileReader.hpp>

// Project Euler - Problem 22
// https://projecteuler.net/problem=22
// Names scores
// Result: 871198282

using namespace reader;

int sumNameScores(std::vector<std::string> names)
{
    std::sort(names.begin(), names.end());

    auto letterSum = [](int sum, char letter) { return sum + alphabet.find(letter)->second; };
    int score = 0;

    for (int i = 0; i < static_cast<int>(names.size()); ++i)
        score += std::accumulate(names[i].begin(), names[i].end(), 0, letterSum) * (i + 1);

    return score;
}

int main()
{
    std::string filename = "input/euler022input.txt";

    auto input = readStrings(filename, ',');
    auto result = sumNameScores(input.front());
    std::cout << result << std::endl;

    return 0;
}
