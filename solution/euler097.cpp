#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 97
// https://projecteuler.net/problem=97
// Large non-Mersenne prime
// Result: 8739992577

// Algorithm for fast computation of large positive integer powers of a number. 
// It is already used in BigInteger, but this implementation includes modulo.
auto expBySquaringWithMod(BigInteger base, int exponent, const BigInteger& mod) -> BigInteger
{
    BigInteger result = 1;

    while (exponent != 0)
    {
        if (exponent % 2 == 0)
        {
            base *= base;
            exponent /= 2;
            base %= mod;
        }
        else
        {
            result *= base;
            --exponent;
            result %= mod;
        }
    }

    return result;
}

auto nonMersennePrimeWithMod(int exponent, int multiplier, int lastDigits) -> BigInteger
{
    const BigInteger mod = static_cast<long long>(pow(10, lastDigits));
    return (expBySquaringWithMod(2, exponent, mod) * multiplier + 1) % mod;
}

int main()
{
    int exponent = 7830457;
    int multiplier = 28433;
    int lastDigits = 10;
    auto result = nonMersennePrimeWithMod(exponent, multiplier, lastDigits);
    std::cout << result << std::endl;

    return 0;
}
