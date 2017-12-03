#include "LoadingState.hpp"

LoadingState::LoadingState () {

    m_controller.addLoopKeybinding(
        LoopKeybinding([](){}, sf::Keyboard::Key::LShift)
    );

}

LoadingState::~LoadingState () {}

void LoadingState::onActivate () {

    Log::verbose("Loading... forever at the moment...");

}

void LoadingState::onDeactivate () {

    Log::verbose("Loading complete!");

}

void LoadingState::onPush () {

    Log::verbose("Loading state pushed.");

}

void LoadingState::onPop () {}

void LoadingState::onAscend () {}

void LoadingState::onDescend () {}

void LoadingState::render (double deltaTime) {}

void LoadingState::update () {}
