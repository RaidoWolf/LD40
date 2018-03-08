#ifndef H_CLASS_MENUSTATE
#define H_CLASS_MENUSTATE

#include <functional>
#include "../../engine/class/GameState/GameState.hpp"
#include "../../engine/class/GameStateManager/GameStateManager.hpp"
#include "../../engine/class/LoopKeybinding/LoopKeybinding.hpp"
#include "../../engine/class/AssetStore/AssetStore.hpp"
#include "../../engine/class/Button/Button.hpp"
#include "../../engine/class/Log/Log.hpp"

class MenuState : public GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    MenuState ();
    ~MenuState () override = default;

    MenuState (MenuState&&) = default;
    MenuState& operator = (MenuState&&) = default;

    MenuState (const MenuState&) = default;
    MenuState& operator = (const MenuState&) = default;

    void onActivate () override;
    void onDeactivate () override;
    void onPush () override;
    void onPop () override;
    void onAscend () override;
    void onDescend () override;

    void render (double) override;
    void update () override;

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
