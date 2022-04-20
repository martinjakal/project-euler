#include <iostream>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 36
// https://projecteuler.net/problem=36
// Double-base palindromes
// Result: 872187

using namespace math;

int makePalindrome(int number, int base, bool isOdd)
{
    int palindrome = number;

    if (isOdd)
        number /= base;

    while (number > 0)
    {
        palindrome = base * palindrome + number % base;
        number /= base;
    }

    return palindrome;
}

// Generate palindromes and verify palindrome property in the other base.
// Odd and even numbers are generated differently.
int sumDoubleBasePalindromes(int limit)
{
    int sumPalindromes = 0;

    for (int i = 0; i < 2; ++i)
    {
        bool isOdd = i % 2 == 0;

        for (int number = 1; ; ++number)
        {
            int palindrome = makePalindrome(number, 10, isOdd);

            if (palindrome >= limit)
                break;

            if (isPalindrome(palindrome, 2))
                sumPalindromes += palindrome;
        }
    }

    return sumPalindromes;
}

int main()
{
    int limit = 1'000'000;

    auto result = sumDoubleBasePalindromes(limit);
    std::cout << result << std::endl;

    return 0;
}
