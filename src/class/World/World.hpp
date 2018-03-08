#ifndef H_CLASS_WORLD
#define H_CLASS_WORLD

#include <ctime>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../engine/lib/FastNoise/FastNoise.h"
#include "../../engine/class/Window/Window.hpp"
#include "../../engine/class/AssetStore/AssetStore.hpp"
#include "../../engine/class/Log/Log.hpp"
#include "../BoatyMcBoatFace/BoatyMcBoatFace.hpp"

class World {

public:

    World ();
    ~World () = default;

    World (World&&) = default;
    World& operator = (World&&) = default;

    World (const World&) = default;
    World& operator = (const World&) = default;

    enum Block {
        HomeWater,
        Water,
        Trees,
        Stone,
        Ice
    };

    BoatyMcBoatFace* getPlayer () const;

    void generateTerrain ();

    void setCamera (float x, float y);
    void moveCamera (float x, float y);
    void render ();

private:

    unsigned int indexOf (unsigned int, unsigned int) const;

    float* m_heightMap;
    float* m_zoneMap;
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

    std::unique_ptr<BoatyMcBoatFace> m_player;

};

#endif
