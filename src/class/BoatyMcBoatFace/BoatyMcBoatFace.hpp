#ifndef H_CLASS_BOATYMCBOATFACE
#define H_CLASS_BOATYMCBOATFACE

#include <math.h>
#include <SFML/Graphics.hpp>
#include "../../engine/class/AssetStore/AssetStore.hpp"
#include "../../engine/class/Window/Window.hpp"

class World;

class BoatyMcBoatFace {

public:

    explicit BoatyMcBoatFace (World*);
    ~BoatyMcBoatFace () = default;

    BoatyMcBoatFace (BoatyMcBoatFace&&) = default;
    BoatyMcBoatFace& operator = (BoatyMcBoatFace&&) = default;

    BoatyMcBoatFace (const BoatyMcBoatFace&) = default;
    BoatyMcBoatFace& operator = (const BoatyMcBoatFace&) = default;

    void setPosition (float, float);
    void movePosition (float, float);

    unsigned int getValue () const;
    unsigned int getWeight () const;

    void setValue (unsigned int);
    void addValue (int);
    void subtractValue (int);
    void setWeight (unsigned int);
    void addWeight (int);
    void subtractWeight (int);

    void render ();

    void update ();

private:

    float m_positionX = 16384.0;
    float m_positionY = 16384.0;

    unsigned int m_value = 0;
    unsigned int m_weight = 0;

    sf::Texture m_boatTexture;
    sf::Sprite m_boatSprite;

    World* m_world;

};

#endif
