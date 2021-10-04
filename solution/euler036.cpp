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

// Generate palindromes and verify palindrome property in other base too.
// Odd and even numbers are generated differently.
int sumDoubleBasePalindrome(int limit)
{
    int sum = 0;

    for (int i = 0; i < 2; ++i)
    {
        bool isOdd = i % 2;

        for (int number = 1; ; ++number)
        {
            int palindrome = makePalindrome(number, 10, isOdd);

            if (palindrome >= limit)
                break;

            if (isPalindrome(palindrome, 2))
                sum += palindrome;
        }
    }

    return sum;
}

int main()
{
    int limit = 1000000;
    auto result = sumDoubleBasePalindrome(limit);
    std::cout << result << std::endl;

    return 0;
}
