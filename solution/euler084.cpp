#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Project Euler - Problem 84
// https://projecteuler.net/problem=84
// Monopoly odds
// Result: 101524

class Monopoly
{
public:
    Monopoly(int dice) : dice_(dice) { prepareBoard(); }

    int analyzeDiceRolls()
    {
        int pos = go_;
        int doubles = 0;

        for (int i = 0; i < maxIteration_; ++i)
        {
            int roll1 = (std::rand() % dice_) + 1;
            int roll2 = (std::rand() % dice_) + 1;

            pos = (pos + roll1 + roll2) % squares_;

            if (roll1 == roll2)
                ++doubles;
            else
                doubles = 0;

            if (doubles == 3)
            {
                pos = jail_;
                doubles = 0;
            }
            else
            {
                if (pos == 7 || pos == 22 || pos == 36)
                    pos = chance(pos);

                if (pos == 2 || pos == 17 || pos == 33)
                    pos = communityChest(pos);

                if (pos == goToJail_)
                    pos = jail_;
            }

            ++board_[pos];
        }

        std::vector<std::pair<int, int>> visitedSquares;
        for (int i = 0; i < board_.size(); ++i)
            visitedSquares.emplace_back(i, board_[i]);
        std::sort(visitedSquares.begin(), visitedSquares.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) 
            { return a.second > b.second; });

        return visitedSquares[0].first * 10000 + visitedSquares[1].first * 100 + visitedSquares[2].first;
    }

private:
    std::random_device rd_;
    const int maxIteration_ = 10'000'000;
    const int dice_;
    const int squares_ = 40;
    std::vector<int> board_;

    std::vector<int> communityChest_;
    std::vector<int> chance_;

    const int go_ = 0;
    const int jail_ = 10;
    const int goToJail_ = 30;

    void prepareBoard()
    {
        board_.resize(squares_);

        for (int i = 0; i < 16; ++i)
        {
            communityChest_.push_back(i);
            chance_.push_back(i);
        }

        std::shuffle(communityChest_.begin(), communityChest_.end(), rd_);
        std::shuffle(chance_.begin(), chance_.end(), rd_);
    }

    int communityChest(int pos)
    {
        int i = communityChest_.front();
        std::rotate(communityChest_.begin(), communityChest_.begin() + 1, communityChest_.end());

        return i == 1 ? go_ : i == 2 ? jail_ : pos;
    }

    int chance(int pos)
    {
        int i = chance_.front();
        std::rotate(chance_.begin(), chance_.begin() + 1, chance_.end());

        return i == 1 ? go_ : i == 2 ? jail_ : i == 3 ? 11 : i == 4 ? 24 : i == 5 ? 39 : i == 6 ? 5 : 
            i == 7 ? nextRailway(pos) : i == 8 ? nextRailway(pos) : i == 9 ? nextUtility(pos) : 
            i == 10 ? (pos - 3) % squares_ : pos;
    }

    int nextRailway(int pos) const
    {
        return 5 <= pos && pos < 15 ? 15 :
            15 <= pos && pos < 25 ? 25 :
            25 <= pos && pos < 35 ? 35 : 5;
    }

    int nextUtility(int pos) const
    {
        return 12 <= pos && pos < 28 ? 28 : 12;
    }
};

int main()
{
    int size = 4;
    auto result = Monopoly(size).analyzeDiceRolls();
    std::cout << result << std::endl;

    return 0;
}
