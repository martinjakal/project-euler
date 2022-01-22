#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 79
// https://projecteuler.net/problem=79
// Passcode derivation
// Result: 73162890

using namespace reader;

// The algorithm assumes all logins contain non-repeating digits.
auto crackPassword(const std::vector<std::string>& logins) -> std::string
{
    const int length = 3;
    std::vector<std::set<char>> characters(length);

    for (const auto& login : logins)
    {
        for (int i = 0; i < length; ++i)
            characters[i].insert(login[i]);
    }

    std::set<char> candidates;
    std::string password;
    char curChar;
    char lastChar;

    // First character has a unique value found only in the first column.
    std::set_difference(characters[0].begin(), characters[0].end(), characters[1].begin(), characters[1].end(), 
        std::inserter(candidates, candidates.end()));
    curChar = *candidates.begin();
    password += curChar;
    candidates.clear();

    // Last character has a unique value found only in the last column.
    std::set_difference(characters[length - 1].begin(), characters[length - 1].end(), 
        characters[length - 2].begin(), characters[length - 2].end(), std::inserter(candidates, candidates.end()));
    lastChar = *candidates.begin();
    candidates.clear();

    while (curChar != lastChar)
    {
        // Create set of candidate characters as characters appearing right after the current character.
        for (const auto& login : logins)
        {
            for (int i = 0; i < length - 1; ++i)
            {
                if (login[i] == curChar)
                    candidates.insert(login[i + 1]);
            }
        }

        // If both A and B are candidates and login combination AB is found, remove B from the candidates.
        for (const auto& login : logins)
        {
            bool isFirstCand = candidates.find(login[0]) != candidates.end();
            bool isSecondCand = candidates.find(login[1]) != candidates.end();
            bool isThirdCand = candidates.find(login[2]) != candidates.end();

            if (isFirstCand && isSecondCand)
                candidates.erase(login[1]);
            if ((isFirstCand || isSecondCand) && isThirdCand)
                candidates.erase(login[2]);

            if (candidates.size() == 1)
                break;
        }

        curChar = *candidates.begin();
        password += curChar;
        candidates.clear();
    }

    return password;
}

int main()
{
    std::string filename = "input/euler079input.txt";
    auto input = readStrings(filename);
    auto result = crackPassword(input);
    std::cout << result << std::endl;

    return 0;
}
