#include "GameLoop.hpp"

unsigned int GameLoop::getRenderFrameRate () {

    return m_renderFrameRate;

}

unsigned int GameLoop::getUpdateTickRate () {

    return m_updateTickRate;

}

void GameLoop::setRenderFrameRate (unsigned int framesPerSecond) {

    m_renderSeconds = 1.0 / framesPerSecond;
    m_renderFrameRate = std::move(framesPerSecond);

}

void GameLoop::setUpdateTickRate (unsigned int ticksPerSecond) {

    m_updateSeconds = 1.0 / ticksPerSecond;
    m_updateTickRate = std::move(ticksPerSecond);

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

                GameStateManager::loopInput();

                sf::Event windowEvent;
                while (Window::pollEvent(windowEvent)) {

                    switch (windowEvent.type) {

                        case sf::Event::Closed:
                            // TODO: onExit in GameStateManager so developer has a chance to clean up before the window is killed
                            Window::close();
                            m_windowOpen = false;
                            m_isRunning = false;
                            m_updateThread.join();
                            return;

                        case sf::Event::Resized:
                            GameStateManager::resizeCallback(
                                windowEvent.size.width,
                                windowEvent.size.height
                            );
                            break;

                        case sf::Event::LostFocus:
                            GameStateManager::focusCallback();
                            break;

                        case sf::Event::GainedFocus:
                            GameStateManager::unfocusCallback();
                            break;

                        case sf::Event::TextEntered:
                            GameStateManager::textCallback(windowEvent.text.unicode);
                            break;

                        case sf::Event::KeyPressed:
                            GameStateManager::keyPressCallback(
                                windowEvent.key.code,
                                windowEvent.key.alt,
                                windowEvent.key.control,
                                windowEvent.key.shift
                            );
                            break;

                        case sf::Event::KeyReleased:
                            GameStateManager::keyReleaseCallback(
                                windowEvent.key.code,
                                windowEvent.key.alt,
                                windowEvent.key.control,
                                windowEvent.key.shift
                            );
                            break;

                        case sf::Event::MouseWheelMoved:
                            GameStateManager::scrollCallback(
                                windowEvent.mouseWheel.delta
                            );
                            break;

                        case sf::Event::MouseButtonPressed:
                            GameStateManager::mouseButtonPressCallback(
                                windowEvent.mouseButton.button,
                                windowEvent.mouseButton.x,
                                windowEvent.mouseButton.y
                            );
                            break;

                        case sf::Event::MouseButtonReleased:
                            GameStateManager::mouseButtonReleaseCallback(
                                windowEvent.mouseButton.button,
                                windowEvent.mouseButton.x,
                                windowEvent.mouseButton.y
                            );
                            break;

                        case sf::Event::MouseMoved:
                            GameStateManager::cursorCallback(
                                windowEvent.mouseMove.x,
                                windowEvent.mouseMove.y
                            );
                            break;

                        case sf::Event::MouseEntered:
                            GameStateManager::cursorInCallback();
                            break;

                        case sf::Event::MouseLeft:
                            GameStateManager::cursorOutCallback();
                            break;

                        default:
                            break;

                    }

                }

                double deltaTime = m_updateLoopClock.getElapsedTime().asSeconds();
                Window::clear();
                GameStateManager::clearWindow();
                render(deltaTime);
                Window::display();

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

    GameStateManager::render(std::move(deltaTime));

}

void GameLoop::update (
    sf::Clock& updateLoopClock,
    unsigned int& updateTickRate,
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
            std::this_thread::sleep_for(std::chrono::duration<double>(updateSeconds - elapsedTime.asSeconds()));
        }

        deltaTime = updateLoopClock.getElapsedTime().asSeconds() - startTime.asSeconds();
        updateLoopClock.restart();

    }

    updateLoopRunning = false;

}

unsigned int GameLoop::m_renderFrameRate = 60;
unsigned int GameLoop::m_updateTickRate = 40;

double GameLoop::m_renderSeconds = 1.0 / 60.0;
double GameLoop::m_updateSeconds = 1.0 / 40.0;

sf::Clock GameLoop::m_updateLoopClock;

bool GameLoop::m_windowOpen = false;
bool GameLoop::m_isRunning = false;

bool GameLoop::m_renderLoopRunning = false;
bool GameLoop::m_updateLoopRunning = false;

std::thread GameLoop::m_updateThread;
