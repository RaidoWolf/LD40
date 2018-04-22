#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <ArcticWolf/Log.hpp>
#include <ArcticWolf/LogLevel.hpp>
#include <ArcticWolf/ConsoleLogObserver.hpp>
#include <ArcticWolf/FileLogObserver.hpp>
#include <ArcticWolf/Window.hpp>
#include <ArcticWolf/GameStateManager.hpp>
#include <ArcticWolf/GameStateStore.hpp>
#include <ArcticWolf/GameLoop.hpp>
#include "../include/LoadingState.hpp"
#include "../include/MenuState.hpp"
#include "../include/PlayingState.hpp"
#include "../include/config.h"

int main (int argc, const char* argv[]) {

    try {

        // log unhandled exceptions
        aw::Log::bindUnhandledException();

        // configure log observers
        aw::Log::makeObserver<aw::ConsoleLogObserver>();
        aw::Log::makeObserver<aw::FileLogObserver>("./log.txt");

        // set the log filter level
        aw::Log::verbose("main", "Starting LD40 game!");

        // create game window
        aw::Log::verbose("main", "Creating window.");
        aw::Window::setWidth(800);
        aw::Window::setHeight(600);
        aw::Window::setTitle("Ludum Dare 40");
        aw::Window::open();

        aw::GameStateStore::makeState<LoadingState>("loading");
        aw::GameStateStore::makeState<MenuState>("menu");
        aw::GameStateStore::makeState<PlayingState>("playing");
        aw::GameStateManager::pushState("loading"); // bootstrap

        aw::Log::verbose("main", "Starting game loop.");
        aw::GameLoop::setRenderFrameRate(60);
        aw::GameLoop::setUpdateTickRate(60);
        aw::GameLoop::run();

        aw::Log::verbose("main", "Exiting. Thanks for playing!");
        exit(EXIT_SUCCESS);
        return 0;

    } catch (const std::exception& e) {

        aw::Log::error("exception", "Uncaught exception: ", e.what());

    }

}
