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
    Node(int i, int j, int distance) : i(i), j(j), distance(distance) {}

    bool operator<(const Node& other) const
    {
        if (distance == other.distance)
            return i != other.i ? i < other.i : j < other.j;

        return distance < other.distance;
    }

    int i;
    int j;
    int distance;
};

// Implementation of Dijkstra's algorithm.
int minPathFourDirectionMatrix(const std::vector<std::vector<int>>& matrix)
{
    const std::size_t rows = matrix.size();
    const std::size_t cols = matrix[0].size();

    std::vector<std::vector<int>> distances(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
    distances[0][0] = matrix[0][0];

    const std::vector<std::pair<int, int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 },  { 0, 1 } };

    std::set<Node> remainingNodes;
    remainingNodes.insert(Node(0, 0, distances[0][0]));

    while (!remainingNodes.empty())
    {
        Node cur = *remainingNodes.begin();
        remainingNodes.erase(*remainingNodes.begin());

        for (const auto& dir : directions)
        {
            int nextI = cur.i + dir.first;
            int nextJ = cur.j + dir.second;

            if (nextI < 0 || nextI >= rows || nextJ < 0 || nextJ >= cols)
                continue;

            if (distances[cur.i][cur.j] + matrix[nextI][nextJ] < distances[nextI][nextJ])
            {
                if (distances[nextI][nextJ] != std::numeric_limits<int>::max()) // node is already visited
                    remainingNodes.erase(remainingNodes.find(Node(nextI, nextJ, distances[nextI][nextJ])));

                distances[nextI][nextJ] = distances[cur.i][cur.j] + matrix[nextI][nextJ];
                remainingNodes.insert(Node(nextI, nextJ, distances[nextI][nextJ]));
            }
        }
    }

    return distances.back().back();
}

int main()
{
    std::string filename = "input/euler083input.txt";
    auto input = readNumbers(filename, ',');
    auto result = minPathFourDirectionMatrix(input);
    std::cout << result << std::endl;

    return 0;
}
