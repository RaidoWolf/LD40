#ifndef H_CLASS_CONTROLLER
#define H_CLASS_CONTROLLER

#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
#include "../Log/Log.hpp"
#include "../Keybinding/Keybinding.hpp"
#include "../LoopKeybinding/LoopKeybinding.hpp"

class Controller {

public:

    typedef std::function<void(sf::Uint32)> TextCallback;
    typedef std::function<void(double,double)> CursorCallback;
    typedef std::function<void()> CursorInCallback;
    typedef std::function<void()> CursorOutCallback;
    typedef std::function<void()> FocusCallback;
    typedef std::function<void()> UnfocusCallback;
    typedef std::function<void(int,int,int)> MouseButtonPressCallback;
    typedef std::function<void(int,int,int)> MouseButtonReleaseCallback;
    typedef std::function<void(int,int,int)> LoopMouseButtonCallback;
    typedef std::function<void(double)> ScrollCallback;
    typedef std::function<void(int,int)> ResizeCallback;

    Controller ();
    ~Controller () = default;

    Controller (Controller&&) = default;
    Controller& operator = (Controller&&) = default;

    Controller (const Controller&) = default;
    Controller& operator = (const Controller&) = default;

    void loopCheck ();

    void onKeyPress (sf::Keyboard::Key, bool, bool, bool);
    void onKeyRelease (sf::Keyboard::Key, bool, bool, bool);
    void onLoopKey (const std::vector<sf::Keyboard::Key>&);
    void onText (sf::Uint32);
    void onCursor (double, double);
    void onCursorIn ();
    void onCursorOut ();
    void onFocus ();
    void onUnfocus ();
    void onMouseButtonPress (int, int, int);
    void onMouseButtonRelease (int, int, int);
    void onLoopMouseButton (int, int, int);
    void onScroll (double);
    void onResize (int, int);

    std::vector<Keybinding> getKeybindings () const;
    std::vector<LoopKeybinding> getLoopKeybindings () const;

    void setKeybindings (const std::vector<Keybinding>&);
    void addKeybinding (const Keybinding&);
    void clearKeybindings ();
    void setLoopKeybindings (const std::vector<LoopKeybinding>&);
    void addLoopKeybinding (const LoopKeybinding&);
    void clearLoopKeybindings ();
    void addTextCallback (const TextCallback&);
    void clearTextCallbacks ();
    void addCursorCallback (const CursorCallback&);
    void clearCursorCallbacks ();
    void addCursorInCallback (const CursorInCallback&);
    void clearCursorInCallbacks ();
    void addCursorOutCallback (const CursorOutCallback&);
    void clearCursorOutCallbacks ();
    void addFocusCallback (const FocusCallback&);
    void clearFocusCallbacks ();
    void addUnfocusCallback (const UnfocusCallback&);
    void clearUnfocusCallbacks();
    void addMouseButtonPressCallback (const MouseButtonPressCallback&);
    void clearMouseButtonPressCallbacks ();
    void addMouseButtonReleaseCallback (const MouseButtonReleaseCallback&);
    void clearMouseButtonReleaseCallbacks ();
    void addLoopMouseButtonCallback (const LoopMouseButtonCallback&);
    void clearLoopMouseButtonCallbacks ();
    void addScrollCallback (const ScrollCallback&);
    void clearScrollCallbacks ();
    void addResizeCallback (const ResizeCallback&);
    void clearResizeCallbacks ();

private:

    std::vector<Keybinding> m_keybindings;
    std::vector<LoopKeybinding> m_loopKeybindings;
    std::vector<sf::Keyboard::Key> m_keysToLoop;

    std::vector<TextCallback> m_textCallbacks;
    std::vector<CursorCallback> m_cursorCallbacks;
    std::vector<CursorInCallback> m_cursorInCallbacks;
    std::vector<CursorOutCallback> m_cursorOutCallbacks;
    std::vector<FocusCallback> m_focusCallbacks;
    std::vector<UnfocusCallback> m_unfocusCallbacks;
    std::vector<MouseButtonPressCallback> m_mouseButtonPressCallbacks;
    std::vector<MouseButtonReleaseCallback> m_mouseButtonReleaseCallbacks;
    std::vector<LoopMouseButtonCallback> m_loopMouseButtonCallbacks;
    std::vector<ScrollCallback> m_scrollCallbacks;
    std::vector<ResizeCallback> m_resizeCallbacks;

    bool m_mouseIsDown = false;
    int m_lastButtons = 0;
    int m_lastMouseX = 0;
    int m_lastMouseY = 0;

};

#endif
