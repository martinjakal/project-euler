#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 54
// https://projecteuler.net/problem=54
// Poker hands
// Result: 376

using namespace reader;

class Card
{
public:
    Card(char rank, char suit) : suit_(suit) 
    {
        rank_ = rank == 'T' ? 10 : rank == 'J' ? 11 :
                rank == 'Q' ? 12 : rank == 'K' ? 13 :
                rank == 'A' ? 14 : rank - '0';
    }

    bool operator<(const Card& other) const
    {
        if (rank_ == other.rank_)
            return suit_ < other.suit_;

        return rank_ < other.rank_;
    }

    friend class Hand;

private:
    int rank_;
    char suit_;
};

class Hand
{
public:
    void drawCard(const Card& c)
    {
        cards_.push_back(c);

        if (fullHand())
            std::sort(cards_.begin(), cards_.end());
    }

    // A hand with 5 cards receives 11-digit score for easy comparison determined by poker rules. The first digit determines 
    // the rank of the hand. Following digits store necessary information to decide a winner if two hands tie (i.e. highest card).
    // For example, score 60805000000 means: 6 - full house, 08 - in three, 05 - in pair.
    auto calcScore() const -> std::string
    {
        if (!fullHand())
            throw std::runtime_error("Invalid poker hand");

        bool flush = sameSuit();
        bool straight = consecutive();

        if (straight && flush && cards_[0].rank_ == 10)
            return "90000000000";

        if (straight && flush)
            return "8" + str(cards_[4]) + "00000000";

        if (isFour(0))
            return "7" + str(cards_[0]) + str(cards_[4]) + "000000";
        if (isFour(1))
            return "7" + str(cards_[1]) + str(cards_[0]) + "000000";

        if (isThree(0) && isPair(3))
            return "6" + str(cards_[0]) + str(cards_[3]) + "000000";
        if (isThree(2) && isPair(0))
            return "6" + str(cards_[2]) + str(cards_[0]) + "000000";

        if (flush)
            return "5" + str(cards_[4]) + str(cards_[3]) + str(cards_[2]) + str(cards_[1]) + str(cards_[0]);

        if (straight)
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

    bool fullHand() const { return cards_.size() == 5; }
    bool isPair(int i) const { return cards_[i].rank_ == cards_[i + 1].rank_; }
    bool isThree(int i) const { return isPair(i) && isPair(i + 1); }
    bool isFour(int i) const { return isPair(i) && isThree(i + 1); }

    bool consecutive() const
    {
        for (int i = 0; i < cards_.size() - 1; ++i)
        {
            if (cards_[i].rank_ != cards_[i + 1].rank_ - 1)
                return false;
        }
        return true;
    }

    bool sameSuit() const
    {
        for (int i = 0; i < cards_.size() - 1; ++i)
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

        for (int i = 0; i < game.size(); ++i)
        {
            Card card(game[i][0], game[i][1]);
            i < 5 ? player1.drawCard(card) : player2.drawCard(card);
        }

        if (player1.calcScore() > player2.calcScore())
            ++firstPlayerWins;
    }

    return firstPlayerWins;
}

int main()
{
    std::string filename = "input/euler054input.txt";
    auto input = readCards(filename);
    auto result = countPokerWins(input);
    std::cout << result << std::endl;

    return 0;
}
