#ifndef H_CLASS_WINDOW
#define H_CLASS_WINDOW

#include <string>
#include <functional>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Log/Log.hpp"

class Window {

public:

    typedef std::function<void(int,bool,bool,bool)> KeyPressCallback;
    typedef std::function<void(int,bool,bool,bool)> KeyReleaseCallback;
    typedef std::function<void(std::string)> TextCallback;
    typedef std::function<void(double,double)> CursorCallback;
    typedef std::function<void()> CursorInCallback;
    typedef std::function<void()> CursorOutCallback;
    typedef std::function<void()> FocusCallback;
    typedef std::function<void()> UnfocusCallback;
    typedef std::function<void(int,int,int)> MouseButtonPressedCallback;
    typedef std::function<void(int,int,int)> MouseButtonReleasedCallback;
    typedef std::function<void(double)> ScrollCallback;
    typedef std::function<void(int,int)> ResizeCallback;

    Window () = delete; // static only
    ~Window () = delete;

    Window (Window&&) = delete;
    Window& operator = (Window&&) = delete;

    Window (const Window&) = delete;
    Window& operator = (const Window&) = delete;

    static sf::RenderWindow* getContext ();

    static bool exists ();
    static bool isOpen ();
    static void open ();
    static void close ();

    static void display ();
    static void draw (
        const sf::Drawable& drawable,
        const sf::RenderStates& states = sf::RenderStates::Default
    );
    static void clear ();
    static void clear (const sf::Color&);
    static bool pollEvent (sf::Event&);

    static int getWidth ();
    static int getHeight ();
    static void setWidth (int);
    static void setHeight (int);
    static void setSize (int, int);

    static std::string getTitle ();
    static void setTitle (const std::string&);

    static void setKeyCallback ();

private:

    static void pushWindowSize ();
    static void pushWindowTitle ();

    static std::unique_ptr<sf::RenderWindow> m_context;

    static int m_width;
    static int m_height;
    static std::mutex mutex_size;

    static std::string m_title;
    static std::mutex mutex_title;

};

#endif
