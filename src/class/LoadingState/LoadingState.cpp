#include "LoadingState.hpp"

LoadingState::LoadingState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(255, 255, 255, 255);

    m_progressBar.setWidth(500.0);
    m_progressBar.setHeight(40.0);
    m_progressBar.setPadding(5.0);
    m_progressBar.setOriginToCenter();
    m_progressBar.setPositionX(400.0);
    m_progressBar.setPositionY(300.0);
    m_progressBar.setBackgroundColor(sf::Color(0, 0, 0, 255));
    m_progressBar.setForegroundColor(sf::Color(255, 255, 255, 255));

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

void LoadingState::render (double deltaTime) {

    m_progressBar.render();

}

void LoadingState::update () {

    m_progressBar.incrementFill(0.0001);

}
