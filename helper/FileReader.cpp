#include "FileReader.hpp"

#include <fstream>

namespace reader
{
auto readInputString(const std::string& filename) -> std::string
{
    std::ifstream file(filename);
    std::string out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string word;
        getline(file, word);
        out.append(word);
    }

    return out;
}

auto readLines(const std::string& filename) -> std::vector<std::string>
{
    std::ifstream file(filename);
    std::vector<std::string> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string word;
        getline(file, word);
        out.push_back(word);
    }

    return out;
}

auto readInputNumbersGrid(const std::string& filename) -> std::vector<std::vector<int>>
{
    std::ifstream file(filename);
    std::vector<std::vector<int>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string row;
        getline(file, row);
        out.push_back({});

        for (size_t i = 0; i < row.size(); i += 3)
            out.back().push_back(std::stoi(row.substr(i, 2)));
    }

    return out;
}

auto readInputWords(const std::string& filename) -> std::vector<std::string>
{
    std::ifstream file(filename);
    std::vector<std::string> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string word;
        getline(file, word, ',');
        out.push_back(word.substr(1, word.size() - 2)); // skip " symbols
    }

    return out;
}

auto readInputSudoku(const std::string& filename) -> std::vector<std::vector<std::vector<int>>>
{
    std::ifstream file(filename);
    std::vector<std::vector<std::vector<int>>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string row;
        std::vector<std::vector<int>> grid(9, std::vector<int>(9));

        getline(file, row); // discard header

        for (int i = 0; i < 9; ++i)
        {
            getline(file, row);

            for (int j = 0; j < 9; ++j)
                grid[i][j] = std::stoi(row.substr(j, 1));
        }

        out.push_back(grid);
    }

    return out;
}

auto readInputNumberPairs(const std::string& filename) -> std::vector<std::pair<int, int>>
{
    std::ifstream file(filename);
    std::vector<std::pair<int, int>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    int firstNum;
    int secondNum;
    char separator;

    while (file.good() && file >> firstNum >> separator >> secondNum)
    {
        out.push_back({ firstNum, secondNum });
    }

    return out;
}

} // namespace reader
