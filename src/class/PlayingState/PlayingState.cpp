#include "PlayingState.hpp"

PlayingState::PlayingState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(0, 0, 0, 255);

}

PlayingState::~PlayingState () {}

void PlayingState::onActivate () {

    Log::verbose("Playing...");

}

void PlayingState::onDeactivate () {}

void PlayingState::onPush () {}

void PlayingState::onPop () {}

void PlayingState::onAscend () {}

void PlayingState::onDescend () {}

void PlayingState::render (double deltaTime) {}

void PlayingState::update () {}
