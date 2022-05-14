#ifndef POKER_SFML_H
#define POKER_SFML_H

#include "SFML/Graphics.hpp"
#include<sstream>

class sfml
{
    int w = sf::VideoMode::getDesktopMode().width;
    int	h = sf::VideoMode::getDesktopMode().height;

    sf::Sprite sprite[10];
    sf::Text text[10];
    sf::Texture texture[10];
    sf::Text occur[10];
    sf::Font font;

    std::stringstream ss0, ss1, ss2, ss3, ss4, ss5, ss6, ss7, ss8, ss9;

public:
    sfml();
    void draw(sf::RenderWindow& window);
    void occurences(int arr[]);
};

#endif //POKER_SFML_H
