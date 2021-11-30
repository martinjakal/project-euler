#include <iostream>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 99
// https://projecteuler.net/problem=99
// Largest exponential
// Result: 709

using namespace reader;

int findLineWithMaxExponential(const std::vector<std::pair<int, int>>& numbers)
{
    double maxExp = 0;
    int lineNumber = 0;

    // If a ^ b = c ^ d, then b * log(a) = d * log(c).
    for (int i = 0; i < static_cast<int>(numbers.size()); ++i)
    {
        double exp = numbers[i].second * log(numbers[i].first);

        if (exp > maxExp)
        {
            maxExp = exp;
            lineNumber = i + 1;
        }
    }

    return lineNumber;
}

int main()
{
    std::string filename = "input/euler099input.txt";
    auto input = readInputNumberPairs(filename);
    auto result = findLineWithMaxExponential(input);
    std::cout << result << std::endl; 

    return 0;
}
