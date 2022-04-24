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
    Monopoly(int dice) : dice_(dice) {}

    // Simulate dice rolls and count square visits to obtain the three most visited squares.
    int analyzeDiceRolls()
    {
        initBoard();

        for (int i = 0; i < maxIteration_; ++i)
        {
            diceRoll();
            ++board_[position_];
        }

        std::vector<std::pair<int, int>> visitedSquares;
        for (int i = 0; i < board_.size(); ++i)
            visitedSquares.emplace_back(i, board_[i]);

        std::sort(visitedSquares.begin(), visitedSquares.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            { return a.second > b.second; });

        return visitedSquares[0].first * 10000 + visitedSquares[1].first * 100 + visitedSquares[2].first;
    }

private:
    const int maxIteration_ = 10'000'000;
    const int squares_ = 40;
    const int dice_;

    std::random_device rd_;
    std::vector<int> board_;
    std::vector<int> communityChest_;
    std::vector<int> chance_;

    const int go_ = 0;
    const int jail_ = 10;
    const int goToJail_ = 30;

    int position_ = go_;
    int doubles_ = 0;

    void initBoard()
    {
        board_.clear();
        communityChest_.clear();
        chance_.clear();

        board_.resize(squares_);
        position_ = go_;
        doubles_ = 0;

        for (int i = 0; i < 16; ++i)
        {
            communityChest_.push_back(i);
            chance_.push_back(i);
        }

        std::shuffle(communityChest_.begin(), communityChest_.end(), rd_);
        std::shuffle(chance_.begin(), chance_.end(), rd_);
    }

    void diceRoll()
    {
        const int roll1 = (std::rand() % dice_) + 1;
        const int roll2 = (std::rand() % dice_) + 1;

        if (roll1 == roll2)
            ++doubles_;
        else
            doubles_ = 0;

        if (doubles_ == 3)
        {
            position_ = jail_;
            doubles_ = 0;
        }
        else
        {
            position_ = (position_ + roll1 + roll2) % squares_;

            if (position_ == 7 || position_ == 22 || position_ == 36)
                applyChance();

            if (position_ == 2 || position_ == 17 || position_ == 33)
                applyCommunityChest();

            if (position_ == goToJail_)
                position_ = jail_;
        }
    }

    void applyCommunityChest()
    {
        int cc = communityChest_.front();
        std::rotate(communityChest_.begin(), communityChest_.begin() + 1, communityChest_.end());

        position_ = cc == 1 ? go_ :
                    cc == 2 ? jail_ :
                    position_;
    }

    void applyChance()
    {
        int ch = chance_.front();
        std::rotate(chance_.begin(), chance_.begin() + 1, chance_.end());

        position_ = ch == 1 ? go_ :
                    ch == 2 ? jail_ :
                    ch == 3 ? 11 :
                    ch == 4 ? 24 :
                    ch == 5 ? 39 :
                    ch == 6 ? 5 :
                    ch == 7 ? nextRailway() :
                    ch == 8 ? nextRailway() :
                    ch == 9 ? nextUtility() :
                    ch == 10 ? (position_ - 3) % squares_ :
                    position_;
    }

    int nextRailway() const
    {
        return 5 <= position_ && position_ < 15 ? 15 :
               15 <= position_ && position_ < 25 ? 25 :
               25 <= position_ && position_ < 35 ? 35 : 5;
    }

    int nextUtility() const
    {
        return 12 <= position_ && position_ < 28 ? 28 : 12;
    }
};

int main()
{
    int dice = 4;

    auto result = Monopoly(dice).analyzeDiceRolls();
    std::cout << result << std::endl;

    return 0;
}
