#include <iostream>
#include <vector>

// Project Euler - Problem 26
// https://projecteuler.net/problem=26
// Reciprocal cycles
// Result: 983

int findNumberWithMaxRecurringCycle(int limit)
{
    int maxLength = 0;
    int number = 0;

    for (int n = 2; n < limit; ++n)
    {
        std::vector<int> remainders;
        int base = 10 % n;

        // The cycle continues as long as new remainders are found.
        while (base != 0 && std::find(remainders.begin(), remainders.end(), base) == remainders.end())
        {
            remainders.push_back(base);
            base = base * 10 % n;
        }

        int length = static_cast<int>(remainders.size());

        if (length > maxLength)
        {
            maxLength = length;
            number = n;
        }
    }

    return number;
}

int main()
{
    int limit = 1000;

    auto result = findNumberWithMaxRecurringCycle(limit);
    std::cout << result << std::endl;

    return 0;
}
