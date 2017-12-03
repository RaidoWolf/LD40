#ifndef H_CLASS_LOADINGSTATE
#define H_CLASS_LOADINGSTATE

#include "../GameState/GameState.hpp"
#include "../Log/Log.hpp"

class LoadingState : public GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    LoadingState ();
    ~LoadingState ();

    void onActivate ();
    void onDeactivate ();
    void onPush ();
    void onPop ();
    void onAscend ();
    void onDescend ();

    void render (double);
    void update ();

};

#endif
