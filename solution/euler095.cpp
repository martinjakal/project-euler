#include <iostream>
#include <vector>

// Project Euler - Problem 95
// https://projecteuler.net/problem=95
// Amicable chains
// Result: 14316

int maxAmicableChain(int limit)
{
    // Precalculate the sums of proper divisors.
    std::vector<int> sumProperDivisors(limit + 1, 1);
    for (int i = 2; i <= (limit + 1) / 2; ++i)
    {
        for (int j = i * 2; j <= limit; j += i)
            sumProperDivisors[j] += i;
    }

    int maxLength = 0;
    int minNumber = 0;

    for (int i = 1; i <= limit; ++i)
    {
        std::vector<int> chain = { i };
        int length = 1;
        bool validChain = true;

        for (int number = sumProperDivisors[i]; number != i; number = sumProperDivisors[number])
        {
            // If the current number is already in the chain, there is a loop which never goes back to the starting number.
            if (number > limit || std::find(chain.begin(), chain.end(), number) != chain.end())
            {
                validChain = false;
                break;
            }

            chain.push_back(number);
            ++length;
        } 

        if (validChain && length > maxLength)
        {
            maxLength = length;
            minNumber = i;
        }
    }
    
    return minNumber;
}

int main()
{
    int limit = 1000000;
    auto result = maxAmicableChain(limit); 
    std::cout << result << std::endl;
    
    return 0;
}
