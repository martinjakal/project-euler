#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include <helper/Constants.hpp>
#include <helper/FileReader.hpp>
#include <helper/MathPackage.hpp>

// Project Euler - Problem 42
// https://projecteuler.net/problem=42
// Coded triangle numbers
// Result: 162

using namespace math;
using namespace reader;

int countTriangleWords(const std::vector<std::string>& words)
{
    auto letterSum = [](int sum, char letter) { return sum + alphabet.find(letter)->second; };
    int triangleCnt = 0;

    for (const auto& word : words)
    {
        auto wordValue = std::accumulate(word.begin(), word.end(), 0, letterSum);
        triangleCnt += isTriangular(wordValue);
    }

    return triangleCnt;
}

int main()
{
    std::string filename = "input/euler042input.txt";

    auto input = readStrings(filename, ',');
    auto result = countTriangleWords(input.front());
    std::cout << result << std::endl;

    return 0;
}
