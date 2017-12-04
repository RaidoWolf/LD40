#include "LoadingState.hpp"

LoadingState::LoadingState () {

    m_controller.addLoopKeybinding(
        LoopKeybinding([](){}, sf::Keyboard::Key::LShift)
    );

    m_clearWindow = true;
    m_clearColor = sf::Color(255, 255, 255, 255);

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
