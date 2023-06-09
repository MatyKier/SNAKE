#ifndef GAME_H
#define GAME_H

#include "MainMenuController.h"
#include "GameController.h"
#include "EndMenuController.h"
#include "Board.h"

class Game {
public:
    Game(MainMenuController &mmc, GameController &gmc, EndMenuController &emc);
    void draw(sf::RenderWindow &win);
    void handleEvent(sf::Event &event);

private:
    MainMenuController &mainMenuController;
    GameController &gameController;
    EndMenuController &endMenuController;
    enum GameState { MAIN, GAME, END };
    GameState state;
    void updateState();

};

#endif // GAME_H
