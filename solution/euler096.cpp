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

int sumTopLeftCornerOfSolvedSudokus(const std::vector<SudokuBacktracker::Grid>& sudokus)
{
    int sumTopLeftCorner = 0;

    for (const auto& sudoku : sudokus)
    {
        const auto solved = SudokuBacktracker(sudoku)();
        sumTopLeftCorner += solved[0][0] * 100 + solved[0][1] * 10 + solved[0][2];
    }

    return sumTopLeftCorner;
}

int main()
{
    std::string filename = "input/euler096input.txt";

    auto input = readSudoku(filename);
    auto result = sumTopLeftCornerOfSolvedSudokus(input);
    std::cout << result << std::endl;

    return 0;
}
