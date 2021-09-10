#pragma once
#include <string>
#include <vector>

auto readInputString(const std::string& filename) -> std::string; 
auto readInputNumbers(const std::string& filename) -> std::vector<std::string>;
auto readInputNumbersGrid(const std::string& filename) -> std::vector<std::vector<int>>;
