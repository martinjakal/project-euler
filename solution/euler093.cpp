#include <algorithm>
#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 93
// https://projecteuler.net/problem=93
// Arithmetic expressions
// Result: 1258

using namespace math;

double op(double a, double b, char sign)
{
    return sign == '+' ? a + b :
           sign == '-' ? a - b :
           sign == '*' ? a * b :
           sign == '/' && b != 0 ? a / b : 0;
}

int arithmeticExpressionsMaxLength()
{
    const std::vector<int> digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const std::vector<char> signs = { '+', '-', '*', '/' };
    const auto digitCombinations = generateCombinations(digits, 4, false);
    const auto signCombinations = generateCombinations(signs, 3, true);
    int maxLength = 0;
    int bestSet = 0;

    for (auto d : digitCombinations) // digit selection
    {
        std::vector<int> resultStore;

        do // digit permutation
        {
            for (const auto& s : signCombinations) // sign selection
            {
                std::vector<double> results(5);

                results[0] = op(op(op(d[0], d[1], s[0]), d[2], s[1]), d[3], s[2]); // ((1)2)3
                results[1] = op(d[0], op(d[1], op(d[2], d[3], s[2]), s[1]), s[0]); // 3(2(1))
                results[2] = op(op(d[0], d[1], s[0]), op(d[2], d[3], s[2]), s[1]); // (1)3(2)
                results[3] = op(op(d[0], op(d[1], d[2], s[1]), s[0]), d[3], s[2]); // (2(1))3
                results[4] = op(d[0], op(op(d[1], d[2], s[1]), d[3], s[2]), s[0]); // 3((1)2)

                for (auto res : results)
                {
                    int resInt = static_cast<int>(res);
                    if (resInt > 0 && resInt == res && std::find(resultStore.begin(), resultStore.end(), resInt) == resultStore.end())
                        resultStore.push_back(resInt);
                }
            }
        } 
        while (std::next_permutation(d.begin(), d.end()));

        std::sort(resultStore.begin(), resultStore.end());
        if (resultStore.empty() || resultStore[0] != 1)
            continue;

        int length = 1;
        for (int i = 1; i < resultStore.size(); ++i) // find longest chain from 1 to n
        {
            if (resultStore[i] == resultStore[i - 1] + 1)
                ++length;
            else
                break;
        }

        if (length > maxLength)
        {
            maxLength = length;
            bestSet = concat(concat(concat(d[0], d[1]), d[2]), d[3]);
        }
    }

    return bestSet;
}

int main()
{
    auto result = arithmeticExpressionsMaxLength();
    std::cout << result << std::endl;

    return 0;
}
