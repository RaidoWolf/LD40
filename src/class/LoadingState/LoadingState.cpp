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

    auto mainFont = AssetStore::createFont("main");
    if (!mainFont->loadFromFile("./res/fonts/poiretone/PoiretOne-Regular.ttf")) {
        Log::warning("Could not load ./res/fonts/poiretone/PoiretOne-Regular.ttf.");
    }

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

void LoadingState::onActivate () {

    Log::verbose("Loading...");

    auto titleImage = AssetStore::createImage("title");
    if (!titleImage->loadFromFile("./res/images/speedfishing-title.png")) {
        Log::warning("Could not load ./res/images/speedfishing-title.png.");
    }
    m_progressBar.setFill(0.1666);

    auto treesImage = AssetStore::createImage("trees");
    if (!treesImage->loadFromFile("./res/images/trees.png")) {
        Log::warning("Could not load ./res/images/trees.png");
    }
    m_progressBar.setFill(0.3333);

    auto stoneImage = AssetStore::createImage("stone");
    if (!stoneImage->loadFromFile("./res/images/stone.png")) {
        Log::warning("Could not load ./res/images/stone.png");
    }
    m_progressBar.setFill(0.5);

    auto iceImage = AssetStore::createImage("ice");
    if (!iceImage->loadFromFile("./res/images/ice.png")) {
        Log::warning("Could not load ./res/images/ice.png");
    }
    m_progressBar.setFill(0.6667);

    auto waterImage = AssetStore::createImage("water");
    if (!waterImage->loadFromFile("./res/images/water.png")) {
        Log::warning("Could not load ./res/images/water.png");
    }
    m_progressBar.setFill(0.8333);

    auto boatyMcBoatFaceImage = AssetStore::createImage("boatyMcBoatFace");
    if (!boatyMcBoatFaceImage->loadFromFile("./res/images/player-boat.png")) {
        Log::warning("Could not load ./res/images/player-boat.png");
    }
    m_progressBar.setFill(1.0);

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

    if (m_progressBar.getFill() == 1.0) {
        GameStateManager::pushState("menu");
    }

}
