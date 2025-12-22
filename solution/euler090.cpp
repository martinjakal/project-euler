#include <iostream>
#include <string>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 90
// https://projecteuler.net/problem=90
// Cube digit pairs
// Result: 1217

using namespace math;

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

int countDiceArrangementsAllowingAllSquares()
{
    const std::string digits = "0123456789";
    const std::vector<std::string> pairs = {"01", "04", "06", "16",
                                            "18", "25", "36", "46"};  // some digits are switched, 9 is replaced with 6

    auto dices = generateCombinations(digits, 6, false);

    // The dices are generated with all digits, but 9 is replaced with 6 for easier checking.
    for (auto& dice : dices)
    {
        auto pos = dice.find("9");
        if (pos != std::string::npos)
            dice.replace(pos, 1, "6");
    }

    int arrangements = 0;

    for (std::size_t i = 0; i < dices.size() - 1; ++i)
    {
        for (std::size_t j = i + 1; j < dices.size(); ++j)
        {
            arrangements += canObtainAllPairs(pairs, dices[i], dices[j]);
        }
    }

    return arrangements;
}

int main()
{
    auto result = countDiceArrangementsAllowingAllSquares();
    std::cout << result << std::endl;

    return 0;
}
