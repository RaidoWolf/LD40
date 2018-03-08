#ifndef H_CLASS_PLAYINGSTATE
#define H_CLASS_PLAYINGSTATE

#include <functional>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../engine/class/GameState/GameState.hpp"
#include "../../engine/class/GameStateManager/GameStateManager.hpp"
#include "../../engine/class/Controller/Controller.hpp"
#include "../../engine/class/LoopKeybinding/LoopKeybinding.hpp"
#include "../World/World.hpp"

class PlayingState : public GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    PlayingState ();
    ~PlayingState () override = default;

    PlayingState (PlayingState&&) = default;
    PlayingState& operator = (PlayingState&&) = default;

    PlayingState (const PlayingState&) = default;
    PlayingState& operator = (const PlayingState&) = default;

    void onActivate () override;
    void onDeactivate () override;
    void onPush () override;
    void onPop () override;
    void onAscend () override;
    void onDescend () override;

    void render (double) override;
    void update () override;

private:

    std::unique_ptr<World> m_world;

};

#endif
