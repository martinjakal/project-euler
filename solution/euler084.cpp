#include <algorithm>
#include <iostream>
#include <random>
#include <string>
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
    auto analyzeDiceRolls() -> std::string
    {
        initGame();
        std::vector<int> board(squares_);

        for (int roll = 0; roll < maxRolls_; ++roll)
        {
            diceRoll();
            ++board[position_];
        }

        std::vector<std::pair<int, int>> visitedSquares;
        for (int i = 0; i < board.size(); ++i)
            visitedSquares.emplace_back(i, board[i]);

        std::sort(visitedSquares.begin(), visitedSquares.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            { return a.second > b.second; });

        return str(visitedSquares[0].first) + str(visitedSquares[1].first) + str(visitedSquares[2].first);
    }

private:
    const int maxRolls_ = 10'000'000;
    const int squares_ = 40;
    const int dice_;

    std::random_device rd_;
    std::vector<int> communityChest_;
    std::vector<int> chance_;

    static constexpr int GO = 0;
    static constexpr int JAIL = 10;
    static constexpr int GO_TO_JAIL = 30;

    int position_ = GO;
    int doubles_ = 0;

    auto str(int value) const -> std::string
    {
        return (value < 10 ? "0" : "") + std::to_string(value);
    }

    void initGame()
    {
        communityChest_.clear();
        chance_.clear();

        position_ = GO;
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
            position_ = JAIL;
            doubles_ = 0;
        }
        else
        {
            position_ = (position_ + roll1 + roll2) % squares_;

            if (position_ == 7 || position_ == 22 || position_ == 36)
                applyChance();

            if (position_ == 2 || position_ == 17 || position_ == 33)
                applyCommunityChest();

            if (position_ == GO_TO_JAIL)
                position_ = JAIL;
        }
    }

    void applyCommunityChest()
    {
        int cc = communityChest_.front();
        std::rotate(communityChest_.begin(), communityChest_.begin() + 1, communityChest_.end());

        position_ = cc == 1 ? GO :
                    cc == 2 ? JAIL :
                    position_;
    }

    void applyChance()
    {
        int ch = chance_.front();
        std::rotate(chance_.begin(), chance_.begin() + 1, chance_.end());

        position_ = ch == 1 ? GO :
                    ch == 2 ? JAIL :
                    ch == 3 ? 11 :
                    ch == 4 ? 24 :
                    ch == 5 ? 39 :
                    ch == 6 ? 5 :
                    ch == 7 ? nextRailway() :
                    ch == 8 ? nextRailway() :
                    ch == 9 ? nextUtility() :
                    ch == 10 ? (position_ - 3) % squares_ : // 3 steps back
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
