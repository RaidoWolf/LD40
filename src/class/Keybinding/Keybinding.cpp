#include "Keybinding.hpp"

Keybinding::Keybinding (
    KeybindingCallback callback,
    bool action,
    sf::Keyboard::Key key,
    bool alt,
    bool control,
    bool shift
) :
  m_callback(callback),
  m_action(action),
  m_key(key),
  m_alt(alt),
  m_control(control),
  m_shift(shift)
{}

bool Keybinding::check (bool action, sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    if (
        action == m_action &&
        key == m_key &&
        alt == m_alt &&
        control == m_control &&
        shift == m_shift
    ) {
        return true;
    } else {
        return false;
    }

}

void Keybinding::process (bool action, sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    if (check(action, key, alt, control, shift)) {
        m_callback();
    }

}
