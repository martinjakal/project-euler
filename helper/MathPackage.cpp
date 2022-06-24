#include "MathPackage.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <numeric>
#include <sstream>

namespace math 
{
int countDigits(int number)
{
    return number != 0 ? static_cast<int>(std::floor(std::log10(std::abs(number)))) + 1 : 1;
}

int factorial(int number)
{
    assert(0 <= number && number <= 12 && "Invalid factorial"); // prevent overflow
    int fac = 1;
    for (int i = 2; i <= number; ++i)
        fac *= i;
    return fac;
}

auto getProperDivisors(int number) -> std::vector<int>
{
    if (number == 1)
        return {};

    std::vector<int> properDivisors = { 1 };

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            properDivisors.push_back(number / i);

            if (number != i * i)
                properDivisors.push_back(i);
        }    
    }

    return properDivisors;
}

auto getDivisors(int number) -> std::vector<int>
{
    auto divisors = getProperDivisors(number);
    divisors.push_back(number);
    return divisors;
}

int sumProperDivisors(int number)
{
    auto properDivisors = getProperDivisors(number);
    return std::accumulate(properDivisors.begin(), properDivisors.end(), 0);
}

bool isAbundant(int number)
{
    return number < sumProperDivisors(number);
}

bool isPrime(int number)
{
    if (number == 2)
        return true;

    if (number < 2 || number % 2 == 0)
        return false;

    for (int div = 3; div * div <= number; div += 2)
    {
        if (number % div == 0)
            return false;
    }

    return true;
}

auto getPrimeFactors(int number) -> std::vector<int>
{
    std::vector<int> factors;

    while (number % 2 == 0)
    {
        factors.push_back(2);
        number /= 2;
    }

    for (int div = 3; div * div <= number; div += 2)
    {
        while (number % div == 0)
        {
            factors.push_back(div);
            number /= div;
        }
    }

    if (number != 1)
        factors.push_back(number);

    return factors;
}

int countDistinctFactors(int number)
{
    auto factors = getPrimeFactors(number);
    assert(std::is_sorted(factors.begin(), factors.end()) && "Unsorted factors");
    return static_cast<int>(std::unique(factors.begin(), factors.end()) - factors.begin());
}

auto sieveOfEratosthenes(int limit) -> std::vector<int>
{
    if (limit < 2)
        return {};

    std::vector<bool> primeCheck(limit + 1, true);
    std::vector<int> primes;

    primes.push_back(2);
    for (int i = 4; i <= limit; i += 2)
        primeCheck[i] = false;

    for (int i = 3; i * i <= limit; i += 2)
    {
        if (primeCheck[i])
        {
            for (int j = i * i; j <= limit; j += i)
                primeCheck[j] = false;
        }
    }

    for (int i = 3; i <= limit; i += 2)
    {
        if (primeCheck[i])
            primes.push_back(i);
    }

    return primes;
}

// Number stays prime during cyclic rotation of the digits.
bool isCircularPrime(int number)
{
    int digitCnt = 0;
    int n = number;

    while (n > 0)
    {
        int digit = n % 10;
        if (digitCnt > 0 && digit != 1 && digit != 3 && digit != 7 && digit != 9)
            return false;

        ++digitCnt;
        n /= 10;
    }

    const int rank = static_cast<int>(std::pow(10, digitCnt)) / 10;
    n = number;

    while (isPrime(n))
    {
        n = n % 10 * rank + n / 10;

        if (n == number)
            return true;
    }

    return false;
}

// Number stays prime when removing leading (left) digits.
bool isLeftTruncatablePrime(int number)
{
    if (number < 2)
        return false;

    for (int i = number; i > 0; i /= 10)
    {
        if (i % 10 == 0)
            return false;
    }

    const int rank = static_cast<int>(std::pow(10, countDigits(number)));
    for (int i = rank; i > 1; i /= 10)
    {
        if (!isPrime(number % i))
            return false;
    }

    return true;
}

// Number stays prime when removing last (right) digits.
bool isRightTruncatablePrime(int number)
{
    if (number < 2)
        return false;

    while (number > 0)
    {
        if (!isPrime(number))
            return false;
        
        number /= 10;
    }

    return true;
}

bool isTruncatablePrime(int number)
{
    return isLeftTruncatablePrime(number) && isRightTruncatablePrime(number);
}

bool isTriangular(unsigned long long number)
{
    double n = (std::sqrt(8 * number + 1) - 1) / 2;
    return n == static_cast<int>(n);
}

bool isPentagonal(unsigned long long number)
{
    double n = (std::sqrt(24 * number + 1) + 1) / 6;
    return n == static_cast<int>(n);
}

bool isPalindrome(int number, int base)
{
    int reversed = 0;
    int n = number;

    while (n > 0)
    {
        reversed = base * reversed + n % base;
        n /= base;
    }

    return number == reversed;
}

bool isPermutation(int number1, int number2)
{
    std::array<int, 10> digits{};

    while (number1 > 0)
    {
        ++digits[number1 % 10];
        number1 /= 10;
    }

    while (number2 > 0)
    {
        --digits[number2 % 10];
        number2 /= 10;
    }

    return std::all_of(digits.begin(), digits.end(), [](int n) { return n == 0; });
}

// Number is n-pandigital if it contains each digit from 1 to n exactly once.
bool isPandigital(int number, int maxDigit)
{
    if (countDigits(number) != maxDigit)
        return false;

    std::array<int, 10> digits{};

    while (number > 0)
    {
        ++digits[number % 10];
        number /= 10;
    }

    return std::count(digits.begin() + 1, digits.begin() + maxDigit + 1, 1) == maxDigit;
}

int concat(int number1, int number2)
{
    int rank = 1;

    while (rank <= number2)
        rank *= 10;

    return rank * number1 + number2;
}

} // namespace math
