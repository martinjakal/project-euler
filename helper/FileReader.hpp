#pragma once

#include <string>
#include <vector>

namespace reader
{
auto readInputString(const std::string& filename) -> std::string;
auto readInputNumbers(const std::string& filename) -> std::vector<std::string>;
auto readInputNumbersGrid(const std::string& filename) -> std::vector<std::vector<int>>;
auto readInputWords(const std::string& filename) -> std::vector<std::string>;
auto readInputSudoku(const std::string& filename) -> std::vector<std::vector<std::vector<int>>>;

} // namespace reader
