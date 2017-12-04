#ifndef H_CLASS_WINDOW
#define H_CLASS_WINDOW

#include <string>
#include <SFML/Graphics.hpp>
#include "../Log/Log.hpp"

class Window {

public:

    typedef void (* KeyPressCallback) (int, bool, bool, bool);
    typedef void (* KeyReleaseCallback) (int, bool, bool, bool);
    typedef void (* TextCallback) (std::string);
    typedef void (* CursorCallback) (double, double);
    typedef void (* CursorInCallback) ();
    typedef void (* CursorOutCallback) ();
    typedef void (* FocusCallback) ();
    typedef void (* UnfocusCallback) ();
    typedef void (* MouseButtonPressedCallback) (int, int, int);
    typedef void (* MouseButtonReleasedCallback) (int, int, int);
    typedef void (* ScrollCallback) (double);
    typedef void (* ResizeCallback) (int, int);

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
    static void clear (const sf::Color);
    static bool pollEvent (sf::Event&);

    static int getWidth ();
    static int getHeight ();
    static void setWidth (const int);
    static void setHeight (const int);
    static void setSize (const int, const int);

    static std::string getTitle ();
    static void setTitle (const std::string);

    static void setKeyCallback ();

private:

    Window () = delete;

    static void pushWindowSize ();
    static void pushWindowTitle ();

    static sf::RenderWindow* m_context;

    static int m_width;
    static int m_height;
    static std::mutex mutex_size;

    static std::string m_title;
    static std::mutex mutex_title;

};

#endif
