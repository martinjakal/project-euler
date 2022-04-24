#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 83
// https://projecteuler.net/problem=83
// Path sum: four ways
// Result: 425185

using namespace reader;

struct Node
{
    Node(int i, int j, int distance) : i_(i), j_(j), distance_(distance) {}

    bool operator<(const Node& other) const
    {
        if (distance_ == other.distance_)
            return i_ != other.i_ ? i_ < other.i_ : j_ < other.j_;

        return distance_ < other.distance_;
    }

    int i_;
    int j_;
    int distance_;
};

// Implementation of Dijkstra's algorithm.
int sumMinPathInFourDirectionMatrix(const std::vector<std::vector<int>>& matrix)
{
    const std::vector<std::pair<int, int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 },  { 0, 1 } };
    const std::size_t rows = matrix.size();
    const std::size_t cols = matrix[0].size();

    std::vector<std::vector<int>> distances(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
    distances[0][0] = matrix[0][0];

    std::set<Node> remainingNodes;
    remainingNodes.insert(Node(0, 0, distances[0][0]));

    while (!remainingNodes.empty())
    {
        Node cur = *remainingNodes.begin();
        remainingNodes.erase(*remainingNodes.begin());

        for (const auto& dir : directions)
        {
            int nextI = cur.i_ + dir.first;
            int nextJ = cur.j_ + dir.second;

            if (nextI < 0 || nextI >= rows || nextJ < 0 || nextJ >= cols)
                continue;

            int newDistance = distances[cur.i_][cur.j_] + matrix[nextI][nextJ];
            int& curDistance = distances[nextI][nextJ];

            if (newDistance < curDistance)
            {
                if (curDistance != std::numeric_limits<int>::max()) // node is already visited
                    remainingNodes.erase(remainingNodes.find(Node(nextI, nextJ, curDistance)));

                curDistance = newDistance;
                remainingNodes.insert(Node(nextI, nextJ, curDistance));
            }
        }
    }

    return distances.back().back();
}

int main()
{
    std::string filename = "input/euler083input.txt";

    auto input = readNumbers(filename, ',');
    auto result = sumMinPathInFourDirectionMatrix(input);
    std::cout << result << std::endl;

    return 0;
}
