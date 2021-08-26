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
