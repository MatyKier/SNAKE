#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "GameText.h"
#include "Board.h"
#include "MainMenuText.h"

class GameController {
public:
    GameController(GameText & v, Board & b);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win);
    bool isFinished();

private:
    bool finished = false;
    GameText & view;
    Board & board;
};

#endif // GAMECONTROLLER_H

