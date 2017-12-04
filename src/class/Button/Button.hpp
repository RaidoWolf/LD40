#ifndef H_CLASS_BUTTON
#define H_CLASS_BUTTON

#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "../AssetStore/AssetStore.hpp"
#include "../Window/Window.hpp"
#include "../Controller/Controller.hpp"

class Button {

public:

    enum class Alignment {
        TopLeft,
        TopCenter,
        TopRight,
        LeftCenter,
        Center,
        RightCenter,
        BottomLeft,
        BottomCenter,
        BottomRight
    };

    typedef std::function < void () > ButtonCallback;

    Button (
        ButtonCallback&,
        Controller&,
        sf::Font*,
        std::string,
        float fontSize = 32.0,
        float padding = 10.0,
        sf::Color backgroundColor = sf::Color(0, 0, 0, 0),
        sf::Color foregroundColor = sf::Color(0, 0, 0, 255),
        Button::Alignment alignment = Button::Alignment::Center
    );
    Button (
        ButtonCallback&,
        Controller&,
        std::string,
        std::string,
        float fontSize = 32.0,
        float padding = 10.0,
        sf::Color backgroundColor = sf::Color(0, 0, 0, 0),
        sf::Color foregroundColor = sf::Color(0, 0, 0, 255),
        Button::Alignment alignment = Button::Alignment::Center
    );
    ~Button ();

    void render ();
    void onPress ();
    void onClick (int, int, int); // not the same thing as onPress

    void setPosition (float, float);
    void setPositionX (float);
    void setPositionY (float);
    void setAlignment (Button::Alignment);

    ButtonCallback& getCallback ();
    sf::Font* getFont ();
    std::string getText ();
    sf::Color getBackgroundColor ();
    sf::Color getForegroundColor ();

    void setCallback (ButtonCallback&);
    void setFont (sf::Font*);
    void setText (std::string);
    void setFontSize (float);
    void setPadding (float);
    void setBackgroundColor (sf::Color);
    void setForegroundColor (sf::Color);

private:

    void updatePositionX ();
    void updatePositionY ();
    void updateAlignment ();
    void updateSize ();
    void updateFont ();
    void updateText ();
    void updateFontSize ();
    void updatePadding ();
    void updateBackgroundColor ();
    void updateForegroundColor ();

    ButtonCallback m_callback;
    Controller* m_controller;
    sf::Font* m_font;
    std::string m_text;
    float m_fontSize = 32.0;
    float m_padding = 10.0;
    sf::Color m_backgroundColor {0, 0, 0, 0};
    sf::Color m_foregroundColor {0, 0, 0, 255};

    float m_positionX = 0;
    float m_positionY = 0;
    Button::Alignment m_alignment = Button::Alignment::Center;

    sf::RectangleShape m_borderElement;
    sf::Text m_textElement;

};

#endif
