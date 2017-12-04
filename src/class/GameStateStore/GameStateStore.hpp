#ifndef H_CLASS_GAMESTATESTORE
#define H_CLASS_GAMESTATESTORE

#include <map>
#include <string>
#include "../GameState/GameState.hpp"

class GameStateStore {

public:

    static bool stateExists (std::string);
    static GameState* getState (std::string);

    static bool registerState (std::string, GameState*);
    static void deleteState (std::string);

private:

    GameStateStore () = delete;

    static std::map<std::string, GameState*> m_stateMap;

};

#endif
