#include "PokerGame.h"

void PokerGame::Init(int iters) {
    window = new sf::RenderWindow(sf::VideoMode(w, h), title,  sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    for(int i=PokerScore::ROYAL_FLUSH;i<=PokerScore::HIGH_CARD;i++){
        freq[i].first = static_cast<PokerScore::Scores>(i);
        freq[i].second=0;
    }

    for(int x=0;x<iters;x++){
        Deck deck;
        CardHand cardHand[5];
        for(int i=0;i<5;i++) {
            for (int j = 0; j < 5; j++) {
                cardHand[i].putCard(deck.dealCard());
            }
        }
        pokerScore = CardHandScorer::scorePokerHand(cardHand[0]);
        for(int i=0;i<pokerScore.size();i++){
            freq[pokerScore[i]].second+=1;
        }
    }
}

void PokerGame::PrintCombos() {
    std::string scores[10] = {"ROYAL_FLUSH", "STRAIGHT_FLUSH", "FOUR_OF_A_KIND",
                              "FULL_HOUSE", "FLUSH", "STRAIGHT",
                              "THREE_OF_A_KIND", "TWO_PAIR", "ONE_PAIR",
                              "HIGH_CARD"};
    for(auto& item: freq){
        std::cout<<scores[item.first]<<" occurred "<<item.second<<" times\n";
    }
}

void PokerGame::RenderCombos() {
    getOccurences();
    game.occurences(occurences);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        window->clear(sf::Color::Green);
        game.draw(*window);
        window->display();
    }
}
void PokerGame::getOccurences() {
    for(int i=0;i<10;i++){
        occurences[i] = freq[i].second;
    }

}

PokerGame::~PokerGame() {
    delete window;
}
