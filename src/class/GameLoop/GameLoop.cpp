#include "GameLoop.hpp"

void GameLoop::setRenderFrameRate (int framesPerSecond) {

    m_renderFrameRate = framesPerSecond;
    m_renderSeconds = 1.0 / framesPerSecond;

}

void GameLoop::setUpdateTickRate (int ticksPerSecond) {

    m_updateTickRate = ticksPerSecond;
    m_updateSeconds = 1.0 / ticksPerSecond;

}

void GameLoop::run () {

    m_windowOpen = true;
    m_isRunning = true;

    if (!m_updateLoopRunning) {

        m_updateThread = std::thread(
            update,
            std::ref(m_updateLoopClock),
            std::ref(m_updateTickRate),
            std::ref(m_updateSeconds),
            std::ref(m_windowOpen),
            std::ref(m_isRunning),
            std::ref(m_updateLoopRunning)
        );

    }

    if (!m_renderLoopRunning) {

        m_renderLoopRunning = true;

        while (Window::isOpen()) {

            sf::Clock renderLoopClock;

            if (m_isRunning) {

                if (Window::exists()) {
                    Window::clear();
                }

                sf::Event windowEvent;
                Window::pollEvent(windowEvent);
                input(windowEvent);

                double deltaTime = m_updateLoopClock.getElapsedTime().asSeconds();
                render(deltaTime);

            }

            sf::Time elapsedTime = renderLoopClock.getElapsedTime();

            if (elapsedTime.asSeconds() < m_renderSeconds) {
                std::this_thread::sleep_for(std::chrono::duration<double>(m_renderSeconds - elapsedTime.asSeconds()));
            }

            renderLoopClock.restart();

        }

        m_windowOpen = false;
        m_renderLoopRunning = false;

    }

    m_updateThread.join();

}

void GameLoop::freeze () {

    m_isRunning = false;

}

bool GameLoop::isRunning () {

    return m_isRunning;

}

void GameLoop::render (double deltaTime) {

    GameStateManager::render(deltaTime);

}

void GameLoop::update (
    sf::Clock& updateLoopClock,
    int& updateTickRate,
    double& updateSeconds,
    bool& windowOpen,
    bool& isRunning,
    bool& updateLoopRunning
) {

    updateLoopRunning = true;

    double deltaTime = updateSeconds;
    while (windowOpen) {

        sf::Time startTime = updateLoopClock.getElapsedTime();

        if (isRunning) {

            int ticks = static_cast<int>(deltaTime * updateTickRate);
            for (int i = 0; i < ticks; ++i) {
                GameStateManager::update();
            }

        }

        sf::Time elapsedTime = updateLoopClock.getElapsedTime();

        if (elapsedTime.asSeconds() < updateSeconds) {
            std::this_thread::sleep_for(std::chono::duration<double>(updateSeconds - elapsedTime.asSeconds()));
        }

        deltaTime = updateLoopClock.getElapsedTime().asSeconds() - startTime.asSeconds();
        updateLoopClock.restart();

    }

    updateLoopRunning = false;

}

int GameLoop::m_renderFrameRate = 60;
int GameLoop::m_updateTickRate = 40;

double GameLoop::m_renderSeconds = 1.0 / 60.0;
double GameLoop::m_updateSeconds = 1.0 / 40.0;

sf::Clock GameLoop::m_updateLoopClock;

bool GameLoop::m_windowOpen = false;
bool GameLoop::m_isRunning = false;

bool GameLoop::m_renderLoopRunning = false;
bool GameLoop::m_updateLoopRunning = false;

std::thread GameLoop::m_updateThread;
