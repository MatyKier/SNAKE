#include "GameController.h"
#include <Windows.h>


GameController::GameController(GameText & v, Board & b) : view(v), board(b)
{
}

void GameController::handleEvent(sf::Event & event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Right)
        {
            board.changeDirection(RIGHT);
        }
        if (event.key.code == sf::Keyboard::Left)
        {
            board.changeDirection(LEFT);
        }
        if (event.key.code == sf::Keyboard::Up)
        {
            board.changeDirection(UP);
        }
        if (event.key.code == sf::Keyboard::Down)
        {
            board.changeDirection(DOWN);
        }
    }

    if (board.getGameState() == FINISHED_LOSS)
    {
        finished = true;
    }
}

void GameController::draw(sf::RenderWindow & win)
{
    view.draw(win);
}

bool GameController::isFinished(){
    bool result = finished;
    return result;
}


