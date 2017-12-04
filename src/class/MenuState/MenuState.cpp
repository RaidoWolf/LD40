#include "MenuState.hpp"

MenuState::MenuState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(38, 118, 248, 255);

    m_startButton.setPosition(400, 300);

}

MenuState::~MenuState () {}

void MenuState::onActivate () {

    Log::verbose("Loading... forever at the moment...");

}

void MenuState::onDeactivate () {

    Log::verbose("Loading complete!");

}

void MenuState::onPush () {

    Log::verbose("Loading state pushed.");

}

void MenuState::onPop () {}

void MenuState::onAscend () {}

void MenuState::onDescend () {}

void MenuState::render (double deltaTime) {

    m_startButton.render();

}

void MenuState::update () {}

void MenuState::startGame () {

    Log::verbose("Starting game!");

}
