#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 74
// https://projecteuler.net/problem=74
// Digit factorial chains
// Result: 402

using namespace math;

int sumDigitFactorial(int number, const std::vector<int>& factorials)
{
    int digitSum = 0;

    while (number > 9)
    {
        digitSum += factorials[number % 10];
        number /= 10;
    }

    return digitSum + factorials[number];
}

int chainsDigitFactorial(int limit, int length)
{
    std::vector<int> factorials;
    for (int i = 0; i < 10; ++i)
        factorials.push_back(factorial(i));

    // Precompute all sums of digit factorials up to the range obtained as number of digits * 9!.
    const int digits = static_cast<int>(std::ceil(std::log10(limit - 1)));
    std::vector<int> factDigitSums(digits * factorials[9] + 1, 0);

    for (int i = 0; i < factDigitSums.size(); ++i)
        factDigitSums[i] = sumDigitFactorial(i, factorials);

    std::vector<int> chainLengths(limit + 1, 0);

    for (int i = 1; i < limit; ++i)
    {
        int number = i;
        std::vector<int> terms;

        while (std::find(terms.begin(), terms.end(), number) == terms.end())
        {
            terms.push_back(number);
            ++chainLengths[i];
            number = factDigitSums[number];

            // Reuse the chain length for smaller terms which is already stored.
            if (number < i)
            {
                chainLengths[i] += chainLengths[number];
                break;
            }
        }
    }

    return static_cast<int>(std::count(chainLengths.begin(), chainLengths.end(), length));
}

int main()
{
    int limit = 1000000;
    int length = 60;
    auto result = chainsDigitFactorial(limit, length);
    std::cout << result << std::endl;

    return 0;
}
