#include "PokerScore.h"

void PokerScore::operator+=(const PokerScore::Scores &score) {
    scores.push_back(score);
}

PokerScore::Scores& PokerScore::operator[](unsigned int index) {
    return scores[index];
}

int PokerScore::size() {
    return scores.size();
}

bool operator==(PokerScore &p, PokerScore::Scores score) {
    bool check = false;
    for(int i=0;i<p.size();i++){
        if(p[i]==score){
            check = true;
            break;
        }
    }
    return check;

}


