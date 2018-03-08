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

    setWidth(std::move(width));
    setHeight(std::move(height));
    setPadding(std::move(padding));
    setPositionX(std::move(positionX));
    setPositionY(std::move(positionY));
    setOriginX(std::move(originX));
    setOriginY(std::move(originY));
    setBackgroundColor(std::move(backgroundColor));
    setForegroundColor(std::move(foregroundColor));

}

ProgressBar::~ProgressBar () {}

void ProgressBar::render () {

    Window::draw(m_backgroundRect);
    Window::draw(m_foregroundRect);

}

void ProgressBar::setPosition (float x, float y) {

    setPositionX(std::move(x));
    setPositionY(std::move(y));

}

void ProgressBar::setPositionX (float x) {

    m_positionX = std::move(x);

    updatePositionX();

}

void ProgressBar::setPositionY (float y) {

    m_positionY = std::move(y);

    updatePositionY();

}

void ProgressBar::setOrigin (float x, float y) {

    setOriginX(std::move(x));
    setOriginY(std::move(y));

}

void ProgressBar::setOriginX (float x) {

    m_originX = std::move(x);

    updateOriginX();

}

void ProgressBar::setOriginY (float y) {

    m_originY = std::move(y);

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

double ProgressBar::getFill () const {

    return m_fill;

}

float ProgressBar::getWidth () const {

    return m_width;

}

float ProgressBar::getHeight () const {

    return m_height;

}

float ProgressBar::getPadding () const {

    return m_padding;

}

sf::Color ProgressBar::getBackgroundColor () const {

    return m_backgroundColor;

}

sf::Color ProgressBar::getForegroundColor () const {

    return m_foregroundColor;

}

void ProgressBar::setFill (double fill) {

    if (fill < 0) {
        fill = 0;
    } else if (fill > 1.0) {
        fill = 1.0;
    }

    m_fill = std::move(fill);

    updateFill();

}

double ProgressBar::incrementFill (double fill) {

    fill += m_fill;
    setFill(std::move(fill));

    return m_fill;

}

double ProgressBar::decrementFill (double fill) {

    fill = m_fill - fill;
    setFill(std::move(fill));

    return m_fill;

}

void ProgressBar::setWidth (float width) {

    if (width < 0.0) {
        width = 0.0;
    }

    m_width = std::move(width);

    updateWidth();

}

void ProgressBar::setHeight (float height) {

    if (height < 0.0) {
        height = 0.0;
    }

    m_height = std::move(height);

    updateHeight();

}

void ProgressBar::setPadding (float padding) {

    m_padding = std::move(padding);

    updatePadding();

}

void ProgressBar::setBackgroundColor (sf::Color color) {

    m_backgroundColor = std::move(color);

    updateBackgroundColor();

}

void ProgressBar::setForegroundColor (sf::Color color) {

    m_foregroundColor = std::move(color);

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
