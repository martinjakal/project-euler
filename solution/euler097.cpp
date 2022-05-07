#include <cmath>
#include <iostream>

#include <helper/BigInteger.hpp>

// Project Euler - Problem 97
// https://projecteuler.net/problem=97
// Large non-Mersenne prime
// Result: 8739992577

// Algorithm for fast computation of large positive integer powers of a number with modulo.
auto expBySquaringWithMod(BigInteger base, BigInteger exponent, const BigInteger& mod) -> BigInteger
{
    BigInteger result = 1;

    while (exponent != 0)
    {
        if (exponent % 2 == 0)
        {
            base *= base;
            base %= mod;
            exponent /= 2;
        }
        else
        {
            result *= base;
            result %= mod;
            --exponent;
        }
    }

    return result;
}

auto findLastDigitsOfNonMersennePrime(int exponent, int multiplier, int lastDigits) -> BigInteger
{
    const BigInteger mod = static_cast<long long>(std::pow(10, lastDigits));
    return (expBySquaringWithMod(2, exponent, mod) * multiplier + 1) % mod;
}

int main()
{
    int exponent = 7'830'457;
    int multiplier = 28'433;
    int lastDigits = 10;

    auto result = findLastDigitsOfNonMersennePrime(exponent, multiplier, lastDigits);
    std::cout << result << std::endl;

    return 0;
}
