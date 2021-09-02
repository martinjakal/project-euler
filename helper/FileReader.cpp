#include "FileReader.hpp"

#include <fstream>

auto readInputString(const std::string& filename) -> std::string
{
    std::ifstream file(filename);
    std::string out;

    while (file.good())
    {
        std::string word;
        getline(file, word);
        out.append(word);
    }

    return out;
}

auto readInputNumbersGrid(const std::string& filename) -> std::vector<std::vector<int>>
{
    std::ifstream file(filename);
    std::vector<std::vector<int>> out;

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
