#include <iostream>
#include <vector>

// Project Euler - Problem 92
// https://projecteuler.net/problem=92
// Square digit chains
// Result: 8581146

int sumSquareDigits(int number)
{
    int sum = 0;

    while (number != 0)
    {
        int digit = number % 10;
        sum += digit * digit;
        number /= 10;
    }

    return sum;
}
 
int squareDigitChainsEndingAt89(int limit)
{
    const int maxSumSquareDigits = static_cast<int>(ceil(log10(limit - 1)) * pow(9, 2));
    std::vector<int> chainStore(maxSumSquareDigits + 1);
    int endAt89Count = 0;

    // Calculate all chain results for numbers below max possible sum of square digits 
    // which is obtained as number of digits * (9 ^ 2).
    for (int i = 1; i <= maxSumSquareDigits; ++i)
    {
        int number = i;

        while (number != 1 && number != 89)
            number = sumSquareDigits(number);

        chainStore[i] = number;
    }

    // Use cached results instead of calculating all chains.
    for (int i = 1; i < limit; ++i)
    {
        if (chainStore[sumSquareDigits(i)] == 89)
            ++endAt89Count;
    }

    return endAt89Count;
}

int main()
{
    int limit = 10000000;
    auto result = squareDigitChainsEndingAt89(limit);
    std::cout << result << std::endl;

    return 0;
}
