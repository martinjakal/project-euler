#pragma once

#include <vector>

namespace math
{
namespace impl
{
template <typename T>
void generateCombinations(const T& data, int length, int start, T& result, std::vector<T>& carrier, bool repeat)
{
    if (length == 0)
    {
        carrier.push_back(result);
        return;
    }

    for (int i = (repeat ? 0 : start); i <= data.size() - (repeat ? 1 : length); ++i)
    {
        result[result.size() - length] = data[i];
        generateCombinations(data, length - 1, i + 1, result, carrier, repeat);
    }
}

} // namespace impl

// General
int factorial(int number);

// Combinatorics
template <typename T>
auto generateCombinations(const T& data, int length, bool repeat) -> std::vector<T>
{
    std::vector<T> combinations;
    T result(length, ' ');
    impl::generateCombinations(data, length, 0, result, combinations, repeat);
    return combinations;
}

// Divisibility
int countDistinctFactors(int number);
int sumProperDivisors(int number);
bool isAbundant(int number);

// Primes
bool isPrime(int number);
bool isPrime(int number, const std::vector<int>& primes);
bool isCircularPrime(int number);
bool isLeftTruncatablePrime(int number);
bool isRightTruncatablePrime(int number);
bool isTruncatablePrime(int number);
auto primeFactors(int number) -> std::vector<int>;
auto sieveOfEratosthenes(int limit) -> std::vector<int>;

// Properties
bool isTriangular(unsigned long long number);
bool isPentagonal(unsigned long long number);
bool isPalindrome(int number, int base = 10);
bool isPermutation(int number1, int number2);
bool isPandigital(int number, int maxDigit = 9);

// Helper
int concat(int number1, int number2);

} // namespace math
