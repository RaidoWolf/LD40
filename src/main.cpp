#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "class/Log/Log.hpp"
#include "enum/LogLevel/LogLevel.hpp"
#include "config.h"

int main (int argc, const char* argv[]) {

    Log::setFilterLevel(LogLevel::VERBOSE);
    Log::verbose("Starting LD40 game!");

    // create game window
    Log::verbose("Creating window.");
    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "LD40",
        sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar
    );

    Log::verbose("Starting game loop.");
    while (window.isOpen()) {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent)) {
            if (windowEvent.type == sf::Event::Closed) {
                Log::verbose("Closing window (close button pressed).");
                window.close();
            }
        }
        window.display();
    }

    Log::verbose("Exiting. Thanks for playing!");
    exit(EXIT_SUCCESS);
    return 0;

}
