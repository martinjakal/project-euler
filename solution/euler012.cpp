#include <iostream>

// Project Euler - Problem 12
// https://projecteuler.net/problem=12
// Highly divisible triangular number
// Result: 76576500

int divisorsCount(int number)
{
	int divisors = 0;

	for (int i = 2; i * i <= number; ++i)
	{
		if (number % i == 0)
			divisors += 2;

		if (i * i == number)
			--divisors;
	}

	return divisors;
}

int firstTriangleNumWithDivisors(int divisors)
{
	for (int i = 1; ; ++i)
	{
		int triangle = i * (i + 1) / 2;

		if (divisorsCount(triangle) > divisors)
			return triangle;
	}
}

int main()
{
	int divisors = 500;
	auto result = firstTriangleNumWithDivisors(divisors);
	std::cout << result << std::endl;

	return 0;
}
