#pragma once

#include <string>
#include <vector>

namespace reader
{
auto readStrings(const std::string& filename, char separator) -> std::vector<std::vector<std::string>>;
auto readNumbers(const std::string& filename, char separator) -> std::vector<std::vector<int>>;
auto readSudoku(const std::string& filename) -> std::vector<std::vector<std::vector<int>>>;

} // namespace reader
