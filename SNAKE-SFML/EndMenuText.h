#ifndef ENDMENUTEXT_H
#define ENDMENUTEXT_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class EndMenuText
{
public:
    EndMenuText(Board & b);
    void draw(sf::RenderWindow &win);
    void updateHighscores();

private:
    sf::Font font4;
    sf::Font font5;
    sf::Font font6;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Text gameOver;
    sf::Text score;
    sf::Text exit;
    Board & board;

};

#endif // ENDMENUTEXT_H


