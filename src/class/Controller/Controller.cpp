#include "Controller.hpp"

Controller::Controller () {}

void Controller::onKeyPress (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    Log::verbose("Key pressed.");
    for (int i = 0; i < m_keybindings.size(); ++i) {
        m_keybindings[i].process(true, key, alt, control, shift);
    }

}

void Controller::onKeyRelease (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    Log::verbose("Key released.");
    for (int i = 0; i < m_keybindings.size(); ++i) {
        m_keybindings[i].process(false, key, alt, control, shift);
    }

}

void Controller::onText (sf::Uint32 character) {

    Log::verbose("Text entered.");
    for (int i = 0; i < m_textCallbacks.size(); ++i) {
        m_textCallbacks[i](character);
    }

}

void Controller::onCursor (double xPos, double yPos) {

    Log::verbose("Cursor moved.");
    for (int i = 0; i < m_cursorCallbacks.size(); ++i) {
        m_cursorCallbacks[i](xPos, yPos);
    }

}

void Controller::onCursorIn () {

    Log::verbose("Cursor entered");
    for (int i = 0; i < m_cursorInCallbacks.size(); ++i) {
        m_cursorInCallbacks[i]();
    }

}

void Controller::onCursorOut () {

    Log::verbose("Cursor exited.");
    for (int i = 0; i < m_cursorOutCallbacks.size(); ++i) {
        m_cursorOutCallbacks[i]();
    }

}

void Controller::onFocus () {

    Log::verbose("Window focused.");
    for (int i = 0; i < m_focusCallbacks.size(); ++i) {
        m_focusCallbacks[i]();
    }

}

void Controller::onUnfocus () {

    Log::verbose("Window unfocused");
    for (int i = 0; i < m_unfocusCallbacks.size(); ++i) {
        m_unfocusCallbacks[i]();
    }

}

void Controller::onMouseButtonPress (int buttons, int x, int y) {

    Log::verbose("Mouse button pressed.");
    for (int i = 0; i < m_mouseButtonPressCallbacks.size(); ++i) {
        m_mouseButtonPressCallbacks[i](buttons, x, y);
    }

}

void Controller::onMouseButtonRelease (int buttons, int x, int y) {

    Log::verbose("Mouse button released.");
    for (int i = 0; i < m_mouseButtonReleaseCallbacks.size(); ++i) {
        m_mouseButtonReleaseCallbacks[i](buttons, x, y);
    }

}

void Controller::onScroll (double offset) {

    Log::verbose("Mouse scrolled.");
    for (int i = 0; i < m_scrollCallbacks.size(); ++i) {
        m_scrollCallbacks[i](offset);
    }

}

void Controller::onResize (int width, int height) {

    Log::verbose("Window resized.");
    for (int i = 0; i < m_resizeCallbacks.size(); ++i) {
        m_resizeCallbacks[i](width, height);
    }

}

std::vector<Keybinding> Controller::getKeybindings () {

    return m_keybindings;

}

void Controller::setKeybindings (std::vector<Keybinding> keybindings) {

    m_keybindings = keybindings;

}

void Controller::addKeybinding (Keybinding keybinding) {

    m_keybindings.push_back(keybinding);

}

void Controller::clearKeybindings () {

    m_keybindings = std::vector<Keybinding>();

}

void Controller::addTextCallback (TextCallback textCallback) {

    m_textCallbacks.push_back(textCallback);

}

void Controller::clearTextCallbacks () {

    m_textCallbacks = std::vector<TextCallback>();

}

void Controller::addCursorCallback (CursorCallback cursorCallback) {

    m_cursorCallbacks.push_back(cursorCallback);

}

void Controller::clearCursorCallbacks () {

    m_cursorCallbacks = std::vector<CursorCallback>();

}

void Controller::addCursorInCallback (CursorInCallback cursorInCallback) {

    m_cursorInCallbacks.push_back(cursorInCallback);

}

void Controller::clearCursorInCallbacks () {

    m_cursorInCallbacks = std::vector<CursorInCallback>();

}

void Controller::addCursorOutCallback (CursorOutCallback cursorOutCallback) {

    m_cursorOutCallbacks.push_back(cursorOutCallback);

}

void Controller::clearCursorOutCallbacks () {

    m_cursorOutCallbacks = std::vector<CursorOutCallback>();

}

void Controller::addFocusCallback (FocusCallback focusCallback) {

    m_focusCallbacks.push_back(focusCallback);

}

void Controller::clearFocusCallbacks () {

    m_focusCallbacks = std::vector<FocusCallback>();

}

void Controller::addUnfocusCallback (UnfocusCallback unfocusCallback) {

    m_unfocusCallbacks.push_back(unfocusCallback);

}

void Controller::clearUnfocusCallbacks () {

    m_unfocusCallbacks = std::vector<UnfocusCallback>();

}

void Controller::addMouseButtonPressCallback (MouseButtonPressCallback mouseButtonPressCallback) {

    m_mouseButtonPressCallbacks.push_back(mouseButtonPressCallback);

}

void Controller::clearMouseButtonPressCallbacks () {

    m_mouseButtonPressCallbacks = std::vector<MouseButtonPressCallback>();

}

void Controller::addMouseButtonReleaseCallback (MouseButtonReleaseCallback mouseButtonReleaseCallback) {

    m_mouseButtonReleaseCallbacks.push_back(mouseButtonReleaseCallback);

}

void Controller::clearMouseButtonReleaseCallbacks () {

    m_mouseButtonReleaseCallbacks = std::vector<MouseButtonReleaseCallback>();

}

void Controller::addScrollCallback (ScrollCallback scrollCallback) {

    m_scrollCallbacks.push_back(scrollCallback);

}

void Controller::clearScrollCallbacks () {

    m_scrollCallbacks = std::vector<ScrollCallback>();

}

void Controller::addResizeCallback (ResizeCallback resizeCallback) {

    m_resizeCallbacks.push_back(resizeCallback);

}

void Controller::clearResizeCallbacks () {

    m_resizeCallbacks = std::vector<ResizeCallback>();

}
