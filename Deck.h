#ifndef POKER_DECK_H
#define POKER_DECK_H


#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include "Card.h"


class Deck {
private:
    const std::string RANKS[13] = {"two","three","four","five","six","seven","eight",
                                   "nine","ten","Jack","King","Queen","Ace"};
    const std::string SUITS[4] = {"Diamonds","Hearts","Spades","Clubs"};
public:
    bool empty();
    int cardIndex;
    int temp=0;

    Card deck[52];
    const int DECk_SIZE=52;
    void shuffle();
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
    void printDeck(Deck& deck);
    Card dealCard();
    Card getCardAt(int index);
    Deck();
};


#endif //POKER_DECK_H
