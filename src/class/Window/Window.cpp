#include "Window.hpp"

sf::RenderWindow* Window::getContext () {

    return m_context;

}

bool Window::exists () {

    return m_context != nullptr;

}

bool Window::isOpen () {

    if (!Window::exists()) {
        return false;
    }

    if (m_context->isOpen()) {
        return true;
    }

}

void Window::open () {

    if (Window::exists()) {
        Log::warning("Window cannot be opened because it is already open.");
        return;
    }

    m_context = new sf::RenderWindow(
        sf::VideoMode(m_width, m_height),
        m_title,
        sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar
    );

    if (!m_context) {
        Log::error("Failed to create a window.");
        return;
    }

    Log::verbose("Window opened.");

}

void Window::close () {

    if (!Window::isOpen()) {
        Log::warning("Window cannot be closed because it is not open.");
    }

    Log::verbose("Closing window.");
    m_context->close();
    if (m_context) {
        delete m_context;
    }

}

void Window::display () {

    if (!Window::exists()) {
        Log::warning("Cannot display window because it is not open.");
        return;
    }

    m_context->display();

}

void Window::draw (const sf::Drawable& drawable, const sf::RenderStates& states) {

    m_context->draw(drawable, states);

}

void Window::clear () {

    if (!Window::exists()) {
        Log::warning("Cannot clear window because it is not open.");
        return;
    }

    m_context->clear();

}

void Window::clear (const sf::Color color) {

    if (!Window::exists()) {
        Log::warning("Cannot clear window because it is not open.");
    }

    m_context->clear(color);

}

bool Window::pollEvent (sf::Event& windowEvent) {

    return m_context->pollEvent(windowEvent);

}

int Window::getWidth () {

    return m_width;

}

int Window::getHeight () {

    return m_height;

}

void Window::setWidth (const int width) {

    std::unique_lock<std::mutex> lock_size(mutex_size);

    m_width = width;
    pushWindowSize();

}

void Window::setHeight (const int height) {

    std::unique_lock<std::mutex> lock_size(mutex_size);

    m_height = height;
    pushWindowSize();

}

void Window::setSize (const int width, const int height) {

    std::unique_lock<std::mutex> lock_size(mutex_size);

    m_width = width;
    m_height = height;
    pushWindowSize();

}

std::string Window::getTitle () {

    return m_title;

}

void Window::setTitle (const std::string title) {

    std::unique_lock<std::mutex> lock_title(mutex_title);

    m_title = title;
    pushWindowTitle();

}

void Window::pushWindowSize () {

    if (m_context) {
        m_context->setSize(sf::Vector2u(m_width, m_height));
    }

}

void Window::pushWindowTitle () {

    if (m_context) {
        m_context->setTitle(sf::String(m_title));
    }

}

sf::RenderWindow* Window::m_context = nullptr;

int Window::m_width = 800;
int Window::m_height = 600;
std::mutex Window::mutex_size;

std::string Window::m_title = "";
std::mutex Window::mutex_title;
