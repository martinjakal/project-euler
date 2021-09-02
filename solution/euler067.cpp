#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 67
// https://projecteuler.net/problem=67
// Maximum path sum II
// Result: 7273

// Add the greater child to its parent from bottom to top, maximum path is in the root.
int maxPathInTriangle(std::vector<std::vector<int>> triangle)
{
    for (size_t i = triangle.size() - 1; i > 0; --i)
    {
        for (size_t j = 0; j < i; ++j)
            triangle[i - 1][j] += std::max(triangle[i][j], triangle[i][j + 1]);
    }

    return triangle[0][0];
}

int main()
{
    std::string filename = "input/euler067input.txt";
    auto input = readInputNumbersGrid(filename);
    auto result = maxPathInTriangle(input);
    std::cout << result << std::endl;

    return 0;
}
