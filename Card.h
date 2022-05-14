#ifndef POKER_CARD_H
#define POKER_CARD_H

#include "suits_ranks.h"
#include <iostream>

class Card {
private:
    suits suit;
    ranks rank;
public:
    std::string getSuit();
    std::string getRank();
    void setSuit(suits suit);
    void setRank(ranks value);
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    Card(std::string suit, std::string value);
    Card();
};

#endif //POKER_CARD_H
