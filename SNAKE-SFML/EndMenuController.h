#ifndef ENDMENUCONTROLLER_H
#define ENDMENUCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "EndMenuText.h"
#include "MainMenuText.h"

class EndMenuController {

public:
    EndMenuController(EndMenuText & v);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win);
    bool isFinished();

private:
    bool finished = false;
    EndMenuText & view;

};

#endif // ENDMENUCONTROLLER_H
