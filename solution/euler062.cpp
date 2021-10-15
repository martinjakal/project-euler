#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

// Project Euler - Problem 62
// https://projecteuler.net/problem=62
// Cubic permutations
// Result: 127035954683

unsigned long long minCubeWithDigitPermutations(int permCnt)
{    
    // String of sorted digits is used as a key for fast permutation check, 
    // value stores the original number and occurrence of its permutations.
    std::unordered_map<std::string, std::pair<unsigned long long, int>> permutations; 

    for (int number = 1; ; ++number)
    {
        unsigned long long cube = static_cast<unsigned long long>(pow(number, 3));
        std::string cubeStr = std::to_string(cube);

        std::sort(cubeStr.begin(), cubeStr.end());

        auto pos = permutations.find(cubeStr);

        if (pos != permutations.end())
        {
            ++pos->second.second;

            if (pos->second.second == permCnt)
                return pos->second.first;
        }    
        else
            permutations[cubeStr] = { cube, 1 };
    }
}

int main()
{
    int permutationCount = 5;
    auto result = minCubeWithDigitPermutations(permutationCount); 
    std::cout << result << std::endl;
    
    return 0;
}
