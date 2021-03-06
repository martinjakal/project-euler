#include <algorithm>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

#include <helper/Constants.hpp>
#include <helper/FileReader.hpp>

// Project Euler - Problem 89
// https://projecteuler.net/problem=89
// Roman numerals
// Result: 743

using namespace reader;

int countLetters(const std::vector<std::string>& words)
{
    return std::accumulate(words.begin(), words.end(), 0, 
        [](int letterCnt, const std::string& word) { return letterCnt + static_cast<int>(word.size()); });
}

auto minimizeRomanNumber(std::string romanNumber) -> std::string
{
    for (const auto& repl : romanNumbersReplacements)
        romanNumber = std::regex_replace(romanNumber, std::regex(repl.first), repl.second);

    return romanNumber;
}

int countSavedCharsInMinimizedRomanNumbers(const std::vector<std::string>& original)
{
    std::vector<std::string> minimized;
    std::transform(original.begin(), original.end(), std::back_inserter(minimized), minimizeRomanNumber);
    return countLetters(original) - countLetters(minimized);
}

int main()
{
    std::string filename = "input/euler089input.txt";

    auto input = readStrings(filename, '\0');
    auto result = countSavedCharsInMinimizedRomanNumbers(input.front());
    std::cout << result << std::endl;

    return 0;
}
