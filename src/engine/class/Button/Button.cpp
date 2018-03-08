#include "Button.hpp"

Button::Button (
    ButtonCallback& callback,
    Controller& controller,
    std::shared_ptr<sf::Font> font,
    std::string text,
    float fontSize,
    float padding,
    sf::Color backgroundColor,
    sf::Color foregroundColor,
    Button::Alignment alignment
) :
  m_controller(controller)
{

    setCallback(callback);
    setFont(std::move(font));
    setText(std::move(text));
    setFontSize(std::move(fontSize));
    setPadding(std::move(padding));
    setBackgroundColor(std::move(backgroundColor));
    setForegroundColor(std::move(foregroundColor));
    setAlignment(std::move(alignment));

    controller.addMouseButtonPressCallback(
        [this](int button, int x, int y){this->onClick(button, x, y);}
    );

    m_borderElement.setOutlineThickness(2.0);

}

Button::Button (
    ButtonCallback& callback,
    Controller& controller,
    std::string font,
    std::string text,
    float fontSize,
    float padding,
    sf::Color backgroundColor,
    sf::Color foregroundColor,
    Button::Alignment alignment
) :
  m_controller(controller)
{

    setCallback(callback);
    setFont(AssetStore::getFont(font));
    setText(std::move(text));
    setFontSize(std::move(fontSize));
    setPadding(std::move(padding));
    setBackgroundColor(std::move(backgroundColor));
    setForegroundColor(std::move(foregroundColor));
    setAlignment(std::move(alignment));

    controller.addMouseButtonPressCallback(
        [this](int button, int x, int y){this->onClick(button, x, y);}
    );

    m_borderElement.setOutlineThickness(2.0);

}

void Button::render () {

    Window::draw(m_borderElement);
    Window::draw(m_textElement);

}

void Button::onPress () {

    m_callback();

}

void Button::onClick (int button, int x, int y) {

    if (button == sf::Mouse::Left) {
        auto rect = m_borderElement.getLocalBounds();
        float offsetX = 0.0;
        float offsetY = 0.0;
        switch (m_alignment) {

            case Button::Alignment::TopLeft:
                break;

            case Button::Alignment::TopCenter:
                offsetX = rect.width * 0.5;
                break;

            case Button::Alignment::TopRight:
                offsetX = rect.width;
                break;

            case Button::Alignment::LeftCenter:
                offsetY = rect.height * 0.5;
                break;

            case Button::Alignment::Center:
                offsetX = rect.width * 0.5;
                offsetY = rect.height * 0.5;
                break;

            case Button::Alignment::RightCenter:
                offsetX = rect.width;
                offsetY = rect.height * 0.5;
                break;

            case Button::Alignment::BottomLeft:
                offsetY = rect.height;
                break;

            case Button::Alignment::BottomCenter:
                offsetX = rect.width * 0.5;
                offsetY = rect.height;
                break;

            case Button::Alignment::BottomRight:
                offsetX = rect.width;
                offsetY = rect.height;
                break;

            default:
                return;

        }
        if (
            x >= rect.left + m_positionX - offsetX &&
            x <= rect.left + m_positionX + rect.width - offsetX &&
            y >= rect.top + m_positionY - offsetY &&
            y <= rect.top + m_positionY + rect.height - offsetY
        ) {
            onPress();
        }
    }

}

void Button::setPosition (float x, float y) {

    setPositionX(std::move(x));
    setPositionY(std::move(y));

}

void Button::setPositionX (float x) {

    m_positionX = std::move(x);

    updatePositionX();

}

void Button::setPositionY (float y) {

    m_positionY = std::move(y);

    updatePositionY();

}

void Button::setAlignment (Button::Alignment alignment) {

    m_alignment = std::move(alignment);

    updateAlignment();

}

const Button::ButtonCallback& Button::getCallback () const {

    return m_callback;

}

std::shared_ptr<sf::Font> Button::getFont () const {

    return m_font;

}

std::string Button::getText () const {

    return m_text;

}

sf::Color Button::getBackgroundColor () const {

    return m_backgroundColor;

}

sf::Color Button::getForegroundColor () const {

    return m_foregroundColor;

}

void Button::setCallback (Button::ButtonCallback& callback) {

    m_callback = callback;

}

void Button::setFont (std::shared_ptr<sf::Font> font) {

    m_font = std::move(font);

    updateFont();

}

void Button::setText (std::string text) {

    m_text = std::move(text);

    updateText();

}

void Button::setFontSize (float size) {

    if (size < 0) {
        size = 0.0;
    }

    m_fontSize = std::move(size);

    updateFontSize();

}

void Button::setPadding (float padding) {

    if (padding < 0) {
        padding = 0.0;
    }

    m_padding = std::move(padding);

    updatePadding();

}

void Button::setBackgroundColor (sf::Color color) {

    m_backgroundColor = std::move(color);

    updateBackgroundColor();

}

void Button::setForegroundColor (sf::Color color) {

    m_foregroundColor = std::move(color);

    updateBackgroundColor();

}

void Button::updatePositionX () {

    auto rect = m_borderElement.getLocalBounds();
    float offsetX = 0.0;
    switch (m_alignment) {

        case Button::Alignment::TopLeft:
            break;

        case Button::Alignment::TopCenter:
            offsetX = rect.width * 0.5;
            break;

        case Button::Alignment::TopRight:
            offsetX = rect.width;
            break;

        case Button::Alignment::LeftCenter:
            break;

        case Button::Alignment::Center:
            offsetX = rect.width * 0.5;
            break;

        case Button::Alignment::RightCenter:
            offsetX = rect.width;
            break;

        case Button::Alignment::BottomLeft:
            break;

        case Button::Alignment::BottomCenter:
            offsetX = rect.width * 0.5;
            break;

        case Button::Alignment::BottomRight:
            offsetX = rect.width;
            break;

        default:
            return;

    }

    m_borderElement.setPosition(m_positionX - offsetX, m_borderElement.getPosition().y);
    m_textElement.setPosition(m_positionX + m_padding - offsetX, m_textElement.getPosition().y);

}

void Button::updatePositionY () {

    auto rect = m_borderElement.getLocalBounds();
    float offsetY = 0.0;
    switch (m_alignment) {

        case Button::Alignment::TopLeft:
            break;

        case Button::Alignment::TopCenter:
            break;

        case Button::Alignment::TopRight:
            break;

        case Button::Alignment::LeftCenter:
            offsetY = rect.height * 0.5;
            break;

        case Button::Alignment::Center:
            offsetY = rect.height * 0.5;
            break;

        case Button::Alignment::RightCenter:
            offsetY = rect.height * 0.5;
            break;

        case Button::Alignment::BottomLeft:
            offsetY = rect.height;
            break;

        case Button::Alignment::BottomCenter:
            offsetY = rect.height;
            break;

        case Button::Alignment::BottomRight:
            offsetY = rect.height;
            break;

        default:
            return;

    }

    m_borderElement.setPosition(m_borderElement.getPosition().x, m_positionY - offsetY);
    m_textElement.setPosition(m_textElement.getPosition().x, m_positionY + m_padding - offsetY);

}

void Button::updateAlignment () {

    updatePositionX();
    updatePositionY();

}

void Button::updateSize () {

    auto rect = m_textElement.getLocalBounds();

    m_borderElement.setSize(
        sf::Vector2f(
            rect.width + (m_padding * 2),
            rect.height + (m_padding * 2)
        )
    );

    updatePositionX();
    updatePositionY();

}

void Button::updateFont () {

    m_textElement.setFont(*m_font);

    updateSize();

}

void Button::updateText () {

    m_textElement.setString(m_text);

    updateSize();

}

void Button::updateFontSize () {

    updateSize();

}

void Button::updatePadding () {

    updateSize();

}

void Button::updateBackgroundColor () {

    m_borderElement.setFillColor(m_backgroundColor);

}

void Button::updateForegroundColor () {

    m_borderElement.setOutlineColor(m_foregroundColor);

}
