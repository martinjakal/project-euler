#include "FileReader.hpp"

#include <fstream>

namespace reader
{
auto readStrings(const std::string& filename) -> std::vector<std::string>
{
    std::ifstream file(filename);
    std::vector<std::string> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string word;
        std::getline(file, word);
        out.push_back(word);
    }

    return out;
}

auto readNumbers(const std::string& filename, char separator) -> std::vector<std::vector<int>>
{
    std::ifstream file(filename);
    std::vector<std::vector<int>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string row;
        std::getline(file, row);
        out.push_back({});

        std::size_t i = 0;
        auto pos = row.find(separator, i);

        for (; pos != std::string::npos; pos = row.find(separator, i))
        {
            out.back().push_back(std::stoi(row.substr(i, pos - i)));
            i = pos + 1;
        }

        out.back().push_back(std::stoi(row.substr(i, row.size() - i)));
    }

    return out;
}

auto readWords(const std::string& filename) -> std::vector<std::string>
{
    std::ifstream file(filename);
    std::vector<std::string> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string word;
        std::getline(file, word, ',');
        out.push_back(word.substr(1, word.size() - 2)); // skip " symbols
    }

    return out;
}

auto readCards(const std::string& filename, char separator) -> std::vector<std::vector<std::string>>
{
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string row;
        std::getline(file, row);
        out.push_back({});

        std::size_t i = 0;
        auto pos = row.find(separator, i);

        for (; pos != std::string::npos; pos = row.find(separator, i))
        {
            out.back().push_back(row.substr(i, pos - i));
            i = pos + 1;
        }

        out.back().push_back(row.substr(i, row.size() - i));
    }

    return out;
}

auto readSudoku(const std::string& filename) -> std::vector<std::vector<std::vector<int>>>
{
    std::ifstream file(filename);
    std::vector<std::vector<std::vector<int>>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string row;
        std::vector<std::vector<int>> grid(9, std::vector<int>(9));

        std::getline(file, row); // discard header

        for (int i = 0; i < 9; ++i)
        {
            std::getline(file, row);

            for (int j = 0; j < 9; ++j)
                grid[i][j] = std::stoi(row.substr(j, 1));
        }

        out.push_back(grid);
    }

    return out;
}

} // namespace reader
