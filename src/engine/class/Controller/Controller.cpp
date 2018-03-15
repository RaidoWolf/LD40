#include "Controller.hpp"

Controller::Controller () {}

void Controller::loopCheck () {

    if (m_mouseIsDown) {
        onLoopMouseButton(m_lastButtons, m_lastMouseX, m_lastMouseY);
    }

    std::vector<sf::Keyboard::Key> down;
    for (int i = 0; i < m_keysToLoop.size(); ++i) {
        if (sf::Keyboard::isKeyPressed(m_keysToLoop[i])) {
            down.push_back(m_keysToLoop[i]);
        }
    }

    if (down.size() > 0) {
        onLoopKey(down);
    }

}

void Controller::onKeyPress (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    for (int i = 0; i < m_keybindings.size(); ++i) {
        m_keybindings[i].process(true, key, alt, control, shift);
    }

}

void Controller::onKeyRelease (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    for (int i = 0; i < m_keybindings.size(); ++i) {
        m_keybindings[i].process(false, key, alt, control, shift);
    }

}

void Controller::onLoopKey (const std::vector<sf::Keyboard::Key>& keys) {

    for (int i = 0; i < m_loopKeybindings.size(); ++i) {
        m_loopKeybindings[i].process(keys);
    }

}

void Controller::onText (sf::Uint32 character) {

    for (int i = 0; i < m_textCallbacks.size(); ++i) {
        m_textCallbacks[i](character);
    }

}

void Controller::onCursor (double xPos, double yPos) {

    m_lastMouseX = xPos;
    m_lastMouseY = yPos;
    for (int i = 0; i < m_cursorCallbacks.size(); ++i) {
        m_cursorCallbacks[i](xPos, yPos);
    }

}

void Controller::onCursorIn () {

    for (int i = 0; i < m_cursorInCallbacks.size(); ++i) {
        m_cursorInCallbacks[i]();
    }

}

void Controller::onCursorOut () {

    for (int i = 0; i < m_cursorOutCallbacks.size(); ++i) {
        m_cursorOutCallbacks[i]();
    }

}

void Controller::onFocus () {

    for (int i = 0; i < m_focusCallbacks.size(); ++i) {
        m_focusCallbacks[i]();
    }

}

void Controller::onUnfocus () {

    for (int i = 0; i < m_unfocusCallbacks.size(); ++i) {
        m_unfocusCallbacks[i]();
    }

}

void Controller::onMouseButtonPress (int buttons, int x, int y) {

    m_lastButtons = buttons;
    m_lastMouseX = x;
    m_lastMouseY = y;
    m_mouseIsDown = true;
    for (int i = 0; i < m_mouseButtonPressCallbacks.size(); ++i) {
        m_mouseButtonPressCallbacks[i](buttons, x, y);
    }

}

void Controller::onMouseButtonRelease (int buttons, int x, int y) {

    m_mouseIsDown = false;
    for (int i = 0; i < m_mouseButtonReleaseCallbacks.size(); ++i) {
        m_mouseButtonReleaseCallbacks[i](buttons, x, y);
    }

}

void Controller::onLoopMouseButton (int buttons, int x, int y) {

    for (int i = 0; i < m_loopMouseButtonCallbacks.size(); ++i) {
        m_loopMouseButtonCallbacks[i](buttons, x, y);
    }

}

void Controller::onScroll (double offset) {

    for (int i = 0; i < m_scrollCallbacks.size(); ++i) {
        m_scrollCallbacks[i](offset);
    }

}

void Controller::onResize (int width, int height) {

    for (int i = 0; i < m_resizeCallbacks.size(); ++i) {
        m_resizeCallbacks[i](width, height);
    }

}

std::vector<Keybinding> Controller::getKeybindings () const {

    return m_keybindings;

}

std::vector<LoopKeybinding> Controller::getLoopKeybindings () const {

    return m_loopKeybindings;

}

void Controller::setKeybindings (const std::vector<Keybinding>& keybindings) {

    m_keybindings = keybindings;

}

void Controller::addKeybinding (const Keybinding& keybinding) {

    m_keybindings.push_back(std::move(keybinding));

}

void Controller::clearKeybindings () {

    m_keybindings = std::vector<Keybinding>();

}

void Controller::setLoopKeybindings (const std::vector<LoopKeybinding>& loopKeybindings) {

    clearLoopKeybindings();

    for (int i = 0; i < loopKeybindings.size(); ++i) {
        addLoopKeybinding(loopKeybindings[i]);
    }

}

void Controller::addLoopKeybinding (const LoopKeybinding& loopKeybinding) {

    for (int i = 0; i < loopKeybinding.getKeys().size(); ++i) {
        bool insert = true;
        for (int j = 0; j < m_keysToLoop.size(); ++j) {
            if (loopKeybinding.getKeys()[i] == m_keysToLoop[j]) {
                insert = false;
                break;
            }
        }
        if (insert) {
            m_keysToLoop.push_back(loopKeybinding.getKeys()[i]);
        } else {
            insert = true;
        }
    }

    m_loopKeybindings.push_back(loopKeybinding);

}

void Controller::clearLoopKeybindings () {

    m_loopKeybindings = std::vector<LoopKeybinding>();
    m_keysToLoop = std::vector<sf::Keyboard::Key>();

}

void Controller::addTextCallback (const TextCallback& textCallback) {

    m_textCallbacks.push_back(textCallback);

}

void Controller::clearTextCallbacks () {

    m_textCallbacks = std::vector<TextCallback>();

}

void Controller::addCursorCallback (const CursorCallback& cursorCallback) {

    m_cursorCallbacks.push_back(cursorCallback);

}

void Controller::clearCursorCallbacks () {

    m_cursorCallbacks = std::vector<CursorCallback>();

}

void Controller::addCursorInCallback (const CursorInCallback& cursorInCallback) {

    m_cursorInCallbacks.push_back(cursorInCallback);

}

void Controller::clearCursorInCallbacks () {

    m_cursorInCallbacks = std::vector<CursorInCallback>();

}

void Controller::addCursorOutCallback (const CursorOutCallback& cursorOutCallback) {

    m_cursorOutCallbacks.push_back(cursorOutCallback);

}

void Controller::clearCursorOutCallbacks () {

    m_cursorOutCallbacks = std::vector<CursorOutCallback>();

}

void Controller::addFocusCallback (const FocusCallback& focusCallback) {

    m_focusCallbacks.push_back(focusCallback);

}

void Controller::clearFocusCallbacks () {

    m_focusCallbacks = std::vector<FocusCallback>();

}

void Controller::addUnfocusCallback (const UnfocusCallback& unfocusCallback) {

    m_unfocusCallbacks.push_back(unfocusCallback);

}

void Controller::clearUnfocusCallbacks () {

    m_unfocusCallbacks = std::vector<UnfocusCallback>();

}

void Controller::addMouseButtonPressCallback (const MouseButtonPressCallback& mouseButtonPressCallback) {

    m_mouseButtonPressCallbacks.push_back(mouseButtonPressCallback);

}

void Controller::clearMouseButtonPressCallbacks () {

    m_mouseButtonPressCallbacks = std::vector<MouseButtonPressCallback>();

}

void Controller::addMouseButtonReleaseCallback (const MouseButtonReleaseCallback& mouseButtonReleaseCallback) {

    m_mouseButtonReleaseCallbacks.push_back(mouseButtonReleaseCallback);

}

void Controller::clearMouseButtonReleaseCallbacks () {

    m_mouseButtonReleaseCallbacks = std::vector<MouseButtonReleaseCallback>();

}

void Controller::addLoopMouseButtonCallback (const LoopMouseButtonCallback& loopMouseButtonCallback) {

    m_loopMouseButtonCallbacks.push_back(loopMouseButtonCallback);

}

void Controller::clearLoopMouseButtonCallbacks () {

    m_loopMouseButtonCallbacks = std::vector<LoopMouseButtonCallback>();

}

void Controller::addScrollCallback (const ScrollCallback& scrollCallback) {

    m_scrollCallbacks.push_back(scrollCallback);

}

void Controller::clearScrollCallbacks () {

    m_scrollCallbacks = std::vector<ScrollCallback>();

}

void Controller::addResizeCallback (const ResizeCallback& resizeCallback) {

    m_resizeCallbacks.push_back(resizeCallback);

}

void Controller::clearResizeCallbacks () {

    m_resizeCallbacks = std::vector<ResizeCallback>();

}
