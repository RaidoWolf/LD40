#ifndef H_CLASS_LOG
#define H_CLASS_LOG

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <mutex>
#include <exception>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../enum/LogLevel/LogLevel.hpp"

class Log {

public:

    static LogLevel getFilterLevel ();
    static void setFilterLevel (const LogLevel);

    static void log (const std::string, const LogLevel = LogLevel::VERBOSE);

    static void verbose (const std::string);
    static void notice  (const std::string);
    static void warning (const std::string);
    static void error   (const std::string);

    static void bindCallbacks ();

    static void unhandledException ();

private:

    Log () = delete; // static only class

    static std::string formatMessage (const std::string, const LogLevel = LogLevel::VERBOSE);

    static LogLevel m_filterLevel;

    static std::mutex mutex_stdout;
    static std::mutex mutex_stderr;

};

#endif
