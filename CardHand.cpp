#include "CardHand.h"

void CardHand::putCard(const Card &card) {
    hand.push_back(card);
}

Card CardHand::getCard(const int index) {
    return hand[index];
}

std::vector<Card> CardHand::getHand() {
    return hand;
}
