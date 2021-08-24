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
