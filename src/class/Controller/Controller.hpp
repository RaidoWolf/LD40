#ifndef H_CLASS_CONTROLLER
#define H_CLASS_CONTROLLER

#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
#include "../Log/Log.hpp"
#include "../Keybinding/Keybinding.hpp"

class Controller {

public:

    typedef std::function < void (sf::Keyboard::Key, bool, bool, bool) > KeyPressCallback;
    typedef std::function < void (sf::Keyboard::Key, bool, bool, bool) > KeyReleaseCallback;
    typedef std::function < void (sf::Uint32) > TextCallback;
    typedef std::function < void (double, double) > CursorCallback;
    typedef std::function < void () > CursorInCallback;
    typedef std::function < void () > CursorOutCallback;
    typedef std::function < void () > FocusCallback;
    typedef std::function < void () > UnfocusCallback;
    typedef std::function < void (int, int, int) > MouseButtonPressCallback;
    typedef std::function < void (int, int, int) > MouseButtonReleaseCallback;
    typedef std::function < void (double) > ScrollCallback;
    typedef std::function < void (int, int) > ResizeCallback;

    Controller ();

    void onKeyPress (sf::Keyboard::Key, bool, bool, bool);
    void onKeyRelease (sf::Keyboard::Key, bool, bool, bool);
    void onText (sf::Uint32);
    void onCursor (double, double);
    void onCursorIn ();
    void onCursorOut ();
    void onFocus ();
    void onUnfocus ();
    void onMouseButtonPress (int, int, int);
    void onMouseButtonRelease (int, int, int);
    void onScroll (double);
    void onResize (int, int);

    std::vector<Keybinding> getKeybindings ();
    // std::vector<LoopKeybinding> getLoopKeybindings ();

    void setKeybindings (std::vector<Keybinding>);
    void addKeybinding (Keybinding);
    void clearKeybindings ();
    void addTextCallback (TextCallback);
    void clearTextCallbacks ();
    void addCursorCallback (CursorCallback);
    void clearCursorCallbacks ();
    void addCursorInCallback (CursorInCallback);
    void clearCursorInCallbacks ();
    void addCursorOutCallback (CursorOutCallback);
    void clearCursorOutCallbacks ();
    void addFocusCallback (FocusCallback);
    void clearFocusCallbacks ();
    void addUnfocusCallback (UnfocusCallback);
    void clearUnfocusCallbacks();
    void addMouseButtonPressCallback (MouseButtonPressCallback);
    void clearMouseButtonPressCallbacks ();
    void addMouseButtonReleaseCallback (MouseButtonReleaseCallback);
    void clearMouseButtonReleaseCallbacks ();
    void addScrollCallback (ScrollCallback);
    void clearScrollCallbacks ();
    void addResizeCallback (ResizeCallback);
    void clearResizeCallbacks ();

private:

    std::vector<Keybinding> m_keybindings;
    // std::vector<LoopKeybinding> m_loopKeybindings;

    std::vector<TextCallback> m_textCallbacks;
    std::vector<CursorCallback> m_cursorCallbacks;
    std::vector<CursorInCallback> m_cursorInCallbacks;
    std::vector<CursorOutCallback> m_cursorOutCallbacks;
    std::vector<FocusCallback> m_focusCallbacks;
    std::vector<UnfocusCallback> m_unfocusCallbacks;
    std::vector<MouseButtonPressCallback> m_mouseButtonPressCallbacks;
    std::vector<MouseButtonReleaseCallback> m_mouseButtonReleaseCallbacks;
    std::vector<ScrollCallback> m_scrollCallbacks;
    std::vector<ResizeCallback> m_resizeCallbacks;

};

#endif
