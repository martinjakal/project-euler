#include <iostream>

// Project Euler - Problem 15
// https://projecteuler.net/problem=15
// Lattice paths
// Result: 137846528820

// Both directions occur n times in square grid with size n, that is (2n n) combinations.
unsigned long long countLatticePathsInSquareGrid(int gridSize)
{
    unsigned long long paths = 1;

    for (unsigned long long i = 1; i <= gridSize; ++i)
    {
        paths *= i + gridSize;
        paths /= i;
    }

    return paths;
}

int main()
{
    int gridSize = 20;
    auto result = countLatticePathsInSquareGrid(gridSize);
    std::cout << result << std::endl;

    return 0;
}
