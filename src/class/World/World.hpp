#ifndef H_CLASS_WORLD
#define H_CLASS_WORLD

#include <ctime>
#include <SFML/Graphics.hpp>
#include "../../lib/FastNoise/FastNoise.h"
#include "../Window/Window.hpp"
#include "../AssetStore/AssetStore.hpp"
#include "../Log/Log.hpp"
#include "../BoatyMcBoatFace/BoatyMcBoatFace.hpp"

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

    float m_cameraX = 16384;
    float m_cameraY = 16384;

    BoatyMcBoatFace* m_player;

};

#endif
