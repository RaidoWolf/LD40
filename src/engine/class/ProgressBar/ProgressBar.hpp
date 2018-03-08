#ifndef H_CLASS_PROGRESSBAR
#define H_CLASS_PROGRESSBAR

#include <SFML/Graphics.hpp>
#include "../Window/Window.hpp"

class ProgressBar {

public:

    ProgressBar (
        float width = 1000,
        float height = 50,
        float padding = 5,
        float positionX = 0,
        float positionY = 0,
        float originX = 0,
        float originY = 0,
        sf::Color = sf::Color(0, 0, 0, 255),
        sf::Color = sf::Color(255, 255, 255, 255)
    );
    ~ProgressBar ();

    void render ();

    void setPosition (float, float);
    void setPositionX (float);
    void setPositionY (float);
    void setOrigin (float, float);
    void setOriginX (float);
    void setOriginY (float);
    void setOriginToCenter ();
    void setOriginToTopLeft ();

    double getFill () const;
    float getWidth () const;
    float getHeight () const;
    float getPadding () const;
    sf::Color getBackgroundColor () const;
    sf::Color getForegroundColor () const;

    void setFill (double);
    double incrementFill (double);
    double decrementFill (double);
    void setWidth (float);
    void setHeight (float);
    void setPadding (float);
    void setBackgroundColor (sf::Color);
    void setForegroundColor (sf::Color);

private:

    void updatePositionX ();
    void updatePositionY ();
    void updateOriginX ();
    void updateOriginY ();
    void updateWidth ();
    void updateHeight ();
    void updateFill ();
    void updatePadding ();
    void updateBackgroundColor ();
    void updateForegroundColor ();

    float m_positionX = 0;
    float m_positionY = 0;
    float m_originX = 0;
    float m_originY = 0;

    double m_fill = 0.000;

    float m_width = 500.0;
    float m_height = 50.0;
    float m_padding = 5.0;

    sf::Color m_backgroundColor {0, 0, 0, 255};
    sf::Color m_foregroundColor {255, 255, 255, 255};

    sf::RectangleShape m_backgroundRect;
    sf::RectangleShape m_foregroundRect;

};

#endif
