#include "PlayingState.hpp"

PlayingState::PlayingState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(0, 0, 0, 255);

}

PlayingState::~PlayingState () {}

void PlayingState::onActivate () {

    Log::verbose("Playing...");

    if (m_world) {
        delete m_world;
    }

    m_world = new World();

}

void PlayingState::onDeactivate () {}

void PlayingState::onPush () {}

void PlayingState::onPop () {}

void PlayingState::onAscend () {}

void PlayingState::onDescend () {}

void PlayingState::render (double deltaTime) {

    m_world->render();

}

void PlayingState::update () {}
