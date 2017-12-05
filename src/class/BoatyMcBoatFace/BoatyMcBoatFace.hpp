#ifndef H_CLASS_BOATYMCBOATFACE
#define H_CLASS_BOATYMCBOATFACE

#include <SFML/Graphics.hpp>
#include "../AssetStore/AssetStore.hpp"
#include "../Window/Window.hpp"

class BoatyMcBoatFace {

public:

    BoatyMcBoatFace ();
    ~BoatyMcBoatFace ();

    unsigned int getValue ();
    unsigned int getWeight ();

    void setValue (unsigned int);
    void addValue (int);
    void subtractValue (int);
    void setWeight (unsigned int);
    void addWeight (int);
    void subtractWeight (int);

    void render ();

    void update ();

private:

    unsigned int m_value = 0;
    unsigned int m_weight = 0;

    sf::Texture m_boatTexture;
    sf::Sprite m_boatSprite;

};

#endif
