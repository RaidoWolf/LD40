#include "Keybinding.hpp"

Keybinding::Keybinding (
    const KeybindingCallback& callback,
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

const Keybinding::KeybindingCallback& Keybinding::getCallback () const {

    return m_callback;

}

bool Keybinding::getAction () const {

    return m_action;

}

sf::Keyboard::Key Keybinding::getKey () const {

    return m_key;

}

bool Keybinding::getAlt () const {

    return m_alt;

}

bool Keybinding::getControl () const {

    return m_control;

}

bool Keybinding::getShift () const {

    return m_shift;

}

void Keybinding::setCallback (const KeybindingCallback& callback) {

    m_callback = callback;

}

void Keybinding::setAction (bool action) {

    m_action = action;

}

void Keybinding::setKey (sf::Keyboard::Key key) {

    m_key = key;

}

void Keybinding::setAlt (bool alt) {

    m_alt = alt;

}

void Keybinding::setControl (bool control) {

    m_control = control;

}

void Keybinding::setShift (bool shift) {

    m_shift = shift;

}