#include "Log.hpp"

LogLevel Log::getFilterLevel () {

    return m_filterLevel;

}

void Log::setFilterLevel (LogLevel filterLevel) {

    m_filterLevel = filterLevel;

}

void Log::bindCallbacks () {

    std::set_terminate(unhandledException);

}

void Log::unhandledException () {

    Log::error("Unhandled exception.");
    std::abort();

}

std::string Log::formatMessage (LogLevel messageType, const std::string& message) {

    auto time = std::time(nullptr);
    auto localtime = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&localtime, "%Y-%m-%d %H:%M:%S");
    oss << ' ';

    switch (messageType) {

        case LogLevel::VERBOSE:
            oss << ". VERBOSE : ";
            break;

        case LogLevel::NOTICE:
            oss << "_ NOTICE  : ";
            break;

        case LogLevel::WARNING:
            oss << "! WARNING : ";
            break;

        case LogLevel::ERROR:
            oss << "# ERROR   : ";
            break;

        default:
            oss << "  UNKNOWN : ";
            break;

    }

    oss << message;

    return oss.str();

}

LogLevel Log::m_filterLevel = LogLevel::VERBOSE;

std::mutex Log::mutex_stdout;
std::mutex Log::mutex_stderr;