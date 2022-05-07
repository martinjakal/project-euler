#include <algorithm>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <unordered_map>

#include <helper/FileReader.hpp>
#include <helper/MathPackage.hpp>

// Project Euler - Problem 98
// https://projecteuler.net/problem=98
// Anagramic squares
// Result: 18769

using namespace math;
using namespace reader;

using WordPair = std::pair<std::string, std::string>;

// Create anagram pairs grouped by the number of distinct characters.
auto findAnagramsByLength(const std::vector<std::string>& words) -> std::map<int, std::vector<WordPair>>
{
    std::map<int, std::vector<WordPair>> anagramsByLength; // key - number of distinct characters, value - anagram pair

    for (std::size_t a = 0; a < words.size(); ++a)
    {
        const int length = static_cast<int>(words[a].size());

        std::unordered_map<char, int> charCountA; // store characters found in the first word
        for (std::size_t i = 0; i < words[a].size(); ++i)
            ++charCountA[words[a][i]];

        for (std::size_t b = a + 1; b < words.size(); ++b)
        {
            if (words[a].size() != words[b].size())
                continue;

            std::unordered_map<char, int> charCountB = charCountA; // remove characters found in the second word
            for (std::size_t i = 0; i < words[b].size(); ++i)
                --charCountB[words[b][i]];

            if (std::all_of(charCountB.begin(), charCountB.end(), [](const std::pair<char, int>& p) { return p.second == 0; }))
                anagramsByLength[length].emplace_back(words[a], words[b]);
        }
    }

    return anagramsByLength;
}

// Generate squares grouped by the number of digits, i.e. 1: (1, 4, 9), 2: (16, 25 ...) etc.
auto findSquaresByDigits(int maxSquare) -> std::unordered_map<int, std::vector<int>>
{
    std::unordered_map<int, std::vector<int>> squaresByDigits;
    for (int i = 1, square = i * i; square < maxSquare; ++i, square = i * i)
        squaresByDigits[countDigits(square)].push_back(square);
    return squaresByDigits;
}

auto transformWordPairToSquares(const WordPair& wordPair, const std::vector<int>& squares) -> std::optional<int>
{
    for (auto firstSquare : squares)
    {
        int firstSquareTmp = firstSquare;
        std::unordered_map<char, int> charToNum;
        bool validFirstSquare = true;

        // Try to build a valid mapping of characters to digits, i.e. TREE, 2855 -> T: 2, R: 8, E: 5.
        for (std::size_t i = wordPair.first.size(); i-- > 0;)
        {
            char c = wordPair.first[i];
            int n = firstSquareTmp % 10;

            if (charToNum.find(c) == charToNum.end())
            {
                // Verify that the digit is not assigned to other characters before adding new character.
                if (std::any_of(charToNum.begin(), charToNum.end(), [n](const std::pair<char, int>& p) { return p.second == n; }))
                {
                    validFirstSquare = false;
                    break;
                }

                charToNum[c] = n;
            }
            else
            {
                // Verify that the digit in square number matches the digit already assigned to the character.
                if (charToNum.find(c)->second != n)
                {
                    validFirstSquare = false;
                    break;
                }
            }

            firstSquareTmp /= 10;
        }

        if (!validFirstSquare)
            continue;

        // Use the mapping to build the second number and verify square property.
        int secondSquare = 0;
        for (std::size_t i = 0; i < wordPair.second.size(); ++i)
            secondSquare = 10 * secondSquare + charToNum.find(wordPair.second[i])->second;

        if (std::find(squares.begin(), squares.end(), secondSquare) != squares.end())
            return std::max(firstSquare, secondSquare);
    }

    return {};
}

int findMaxSquareCreatedByAnagramWordPair(const std::vector<std::string>& words)
{
    const auto anagramsByLength = findAnagramsByLength(words);
    const int maxSquare = static_cast<int>(std::pow(10, anagramsByLength.rbegin()->first));
    const auto squaresByDigits = findSquaresByDigits(maxSquare);

    // Find maximum value of valid transformation to squares for each anagram pair.
    int maxSquareAnagramWordPair = 0;
    for (const auto& anagramSet : anagramsByLength)
    {
        for (const auto& anagramPair : anagramSet.second)
        {
            auto square = transformWordPairToSquares(anagramPair, squaresByDigits.at(anagramSet.first));

            if (square.has_value() && square.value() > maxSquareAnagramWordPair)
                maxSquareAnagramWordPair = square.value();
        }
    }

    return maxSquareAnagramWordPair;
}

int main()
{
    std::string filename = "input/euler098input.txt";

    auto input = readStrings(filename, ',');
    auto result = findMaxSquareCreatedByAnagramWordPair(input.front());
    std::cout << result << std::endl;

    return 0;
}
