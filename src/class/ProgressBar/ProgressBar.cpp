#include "ProgressBar.hpp"

ProgressBar::ProgressBar (
    float width,
    float height,
    float padding,
    float positionX,
    float positionY,
    float originX,
    float originY,
    sf::Color backgroundColor,
    sf::Color foregroundColor
) {

    setWidth(width);
    setHeight(height);
    setPadding(padding);
    setPositionX(positionX);
    setPositionY(positionY);
    setOriginX(originX);
    setOriginY(originY);
    setBackgroundColor(backgroundColor);
    setForegroundColor(foregroundColor);

}

ProgressBar::~ProgressBar () {}

void ProgressBar::render () {

    Window::draw(m_backgroundRect);
    Window::draw(m_foregroundRect);

}

void ProgressBar::setPosition (float x, float y) {

    setPositionX(x);
    setPositionY(y);

}

void ProgressBar::setPositionX (float x) {

    m_positionX = x;

    updatePositionX();

}

void ProgressBar::setPositionY (float y) {

    m_positionY = y;

    updatePositionY();

}

void ProgressBar::setOrigin (float x, float y) {

    setOriginX(x);
    setOriginY(y);

}

void ProgressBar::setOriginX (float x) {

    m_originX = x;

    updateOriginX();

}

void ProgressBar::setOriginY (float y) {

    m_originY = y;

    updateOriginY();

}

void ProgressBar::setOriginToCenter () {

    setOriginX(m_width * 0.5);
    setOriginY(m_height * 0.5);

}

void ProgressBar::setOriginToTopLeft () {

    setOriginX(0);
    setOriginY(0);

}

double ProgressBar::getFill () {

    return m_fill;

}

float ProgressBar::getWidth () {

    return m_width;

}

float ProgressBar::getHeight () {

    return m_height;

}

float ProgressBar::getPadding () {

    return m_padding;

}

sf::Color ProgressBar::getBackgroundColor () {

    return m_backgroundColor;

}

sf::Color ProgressBar::getForegroundColor () {

    return m_foregroundColor;

}

void ProgressBar::setFill (double fill) {

    if (fill < 0) {
        fill = 0;
    } else if (fill > 1.0) {
        fill = 1.0;
    }

    m_fill = fill;

    updateFill();

}

double ProgressBar::incrementFill (double fill) {

    fill += m_fill;
    setFill(fill);

    return m_fill;

}

double ProgressBar::decrementFill (double fill) {

    fill = m_fill - fill;
    setFill(fill);

    return m_fill;

}

void ProgressBar::setWidth (float width) {

    if (width < 0.0) {
        width = 0.0;
    }

    m_width = width;

    updateWidth();

}

void ProgressBar::setHeight (float height) {

    if (height < 0.0) {
        height = 0.0;
    }

    m_height = height;

    updateHeight();

}

void ProgressBar::setPadding (float padding) {

    m_padding = padding;

    updatePadding();

}

void ProgressBar::setBackgroundColor (sf::Color color) {

    m_backgroundColor = color;

    updateBackgroundColor();

}

void ProgressBar::setForegroundColor (sf::Color color) {

    m_foregroundColor = color;

    updateForegroundColor();

}

void ProgressBar::updatePositionX () {

    m_backgroundRect.setPosition(m_positionX - m_originX, m_backgroundRect.getPosition().y);
    m_foregroundRect.setPosition(m_positionX + m_padding - m_originX, m_foregroundRect.getPosition().y);

}

void ProgressBar::updatePositionY () {

    m_backgroundRect.setPosition(m_backgroundRect.getPosition().x, m_positionY - m_originY);
    m_foregroundRect.setPosition(m_foregroundRect.getPosition().x, m_positionY + m_padding - m_originY);

}

void ProgressBar::updateOriginX () {

    updatePositionX();

}

void ProgressBar::updateOriginY () {

    updatePositionY();

}

void ProgressBar::updateWidth () {

    m_backgroundRect.setSize(
        sf::Vector2f(
            m_width,
            m_backgroundRect.getSize().y
        )
    );
    m_foregroundRect.setSize(
        sf::Vector2f(
            (m_width - (m_padding * 2)) * m_fill,
            m_foregroundRect.getSize().y
        )
    );

}

void ProgressBar::updateHeight () {

    m_backgroundRect.setSize(
        sf::Vector2f(
            m_backgroundRect.getSize().x,
            m_height
        )
    );
    m_foregroundRect.setSize(
        sf::Vector2f(
            m_foregroundRect.getSize().x,
            m_height - (m_padding * 2)
        )
    );

}

void ProgressBar::updateFill () {

    updateWidth();

}

void ProgressBar::updatePadding () {

    updateWidth();
    updateHeight();
    updateOriginX();
    updateOriginY();
    updatePositionX();
    updatePositionY();

}

void ProgressBar::updateBackgroundColor () {

    m_backgroundRect.setFillColor(m_backgroundColor);

}

void ProgressBar::updateForegroundColor () {

    m_foregroundRect.setFillColor(m_foregroundColor);

}
