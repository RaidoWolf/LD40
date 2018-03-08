#ifndef H_CLASS_GAMESTATESTORE
#define H_CLASS_GAMESTATESTORE

#include <map>
#include <string>
#include <memory>
#include "../GameState/GameState.hpp"

class GameStateStore {

public:

    GameStateStore () = delete; // static only
    ~GameStateStore () = delete;

    GameStateStore (GameStateStore&&) = delete;
    GameStateStore& operator = (GameStateStore&&) = delete;

    GameStateStore (const GameStateStore&) = delete;
    GameStateStore& operator = (const GameStateStore&) = delete;

    static bool stateExists (std::string);
    static std::shared_ptr<GameState> getState (std::string);

    static bool registerState (std::string, GameState*);
    static void deleteState (std::string);

private:

    static std::map<std::string, std::shared_ptr<GameState>> m_stateMap;

};

#endif
