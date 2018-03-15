#include "BoatyMcBoatFace.hpp"
#include "../World/World.hpp"

BoatyMcBoatFace::BoatyMcBoatFace (World* world) {

    m_world = world;
    m_boatTexture.loadFromImage(*AssetStore::getImage("boatyMcBoatFace"));
    m_boatSprite = sf::Sprite(m_boatTexture);
    m_boatSprite.setOrigin(16.0, 24.0);
    m_boatSprite.setPosition(400.0, 300.0);

}

void BoatyMcBoatFace::setPosition (float x, float y) {

    m_positionX = x;
    m_positionY = y;

}

void BoatyMcBoatFace::movePosition (float x, float y) {

    m_positionX += x;
    m_positionY += y;

    m_world->setCamera(m_positionX, m_positionY);

}

unsigned int BoatyMcBoatFace::getValue () const {

    return m_value;

}

unsigned int BoatyMcBoatFace::getWeight () const {

    return m_weight;

}

void BoatyMcBoatFace::setValue (unsigned int value) {

    m_value = value;

}

void BoatyMcBoatFace::addValue (int value) {

    m_value += value;

}

void BoatyMcBoatFace::subtractValue (int value) {

    m_value -= value;

}

void BoatyMcBoatFace::setWeight (unsigned int weight) {

    m_weight = weight;

}

void BoatyMcBoatFace::addWeight (int weight) {

    m_weight += weight;

}

void BoatyMcBoatFace::subtractWeight (int weight) {

    m_weight -= weight;

}

void BoatyMcBoatFace::render () {

    Window::draw(m_boatSprite);

}

void BoatyMcBoatFace::update () {

    m_world->setCamera(m_positionX, m_positionY);

}
