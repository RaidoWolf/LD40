#include "GameStateStore.hpp"

bool GameStateStore::stateExists (std::string key) {

    if (m_stateMap.find(key) == m_stateMap.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<GameState> GameStateStore::getState (std::string key) {

    if (!stateExists(key)) {
        return nullptr;
    }

    return m_stateMap[key];

}

bool GameStateStore::registerState (std::string key, GameState* gameState) {

    if (stateExists(key)) {
        return false;
    }

    m_stateMap.insert(std::pair<std::string, std::shared_ptr<GameState>>(std::move(key), gameState));
    return true;

}

void GameStateStore::deleteState (std::string key) {

    if (!stateExists(key)) {
        return;
    }

    m_stateMap[key].reset();
    m_stateMap.erase(key);

}

std::map<std::string, std::shared_ptr<GameState>> GameStateStore::m_stateMap;
