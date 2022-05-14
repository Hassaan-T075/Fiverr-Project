#include "CardHandScorer.h"

PokerScore CardHandScorer::scorePokerHand(CardHand &hand) {
    PokerScore pokerScore;
    PokerScore::Scores score;
    if(PokerCombo::isRoyalFlush(hand)){
        pokerScore+= PokerScore::ROYAL_FLUSH;
    }
    if(PokerCombo::isStraightFlush(hand)){
        pokerScore+= PokerScore::STRAIGHT_FLUSH;
    }
    if(PokerCombo::isFourofaKind(hand)){
        pokerScore+=  PokerScore::FOUR_OF_A_KIND;
    }
    if(PokerCombo::isFullHouse(hand)){
        pokerScore+= PokerScore::FULL_HOUSE;
    }
    if(PokerCombo::isFlush(hand)){
        pokerScore+=  PokerScore::FLUSH;
    }
    if(PokerCombo::isStraight(hand)){
        pokerScore+=  PokerScore::STRAIGHT;
    }
    if(PokerCombo::isThreeofaKind(hand)){
        pokerScore+=  PokerScore::THREE_OF_A_KIND;
    }
    if(PokerCombo::isTwoPair(hand)){
        pokerScore+=  PokerScore::TWO_PAIR;
    }
    if(PokerCombo::isPair(hand)){
        pokerScore+=  PokerScore::ONE_PAIR;
    }
    if(PokerCombo::isHighCard(hand)){
        pokerScore+=  PokerScore::HIGH_CARD;
    }
    return pokerScore;
}
