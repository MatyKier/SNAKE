#ifndef MAINMENUTEXT_H
#define MAINMENUTEXT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Board.h"

class MainMenuText
{
public:
    MainMenuText(Board & b);
    void LoadHighScores();
    void draw(sf::RenderWindow& win);
    void setSelectedMode(GameMode mode);

private:
    sf::Font font1;
    sf::Font font2;
    sf::Font font3;
    sf::Font font4;
    sf::Text name;
    sf::Text play;
    sf::Text scoreText;
    sf::Text highscore;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::RectangleShape playButton;
    sf::RectangleShape easyButton;
    sf::RectangleShape normalButton;
    sf::RectangleShape hardButton;
    sf::Text easy;
    sf::Text normal;
    sf::Text hard;
    sf::RectangleShape easyButtonFrame;
    sf::RectangleShape normalButtonFrame;
    sf::RectangleShape hardButtonFrame;
    std::vector<sf::Text> highscoreValues;
    Board board;
    GameMode selectedMode;
};

#endif // MAINMENUTEXT_H
