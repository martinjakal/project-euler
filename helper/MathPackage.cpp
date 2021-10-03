#include "MathPackage.hpp"

#include <sstream>

namespace math 
{
int factorial(int number)
{
    return number == 0 ? 1 : number * factorial(number - 1);
}

int countDistinctFactors(int number)
{
    int factorCnt = 0;

    if (number % 2 == 0)
    {
        ++factorCnt;
        while (number % 2 == 0)
            number /= 2;
    }

    for (int i = 3; i * i <= number; i += 2)
    {
        if (number % i == 0)
        {
            ++factorCnt;
            while (number % i == 0)
                number /= i;
        }
    }

    return number != 1 ? ++factorCnt : factorCnt;
}

int sumProperDivisors(int number)
{
    int sum = 1;

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
            sum += i + number / i;

        if (number == i * i)
            sum -= i;
    }

    return sum;
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

// Number stays prime during cyclic rotation of the digits.
bool isCircularPrime(int number)
{
    int digitCnt = 0;
    int n = number;

    for (; n > 0; n /= 10)
    {
        if (digitCnt > 0 && n % 10 != 1 && n % 10 != 3 && n % 10 != 7 && n % 10 != 9)
            return false;

        ++digitCnt;
    }

    const int rank = static_cast<int>(pow(10, digitCnt)) / 10;
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

    for (int i = static_cast<int>(pow(10, ceil(log10(number)))); i > 1; i /= 10)
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

    for (; number > 0; number /= 10)
    {
        if (!isPrime(number))
            return false;
    }

    return true;
}

bool isTruncatablePrime(int number)
{
    return isLeftTruncatablePrime(number) && isRightTruncatablePrime(number);
}

auto primeFactors(int number) -> std::vector<int>
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

    if (number > 2)
        factors.push_back(number);

    return factors;
}

auto sieveOfEratosthenes(int limit) -> std::vector<int>
{
    std::vector<bool> primeCheck(limit + 1, true);
    std::vector<int> primes;

    for (int i = 2; i * i <= limit; ++i)
    {
        if (primeCheck[i])
        {
            for (int j = i * i; j <= limit; j += i)
                primeCheck[j] = false;
        }
    }

    for (int i = 2; i <= limit; ++i)
    {
        if (primeCheck[i])
            primes.push_back(i);
    }

    return primes;
}

bool isTriangular(unsigned long long number)
{
    double n = (sqrt(8 * number + 1) - 1) / 2;
    return n == static_cast<int>(n);
}

bool isPentagonal(unsigned long long number)
{
    double n = (sqrt(24 * number + 1) + 1) / 6;
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
    std::vector<int> digits(10, 0);

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

    return std::count(digits.begin(), digits.end(), 0) == digits.size();
}

// Number is n-pandigital if it contains each digit from 1 to n exactly once.
bool isPandigital(int number, int maxDigit)
{
    if (maxDigit > 9)
        throw std::runtime_error("Invalid max digit");

    if (ceil(log10(number)) != maxDigit)
        return false;

    std::vector<int> digits(10, 0);

    for (; number > 0; number /= 10)
        ++digits[number % 10];

    return std::count(digits.begin() + 1, digits.begin() + maxDigit + 1, 1) == maxDigit;
}
} // namespace math
