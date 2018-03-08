#ifndef H_CLASS_GAMESTATE
#define H_CLASS_GAMESTATE

#include "../Controller/Controller.hpp"
#include "../Window/Window.hpp"
class GameStateManager;

class GameState {

public:

    // GameState stacking transparency flags
    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    // constructor and destructor
    GameState ();
    virtual ~GameState () = default;

    GameState (GameState&&) = delete;
    GameState& operator = (GameState&&) = delete;

    GameState (const GameState&) = delete;
    GameState& operator = (const GameState&) = delete;

    // state management event callbacks
    virtual void onActivate () = 0;
    virtual void onDeactivate () = 0;
    virtual void onPush () = 0;
    virtual void onPop () = 0;
    virtual void onAscend () = 0;
    virtual void onDescend () = 0;

    // game loop callbacks
    void clearWindow ();
    virtual void render (double) = 0;
    virtual void update () = 0;

    // input handling
    Controller& getController ();
    void setController (Controller&);
    void clearController ();

protected:

    Controller m_controller;
    bool m_clearWindow = false;
    sf::Color m_clearColor = sf::Color(0, 0, 0, 255);

};

#endif
