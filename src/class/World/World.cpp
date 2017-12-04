#include "World.hpp"

World::World () {

    m_treesTexture.loadFromImage(*AssetStore::getImage("trees"));
    m_stoneTexture.loadFromImage(*AssetStore::getImage("stone"));
    m_iceTexture.loadFromImage(*AssetStore::getImage("ice"));
    m_waterTexture.loadFromImage(*AssetStore::getImage("water"));

    m_treesSprite = sf::Sprite(m_treesTexture);
    m_stoneSprite = sf::Sprite(m_stoneTexture);
    m_iceSprite = sf::Sprite(m_iceTexture);
    m_waterSprite = sf::Sprite(m_waterTexture);

    m_blocks = new char[1048576];

    generateTerrain();

}

World::~World () {}

void World::generateTerrain () {

    Perlin perlin;

    float* heightMap = new float[1048576];
    float* zoneMap = new float[1048576];

    for (unsigned int py = 0; py < 1024; ++py) {
        for (unsigned int px = 0; px < 1024; ++px) {

            unsigned int pindex = indexOf(px, py);

            heightMap[pindex] = perlin.noise(px, py, 0.0);
            zoneMap[pindex] = perlin.noise(px, py, 10.0);

        }
    }

    unsigned int distanceFromWall;
    for (unsigned int y = 0; y < 1024; ++y) {
        for (unsigned int x = 0; x < 1024; ++x) {

            unsigned int index = indexOf(x, y);

            // clear area around the spawn zone
            if (
                y >= 480 &&
                y <= 543 &&
                x >= 480 &&
                x <= 543
            ) {
                m_blocks[index] = World::Block::Water;
                continue;
            }

            // barriers all along the walls
            if (
                y == 0 ||
                y == 1023 ||
                x == 0 ||
                x == 1023
            ) {

                if (zoneMap[index] > 0.333) {
                    m_blocks[index] = World::Block::Ice;
                } else if (zoneMap[index] > -0.333) {
                    m_blocks[index] = World::Block::Stone;
                } else {
                    m_blocks[index] = World::Block::Trees;
                }

                continue;

            }

            if (x < 512) {
                distanceFromWall = x;
            } else {
                distanceFromWall = 1024 - x;
            }
            if (y < 512) {
                if (y < distanceFromWall) {
                    distanceFromWall = y;
                }
            } else {
                if (1024 - y < distanceFromWall) {
                    distanceFromWall = 1024 - y;
                }
            }
            float cutoff = static_cast<float>(distanceFromWall) / 1536.0;
            float height = heightMap[index] - cutoff;

            if (height > 0.0) {

                if (zoneMap[index] > 0.333) {
                    m_blocks[index] = World::Block::Ice;
                } else if (zoneMap[index] > -0.333) {
                    m_blocks[index] = World::Block::Stone;
                } else {
                    m_blocks[index] = World::Block::Trees;
                }

                continue;

            }

            m_blocks[indexOf(x, y)] = World::Block::Water;

        }
    }

}

void World::setCamera (float x, float y) {

    m_cameraX = x;
    m_cameraY = y;

}

void World::moveCamera (float x, float y) {

    m_cameraX += x;
    m_cameraY += y;

}

void World::render () {

    int centerBlockX = static_cast<int>(m_cameraX / 32.0);
    int centerBlockY = static_cast<int>(m_cameraY / 32.0);

    if (centerBlockX < 16) {
        centerBlockX = 16;
    }

    if (centerBlockX > 1008) {
        centerBlockX = 1008;
    }

    if (centerBlockY < 16) {
        centerBlockY = 16;
    }

    if (centerBlockY > 1008) {
        centerBlockY = 1008;
    }

    for (int y = -16; y < 16; ++y) {
        for (int x = -16; x < 16; ++x) {

            switch (m_blocks[indexOf(x + centerBlockX, y + centerBlockY)]) {

                case World::Block::Ice:
                    m_iceSprite.setPosition(32.0 * (x + 16) - m_cameraX + 400, 32.0 * (y + 16) - m_cameraY + 300);
                    Window::draw(m_iceSprite);
                    break;

                case World::Block::Stone:
                    m_stoneSprite.setPosition(32.0 * (x + 16) - m_cameraX + 400, 32.0 * (y + 16) - m_cameraY + 300);
                    Window::draw(m_stoneSprite);
                    break;

                case World::Block::Trees:
                    m_treesSprite.setPosition(32.0 * (x + 16) - m_cameraX + 400, 32.0 * (y + 16) - m_cameraY + 300);
                    Window::draw(m_treesSprite);
                    break;

                case World::Block::Water:
                default:
                    m_waterSprite.setPosition(32.0 * (x + 16) - m_cameraX + 400, 32.0 * (y + 16) - m_cameraY + 300);
                    Window::draw(m_waterSprite);
                    break;

            }

        }
    }

}

unsigned int World::indexOf (unsigned int x, unsigned int y) {

    return y * 1024 + x;

}
