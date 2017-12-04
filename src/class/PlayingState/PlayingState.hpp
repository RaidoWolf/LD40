#ifndef H_CLASS_PLAYINGSTATE
#define H_CLASS_PLAYINGSTATE

#include <functional>
#include <SFML/Graphics.hpp>
#include "../GameState/GameState.hpp"
#include "../GameStateManager/GameStateManager.hpp"
#include "../Controller/Controller.hpp"
#include "../World/World.hpp"
#include "../LoopKeybinding/LoopKeybinding.hpp"

class PlayingState : public GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    PlayingState ();
    ~PlayingState ();

    void onActivate ();
    void onDeactivate ();
    void onPush ();
    void onPop ();
    void onAscend ();
    void onDescend ();

    void render (double);
    void update ();

private:

    World* m_world = nullptr;

};

#endif
