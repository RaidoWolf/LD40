#ifndef H_CLASS_GAMESTATEMANAGER
#define H_CLASS_GAMESTATEMANAGER

#include <vector>
#include <memory>
#include <mutex>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../GameState/GameState.hpp"
#include "../GameStateStore/GameStateStore.hpp"
#include "../Window/Window.hpp"
#include "../Log/Log.hpp"

class GameStateManager {

public:

    GameStateManager () = delete; // static only
    ~GameStateManager () = delete;

    GameStateManager (GameStateManager&&) = delete;
    GameStateManager& operator = (GameStateManager&&) = delete;

    GameStateManager (const GameStateManager&) = delete;
    GameStateManager& operator = (const GameStateManager&) = delete;

    static void pushState (std::shared_ptr<GameState>);
    static void pushState (GameState*);
    static bool pushState (std::string);
    static void dropState ();
    static std::shared_ptr<GameState> popState ();

    static void refreshLiveStates ();

    static void clearWindow ();
    static void render (double);

    static void update ();

    static void loopInput ();

    static void keyPressCallback (sf::Keyboard::Key, bool, bool, bool);
    static void keyReleaseCallback (sf::Keyboard::Key, bool, bool, bool);
    static void textCallback (sf::Uint32);
    static void cursorCallback (double, double);
    static void cursorInCallback ();
    static void cursorOutCallback ();
    static void focusCallback ();
    static void unfocusCallback ();
    static void mouseButtonPressCallback (int, int, int);
    static void mouseButtonReleaseCallback (int, int, int);
    static void scrollCallback (double);
    static void resizeCallback (int, int);

private:

    static std::vector<std::shared_ptr<GameState>> m_states;

    static std::vector<std::shared_ptr<GameState>> m_statesLiveRender;
    static std::vector<std::shared_ptr<GameState>> m_statesLiveUpdate;
    static std::vector<std::shared_ptr<GameState>> m_statesLiveInput;

};

#endif
