#include "Card.h"

std::string Card::getSuit() {
    return suit;
}

std::string Card::getRank() {
    return rank;
}

std::ostream &operator<<(std::ostream &out, const Card &card) {
    return out <<card.rank<<" of "<<card.suit;
}

Card::Card(std::string suit, std::string value) {
    this->suit = suit;
    rank = value;
}

Card::Card() {
    suit="";
    rank="";
}

void Card::setRank(ranks value){
    rank = value;
}

void Card::setSuit(suits suit){
    this->suit = suit;
}
