#pragma once

#include <vector>

namespace math {

// General
int factorial(int number);

// Primes
bool isPrime(int number);
bool isCircularPrime(int number);
bool isLeftTruncatablePrime(int number);
bool isRightTruncatablePrime(int number);
bool isTruncatablePrime(int number);
auto primeFactors(int number)->std::vector<int>;
auto sieveOfEratosthenes(int limit)->std::vector<int>;

// Properties
bool isTriangular(unsigned long long number);
bool isPentagonal(unsigned long long number);
bool isPalindrome(int number, int base = 10);

} // namespace math
