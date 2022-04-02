#include "FileReader.hpp"

#include <algorithm>
#include <fstream>

namespace reader
{
auto readStrings(const std::string& filename, char separator) -> std::vector<std::vector<std::string>>
{
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> out;

    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    while (file.good())
    {
        std::string row;
        std::getline(file, row);

        if (separator == '\0')
        {
            if (out.empty())
                out.push_back({});

            out.back().push_back(row);
            continue;
        }

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

    for (auto& line : out)
    {
        for (auto& item : line) // remove quotation marks
            item.erase(std::remove(item.begin(), item.end(), '"'), item.end());
    }

    return out;
}

auto readNumbers(const std::string& filename, char separator) -> std::vector<std::vector<int>>
{
    auto data = readStrings(filename, separator);
    std::vector<std::vector<int>> out;

    for (const auto& line : data)
    {
        out.push_back({});
        for (const auto& item : line)
            out.back().push_back(std::stoi(item));
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
