#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.h"

int main (int argc, const char* argv[]) {

    // create game window
    sf::Window window(
        sf::VideoMode(800, 600),
        "LD40"
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
    }

    exit(EXIT_SUCCESS);
    return 0;

}
