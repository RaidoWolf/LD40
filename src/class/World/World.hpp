#ifndef H_CLASS_WORLD
#define H_CLASS_WORLD

#include <SFML/Graphics.hpp>
#include "../../lib/PerlinNoiseCpp/Perlin.h"
#include "../Window/Window.hpp"
#include "../AssetStore/AssetStore.hpp"

class World {

public:

    World ();
    ~World ();

    enum Block {
        Water,
        Trees,
        Stone,
        Ice
    };

    void generateTerrain ();

    void setCamera (float x, float y);
    void moveCamera (float x, float y);
    void render ();

private:

    unsigned int indexOf (unsigned int, unsigned int);

    char* m_blocks;

    sf::Texture m_treesTexture;
    sf::Sprite m_treesSprite;
    sf::Texture m_stoneTexture;
    sf::Sprite m_stoneSprite;
    sf::Texture m_iceTexture;
    sf::Sprite m_iceSprite;
    sf::Texture m_waterTexture;
    sf::Sprite m_waterSprite;

    float m_cameraX = 0;
    float m_cameraY = 0;

};

#endif
