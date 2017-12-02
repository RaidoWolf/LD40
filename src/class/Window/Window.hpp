#ifndef H_CLASS_WINDOW
#define H_CLASS_WINDOW

#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "../Log/Log.hpp"

class Window {

public:

    typedef void (* KeyCallback) (sf::RenderWindow*, int, int, int, int);
    typedef void (* CursorCallback) (sf::RenderWindow*, double, double);
    typedef void (* CursorInOutCallback) (sf::RenderWindow*, int);
    typedef void (* MouseButtonCallback) (sf::RenderWindow*, int, int, int);
    typedef void (* ScrollCallback) (sf::RenderWindow*, double, double);

    static sf::RenderWindow* getContext ();

    static bool exists ();
    static bool isOpen ();
    static void open ();
    static void close ();

    static void display ();
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
