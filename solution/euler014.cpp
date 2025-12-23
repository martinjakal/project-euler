#include <iostream>
#include <vector>

// Project Euler - Problem 14
// https://projecteuler.net/problem=14
// Longest Collatz sequence
// Result: 837799

int findLongestCollatzSequence(int limit)
{
    std::vector<int> seqLengthCache(limit + 1, 1);
    int maxSeqLength = 0;
    int bestNumber = 0;

    for (int i = 1; i < limit; ++i)
    {
        unsigned long long number = i;

        while (number != 1)
        {
            if (number % 2 == 0)
                number /= 2;
            else
                number = 3 * number + 1;

            if (number < static_cast<unsigned long long>(i))  // sequence length for smaller terms is precalculated
            {
                seqLengthCache[i] += seqLengthCache[static_cast<int>(number)];
                break;
            }
            else
                ++seqLengthCache[i];
        }

        if (seqLengthCache[i] > maxSeqLength)
        {
            maxSeqLength = seqLengthCache[i];
            bestNumber = i;
        }
    }

    return bestNumber;
}

int main()
{
    int limit = 1'000'000;

    auto result = findLongestCollatzSequence(limit);
    std::cout << result << std::endl;

    return 0;
}
