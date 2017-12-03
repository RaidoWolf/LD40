#include "LoadingState.hpp"

LoadingState::LoadingState () {}

LoadingState::~LoadingState () {}

void LoadingState::onActivate () {

    Log::verbose("Loading... forever at the moment...");

}

void LoadingState::onDeactivate () {

    Log::verbose("Loading complete!");

}

void LoadingState::onPush () {

    Log::verbose("Loading state pushed.");

}

void LoadingState::onPop () {}

void LoadingState::onAscend () {}

void LoadingState::onDescend () {}

void LoadingState::render (double deltaTime) {}

void LoadingState::update () {}
