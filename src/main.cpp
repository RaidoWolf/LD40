#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "engine/class/Log/Log.hpp"
#include "engine/enum/LogLevel/LogLevel.hpp"
#include "engine/class/Window/Window.hpp"
#include "engine/class/GameStateManager/GameStateManager.hpp"
#include "engine/class/GameStateStore/GameStateStore.hpp"
#include "engine/class/GameLoop/GameLoop.hpp"
#include "class/LoadingState/LoadingState.hpp"
#include "class/MenuState/MenuState.hpp"
#include "class/PlayingState/PlayingState.hpp"
#include "config.h"

int main (int argc, const char* argv[]) {

    Log::bindCallbacks();

    Log::setFilterLevel(LogLevel::VERBOSE);
    Log::verbose("Starting LD40 game!");

    GameStateStore::registerState("loading", new LoadingState());
    GameStateStore::registerState("menu", new MenuState());
    GameStateStore::registerState("playing", new PlayingState());
    GameStateManager::pushState("loading"); // bootstrap

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
