#include <iostream>

// Project Euler - Problem 2
// https://projecteuler.net/problem=2
// Even Fibonacci numbers
// Result: 4613732

int sumEvenFibonacci(int limit)
{
    int sum = 0;
    int fn = 0;
    int fn1 = 1;
    int fn2 = fn + fn1;

    while (fn2 <= limit)
    {
        if (fn2 % 2 == 0)
            sum += fn2;

        fn = fn1;
        fn1 = fn2;
        fn2 = fn + fn1;
    }

    return sum;
}

int main()
{
    int limit = 4000000;
    auto result = sumEvenFibonacci(limit);
    std::cout << result << std::endl;

    return 0;
}
