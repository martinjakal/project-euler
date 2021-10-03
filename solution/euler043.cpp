#include <algorithm>
#include <iostream>
#include <vector>

// Project Euler - Problem 43
// https://projecteuler.net/problem=43
// Sub-string divisibility
// Result: 16695334890

unsigned long long sumSubstringDivisible()
{
    const std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17 };
    std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    unsigned long long sumDivisible = 0;

    do
    {
        bool divisible = true;

        for (int i = 0; i < static_cast<int>(primes.size()); ++i)
        {
            int substr = digits[i + 1] * 100 + digits[i + 2] * 10 + digits[i + 3];

            if (substr % primes[i] != 0)
            {
                divisible = false;
                break;
            }
        }

        if (divisible)
        {
            unsigned long long number = 0;

            for (auto d : digits)
                number = number * 10 + d;

            sumDivisible += number;
        } 
        
    } while (std::next_permutation(digits.begin(), digits.end()));

    return sumDivisible;
}

int main()
{
    auto result = sumSubstringDivisible();
    std::cout << result << std::endl;

    return 0;
}
