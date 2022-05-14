#ifndef POKER_POKERCOMBO_H
#define POKER_POKERCOMBO_H

#include "PokerScore.h"
#include "CardHand.h"
class PokerCombo {
public:
    static bool isRoyalFlush(CardHand &hand);
    static bool isStraightFlush(CardHand &hand);
    static bool isFourofaKind(CardHand &hand);
    static bool isFullHouse(CardHand &hand);
    static bool isFlush(CardHand &hand);
    static bool isStraight(CardHand &hand);
    static bool isThreeofaKind(CardHand &hand);
    static bool isTwoPair(CardHand &hand);
    static bool isPair(CardHand &hand);
    static bool isHighCard(CardHand &hand);

};

#endif //POKER_POKERCOMBO_H
