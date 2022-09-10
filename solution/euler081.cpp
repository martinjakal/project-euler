#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 81
// https://projecteuler.net/problem=81
// Path sum: two ways
// Result: 427337

using namespace reader;

int sumMinPathInTwoDirectionMatrix(std::vector<std::vector<int>> matrix)
{
    const auto rowCnt = matrix.size();
    const auto colCnt = matrix[0].size();

    // Initialize first row and first column by adding all previous values.
    for (std::size_t i = 1; i < rowCnt; ++i)
        matrix[i][0] += matrix[i - 1][0];
    for (std::size_t j = 1; j < colCnt; ++j)
        matrix[0][j] += matrix[0][j - 1];

    // Add smaller element from left/top to each element in the remaining submatrix.
    for (std::size_t i = 1; i < rowCnt; ++i)
    {
        for (std::size_t j = 1; j < colCnt; ++j)
            matrix[i][j] += std::min(matrix[i - 1][j], matrix[i][j - 1]);
    }

    return matrix.back().back();
}

int main()
{
    std::string filename = "input/euler081input.txt";

    auto input = readNumbers(filename, ',');
    auto result = sumMinPathInTwoDirectionMatrix(input);
    std::cout << result << std::endl;

    return 0;
}
