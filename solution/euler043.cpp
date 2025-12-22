#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Project Euler - Problem 43
// https://projecteuler.net/problem=43
// Sub-string divisibility
// Result: 16695334890

bool hasSubstringsDivisibleByPrimes(const std::vector<int>& digits, const std::vector<int>& primes)
{
    for (int i = 0; i < primes.size(); ++i)
    {
        int substr = digits[i + 1] * 100 + digits[i + 2] * 10 + digits[i + 3];

        if (substr % primes[i] != 0)
            return false;
    }
    return true;
}

auto sumDivisiblePandigitalNumbers() -> unsigned long long
{
    const std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto sumDivisiblePandigital = 0ull;

    do
    {
        if (hasSubstringsDivisibleByPrimes(digits, primes))
        {
            sumDivisiblePandigital += std::accumulate(digits.begin(), digits.end(), 0ull,
                                                      [](unsigned long long number, int digit) { return number * 10 + digit; });
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
