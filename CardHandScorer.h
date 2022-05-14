#ifndef POKER_CARDHANDSCORER_H
#define POKER_CARDHANDSCORER_H

#include "CardHand.h"
#include "PokerScore.h"
#include "PokerCombo.h"
#include <vector>
class CardHandScorer {
public:
    static PokerScore scorePokerHand(CardHand& hand);
};



#endif //POKER_CARDHANDSCORER_H
