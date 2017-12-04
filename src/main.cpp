#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "class/Log/Log.hpp"
#include "enum/LogLevel/LogLevel.hpp"
#include "class/Window/Window.hpp"
#include "class/GameStateManager/GameStateManager.hpp"
#include "class/GameStateStore/GameStateStore.hpp"
#include "class/GameLoop/GameLoop.hpp"
#include "class/LoadingState/LoadingState.hpp"
#include "config.h"

int main (int argc, const char* argv[]) {

    Log::bindCallbacks();

    Log::setFilterLevel(LogLevel::VERBOSE);
    Log::verbose("Starting LD40 game!");

    GameStateStore::registerState("loading", new LoadingState);
    GameStateManager::pushState("loading");

    // create game window
    Log::verbose("Creating window.");
    Window::setWidth(800);
    Window::setHeight(600);
    Window::setTitle("Ludum Dare 40");
    Window::open();

    Log::verbose("Starting game loop.");
    GameLoop::setRenderFrameRate(60);
    GameLoop::setUpdateTickRate(60);
    GameLoop::run();

    Log::verbose("Exiting. Thanks for playing!");
    exit(EXIT_SUCCESS);
    return 0;

}
