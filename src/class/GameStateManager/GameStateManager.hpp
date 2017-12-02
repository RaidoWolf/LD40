#ifndef H_CLASS_GAMESTATEMANAGER
#ifndef H_CLASS_GAMESTATEMANAGER

#include <vector>
#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Window/Window.hpp"
#include "../Log/Log.hpp"

class GameStateManager {

public:

    static void pushState (GameState*);
    static void dropState ();
    static GameState* popState ();

    static void refreshLiveStates ();

    static void render (double);

    static void update ();

    static void keyCallback (int, int, int, int = -1);
    static void cursorCallback (double, double);
    static void cursorInOutCallback (int);
    static void mouseButtonCallback (int, int, int);
    static void scrollCallback (double, double);

private:

    GameStateManager () = delete;

    static std::vector<GameState*> m_states;

    static std::vector<GameState*> m_statesLiveRender;
    static std::vector<GameState*> m_statesLiveUpdate;
    static std::vector<GameState*> m_statesLiveInput;

};

#endif
