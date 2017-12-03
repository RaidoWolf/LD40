#ifndef H_CLASS_GAMESTATE
#define H_CLASS_GAMESTATE

#include "../Controller/Controller.hpp"
class GameStateManager;

class GameState {

public:

    // GameState stacking transparency flags
    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    // constructor and destructor
    GameState () {};
    virtual ~GameState () = 0;

    // state management event callbacks
    virtual void onActivate () {}
    virtual void onDeactivate () {}
    virtual void onPush () {}
    virtual void onPop () {}
    virtual void onAscend () {}
    virtual void onDescend () {}

    // game loop callbacks
    virtual void render (double) {}
    virtual void update () {}

    // input handling
    Controller& getController ();
    void setController (Controller&);
    void clearController ();

private:

    Controller m_controller;

};

#endif
