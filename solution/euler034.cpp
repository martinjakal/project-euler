#include <iostream>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 34
// https://projecteuler.net/problem=34
// Digit factorials
// Result: 40730

using namespace math;

int digitFactorial(int number, const std::vector<int>& factorial)
{
    int sum = 0;

    while (number > 9)
    {
        sum += factorial[number % 10];
        number /= 10;
    }

    return sum + factorial[number];
}

// Adding extra digit (assume it is a 9) is equal to: lhs * 10 + 9, rhs + 9!.
// Lhs grows faster and becames greater than rhs at 7 digits.
// The upper bound for the number becomes 7 * 9! = 2540160.
int sumDigitFactorials()
{
    const int limit = 2540160;
    int sum = 0;
    std::vector<int> factorialStore;
    for (int i = 0; i < 10; ++i)
        factorialStore.push_back(factorial(i));

    for (int i = 3; i < limit; ++i)
    {
        if (digitFactorial(i, factorialStore) == i)
            sum += i;
    }

    return sum;
}

int main()
{
    auto result = sumDigitFactorials();
    std::cout << result << std::endl;

    return 0;
}
