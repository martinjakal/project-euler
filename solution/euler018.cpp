#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 18
// https://projecteuler.net/problem=18
// Maximum path sum I
// Result: 1074

using namespace reader;

// Add the greater child to its parent from bottom to top, maximum path is in the root.
int findMaxPathInTriangle(std::vector<std::vector<int>> triangle)
{
    for (std::size_t i = triangle.size() - 1; i > 0; --i)
    {
        for (std::size_t j = 0; j < i; ++j)
            triangle[i - 1][j] += std::max(triangle[i][j], triangle[i][j + 1]);
    }

    return triangle[0][0];
}

int main()
{
    std::string filename = "input/euler018input.txt";

    auto input = readNumbers(filename, ' ');
    auto result = findMaxPathInTriangle(input);
    std::cout << result << std::endl;

    return 0;
}
