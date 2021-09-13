#pragma once
#include <vector>

bool isPrime(int number);

bool isLeftTruncatablePrime(int number);
bool isRightTruncatablePrime(int number);
bool isTruncatablePrime(int number);

auto primeFactors(int number) -> std::vector<int>;
auto sieveOfEratosthenes(int limit) -> std::vector<int>;
