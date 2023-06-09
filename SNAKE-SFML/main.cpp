#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Board.h"
#include "MainMenuText.h"
#include "GameText.h"
#include "EndMenuText.h"
#include "MainMenuController.h"
#include "GameController.h"
#include "EndMenuController.h"
#include "Game.h"


int main()
{
    srand(time(NULL));
    Board b(1000, 1000);

    MainMenuText mmenu(b);
    MainMenuController mmc(mmenu, b);

    GameText game(b);
    GameController gmc(game, b);

    EndMenuText emenu(b);
    EndMenuController emc(emenu);

    Game g(mmc, gmc, emc);

    int Width = b.getWidth();
    int Height = b.getHeight();

    sf::RenderWindow window{ sf::VideoMode{Width, Height}, "SNAKE" };

    window.setFramerateLimit(60);
    sf::Event event;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            g.handleEvent(event);
        }


        window.clear();

        g.draw(window);

        window.display();
    }

    return 0;
}
