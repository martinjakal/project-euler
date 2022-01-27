#pragma once

#include <vector>

namespace math
{
// General
int factorial(int number);

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
