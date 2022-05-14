#include "Deck.h"

bool Deck::empty()
{
    temp++;
    if(temp > 52)
        return false;
    else
        return true;
}

void Deck::shuffle()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            int r = rand() % 52;
            Card c = deck[j];
            deck[j] = deck[r];
            deck[r] = c;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Deck &deck)
{
    for(int i=0;i<52;i++){
        out<<deck.deck[i]<<"\n";
    }
    return out;
}

void Deck::printDeck(Deck& deck)
{
    //Deck deck;
    std::cout<<deck;
}

Card Deck::getCardAt(int index)
{
    return deck[index];
}

Card Deck::dealCard()
{

    cardIndex++;

    return deck[cardIndex-1];
}

Deck::Deck()
{
    cardIndex = 0;
    int index = 0;
    for(int s=0;s<4;s++)
    {
        for(int r=0;r<13;r++)
        {
            deck[index] = Card(SUITS[s],RANKS[r]);
            index++;
        }
    }
    shuffle();
}