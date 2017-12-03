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

    bool check (const std::vector<sf::Keyboard::Key>&);
    void process (const std::vector<sf::Keyboard::Key>&);

    LoopKeybindingCallback m_callback;
    std::vector<sf::Keyboard::Key> m_keys;

};

#endif
