#pragma once

#include <array>
#include <string>
#include <unordered_map>

inline const std::unordered_map<int, int> numberLetters = { { 1, 3 }, { 2, 3 }, { 3, 5 }, { 4, 4 }, { 5, 4 },
    { 6, 3 }, { 7, 5 }, { 8, 5 }, { 9, 4 }, { 10, 3 }, { 11, 6 }, { 12, 6 }, { 13, 8 }, { 14, 8 }, { 15, 7 },
    { 16, 7 }, { 17, 9 }, { 18, 8 }, { 19, 8 }, { 20, 6 }, { 30, 6 }, { 40, 5 }, { 50, 5 }, { 60, 5 }, 
    { 70, 7 }, { 80, 6 }, { 90, 6 }, { 100, 7 }, { 1000, 8 } };

inline const std::unordered_map<char, int> alphabet = { { 'A', 1 }, { 'B', 2 }, { 'C', 3 }, { 'D', 4 }, { 'E', 5 },
    { 'F', 6 }, { 'G', 7 }, { 'H', 8 }, { 'I', 9 }, { 'J', 10 }, { 'K', 11 }, { 'L', 12 }, { 'M', 13 }, { 'N', 14 },
    { 'O', 15 }, { 'P', 16 }, { 'Q', 17 }, { 'R', 18 }, { 'S', 19 }, { 'T', 20 }, { 'U', 21 }, { 'V', 22 },
    { 'W', 23 }, { 'X', 24 }, { 'Y', 25 }, { 'Z', 26 } };

inline constexpr std::array<int, 8> coins = { 1, 2, 5, 10, 20, 50, 100, 200 };

inline const std::unordered_map<std::string, std::string> romanNumbersReplacements = {
    { "DCCCC", "CM" },
    { "LXXXX", "XC" },
    { "VIIII", "IX" },
    { "CCCC", "CD" },
    { "XXXX", "XL" },
    { "IIII", "IV" } };