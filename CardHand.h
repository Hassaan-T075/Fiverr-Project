#ifndef POKER_CARDHAND_H
#define POKER_CARDHAND_H

#include "Card.h"
#include "vector"
class CardHand {
private:
    std::vector<Card> hand;
public:
    void putCard(const Card& card);
    Card getCard(const int index);
    std::vector<Card> getHand();
};


#endif //POKER_CARDHAND_H
