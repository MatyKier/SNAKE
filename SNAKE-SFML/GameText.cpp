#include "GameText.h"
#include <Windows.h>
#include <SFML/Graphics/Texture.hpp>

GameText::GameText(Board& b) : board(b), selectedMode(GameMode::NONE)
{
    backgroundTexture.loadFromFile("images/board.jpg");
    snakeTexture.loadFromFile("images/snake.jpg");
    fruitTexture.loadFromFile("images/fruit.png");
    font.loadFromFile("fonts/VIDEOPHREAK.ttf");
    wallTexture.loadFromFile("images/wall.jpg");

    background.setSize(sf::Vector2f(board.getWidth(), board.getWidth()));
    background.setTexture(&backgroundTexture);

    snake.setSize(sf::Vector2f(board.getWidth() / board.getBoardWidth(), board.getHeight() / board.getBoardHeight()));
    snake.setTexture(&snakeTexture);

    fruit.setSize(sf::Vector2f(1.4 * (board.getWidth() / board.getBoardWidth()), 1.4 * (board.getHeight() / board.getBoardHeight())));
    fruit.setTexture(&fruitTexture);

    score.setFont(font);
    score.setCharacterSize(board.getHeight() / 50);
    score.setFillColor(sf::Color::Black);
    score.setPosition(board.getWidth() / 55, 0);
}

void GameText::setSelectedMode(GameMode mode) {
    selectedMode = mode;
}
void GameText::draw(sf::RenderWindow& w)
{
    board.move();
    w.draw(background);

    for (int i = 0; i < board.getBoardHeight(); ++i)
    {
        for (int j = 0; j < board.getBoardWidth(); ++j)
        {
            if (board.getFieldInfo(j, i) == 'S')
            {
                snake.setPosition(sf::Vector2f((j + 1) * (board.getWidth() / (board.getBoardWidth() + 2)), (i + 1) * (board.getHeight() / (board.getBoardHeight() + 2))));
                w.draw(snake);
            }
            else if (board.getFieldInfo(j, i) == 'F')
            {
                fruit.setPosition(sf::Vector2f((j + 1) * (board.getWidth() / (board.getBoardWidth() + 2)), (i + 1) * (board.getHeight() / (board.getBoardHeight() + 2))));
                w.draw(fruit);
            }
            else if (board.getFieldInfo(j, i) == 'W')
            {
                wall.setTexture(&wallTexture);
                wall.setSize(sf::Vector2f(board.getWidth() / board.getBoardWidth(), board.getHeight() / board.getBoardHeight()));
                wall.setPosition(sf::Vector2f((j + 1) * (board.getWidth() / (board.getBoardWidth() + 2)), (i + 1) * (board.getHeight() / (board.getBoardHeight() + 2))));
                w.draw(wall);
            }
        }
    }

    score.setString("Score: " + std::to_string(board.getSnakeLength()));
    w.draw(score);

    if (board.getGameState() == FINISHED_LOSS)
    {
        finished = true;
    }

    if (finished)
    {
        return;
    }

    if (selectedMode != GameMode::NONE)
    {

        switch (selectedMode)
        {
            case GameMode::EASY:
                Sleep(300);
                break;
            case GameMode::NORMAL:
                Sleep(200);
                break;
            case GameMode::HARD:
                Sleep(50);
                break;
            default:
                break;
        }
    }
    else if (selectedMode == GameMode::NONE)
    {
        Sleep(50);
    }
}
