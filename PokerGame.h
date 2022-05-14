#ifndef POKER_POKERGAME_H
#define POKER_POKERGAME_H

#include "PokerScore.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include "Deck.h"
#include "SFML/Graphics.hpp"
#include "sfml.h"
#include <array>

class PokerGame {
private:
    PokerScore pokerScore;
    std::array<std::pair<PokerScore::Scores,int>,10> freq;
    sfml game;
    sf::RenderWindow* window;
    int w = sf::VideoMode::getDesktopMode().width, h = sf::VideoMode::getDesktopMode().height;
    int occurences[10];
    const char* title = "PokerGame";
    void getOccurences();

public:
    void Init(int iters); //iters-> how many times to run the loop and count combos
    void PrintCombos();
    void RenderCombos();
    ~PokerGame();

};

#endif //POKER_POKERGAME_H
