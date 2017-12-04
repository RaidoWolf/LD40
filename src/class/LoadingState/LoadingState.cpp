#include "LoadingState.hpp"

LoadingState::LoadingState () {

    m_clearWindow = true;
    m_clearColor = sf::Color(255, 255, 255, 255);

    m_progressBar.setWidth(500.0);
    m_progressBar.setHeight(40.0);
    m_progressBar.setPadding(5.0);
    m_progressBar.setOriginToCenter();
    m_progressBar.setPositionX(400.0);
    m_progressBar.setPositionY(300.0);
    m_progressBar.setBackgroundColor(sf::Color(0, 0, 0, 255));
    m_progressBar.setForegroundColor(sf::Color(255, 255, 255, 255));

    sf::Font* mainFont = new sf::Font();
    if (!mainFont->loadFromFile("./res/fonts/poiretone/PoiretOne-Regular.ttf")) {
        Log::warning("Could not load PoiretOne-Regular.ttf.");
    }
    AssetStore::registerFont("main", mainFont);

    m_loadingText = sf::Text("Loading...", *mainFont);
    m_loadingText.setCharacterSize(36);
    m_loadingText.setStyle(sf::Text::Regular);
    m_loadingText.setFillColor(sf::Color(0, 0, 0, 255));
    sf::FloatRect loadingTextRect = m_loadingText.getLocalBounds();
    m_loadingText.setOrigin(
        loadingTextRect.left + loadingTextRect.width * 0.5,
        loadingTextRect.top + loadingTextRect.height * 0.5
    );
    m_loadingText.setPosition(
        sf::Vector2f(
            400.0,
            240.0
        )
    );

}

LoadingState::~LoadingState () {}

void LoadingState::onActivate () {

    Log::verbose("Loading...");

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

void LoadingState::render (double deltaTime) {

    m_progressBar.render();
    Window::draw(m_loadingText);

}

void LoadingState::update () {

    m_progressBar.incrementFill(0.02);
    if (m_progressBar.getFill() == 1.0) {
        GameStateManager::pushState("menu");
    }

}
