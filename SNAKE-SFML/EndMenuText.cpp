#include "EndMenuText.h"
#include <fstream>

EndMenuText::EndMenuText(Board & b) : board(b)
{
    font4.loadFromFile("fonts/ARCADE.TTF");
    font5.loadFromFile("fonts/zerovelo.ttf");
    font6.loadFromFile("fonts/rexlia rg.otf");
    backgroundTexture.loadFromFile("images/EndMenuBackground.jpg");

    background.setSize({ board.getWidth(), board.getHeight() });
    background.setTexture(&backgroundTexture);

    gameOver.setFont(font4);
    gameOver.setFillColor(sf::Color::Red);
    gameOver.setString("Game Over");
    gameOver.setCharacterSize(board.getHeight() / 5);
    sf::FloatRect textBounds1 = gameOver.getLocalBounds();
    float posX1 = (board.getWidth() - textBounds1.width) / 2;
    float posY1 = board.getHeight() / 4 - textBounds1.height / 2;
    gameOver.setPosition(posX1, posY1);


    exit.setFont(font6);
    exit.setCharacterSize(board.getHeight() / 40);
    exit.setFillColor(sf::Color::White);
    exit.setString("enter space to exit");
    sf::FloatRect textBounds = exit.getLocalBounds();
    float posX3 = (board.getWidth() - textBounds.width) / 2;
    float posY3 = (board.getHeight() * 3 / 4) - (textBounds.height / 2);
    exit.setPosition(posX3, posY3);
}

void EndMenuText::draw(sf::RenderWindow & win)
{
    score.setFont(font5);
    score.setCharacterSize(board.getHeight() / 10);
    score.setFillColor(sf::Color::White);
    score.setString("score: " + std::to_string(board.getSnakeLength()));
    sf::FloatRect textBounds2 = score.getLocalBounds();
    float posX2 = (board.getWidth() - textBounds2.width) / 2;
    float posY2 = (board.getHeight() - textBounds2.height) / 2;
    score.setPosition(posX2, posY2);

    win.draw(background);
    win.draw(gameOver);
    win.draw(score);
    win.draw(exit);
    updateHighscores();
}

void EndMenuText::updateHighscores()
{
    std::ifstream file("highscore.txt");
    if (file.is_open())
    {
        std::vector<int> highscores;
        int score;
        while (file >> score)
        {
            highscores.push_back(score);
        }
        file.close();

        std::sort(highscores.rbegin(), highscores.rend());

        int currentScore = board.getSnakeLength();
        if (currentScore > highscores.back())
        {
            highscores.back() = currentScore;
        }

        std::ofstream outputFile("highscore.txt");
        if (outputFile.is_open())
        {
            for (const auto& hs : highscores)
            {
                outputFile << hs << '\n';
            }
            outputFile.close();
        }
    }
}

