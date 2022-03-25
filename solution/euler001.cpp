#include <iostream>

// Project Euler - Problem 1
// https://projecteuler.net/problem=1
// Multiples of 3 and 5
// Result: 233168

int sumMultiples(int multiple, int limit)
{
    int last = (limit - 1) / multiple;
    return multiple * last * (last + 1) / 2;
}

int sumMultiplesTwoNumbers(int num1, int num2, int limit)
{
    return sumMultiples(num1, limit) + sumMultiples(num2, limit) - sumMultiples(num1 * num2, limit);
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
