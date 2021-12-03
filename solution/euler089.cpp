#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 89
// https://projecteuler.net/problem=89
// Roman numerals
// Result: 743

using namespace reader;

const std::vector<std::pair<std::string, std::string>> replacements = { 
    { "DCCCC", "CM" }, { "LXXXX", "XC" }, { "VIIII", "IX" }, 
    { "CCCC", "CD" }, { "XXXX", "XL" }, { "IIII", "IV" } };

int countLetters(const std::vector<std::string>& words)
{
    return std::accumulate(words.begin(), words.end(), 0, 
        [](int letterCnt, const std::string& word) { return letterCnt + word.size(); });
}

auto minimizeRomanNumber(std::string romanNumber) -> std::string
{
    for (const auto& repl : replacements)
        romanNumber = std::regex_replace(romanNumber, std::regex(repl.first), repl.second);

    return romanNumber;
}

int charsSavedInRomanNumbers(const std::vector<std::string>& original)
{
    std::vector<std::string> minimized;
    std::transform(original.begin(), original.end(), std::back_inserter(minimized), minimizeRomanNumber);
    return countLetters(original) - countLetters(minimized);
}

int main()
{
    std::string filename = "input/euler089input.txt";
    auto input = readLines(filename);
    auto result = charsSavedInRomanNumbers(input);
    std::cout << result << std::endl;
    
    return 0;
}
