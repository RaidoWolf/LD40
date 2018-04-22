#include "../include/MenuState.hpp"

MenuState::MenuState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(38, 118, 248, 255);

    m_startButton.setPosition(400, 300);

}

void MenuState::onActivate () {

    aw::Log::verbose("menustate", "Launching Menu.");

    m_titleTexture.loadFromImage(*aw::AssetStore::getImage("title"));
    m_titleSprite = sf::Sprite(m_titleTexture);
    m_titleSprite.setOrigin(128.0, 32.0);
    m_titleSprite.setPosition(400.0, 180.0);

}

void MenuState::onDeactivate () {}

void MenuState::onPush () {}

void MenuState::onPop () {}

void MenuState::onAscend () {}

void MenuState::onDescend () {}

void MenuState::render (double deltaTime) {

    aw::Window::draw(m_titleSprite);
    m_startButton.render();

}

void MenuState::update () {}

void MenuState::startGame () {

    aw::GameStateManager::pushState("playing");

}
