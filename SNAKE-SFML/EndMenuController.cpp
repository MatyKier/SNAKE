#include "EndMenuController.h"

EndMenuController::EndMenuController(EndMenuText & v) : view(v)
{
}

void EndMenuController::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space)
        {
            finished = true;
        }
    }
}

void EndMenuController::draw(sf::RenderWindow & win)
{
    view.draw(win);
}

bool EndMenuController::isFinished(){
    bool result = finished;
    return result;
}
