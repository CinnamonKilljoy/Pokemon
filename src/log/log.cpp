#include "errors.hpp"
#include "log.hpp"
#include "strings.hpp"

namespace ck {

log::LOG_LEVEL log::currentLevel = LOG_LEVEL::DEBUG;

const std::map<log::LOG_LEVEL, std::string> log::ENUM_STRING = {
    { LOG_LEVEL::CRITICAL, "CRITICAL" },
    { LOG_LEVEL::DEBUG,    "DEBUG" },
    { LOG_LEVEL::ERROR,    "ERROR" },
    { LOG_LEVEL::INFO,     "INFO" },
    { LOG_LEVEL::WARNING,  "WARNING" },
};

std::string log::appName() {
    #ifndef APP_NAME
    return "<NULL_NAME>";
    #else
    return QUOTE(APP_NAME);
    #endif
}

std::string log::createMessage(const log::LOG_LEVEL &logLevel, const std::string &message) {
    return "[" + appName() + "]" + string::pad("[" + ENUM_STRING.at(logLevel) + "]: ", 12) + message;
}

void log::setLevel(const std::string &level) {
    try {
        currentLevel = static_cast<LOG_LEVEL>(std::atoi(level.c_str()));
    } catch (std::runtime_error &error) {
        throw error::LogError("Invalid log level " + level + ": " + error.what(), error::code::INVALID_LOG_LEVEL);
    }
}

void log::critical(const std::string &message) {
    echo(log::LOG_LEVEL::CRITICAL, message);
}

void log::debug(const std::string &message) {
    echo(log::LOG_LEVEL::DEBUG, message);
}

void log::echo(const std::string &message) {
    std::cout << message << std::endl;
}

void log::error(const std::string &message) {
    echo(log::LOG_LEVEL::ERROR, message);
}

void log::info(const std::string &message) {
    echo(log::LOG_LEVEL::INFO, message);
}

void log::warning(const std::string &message) {
    echo(log::LOG_LEVEL::WARNING, message);
}

void log::critical(const std::vector<std::string> &lines) {
    echo(log::LOG_LEVEL::CRITICAL, lines);
}

void log::debug(const std::vector<std::string> &lines) {
    echo(log::LOG_LEVEL::DEBUG, lines);
}

void log::echo(const std::vector<std::string> &lines) {
    for (const std::string &message : lines) {
        echo(message);
    }
}

void log::error(const std::vector<std::string> &lines) {
    echo(log::LOG_LEVEL::ERROR, lines);
}

void log::info(const std::vector<std::string> &lines) {
    echo(log::LOG_LEVEL::INFO, lines);
}

void log::warning(const std::vector<std::string> &lines) {
    echo(log::LOG_LEVEL::WARNING, lines);
}

void log::echo(const log::LOG_LEVEL &logLevel, const std::vector<std::string> &lines) {
    for (const std::string &message : lines) {
        echo(logLevel, message);
    }
}

void log::echo(const log::LOG_LEVEL &logLevel, const std::string &message) {
    if (logLevel < currentLevel) {
        return;
    }
    if (logLevel < log::LOG_LEVEL::WARNING) {
        std::cout << createMessage(logLevel, message) << std::endl;
        std::cout.flush();
    } else {
        std::cerr << createMessage(logLevel, message) << std::endl;
        std::cerr.flush();
    }
}

}   // namespace ck
