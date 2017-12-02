#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "class/Log/Log.hpp"
#include "enum/LogLevel/LogLevel.hpp"
#include "class/Window/Window.hpp"
#include "config.h"

int main (int argc, const char* argv[]) {

    Log::bindCallbacks();

    Log::setFilterLevel(LogLevel::VERBOSE);
    Log::verbose("Starting LD40 game!");

    // create game window
    Log::verbose("Creating window.");
    Window::setWidth(800);
    Window::setHeight(600);
    Window::setTitle("Ludum Dare 40");
    Window::open();

    Log::verbose("Starting game loop.");
    while (Window::isOpen()) {
        sf::Event windowEvent;
        while (Window::pollEvent(windowEvent)) {
            if (windowEvent.type == sf::Event::Closed) {
                Log::verbose("Closing window (close button pressed).");
                Window::close();
            }
        }
        Window::display();
    }

    Log::verbose("Exiting. Thanks for playing!");
    exit(EXIT_SUCCESS);
    return 0;

}
