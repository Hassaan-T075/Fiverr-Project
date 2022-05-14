#include "PokerGame.h"

int main() {

    PokerGame Poker;
    Poker.Init(1000);
    Poker.PrintCombos();
    Poker.RenderCombos();

    return 0;
}
