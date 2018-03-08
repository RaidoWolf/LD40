#include "LoopKeybinding.hpp"

LoopKeybinding::LoopKeybinding (
    LoopKeybindingCallback callback,
    sf::Keyboard::Key key
) :
  m_callback(callback),
  m_keys(std::vector<sf::Keyboard::Key>(1, key))
{}

LoopKeybinding::LoopKeybinding (
    LoopKeybindingCallback callback,
    std::vector<sf::Keyboard::Key>& keys
) :
  m_callback(callback),
  m_keys(keys)
{}

bool LoopKeybinding::check (const std::vector<sf::Keyboard::Key>& keys) {

    for (int i = 0; i < m_keys.size(); ++i) {
        bool found = false;
        for (int j = 0; j < keys.size(); ++j) {
            if (m_keys[i] == keys[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        } else {
            found = false;
        }
    }

    return true;

}

void LoopKeybinding::process (const std::vector<sf::Keyboard::Key>& keys) {

    if (check(keys)) {
        m_callback();
    }

}

const LoopKeybinding::LoopKeybindingCallback& LoopKeybinding::getCallback () const {

    return m_callback;

}

std::vector<sf::Keyboard::Key> LoopKeybinding::getKeys () const {

    return m_keys;

}

void LoopKeybinding::setCallback (LoopKeybindingCallback callback) {

    m_callback = std::move(callback);

}

void LoopKeybinding::setKeys (std::vector<sf::Keyboard::Key> keys) {

    m_keys = std::move(keys);

}
