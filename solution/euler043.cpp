#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Project Euler - Problem 43
// https://projecteuler.net/problem=43
// Sub-string divisibility
// Result: 16695334890

const std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17 };
const int primeCnt = static_cast<int>(primes.size());

// Check if the digit substrings are divisible by respective primes.
bool hasDivisibleSubstrings(const std::vector<int>& digits)
{
    for (int i = 0; i < primeCnt; ++i)
    {
        int substr = digits[i + 1] * 100 + digits[i + 2] * 10 + digits[i + 3];

        if (substr % primes[i] != 0)
            return false;
    }

    return true;
}

unsigned long long sumDivisiblePandigitalNumbers()
{
    std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    unsigned long long sumDivisiblePandigital = 0;

    do
    {
        if (hasDivisibleSubstrings(digits))
        {
            sumDivisiblePandigital += std::accumulate(digits.begin(), digits.end(), 0ull,
                [](unsigned long long number, int d) { return number * 10 + d; });
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    return sumDivisiblePandigital;
}

int main()
{
    auto result = sumDivisiblePandigitalNumbers();
    std::cout << result << std::endl;

    return 0;
}
