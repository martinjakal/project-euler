#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 69
// https://projecteuler.net/problem=69
// Totient maximum
// Result: 510510

using namespace math;

// Euler's totient function is used: phi(n) = n * product (1 - 1 / p), where p is a prime which divides n.
// To maximize n / phi(n), the product of primes must be maximized.
int findNumberWithMaxTotient(int limit)
{
    int totient = 1;

    for (int number = 2; totient * number <= limit; ++number)
    {
        if (isPrime(number))
            totient *= number;
    }

    return totient;
}

int main()
{
    int limit = 1'000'000;

    auto result = findNumberWithMaxTotient(limit);
    std::cout << result << std::endl;

    return 0;
}
