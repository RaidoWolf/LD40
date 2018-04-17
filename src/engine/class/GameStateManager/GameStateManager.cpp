#include "GameStateManager.hpp"

void GameStateManager::pushState (const std::shared_ptr<GameState>& state) {

    m_states.push_back(state);
    state->onPush();
    state->onActivate();

    if (m_states.size() > 1) {
        auto prev = m_states[m_states.size() - 2];
        prev->onDeactivate();
        for (int i = m_states.size() - 2; i >= 0; --i) {
            m_states[i]->onDescend();
        }
    }

    refreshLiveStates();

}

void GameStateManager::pushState (GameState* state) {

    std::shared_ptr<GameState> ptrState(state);
    pushState(ptrState);

}

bool GameStateManager::pushState (const std::string& key) {

    if (!GameStateStore::stateExists(key)) {
        return false;
    }

    auto state = GameStateStore::getState(key);
    pushState(state);

    return true;

}

void GameStateManager::dropState () {

    auto top = m_states[m_states.size() - 1];
    top->onDeactivate();
    top->onPop();
    top.reset();

    if (m_states.size() > 0) {
        auto top = m_states[m_states.size() - 1];
        top->onActivate();
        for (int i = m_states.size() - 1; i >= 0; --i) {
            m_states[i]->onAscend();
        }
    }

    refreshLiveStates();

}

std::shared_ptr<GameState> GameStateManager::popState () {

    auto top = m_states[m_states.size() - 1];
    top->onDeactivate();
    top->onPop();

    if (m_states.size() > 0) {
        auto newTop = m_states[m_states.size() - 1];
        newTop->onActivate();
        for (int i = m_states.size() - 1; i >= 0; --i) {
            m_states[i]->onAscend();
        }
    }

    refreshLiveStates();

    return top;

}

void GameStateManager::refreshLiveStates () {

    std::vector<std::shared_ptr<GameState>> liveRenderStates;
    std::vector<std::shared_ptr<GameState>> liveUpdateStates;
    std::vector<std::shared_ptr<GameState>> liveInputStates;

    auto top = m_states[m_states.size() - 1];
    liveRenderStates.push_back(top);
    liveUpdateStates.push_back(top);
    liveInputStates.push_back(top);

    if (
        m_states.size() > 1 &&
        (
            top->transparentRender ||
            top->transparentUpdate ||
            top->transparentInput
        )
    ) {

        auto prev = top;
        bool renderBroken = !prev->transparentRender;
        bool updateBroken = !prev->transparentUpdate;
        bool inputBroken = !prev->transparentInput;

        for (int i = m_states.size() - 2; i >= 0; --i) {

            auto cur = m_states[i];

            if (renderBroken && updateBroken && inputBroken) {
                break;
            }

            if (prev->transparentRender) {
                liveRenderStates.push_back(cur);
            } else {
                renderBroken = true;
            }

            if (prev->transparentUpdate) {
                liveUpdateStates.push_back(cur);
            } else {
                updateBroken = true;
            }

            if (prev->transparentInput) {
                liveInputStates.push_back(cur);
            } else {
                inputBroken = true;
            }

            prev = m_states[i];

        }

    }

    m_statesLiveRender = liveRenderStates;
    m_statesLiveUpdate = liveUpdateStates;
    m_statesLiveInput = liveInputStates;

}

void GameStateManager::clearWindow () {

    for (int i = m_statesLiveRender.size() - 1; i >= 0; --i) {
        m_statesLiveRender[i]->clearWindow();
    }

}

void GameStateManager::render (double deltaTime) {

    for (int i = 0; i < m_statesLiveRender.size(); ++i) {
        m_statesLiveRender[i]->render(deltaTime);
    }

}

void GameStateManager::update () {

    for (int i = 0; i < m_statesLiveUpdate.size(); ++i) {
        m_statesLiveUpdate[i]->update();
    }

}

void GameStateManager::loopInput () {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().loopCheck();
    }

}

void GameStateManager::keyPressCallback (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onKeyPress(key, alt, control, shift);
    }

}

void GameStateManager::keyReleaseCallback (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onKeyRelease(key, alt, control, shift);
    }

}

void GameStateManager::textCallback (sf::Uint32 character) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onText(character);
    }

}

void GameStateManager::cursorCallback (double xPos, double yPos) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onCursor(xPos, yPos);
    }

}

void GameStateManager::cursorInCallback () {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onCursorIn();
    }

}

void GameStateManager::cursorOutCallback () {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onCursorOut();
    }

}

void GameStateManager::focusCallback () {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onFocus();
    }

}

void GameStateManager::unfocusCallback () {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onUnfocus();
    }

}

void GameStateManager::mouseButtonPressCallback (int buttons, int x, int y) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onMouseButtonPress(buttons, x, y);
    }

}

void GameStateManager::mouseButtonReleaseCallback (int buttons, int x, int y) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onMouseButtonRelease(buttons, x, y);
    }

}

void GameStateManager::scrollCallback (double offset) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onScroll(offset);
    }

}

void GameStateManager::resizeCallback (int width, int height) {

    for (int i = 0; i < m_statesLiveInput.size(); ++i) {
        m_statesLiveInput[i]->getController().onResize(width, height);
    }

}

std::vector<std::shared_ptr<GameState>> GameStateManager::m_states;

std::vector<std::shared_ptr<GameState>> GameStateManager::m_statesLiveRender;
std::vector<std::shared_ptr<GameState>> GameStateManager::m_statesLiveUpdate;
std::vector<std::shared_ptr<GameState>> GameStateManager::m_statesLiveInput;
