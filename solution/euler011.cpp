#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 11
// https://projecteuler.net/problem=11
// Largest product in a grid
// Result: 70600674 

int maxProductInGrid(const std::vector<std::vector<int>>& grid, int length)
{
    int maxProduct = 0;

    for (size_t i = 0; i < grid.size(); ++i) // rows
    {
        for (size_t j = 0; j <= grid[i].size() - length; ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i][j + k];

            maxProduct = std::max(product, maxProduct);
        }
    }

    for (size_t i = 0; i <= grid.size() - length; ++i) // columns
    {
        for (size_t j = 0; j < grid[i].size(); ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i + k][j];
            
            maxProduct = std::max(product, maxProduct);
        }
    }

    for (size_t i = 0; i <= grid.size() - length; ++i) // left diagonal
    {
        for (size_t j = 0; j <= grid[i].size() - length; ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i + k][j + k];
            
            maxProduct = std::max(product, maxProduct);
        }
    }

    for (size_t i = length - 1; i < grid.size(); ++i) // right diagonal
    {
        for (size_t j = 0; j <= grid[i].size() - length; ++j)
        {
            int product = grid[i][j];

            for (int k = 1; k < length; ++k)
                product *= grid[i - k][j + k];
        
            maxProduct = std::max(product, maxProduct);
        }
    }

    return maxProduct;
}

int main()
{
    std::string filename = "input/euler011input.txt";
    int length = 4;
    auto input = readInputNumbersGrid(filename);
    auto result = maxProductInGrid(input, length);
    std::cout << result << std::endl;

    return 0;
}
