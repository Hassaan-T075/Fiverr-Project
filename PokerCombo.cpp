#include "PokerCombo.h"

int func(std::string& s);
void sort(std::vector <int>& v);

bool PokerCombo::isFlush(CardHand &hand) {
    auto handvec = hand.getHand();
    bool same=true;
    for(int i=0;i<4;i++){
        if(handvec[i].getSuit()!=handvec[i+1].getSuit()){
            same = false;
            break;
        }
    }
    return same;
}

bool PokerCombo::isFourofaKind(CardHand &hand) {
    std::vector <std::string> st;
    auto handvec = hand.getHand();
    std::vector <int> it;

    for(int i=0;i<5;i++)
    {
        auto srank = handvec[i].getRank();
        st.push_back(srank);
    }
    for(int i=0;i<5;i++)
    {
        it.push_back(func(st[i]));
    }
    sort(it);

    return (it[0]==it[1] && it[0]==it[2] && it[0]==it[3]) || (it[1]==it[2] && it[1]==it[3] && it[1]==it[4]) ;
}

bool PokerCombo::isThreeofaKind(CardHand &hand) {
    std::vector <std::string> st;
    auto handvec = hand.getHand();
    std::vector <int> it;

    for(int i=0;i<5;i++)
    {
        auto srank = handvec[i].getRank();
        st.push_back(srank);
    }
    for(int i=0;i<5;i++)
    {
        it.push_back(func(st[i]));
    }
    sort(it);

    return ((it[0]==it[1]&& it[0]==it[2]) || (it[1]==it[2] && it[1]==it[3]) || (it[2]==it[3] && it[2]==it[4]));

}

bool PokerCombo::isPair(CardHand &hand) {
    std::vector <std::string> st;
    auto handvec = hand.getHand();
    std::vector <int> it;

    for(int i=0;i<5;i++)
    {
        auto srank = handvec[i].getRank();
        st.push_back(srank);
    }
    for(int i=0;i<5;i++)
    {
        it.push_back(func(st[i]));
    }
    sort(it);

    if(it[0]==it[1] || it[1]==it[2] || it[2]==it[3] || it[3]==it[4] )
        return true;

    return false;
}

bool PokerCombo::isFullHouse(CardHand &hand) {

    std::vector <std::string> st;
    auto handvec = hand.getHand();
    std::vector <int> it;

    for(int i=0;i<5;i++)
    {
        auto srank = handvec[i].getRank();
        st.push_back(srank);
    }
    for(int i=0;i<5;i++)
    {
        it.push_back(func(st[i]));
    }
    sort(it);

    if((it[0]==it[1] && it[0]==it[2]) && it[3]==it[4])
        return true;
    else if(it[0]==it[1] && (it[2]==it[3] && it[2]==it[4]))
        return true;

    return false;

}

bool PokerCombo::isRoyalFlush(CardHand &hand) {

    std::vector <std::string> st;
    auto handvec = hand.getHand();
    std::vector <int> it;

    if(isFlush(hand)){
        //make temp vector
        for(int i=0;i<5;i++)
        {
            auto srank = handvec[i].getRank();
            st.push_back(srank);
        }
        for(int i=0;i<5;i++)
        {
            it.push_back(func(st[i]));
        }

        if(it[0]==14 && it[1]==13 && it[2]==12 && it[3]==11 && it[4]==10)
            return true;

        return false;

    }

    return false;
}

bool PokerCombo::isStraightFlush(CardHand &hand) {

    std::vector <std::string> st;
    auto handvec = hand.getHand();
    std::vector <int> it;
    if(isFlush(hand))
    {
        for(int i=0;i<5;i++)
        {
            auto srank = handvec[i].getRank();
            st.push_back(srank);
        }
        for(int i=0;i<5;i++)
        {
            it.push_back(func(st[i]));
        }
        sort(it);
        for(int i=0;i<4;i++)
        {
            if((it[i]-it[i+1]) != 1)
            {
                return false;
            }
        }
        return true;
    }


    return false;
}

bool PokerCombo::isStraight(CardHand &hand) {

    std::vector <std::string> st;
    auto shand = hand.getHand();
    std::vector <int> it;

    for(int i=0;i<5;i++)
    {
        auto srank = shand[i].getRank();
        st.push_back(srank);
    }
    for(int i=0;i<5;i++)
    {
        it.push_back(func(st[i]));
    }
    sort(it);
    for(int i=0;i<5;i++)
    {
        if((it[i]-it[i+1]) != 1)
        {
            return false;
        }
    }

    return true;
}

bool PokerCombo::isTwoPair(CardHand &hand) {
    std::vector <std::string> st;
    auto shand = hand.getHand();
    std::vector <int> it;

    for(int i=0;i<5;i++)
    {
        auto srank = shand[i].getRank();
        st.push_back(srank);
    }
    for(int i=0;i<5;i++)
    {
        it.push_back(func(st[i]));
    }
    sort(it);

    for(int i=0;i<4;i++){
        if(it[i]==it[i+1]) {
            i+=2;
            for (; i < 4; i++)
                if (it[i] == it[i + 1])
                    return true;
        }
    }

    return false;
}

bool PokerCombo::isHighCard(CardHand &hand) {

    if (!(isRoyalFlush(hand) || isStraightFlush(hand) || isFourofaKind(hand) || isFullHouse(hand) || isFlush(hand)
          || isStraight(hand) || isThreeofaKind(hand) || isTwoPair(hand) || isPair(hand)))
        return true;

    return false;
}

int func(std::string& s)
{
    if(s=="Ace")
        return 14;
    else if(s=="Queen")
        return 13;
    else if(s=="King")
        return 12;
    else if(s=="Jack")
        return 11;
    else if(s=="ten")
        return 10;
    else if(s=="nine")
        return 9;
    else if(s=="eight")
        return 8;
    else if(s=="seven")
        return 7;
    else if(s=="six")
        return 6;
    else if(s=="five")
        return 5;
    else if(s=="four")
        return 4;
    else if(s=="three")
        return 3;
    else if(s=="two")
        return 2;

}

void sort(std::vector <int>& v)
{
    int t;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<(4-i);j++)
        {
            if(v[j] <= v[j+1])
            {
                t= v[j];
                v[j]=v[j+1];
                v[j+1]=t;
            }
        }
    }
}