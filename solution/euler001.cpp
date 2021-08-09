#include <iostream>

// Project Euler - Problem 1
// https://projecteuler.net/problem=1
// Multiples of 3 and 5
// Result: 233168

int sumMultiples(int multiple, int limit)
{
    int sum = 0;

    for (int i = multiple; i < limit; i += multiple)
        sum += i;

    return sum;
}

int sumMultiplesTwoNumbers(int a, int b, int limit)
{
    return sumMultiples(a, limit) + sumMultiples(b, limit) - sumMultiples(a * b, limit);
}

int main()
{
    int number1 = 3;
    int number2 = 5;
    int limit = 1000;
    auto result = sumMultiplesTwoNumbers(number1, number2, limit);
    std::cout << result << std::endl;

    return 0;
}
