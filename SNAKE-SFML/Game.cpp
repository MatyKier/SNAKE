#include "Game.h"

Game::Game(MainMenuController &mmc, GameController &gmc, EndMenuController &emc) : mainMenuController(mmc), gameController(gmc), endMenuController(emc)
{
    state = MAIN;
}

void Game::updateState() {

    switch (state) {
        case MAIN:
            if (mainMenuController.isFinished())
            {
                state = GAME;
            }

            break;
        case GAME:
            if (gameController.isFinished())
                state = END;
            break;
        case END:
            break;
    }
}

void Game::handleEvent(sf::Event &event)
{
    switch (state) {
        case MAIN:
            mainMenuController.handleEvent(event);
            break;
        case GAME:
            gameController.handleEvent(event);
            break;
        case END:
            endMenuController.handleEvent(event);
            break;
    }
    updateState();
}

void Game::draw(sf::RenderWindow &win)
{
    switch (state) {
        case MAIN:
            mainMenuController.draw(win);
            break;
        case GAME:
            gameController.draw(win);
            break;
        case END:
            endMenuController.draw(win);
            if (endMenuController.isFinished())
                win.close();
            break;
    }
}
