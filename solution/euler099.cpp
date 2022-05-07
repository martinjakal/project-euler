#include <cmath>
#include <iostream>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 99
// https://projecteuler.net/problem=99
// Largest exponential
// Result: 709

using namespace reader;

int findLineWithMaxExponential(const std::vector<std::vector<int>>& numbers)
{
    double maxExponential = 0;
    int lineIdx = 0;

    // If a^b = c^d, then b * log(a) = d * log(c).
    for (int i = 0; i < static_cast<int>(numbers.size()); ++i)
    {
        double exponential = numbers[i][1] * std::log(numbers[i][0]);

        if (exponential > maxExponential)
        {
            maxExponential = exponential;
            lineIdx = i + 1;
        }
    }

    return lineIdx;
}

int main()
{
    std::string filename = "input/euler099input.txt";

    auto input = readNumbers(filename, ',');
    auto result = findLineWithMaxExponential(input);
    std::cout << result << std::endl;

    return 0;
}
