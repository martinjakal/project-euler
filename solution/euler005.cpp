#include <iostream>
#include <numeric>

// Project Euler - Problem 5
// https://projecteuler.net/problem=5
// Smallest multiple
// Result: 232792560

int minNumberDivisibleByRange(int maxDivisor)
{
    int number = 1;

    for (int div = 2; div <= maxDivisor; ++div)
        number = std::lcm(div, number);

    return number;
}

int main()
{
	int limit = 20;
	auto result = minNumberDivisibleByRange(limit);
	std::cout << result << std::endl;

	return 0;
}
