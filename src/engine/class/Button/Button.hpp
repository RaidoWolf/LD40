#ifndef H_CLASS_BUTTON
#define H_CLASS_BUTTON

#include <string>
#include <functional>
#include <memory>
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

    typedef std::function<void()> ButtonCallback;

    Button (
        ButtonCallback&,
        Controller&,
        std::shared_ptr<sf::Font>,
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
    ~Button () = default;

    Button (Button&&) = default;
    Button& operator = (Button&&) = default;

    Button (const Button&) = default;
    Button& operator = (const Button&) = default;

    void render ();
    void onPress ();
    void onClick (int, int, int); // not the same thing as onPress

    void setPosition (float, float);
    void setPositionX (float);
    void setPositionY (float);
    void setAlignment (Button::Alignment);

    const ButtonCallback& getCallback () const;
    std::shared_ptr<sf::Font> getFont () const;
    std::string getText () const;
    sf::Color getBackgroundColor () const;
    sf::Color getForegroundColor () const;

    void setCallback (ButtonCallback&);
    void setFont (std::shared_ptr<sf::Font>);
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
    Controller& m_controller;
    std::shared_ptr<sf::Font> m_font;
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
