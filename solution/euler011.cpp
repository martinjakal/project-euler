#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 11
// https://projecteuler.net/problem=11
// Largest product in a grid
// Result: 70600674

using namespace reader;

int findMaxProductInGrid(const std::vector<std::vector<int>>& grid, int length)
{
    int maxProduct = 0;

    for (std::size_t i = 0; i < grid.size(); ++i) // horizontal
    {
        for (std::size_t j = 0; j <= grid[i].size() - length; ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i][j + k];

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    for (std::size_t i = 0; i <= grid.size() - length; ++i) // vertical
    {
        for (std::size_t j = 0; j < grid[i].size(); ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i + k][j];

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    for (std::size_t i = 0; i <= grid.size() - length; ++i) // left diagonal
    {
        for (std::size_t j = 0; j <= grid[i].size() - length; ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i + k][j + k];

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    for (std::size_t i = length - 1; i < grid.size(); ++i) // right diagonal
    {
        for (std::size_t j = 0; j <= grid[i].size() - length; ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i - k][j + k];

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    return maxProduct;
}

int main()
{
    std::string filename = "input/euler011input.txt";
    int length = 4;

    auto input = readNumbers(filename, ' ');
    auto result = findMaxProductInGrid(input, length);
    std::cout << result << std::endl;

    return 0;
}
