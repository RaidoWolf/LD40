#include "Log.hpp"

LogLevel Log::getFilterLevel () {

    return m_filterLevel;

}

void Log::setFilterLevel (const LogLevel filterLevel) {

    m_filterLevel = filterLevel;

}

void Log::log (const std::string message, const LogLevel messageType) {

    if (messageType == LogLevel::UNDEFINED || messageType >= m_filterLevel) {

        std::string out = Log::formatMessage(message, messageType);

        if (messageType == LogLevel::ERROR) {
            std::unique_lock<std::mutex> lock_stderr(Log::mutex_stderr);
            std::cerr << out << std::endl;
        } else {
            std::unique_lock<std::mutex> lock_stdout(Log::mutex_stdout);
            std::cout << out << std::endl;
        }

    }

}

void Log::verbose (const std::string message) {

    Log::log(message, LogLevel::VERBOSE);

}

void Log::notice (const std::string message) {

    Log::log(message, LogLevel::NOTICE);

}

void Log::warning (const std::string message) {

    Log::log(message, LogLevel::WARNING);

}

void Log::error (const std::string message) {

    Log::log(message, LogLevel::ERROR);

}

void Log::bindCallbacks () {

    std::set_terminate(unhandledException);

}

void Log::unhandledException () {

    Log::error("Unhandled exception.");
    std::abort();

}

std::string Log::formatMessage (const std::string message, LogLevel messageType) {

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
