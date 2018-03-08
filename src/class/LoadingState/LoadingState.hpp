#ifndef H_CLASS_LOADINGSTATE
#define H_CLASS_LOADINGSTATE

#include "../../engine/class/GameState/GameState.hpp"
#include "../../engine/class/GameStateManager/GameStateManager.hpp"
#include "../../engine/class/LoopKeybinding/LoopKeybinding.hpp"
#include "../../engine/class/AssetStore/AssetStore.hpp"
#include "../../engine/class/ProgressBar/ProgressBar.hpp"
#include "../../engine/class/Log/Log.hpp"

class LoadingState : public GameState {

public:

    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    LoadingState ();
    ~LoadingState () override = default;

    LoadingState (LoadingState&&) = default;
    LoadingState& operator = (LoadingState&&) = default;

    LoadingState (const LoadingState&) = default;
    LoadingState& operator = (const LoadingState&) = default;

    void onActivate () override;
    void onDeactivate () override;
    void onPush () override;
    void onPop () override;
    void onAscend () override;
    void onDescend () override;

    void render (double) override;
    void update () override;

private:

    ProgressBar m_progressBar;
    sf::Text m_loadingText;

};

#endif
