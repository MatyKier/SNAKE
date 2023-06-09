#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "Board.h"
#include "MainMenuText.h"
#include "GameText.h"
#include <SFML/Graphics.hpp>

class MainMenuController
{
public:
    MainMenuController(MainMenuText & v, Board & b);
    void handleEvent(sf::Event & event);
    void draw(sf::RenderWindow & win);
    bool isFinished();
    GameMode getSelectedMode();

private:
    MainMenuText & view;
    Board & board;
    bool finished;
    GameMode selectedMode;
};

#endif // MAINMENUCONTROLLER_H
