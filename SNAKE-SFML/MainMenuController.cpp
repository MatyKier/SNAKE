#include "MainMenuController.h"

MainMenuController::MainMenuController(MainMenuText & v, Board & b) : view(v), board(b)
{
    finished = false;
}

void MainMenuController::handleEvent(sf::Event & event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if ((event.mouseButton.x > board.getWidth() / 6) && (event.mouseButton.x < board.getWidth() / 3) && (event.mouseButton.y > board.getHeight() / 2) && (event.mouseButton.y < board.getHeight() * 3 / 4))
            {
                selectedMode = GameMode::EASY;
            }
            else if ((event.mouseButton.x > board.getWidth() / 3) && (event.mouseButton.x < 2 * board.getWidth() / 3) && (event.mouseButton.y > board.getHeight() / 2) && (event.mouseButton.y < board.getHeight() * 3 / 4))
            {
                selectedMode = GameMode::NORMAL;
            }
            else if ((event.mouseButton.x > 2 * board.getWidth() / 3) && (event.mouseButton.x < board.getWidth()) && (event.mouseButton.y > board.getHeight() / 2) && (event.mouseButton.y < board.getHeight() * 3 / 4))
            {
                selectedMode = GameMode::HARD;
            }
            else if ((event.mouseButton.x > board.getWidth() / 3) && (event.mouseButton.x < board.getWidth() / 3 + board.getWidth() / 3) && (event.mouseButton.y > board.getHeight() - board.getHeight() / 4) && (event.mouseButton.y < board.getHeight() - board.getHeight() / 4 + board.getHeight() / 12))
            {
                finished = true;
            }
        }
    }
}

void MainMenuController::draw(sf::RenderWindow & win) {
    view.setSelectedMode(selectedMode);
    view.draw(win);
}

bool MainMenuController::isFinished(){
    return finished;
}

GameMode MainMenuController::getSelectedMode() {
    return selectedMode;
}
