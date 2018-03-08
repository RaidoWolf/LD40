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

    Log () = delete; // static only
    ~Log () = delete;

    Log (Log&&) = delete;
    Log& operator = (Log&&) = delete;

    Log (const Log&) = delete;
    Log& operator = (const Log&) = delete;

    static LogLevel getFilterLevel ();
    static void setFilterLevel (LogLevel);

    static void log (std::string, LogLevel = LogLevel::VERBOSE);

    static void verbose (std::string);
    static void notice  (std::string);
    static void warning (std::string);
    static void error   (std::string);

    static void bindCallbacks ();

    static void unhandledException ();

private:

    static std::string formatMessage (std::string, LogLevel = LogLevel::VERBOSE);

    static LogLevel m_filterLevel;

    static std::mutex mutex_stdout;
    static std::mutex mutex_stderr;

};

#endif
