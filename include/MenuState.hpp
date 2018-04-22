#ifndef H_CLASS_MENUSTATE
#define H_CLASS_MENUSTATE

#include <functional>
#include <ArcticWolf/GameState.hpp>
#include <ArcticWolf/GameStateManager.hpp>
#include <ArcticWolf/LoopKeybinding.hpp>
#include <ArcticWolf/AssetStore.hpp>
#include <ArcticWolf/Button.hpp>
#include <ArcticWolf/Log.hpp>

class MenuState : public aw::GameState {

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
    aw::Button m_startButton {
        m_startButtonCallback,
        m_controller,
        "main",
        "Start",
        50.0,
        12.0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 255),
        aw::Button::Alignment::Center
    };

    sf::Texture m_titleTexture;
    sf::Sprite m_titleSprite;

};

#endif
