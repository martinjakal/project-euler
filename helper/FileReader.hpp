#pragma once
#include <string>
#include <vector>

auto readInputString(const std::string& filename)->std::string; 
auto readInputTriangle(const std::string& filename)->std::vector<std::vector<int>>;
