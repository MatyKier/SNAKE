#include "MainMenuText.h"
#include <iostream>
#include <sstream>
#include <fstream>

MainMenuText::MainMenuText(Board& b) : board(b)
{
    font1.loadFromFile("fonts/ARCADE.TTF");
    font2.loadFromFile("fonts/zerovelo.ttf");
    font3.loadFromFile("fonts/novem___.ttf");
    font4.loadFromFile("fonts/rexlia rg.otf");
    backgroundTexture.loadFromFile("images/MainMenuBackground.jpg");

    background.setSize({ board.getWidth(), board.getHeight() });
    background.setTexture(&backgroundTexture);

    name.setFont(font1);
    name.setCharacterSize(board.getHeight() / 4);
    name.setString("Snake");
    name.setFillColor(sf::Color::Red);
    sf::FloatRect nameBounds = name.getLocalBounds();
    name.setOrigin(nameBounds.left + nameBounds.width / 2, nameBounds.top + nameBounds.height / 2);
    int posY = board.getHeight() / 4;
    name.setPosition(board.getWidth() / 2, posY);

    highscore.setFont(font3);
    highscore.setCharacterSize(board.getHeight() * 2 / 40);
    highscore.setString("Highscores");
    highscore.setFillColor(sf::Color::White);
    highscore.setPosition(board.getWidth() / 2.65, posY + name.getLocalBounds().height + 20);

    LoadHighScores();

    float buttonWidth = board.getWidth() / 3;
    float buttonHeight = board.getHeight() / 12;

    playButton.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    float buttonPosX = (board.getWidth() - buttonWidth) / 2;
    float buttonPosY = board.getHeight() * 8 / 10 - buttonHeight / 2;
    playButton.setPosition(buttonPosX, buttonPosY);
    playButton.setFillColor(sf::Color::Blue);

    play.setFont(font2);
    play.setCharacterSize(board.getHeight() * 3 / 40);
    play.setString("PLAY");
    play.setFillColor(sf::Color::White);
    play.setPosition(board.getWidth() / 2.93, board.getHeight() * 76 / 100);

    float modeButtonWidth = buttonWidth ;
    float modeButtonHeight = buttonHeight * 0.8f;
    float modeButtonSpacing = buttonWidth / 15;
    float modeButtonPosY = buttonPosY - modeButtonHeight - 20.0f;

    easyButton.setSize(sf::Vector2f(modeButtonWidth, modeButtonHeight));
    easyButton.setPosition(buttonPosX - modeButtonWidth - modeButtonSpacing, modeButtonPosY);
    easyButton.setFillColor(sf::Color::Green);

    easy.setFont(font4);
    easy.setCharacterSize(board.getHeight() * 2 / 40);
    easy.setString("EASY");
    easy.setFillColor(sf::Color::White);
    sf::FloatRect easyBounds = easy.getLocalBounds();
    easy.setOrigin(easyBounds.left + easyBounds.width / 2, easyBounds.top + easyBounds.height / 2);
    easy.setPosition(easyButton.getPosition().x + modeButtonWidth / 2, easyButton.getPosition().y + modeButtonHeight / 2);

    normalButton.setSize(sf::Vector2f(modeButtonWidth, modeButtonHeight));
    normalButton.setPosition(buttonPosX, modeButtonPosY);
    normalButton.setFillColor(sf::Color(255, 165, 0));

    normal.setFont(font4);
    normal.setCharacterSize(board.getHeight() * 2 / 40);
    normal.setString("NORMAL");
    normal.setFillColor(sf::Color::White);
    sf::FloatRect normalBounds = normal.getLocalBounds();
    normal.setOrigin(normalBounds.left + normalBounds.width / 2, normalBounds.top + normalBounds.height / 2);
    normal.setPosition(normalButton.getPosition().x + modeButtonWidth / 2, normalButton.getPosition().y + modeButtonHeight / 2);

    hardButton.setSize(sf::Vector2f(modeButtonWidth, modeButtonHeight));
    hardButton.setPosition(buttonPosX + modeButtonWidth + modeButtonSpacing, modeButtonPosY);
    hardButton.setFillColor(sf::Color::Red);

    hard.setFont(font4);
    hard.setCharacterSize(board.getHeight() * 2 / 40);
    hard.setString("HARD");
    hard.setFillColor(sf::Color::White);
    sf::FloatRect hardBounds = hard.getLocalBounds();
    hard.setOrigin(hardBounds.left + hardBounds.width / 2, hardBounds.top + hardBounds.height / 2);
    hard.setPosition(hardButton.getPosition().x + modeButtonWidth / 2, hardButton.getPosition().y + modeButtonHeight / 2);

    easyButtonFrame.setSize(easyButton.getSize());
    easyButtonFrame.setPosition(easyButton.getPosition());
    easyButtonFrame.setFillColor(sf::Color::Transparent);
    easyButtonFrame.setOutlineThickness(5.0f);
    easyButtonFrame.setOutlineColor(sf::Color::Transparent);

    normalButtonFrame.setSize(normalButton.getSize());
    normalButtonFrame.setPosition(normalButton.getPosition());
    normalButtonFrame.setFillColor(sf::Color::Transparent);
    normalButtonFrame.setOutlineThickness(5.0f);
    normalButtonFrame.setOutlineColor(sf::Color::Transparent);

    hardButtonFrame.setSize(hardButton.getSize());
    hardButtonFrame.setPosition(hardButton.getPosition());
    hardButtonFrame.setFillColor(sf::Color::Transparent);
    hardButtonFrame.setOutlineThickness(5.0f);
    hardButtonFrame.setOutlineColor(sf::Color::Transparent);
}

void MainMenuText::LoadHighScores()
{
    int posY = board.getHeight() / 4;

    std::ifstream file("highscore.txt");
    if (file.is_open())
    {
        std::vector<int> scores;
        int score;
        while (file >> score)
        {
            scores.push_back(score);
        }
        file.close();

        std::sort(scores.rbegin(), scores.rend());

        std::size_t numScores = std::min(scores.size(), static_cast<std::size_t>(3));
        for (std::size_t i = 0; i < numScores; ++i)
        {
            sf::Text scoreText;
            scoreText.setFont(font3);
            scoreText.setCharacterSize(board.getHeight() * 2 / 40);
            std::stringstream ss;
            ss << i + 1 << ". " << scores[i];
            scoreText.setString(ss.str());
            scoreText.setFillColor(sf::Color::White);
            scoreText.setPosition(board.getWidth() / 5 + highscore.getLocalBounds().width, posY + name.getLocalBounds().height + 40 + (i + 1) * scoreText.getLocalBounds().height + i * 20);
            highscoreValues.push_back(scoreText);
        }
    }
}

void MainMenuText::setSelectedMode(GameMode mode) {
    selectedMode = mode;
}

void MainMenuText::draw(sf::RenderWindow& win)
{
    win.draw(background);
    win.draw(name);
    win.draw(highscore);
    for (const auto& scoreText : highscoreValues)
    {
        win.draw(scoreText);
    }
    win.draw(easyButton);
    win.draw(easy);
    win.draw(normalButton);
    win.draw(normal);
    win.draw(hardButton);
    win.draw(hard);
    win.draw(playButton);
    win.draw(play);

    easyButtonFrame.setOutlineColor(sf::Color::Transparent);
    normalButtonFrame.setOutlineColor(sf::Color::Transparent);
    hardButtonFrame.setOutlineColor(sf::Color::Transparent);

    switch (selectedMode) {
        case GameMode::EASY:
            easyButtonFrame.setOutlineColor(sf::Color::Red);
            break;
        case GameMode::NORMAL:
            normalButtonFrame.setOutlineColor(sf::Color::Red);
            break;
        case GameMode::HARD:
            hardButtonFrame.setOutlineColor(sf::Color::Red);
            break;
    }

    win.draw(easyButtonFrame);
    win.draw(normalButtonFrame);
    win.draw(hardButtonFrame);
}
