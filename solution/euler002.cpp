#include <iostream>

// Project Euler - Problem 2
// https://projecteuler.net/problem=2
// Even Fibonacci numbers
// Result: 4613732

int sumEvenFibonacci(int limit)
{
    int sum = 0;
    int f0 = 0;
    int f1 = 1;
    int f2 = 1;

    while (f2 < limit)
    {
        if (f2 % 2 == 0)
            sum += f2;

        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
    }

    return sum;
}

int main()
{
    int limit = 4'000'000;
    auto result = sumEvenFibonacci(limit);
    std::cout << result << std::endl;

    return 0;
}
