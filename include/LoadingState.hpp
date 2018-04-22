#ifndef H_CLASS_LOADINGSTATE
#define H_CLASS_LOADINGSTATE

#include <ArcticWolf/GameState.hpp>
#include <ArcticWolf/GameStateManager.hpp>
#include <ArcticWolf/LoopKeybinding.hpp>
#include <ArcticWolf/AssetStore.hpp>
#include <ArcticWolf/ProgressBar.hpp>
#include <ArcticWolf/Log.hpp>

class LoadingState : public aw::GameState {

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

    aw::ProgressBar m_progressBar;
    sf::Text m_loadingText;

};

#endif
