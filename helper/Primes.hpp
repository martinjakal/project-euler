#pragma once

#include <vector>

bool isPrime(int number);
auto primeFactors(int number) -> std::vector<int>;
auto sieveOfEratosthenes(int limit) -> std::vector<int>;
