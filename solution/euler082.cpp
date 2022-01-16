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

int minPathThreeDirectionMatrix(const std::vector<std::vector<int>>& matrix)
{
    const std::size_t rows = matrix.size();
    const std::size_t cols = matrix[0].size();
    std::vector<int> path;

    for (std::size_t i = 0; i < rows; ++i) // store paths separately, starting in the last column
        path.push_back(matrix[i].back());

    // Traverse the matrix from right to left and check if it is better to reach each cell from right, top or bottom.
    for (std::size_t j = cols - 1; j-- > 0; )
    {
        path[0] += matrix[0][j];

        for (std::size_t i = 1; i < rows; ++i)
            path[i] = std::min(path[i], path[i - 1]) + matrix[i][j];

        for (std::size_t i = rows - 1; i-- > 0; )
            path[i] = std::min(path[i], path[i + 1] + matrix[i][j]);
    }

    return *std::min_element(path.begin(), path.end());
}

int main()
{
    std::string filename = "input/euler082input.txt";
    auto input = readNumbers(filename, ',');
    auto result = minPathThreeDirectionMatrix(input);
    std::cout << result << std::endl;
    
    return 0;
}
