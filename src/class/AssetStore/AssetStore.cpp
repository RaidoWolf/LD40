#include "AssetStore.hpp"

bool AssetStore::imageExists (std::string key) {

    if (m_images.find(key) == m_images.end()) {
        return false;
    } else {
        return true;
    }

}

sf::Image* AssetStore::getImage (std::string key) {

    if (!imageExists(key)) {
        return nullptr;
    }

    return m_images[key];

}

bool AssetStore::soundExists (std::string key) {

    if (m_sounds.find(key) == m_sounds.end()) {
        return false;
    } else {
        return true;
    }

}

sf::Sound* AssetStore::getSound (std::string key) {

    if (!soundExists(key)) {
        return nullptr;
    }

    return m_sounds[key];

}

bool AssetStore::fontExists (std::string key) {

    if (m_fonts.find(key) == m_fonts.end()) {
        return false;
    } else {
        return true;
    }

}

sf::Font* AssetStore::getFont (std::string key) {

    if (!fontExists(key)) {
        return nullptr;
    }

    return m_fonts[key];

}

bool AssetStore::registerImage (std::string key, sf::Image* image) {

    if (imageExists(key)) {
        return false;
    }

    m_images.insert(std::pair<std::string, sf::Image*>(key, image));
    return true;

}

void AssetStore::deleteImage (std::string key) {

    if (!imageExists(key)) {
        return;
    }

    delete m_images[key];
    m_images.erase(key);

}

bool AssetStore::registerSound (std::string key, sf::Sound* sound) {

    if (soundExists(key)) {
        return false;
    }

    m_sounds.insert(std::pair<std::string, sf::Sound*>(key, sound));
    return true;

}

void AssetStore::deleteSound (std::string key) {

    if (!soundExists(key)) {
        return;
    }

    delete m_sounds[key];
    m_sounds.erase(key);

}

bool AssetStore::registerFont (std::string key, sf::Font* font) {

    if (fontExists(key)) {
        return false;
    }

    m_fonts.insert(std::pair<std::string, sf::Font*>(key, font));
    return true;

}

void AssetStore::deleteFont (std::string key) {

    if (!fontExists(key)) {
        return;
    }

    delete m_fonts[key];
    m_fonts.erase(key);

}

std::map<std::string, sf::Image*> AssetStore::m_images;
std::map<std::string, sf::Sound*> AssetStore::m_sounds;
std::map<std::string, sf::Font*> AssetStore::m_fonts;
