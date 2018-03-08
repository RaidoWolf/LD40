#ifndef H_CLASS_GAMELOOP
#define H_CLASS_GAMELOOP

#include <thread>
#include <chrono>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../GameStateManager/GameStateManager.hpp"
#include "../Window/Window.hpp"
#include "../Log/Log.hpp"

class GameLoop {

public:

    GameLoop () = delete;
    ~GameLoop () = delete;

    GameLoop (GameLoop&&) = delete;
    GameLoop& operator = (GameLoop&&) = delete;

    GameLoop (const GameLoop&) = delete;
    GameLoop& operator = (const GameLoop&) = delete;

    static unsigned int getRenderFrameRate ();
    static unsigned int getUpdateTickRate ();

    static void setRenderFrameRate (unsigned int);
    static void setUpdateTickRate (unsigned int);

    static void run ();
    static void freeze ();
    static bool isRunning ();

private:

    static void update (sf::Clock&, unsigned int&, double&, bool&, bool&, bool&);

    static void render (double);

    static unsigned int m_renderFrameRate;
    static unsigned int m_updateTickRate;

    static double m_renderSeconds;
    static double m_updateSeconds;

    static sf::Clock m_updateLoopClock;

    static bool m_windowOpen;
    static bool m_isRunning;

    static bool m_renderLoopRunning;
    static bool m_updateLoopRunning;

    static std::thread m_updateThread;

};

#endif
