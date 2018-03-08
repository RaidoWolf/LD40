#ifndef H_CLASS_LOOPKEYBINDING
#define H_CLASS_LOOPKEYBINDING

#include <vector>
#include <functional>
#include <SFML/Window.hpp>

class LoopKeybinding {

public:

    typedef std::function < void () > LoopKeybindingCallback;

    LoopKeybinding (LoopKeybindingCallback, sf::Keyboard::Key);
    LoopKeybinding (LoopKeybindingCallback, std::vector<sf::Keyboard::Key>&);
    ~ LoopKeybinding () = default;

    LoopKeybinding (LoopKeybinding&&) = default;
    LoopKeybinding& operator = (LoopKeybinding&&) = default;

    LoopKeybinding (const LoopKeybinding&) = default;
    LoopKeybinding& operator = (const LoopKeybinding&) = default;

    bool check (const std::vector<sf::Keyboard::Key>&);
    void process (const std::vector<sf::Keyboard::Key>&);

    const LoopKeybindingCallback& getCallback () const;
    std::vector<sf::Keyboard::Key> getKeys () const;

    void setCallback (LoopKeybindingCallback);
    void setKeys (std::vector<sf::Keyboard::Key>);

private:

    LoopKeybindingCallback m_callback;
    std::vector<sf::Keyboard::Key> m_keys;

};

#endif
