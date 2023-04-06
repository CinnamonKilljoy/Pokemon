#ifndef __CK_LOG_HPP__
#define __CK_LOG_HPP__

#define STR(str) #str
#define QUOTE(str) STR(str)

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace ck {

/**
 *  Standard logging utility for the application.
 *  <p>
 *  It is recommended to use `using log = ck::log;`.
 *
 *  @author  Zimon Kuhs (zimonkuhs@gmail.com)
 *  @brief   Application print logger.
 *  @date    2022-01-23
 */
class log {

    public:

        /**
         *  Sets the logging level.
         *
         *  @param level    The log level to set.
         */
        static void setLevel(const std::string &level);

        /**
         * @brief Print critical message.
         *
         * @param message   The message to print.
         */
        static void critical(const std::string &message);

        /**
         * @brief Print debug message.
         *
         * @param message   The message to print.
         */
        static void debug(const std::string &message);

        /**
         * @brief Print standard message. (STDOUT)
         *
         * @param message   The message to print.
         */
        static void echo(const std::string &message);

        /**
         * @brief Print error message.
         *
         * @param message   The message to print.
         */
        static void error(const std::string &message);

        /**
         * @brief Print info message.
         *
         * @param message   The message to print.
         */
        static void info(const std::string &message);

        /**
         * @brief Print warning message.
         *
         * @param message   The message to print.
         */
        static void warning(const std::string &message);

        /**
         * @brief Print critical messages.
         *
         * @param messages  The messages to print.
         */
        static void critical(const std::vector<std::string> &messages);

        /**
         * @brief Print debug messages.
         *
         * @param messages  The messages to print.
         */
        static void debug(const std::vector<std::string> &messages);

        /**
         * @brief Print standard messages. (STDOUT)
         *
         * @param messages  The messages to print.
         */
        static void echo(const std::vector<std::string> &messages);

        /**
         * @brief Print error messages.
         *
         * @param messages  The messages to print.
         */
        static void error(const std::vector<std::string> &messages);

        /**
         * @brief Print info messages.
         *
         * @param messages  The messages to print.
         */
        static void info(const std::vector<std::string> &messages);

        /**
         * @brief Print warning messages.
         *
         * @param messages  The messages to print.
         */
        static void warning(const std::vector<std::string> &messages);

    private:

        enum class LOG_LEVEL {
            CRITICAL = 4,
            DEBUG    = 0,
            ERROR    = 3,
            INFO     = 1,
            WARNING  = 2
        };

        static LOG_LEVEL currentLevel;
        static const std::map<LOG_LEVEL, std::string> ENUM_STRING;

        static std::string appName();
        static std::string createMessage(const LOG_LEVEL &logLevel, const std::string &message);
        static std::string enumString(const LOG_LEVEL &logLevel);
        static void echo(const LOG_LEVEL &logLevel, const std::string &message);
        static void echo(const LOG_LEVEL &logLevel, const std::vector<std::string> &messages);
};

}

#endif  // __CK_LOG_HPP__
