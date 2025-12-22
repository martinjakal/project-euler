#include <iostream>

#include <helper/Constants.hpp>

// Project Euler - Problem 17
// https://projecteuler.net/problem=17
// Number letter counts
// Result: 21124

int countLettersInNumbers(int limit)
{
    int letterCnt = 0;

    for (int i = 1; i <= limit; ++i)
    {
        int thousands = i / 1000 % 10;
        int hundreds = i / 100 % 10;
        int belowHundred = i % 100;

        if (thousands > 0)
            letterCnt += numberLetters.find(thousands)->second + numberLetters.find(1000)->second;

        if (hundreds > 0)
            letterCnt += numberLetters.find(hundreds)->second + numberLetters.find(100)->second;

        if ((thousands > 0 || hundreds > 0) && belowHundred > 0)  // add "and" word
            letterCnt += 3;

        if (belowHundred > 0)
        {
            if (belowHundred < 20 || belowHundred % 10 == 0)
                letterCnt += numberLetters.find(belowHundred)->second;
            else
                letterCnt += numberLetters.find(belowHundred - belowHundred % 10)->second + numberLetters.find(belowHundred % 10)->second;
        }
    }

    return letterCnt;
}

int main()
{
    int limit = 1000;

    auto result = countLettersInNumbers(limit);
    std::cout << result << std::endl;

    return 0;
}
