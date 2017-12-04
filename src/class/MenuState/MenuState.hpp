#ifndef H_CLASS_MENUSTATE
#define H_CLASS_MENUSTATE

#include <functional>
#include "../GameState/GameState.hpp"
#include "../GameStateManager/GameStateManager.hpp"
#include "../LoopKeybinding/LoopKeybinding.hpp"
#include "../AssetStore/AssetStore.hpp"
#include "../Button/Button.hpp"
#include "../Log/Log.hpp"

class MenuState : public GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    MenuState ();
    ~MenuState ();

    void onActivate ();
    void onDeactivate ();
    void onPush ();
    void onPop ();
    void onAscend ();
    void onDescend ();

    void render (double);
    void update ();

    void startGame ();

private:

    std::function<void()> m_startButtonCallback {
        [this] () {
            this->startGame();
        }
    };
    Button m_startButton {
        m_startButtonCallback,
        m_controller,
        "main",
        "Start",
        50.0,
        12.0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 255),
        Button::Alignment::Center
    };

    sf::Texture m_titleTexture;
    sf::Sprite m_titleSprite;

};

#endif
