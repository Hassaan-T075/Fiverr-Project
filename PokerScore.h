#ifndef POKER_POKERSCORE_H
#define POKER_POKERSCORE_H


#include <vector>
#include "iostream"
class PokerScore {

public:
    enum Scores{
        ROYAL_FLUSH,
        STRAIGHT_FLUSH,
        FOUR_OF_A_KIND,
        FULL_HOUSE,
        FLUSH,
        STRAIGHT,
        THREE_OF_A_KIND,
        TWO_PAIR,
        ONE_PAIR,
        HIGH_CARD
    };
    void operator+=(const Scores& score);
    Scores& operator[](unsigned  int index);
    friend bool operator==( PokerScore& p, Scores score);

    int size();

private:

    std::vector<Scores> scores;
};



#endif //POKER_POKERSCORE_H
