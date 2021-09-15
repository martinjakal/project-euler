#include "Primes.hpp"

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
