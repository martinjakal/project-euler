#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>
#include <helper/SudokuBacktracker.hpp>

// Project Euler - Problem 96
// https://projecteuler.net/problem=96
// Su Doku
// Result: 24702

using namespace reader;
using Grid = SudokuBacktracker::Grid;

int solvedSudokuSum(std::vector<Grid>& sudokus)
{
    int leftCornerSum = 0;

    for (auto& sudoku : sudokus)
    {
        sudoku = SudokuBacktracker(sudoku)();
        leftCornerSum += sudoku[0][0] * 100 + sudoku[0][1] * 10 + sudoku[0][2];
    }

    return leftCornerSum;
}

int main()
{
    std::string filename = "input/euler096input.txt";
    auto input = readInputSudoku(filename);
    auto result = solvedSudokuSum(input);
    std::cout << result << std::endl;

    return 0;
}
