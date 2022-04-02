#include <iostream>
#include <string>
#include <vector>

#include <helper/BigInteger.hpp>
#include <helper/FileReader.hpp>

// Project Euler - Problem 13
// https://projecteuler.net/problem=13
// Large sum
// Result: 5537376230

using namespace reader;

auto sumLargeNumbers(const std::vector<std::string>& numbers, int firstDigits) -> std::string
{
    BigInteger sum;

    for (const auto& number : numbers)
        sum += number;

    return sum.print().substr(0, firstDigits);
}

int main()
{ 
    std::string filename = "input/euler013input.txt";
    int firstDigits = 10;
    auto input = readStrings(filename, '\0');
    auto result = sumLargeNumbers(input.front(), firstDigits);
    std::cout << result << std::endl;

    return 0;
}
