#include "GameStateStore.hpp"

bool GameStateStore::stateExists (const std::string& key) {

    if (m_stateMap.find(key) == m_stateMap.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<GameState> GameStateStore::getState (const std::string& key) {

    if (!stateExists(key)) {
        return nullptr;
    }

    return m_stateMap[key];

}

bool GameStateStore::registerState (const std::string& key, GameState* gameState) {

    return registerState(key, std::shared_ptr<GameState>(gameState));

}

bool GameStateStore::registerState (const std::string& key, const std::shared_ptr<GameState>& gameState) {

    if (stateExists(key)) {
        return false;
    }

    m_stateMap.insert(std::pair<std::string, std::shared_ptr<GameState>>(key, gameState));
    return true;

}

void GameStateStore::deleteState (const std::string& key) {

    if (!stateExists(key)) {
        return;
    }

    m_stateMap[key].reset();
    m_stateMap.erase(key);

}

std::unordered_map<std::string, std::shared_ptr<GameState>> GameStateStore::m_stateMap;
