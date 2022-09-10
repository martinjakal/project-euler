#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 82
// https://projecteuler.net/problem=82
// Path sum: three ways
// Result: 260324

using namespace reader;

int sumMinPathInThreeDirectionMatrix(const std::vector<std::vector<int>>& matrix)
{
    const auto rowCnt = matrix.size();
    const auto colCnt = matrix[0].size();

    // Store paths to each cell separately, starting in the last column.
    std::vector<int> paths;
    for (std::size_t i = 0; i < rowCnt; ++i)
        paths.push_back(matrix[i].back());

    // Traverse the matrix from right to left and decide the best direction to visit each cell (left, top or bottom).
    for (std::size_t j = colCnt - 1; j-- > 0; )
    {
        paths[0] += matrix[0][j];

        for (std::size_t i = 1; i < rowCnt; ++i)
            paths[i] = std::min(paths[i], paths[i - 1]) + matrix[i][j];

        for (std::size_t i = rowCnt - 1; i-- > 0; )
            paths[i] = std::min(paths[i], paths[i + 1] + matrix[i][j]);
    }

    return *std::min_element(paths.begin(), paths.end());
}

int main()
{
    std::string filename = "input/euler082input.txt";

    auto input = readNumbers(filename, ',');
    auto result = sumMinPathInThreeDirectionMatrix(input);
    std::cout << result << std::endl;

    return 0;
}
