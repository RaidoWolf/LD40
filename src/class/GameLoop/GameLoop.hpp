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

    static void setRenderFrameRate (int);
    static void setUpdateTickRate (int);

    static void run ();
    static void freeze ();
    static bool isRunning ();

private:

    GameLoop () = delete;

    static void update (sf::Clock&, int&, double&, bool&, bool&, bool&);

    static void render (double);

    static int m_renderFrameRate;
    static int m_updateTickRate;

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
