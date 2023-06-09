#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "MainMenuController.h"

class GameText
{
public:
    GameText(Board& b);
    void draw(sf::RenderWindow& w);
    void setSelectedMode(GameMode mode);

private:
    sf::Font font;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::RectangleShape wall;
    sf::RectangleShape snake;
    sf::RectangleShape fruit;
    sf::Texture fruitTexture;
    sf::Texture wallTexture;
    sf::Texture snakeTexture;
    sf::Text score;
    Board& board;
    bool finished;
    GameMode selectedMode;
};

#endif // GAMETEXT_H

