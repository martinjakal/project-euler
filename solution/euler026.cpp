#include <iostream>
#include <vector>

// Project Euler - Problem 26
// https://projecteuler.net/problem=26
// Reciprocal cycles
// Result: 983

int numWithMaxRecurringCycle(int limit)
{
    int maxNumber = 0;
    int maxLength = 0;

    for (int number = 2; number < limit; ++number)
    {
        std::vector<int> remainders;
        int length = 0;
        int base = 10 % number;

        while (base != 0 && std::find(remainders.begin(), remainders.end(), base) == remainders.end())
        {
            ++length;
            remainders.push_back(base);
            base = base * 10 % number;
        }

        if (length > maxLength)
        {
            maxLength = length;
            maxNumber = number;
        }
    }

    return maxNumber;
}

int main()
{
    int limit = 1000;
    auto result = numWithMaxRecurringCycle(limit);
    std::cout << result << std::endl;

    return 0;
}
