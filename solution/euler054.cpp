#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 54
// https://projecteuler.net/problem=54
// Poker hands
// Result: 376

using namespace reader;

struct Card
{
    Card(char rank, char suit) : suit_(suit)
    {
        rank_ = rank == 'T' ? 10 : rank == 'J' ? 11 : rank == 'Q' ? 12 : rank == 'K' ? 13 : rank == 'A' ? 14 : rank - '0';
    }

    bool operator<(const Card& other) const
    {
        if (rank_ == other.rank_)
            return suit_ < other.suit_;

        return rank_ < other.rank_;
    }

    int rank_;
    char suit_;
};

class Hand
{
public:
    static constexpr std::size_t MAX_CARDS = 5;

    bool isHandFull() const { return cards_.size() == MAX_CARDS; }

    void drawCard(const Card& card)
    {
        if (!isHandFull())
        {
            cards_.push_back(card);
            std::sort(cards_.begin(), cards_.end());
        }
    }

    // A sorted hand with 5 cards is evaluated to obtain 11-digit score for easy comparison determined by poker rules.
    // The first digit determines the total rank of the hand. Following digits store necessary information
    // to decide a winner if two hands tie (i.e. highest card).
    // For example, score 60805000000 means: 6 - full house, 08 - three, 05 - pair.
    auto calcScore() const -> std::string
    {
        assert(isHandFull() && "Cannot calculate score because hand is not full");

        bool isFlush = sameSuit();
        bool isStraight = consecutive();

        if (isStraight && isFlush && cards_[0].rank_ == 10)
            return "90000000000";

        if (isStraight && isFlush)
            return "8" + str(cards_[4]) + "00000000";

        if (isFour(0))
            return "7" + str(cards_[0]) + str(cards_[4]) + "000000";
        if (isFour(1))
            return "7" + str(cards_[1]) + str(cards_[0]) + "000000";

        if (isThree(0) && isPair(3))
            return "6" + str(cards_[0]) + str(cards_[3]) + "000000";
        if (isThree(2) && isPair(0))
            return "6" + str(cards_[2]) + str(cards_[0]) + "000000";

        if (isFlush)
            return "5" + str(cards_[4]) + str(cards_[3]) + str(cards_[2]) + str(cards_[1]) + str(cards_[0]);

        if (isStraight)
            return "4" + str(cards_[4]) + "00000000";

        if (isThree(0))
            return "3" + str(cards_[0]) + str(cards_[4]) + str(cards_[3]) + "0000";
        if (isThree(1))
            return "3" + str(cards_[1]) + str(cards_[4]) + str(cards_[0]) + "0000";
        if (isThree(2))
            return "3" + str(cards_[2]) + str(cards_[1]) + str(cards_[0]) + "0000";

        if (isPair(0) && isPair(2))
            return "2" + str(cards_[2]) + str(cards_[0]) + str(cards_[4]) + "0000";
        if (isPair(0) && isPair(3))
            return "2" + str(cards_[3]) + str(cards_[0]) + str(cards_[2]) + "0000";
        if (isPair(1) && isPair(3))
            return "2" + str(cards_[3]) + str(cards_[1]) + str(cards_[0]) + "0000";

        if (isPair(0))
            return "1" + str(cards_[0]) + str(cards_[4]) + str(cards_[3]) + str(cards_[2]) + "00";
        if (isPair(1))
            return "1" + str(cards_[1]) + str(cards_[4]) + str(cards_[3]) + str(cards_[0]) + "00";
        if (isPair(2))
            return "1" + str(cards_[2]) + str(cards_[4]) + str(cards_[1]) + str(cards_[0]) + "00";
        if (isPair(3))
            return "1" + str(cards_[3]) + str(cards_[2]) + str(cards_[1]) + str(cards_[0]) + "00";

        return "0" + str(cards_[4]) + str(cards_[3]) + str(cards_[2]) + str(cards_[1]) + str(cards_[0]);
    }

private:
    std::vector<Card> cards_;

    auto str(const Card& card) const -> std::string { return (card.rank_ < 10 ? "0" : "") + std::to_string(card.rank_); }

    bool isPair(int i) const { return cards_[i].rank_ == cards_[i + 1].rank_; }

    bool isThree(int i) const { return isPair(i) && isPair(i + 1); }

    bool isFour(int i) const { return isPair(i) && isThree(i + 1); }

    bool consecutive() const
    {
        for (std::size_t i = 0; i < MAX_CARDS - 1; ++i)
        {
            if (cards_[i].rank_ != cards_[i + 1].rank_ - 1)
                return false;
        }
        return true;
    }

    bool sameSuit() const
    {
        for (std::size_t i = 0; i < MAX_CARDS - 1; ++i)
        {
            if (cards_[i].suit_ != cards_[i + 1].suit_)
                return false;
        }
        return true;
    }
};

int countPokerWins(const std::vector<std::vector<std::string>>& games)
{
    int firstPlayerWins = 0;

    for (const auto& game : games)
    {
        Hand player1;
        Hand player2;

        for (std::size_t i1 = 0, i2 = Hand::MAX_CARDS; i1 < Hand::MAX_CARDS; ++i1, ++i2)
        {
            player1.drawCard(Card(game[i1][0], game[i1][1]));
            player2.drawCard(Card(game[i2][0], game[i2][1]));
        }

        firstPlayerWins += player1.calcScore() > player2.calcScore();
    }

    return firstPlayerWins;
}

int main()
{
    std::string filename = "input/euler054input.txt";

    auto input = readStrings(filename, ' ');
    auto result = countPokerWins(input);
    std::cout << result << std::endl;

    return 0;
}
