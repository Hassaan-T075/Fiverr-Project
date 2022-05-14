#include "sfml.h"

sfml::sfml()
{
    texture[0].loadFromFile("../sprites/royalflush1.png");
    texture[1].loadFromFile("../sprites/straightflush.png");
    texture[2].loadFromFile("../sprites/fourofakind.png");
    texture[3].loadFromFile("../sprites/fullhouse1.png");
    texture[4].loadFromFile("../sprites/threeofakind.png");
    texture[5].loadFromFile("../sprites/straight.png");
    texture[6].loadFromFile("../sprites/flush.png");
    texture[7].loadFromFile("../sprites/twopair.png");
    texture[8].loadFromFile("../sprites/onepair.png");
    texture[9].loadFromFile("../sprites/highcard.png");

    for (int i = 0; i < 10; i++)
        texture[i].setSmooth(true);

    for (int i = 0; i < 10; i++)
        sprite[i].setTexture(texture[i]);

    sprite[0].scale(sf::Vector2f(0.4f, 0.4f));
    sprite[1].scale(sf::Vector2f(0.3f, 0.3f));
    sprite[2].scale(sf::Vector2f(0.3f, 0.3f));
    sprite[3].scale(sf::Vector2f(0.4f, 0.4f));
    sprite[4].scale(sf::Vector2f(0.35f, 0.35f));
    sprite[5].scale(sf::Vector2f(0.3f, 0.3f));
    sprite[6].scale(sf::Vector2f(0.3f, 0.3f));
    sprite[7].scale(sf::Vector2f(0.6f, 0.6f));
    sprite[8].scale(sf::Vector2f(0.3f, 0.3f));
    sprite[9].scale(sf::Vector2f(0.25f, 0.25f));

    sprite[0].setPosition(sf::Vector2f(w / 14, h / 22));
    sprite[1].setPosition(sf::Vector2f(w / 3.4, h / 22));
    sprite[2].setPosition(sf::Vector2f(w / 1.95, h / 22));
    sprite[3].setPosition(sf::Vector2f(w / 1.35, h / 22));

    sprite[4].setPosition(sf::Vector2f(w / 14, h / 2.56));
    sprite[5].setPosition(sf::Vector2f(w / 3.4, h / 2.56));
    sprite[6].setPosition(sf::Vector2f(w / 1.95, h / 2.56));
    sprite[7].setPosition(sf::Vector2f(w / 1.35, h / 2.56));

    sprite[8].setPosition(sf::Vector2f(w / 3.42, h / 1.39));
    sprite[9].setPosition(sf::Vector2f(w / 1.91, h / 1.4));

    font.loadFromFile("../sprites/arial.ttf");

    for (int i = 0; i < 10; i++)
    {
        text[i].setFont(font);
        text[i].setFillColor(sf::Color::White);
        occur[i].setFont(font);
        occur[i].setFillColor(sf::Color::Black);
    }

    text[0].setString("Royal Flush");
    text[1].setString("Straight Flush");
    text[2].setString("Four of a Kind");
    text[3].setString("Full House");
    text[4].setString("Three of a Kind");
    text[5].setString("Straight");
    text[6].setString("Flush");
    text[7].setString("Two Pair");
    text[8].setString("One Pair");
    text[9].setString("High Card");

    text[0].setPosition(sf::Vector2f(w / 9.12, h / 3.5));
    text[1].setPosition(sf::Vector2f(w / 3.25, h / 3.5));
    text[2].setPosition(sf::Vector2f(w / 1.9, h / 3.5));
    text[3].setPosition(sf::Vector2f(w / 1.3, h / 3.5));

    text[4].setPosition(sf::Vector2f(w / 13, h / 1.56));
    text[5].setPosition(sf::Vector2f(w / 3.04, h / 1.56));
    text[6].setPosition(sf::Vector2f(w / 1.77, h / 1.56));
    text[7].setPosition(sf::Vector2f(w / 1.28, h / 1.56));

    text[8].setPosition(sf::Vector2f(w / 3.04, h / 1.09));
    text[9].setPosition(sf::Vector2f(w / 1.8, h / 1.1));

    occur[0].setPosition(sf::Vector2f(w / 4.1, h / 3.5));
    occur[1].setPosition(sf::Vector2f(w / 2.1, h / 3.5));
    occur[2].setPosition(sf::Vector2f(w / 1.4, h / 3.5));
    occur[3].setPosition(sf::Vector2f(w / 1.1, h / 3.5));

    occur[4].setPosition(sf::Vector2f(w / 4.1, h / 1.56));
    occur[5].setPosition(sf::Vector2f(w / 2.3, h / 1.56));
    occur[6].setPosition(sf::Vector2f(w / 1.5, h / 1.56));
    occur[7].setPosition(sf::Vector2f(w / 1.1, h / 1.56));

    occur[8].setPosition(sf::Vector2f(w / 2.3, h / 1.09));
    occur[9].setPosition(sf::Vector2f(w / 1.5, h / 1.1));

};

void sfml::occurences(int arr[])
{
    int a;
    a=arr[4];
    arr[4]=arr[6];
    arr[6]=a;

    for(int i=0;i<10;i++){
        occur[i].setString(std::to_string(arr[i]));
    }

}

void sfml::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 10; i++)
    {
        window.draw(sprite[i]);
        window.draw(text[i]);
        window.draw(occur[i]);
    }
}
