#include "BoatyMcBoatFace.hpp"

BoatyMcBoatFace::BoatyMcBoatFace () {

    m_boatTexture.loadFromImage(*AssetStore::getImage("boatyMcBoatFace"));
    m_boatSprite = sf::Sprite(m_boatTexture);
    m_boatSprite.setPosition(400.0, 300.0);

}

BoatyMcBoatFace::~BoatyMcBoatFace () {}

unsigned int BoatyMcBoatFace::getValue () {

    return m_value;

}

unsigned int BoatyMcBoatFace::getWeight () {

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



}
