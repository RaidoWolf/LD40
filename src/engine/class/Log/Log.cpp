#include "Log.hpp"

LogLevel Log::getFilterLevel () {

    return m_filterLevel;

}

void Log::setFilterLevel (LogLevel filterLevel) {

    m_filterLevel = std::move(filterLevel);

}

void Log::log (std::string message, LogLevel messageType) {

    if (messageType == LogLevel::UNDEFINED || messageType >= m_filterLevel) {

        std::string out = Log::formatMessage(std::move(message), messageType);

        if (messageType == LogLevel::ERROR) {
            std::unique_lock<std::mutex> lock_stderr(Log::mutex_stderr);
            std::cerr << out << std::endl;
        } else {
            std::unique_lock<std::mutex> lock_stdout(Log::mutex_stdout);
            std::cout << out << std::endl;
        }

    }

}

void Log::verbose (std::string message) {

    Log::log(std::move(message), LogLevel::VERBOSE);

}

void Log::notice (std::string message) {

    Log::log(std::move(message), LogLevel::NOTICE);

}

void Log::warning (std::string message) {

    Log::log(std::move(message), LogLevel::WARNING);

}

void Log::error (std::string message) {

    Log::log(std::move(message), LogLevel::ERROR);

}

void Log::bindCallbacks () {

    std::set_terminate(unhandledException);

}

void Log::unhandledException () {

    Log::error("Unhandled exception.");
    std::abort();

}

std::string Log::formatMessage (std::string message, LogLevel messageType) {

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

    oss << std::move(message);

    return oss.str();

}

LogLevel Log::m_filterLevel = LogLevel::VERBOSE;

std::mutex Log::mutex_stdout;
std::mutex Log::mutex_stderr;
