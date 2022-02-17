#include <iostream>
#include <string>
#include <vector>

// Project Euler - Problem 90
// https://projecteuler.net/problem=90
// Cube digit pairs
// Result: 1217

void generateCombinations(const std::string& data, int length , int start, std::string& result, std::vector<std::string>& carrier)
{
    if (length == 0)
    {
        carrier.push_back(result);
        return;
    }

    for (int i = start; i <= data.size() - length; ++i)
    {
        result[result.size() - length] = data[i];
        generateCombinations(data, length - 1, i + 1, result, carrier);
    }
}

auto generateCombinations(const std::string& data, int length) -> std::vector<std::string>
{
    std::vector<std::string> combinations;
    std::string result(length, ' ');
    generateCombinations(data, length, 0, result, combinations);
    return combinations;
}

bool canObtainAllPairs(const std::vector<std::string>& pairs, const std::string& dice1, const std::string& dice2)
{
    for (const auto& p : pairs)
    {
        if ((dice1.find(p[0]) == std::string::npos || dice2.find(p[1]) == std::string::npos) && 
            (dice1.find(p[1]) == std::string::npos || dice2.find(p[0]) == std::string::npos))
            return false;
    }

    return true;
}

int countDiceArrangements()
{
    const std::string numbers = "0123456789";
    const std::vector<std::string> pairs = { "01", "04", "06", "16", "18", "25", "36", "46" }; // some digits switched, 9 replaced with 6

    auto dices = generateCombinations(numbers, 6);
    int arrangements = 0;

    // Dices are generated with all numbers, but 9 is then replaced with 6 for easier checking.
    for (auto& dice : dices)
    {
        auto pos = dice.find("9");
        if (pos != std::string::npos)
            dice.replace(pos, 1, "6");
    }

    for (int i = 0; i < dices.size() - 1; ++i)
    {
        for (int j = i + 1; j < dices.size(); ++j)
        {
            if (canObtainAllPairs(pairs, dices[i], dices[j]))
                ++arrangements;
        }
    }

    return arrangements;
}

int main()
{
    auto result = countDiceArrangements();
    std::cout << result << std::endl;

    return 0;
}
