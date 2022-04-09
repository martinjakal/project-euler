#include <iostream>
#include <numeric>

// Project Euler - Problem 5
// https://projecteuler.net/problem=5
// Smallest multiple
// Result: 232792560

int findMinNumberDivisibleByRange(int maxDivisor)
{
    int number = 1;

    for (int div = 2; div <= maxDivisor; ++div)
        number = std::lcm(div, number);

    return number;
}

int main()
{
    int maxDivisor = 20;

    auto result = findMinNumberDivisibleByRange(maxDivisor);
    std::cout << result << std::endl;

    return 0;
}
