#ifndef H_CLASS_KEYBINDING
#define H_CLASS_KEYBINDING

#include <vector>
#include <functional>
#include <SFML/Window.hpp>

class Keybinding {

public:

    typedef std::function <void()> KeybindingCallback;

    Keybinding (const KeybindingCallback&, bool, sf::Keyboard::Key, bool, bool, bool);
    ~Keybinding () = default;

    Keybinding (Keybinding&&) = default;
    Keybinding& operator = (Keybinding&&) = default;

    Keybinding (const Keybinding&) = default;
    Keybinding& operator = (const Keybinding&) = default;

    bool check (bool, sf::Keyboard::Key, bool, bool, bool) const;
    void process (bool, sf::Keyboard::Key, bool, bool, bool);

    const KeybindingCallback& getCallback () const;
    bool getAction () const;
    sf::Keyboard::Key getKey () const;
    bool getAlt () const;
    bool getControl () const;
    bool getShift () const;

    void setCallback (const KeybindingCallback&);
    void setAction (bool);
    void setKey (sf::Keyboard::Key);
    void setAlt (bool);
    void setControl (bool);
    void setShift (bool);

private:

    KeybindingCallback m_callback;
    bool m_action;
    sf::Keyboard::Key m_key;
    bool m_alt;
    bool m_control;
    bool m_shift;

};

#endif
