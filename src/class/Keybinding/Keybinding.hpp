#ifndef H_CLASS_KEYBINDING
#define H_CLASS_KEYBINDING

#include <vector>
#include <functional>
#include <SFML/Window.hpp>

class Keybinding {

public:

    typedef std::function < void () > KeybindingCallback;

    Keybinding (KeybindingCallback, bool, sf::Keyboard::Key, bool, bool, bool);

    bool check (bool, sf::Keyboard::Key, bool, bool, bool);
    void process (bool, sf::Keyboard::Key, bool, bool, bool);

    KeybindingCallback m_callback;
    bool m_action;
    sf::Keyboard::Key m_key;
    bool m_alt;
    bool m_control;
    bool m_shift;

};

#endif
