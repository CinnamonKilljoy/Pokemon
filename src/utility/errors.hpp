/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   Error functionality.
 * @date    2022-01-25
 */
#ifndef __CK_ERRORS_HPP__
#define __CK_ERRORS_HPP__

#include <stdexcept>
#include <string>
#include <vector>

namespace ck {

namespace error {

enum class code {
    FILE_ERROR,
    INITIALIZATION,
    IMPLEMENTATION_ERROR,
    INTERNAL,
    INVALID_LOG_LEVEL,
    PARSER_ERROR,
    STATE_ERROR,
    STRING_ERROR,
    UNKNOWN,
    UNKNOWN_FUNCTION,
    UNKNOWN_MOVE,
    UNKNOWN_STATISTIC,
    UNKNOWN_OPTION,
    VALUE_ERROR,
    WRONG_MOVE_AMOUNT
};

class ProgramError : public std::runtime_error {

    public:
        ProgramError(const std::string &message) : ProgramError(message, error::code::INTERNAL) {}
        ProgramError(const std::string &message, const code &code) : std::runtime_error(message), myCode(code) {}

        error::code code() const { return myCode; }

    private:
        const error::code myCode { 0 };
};

class FileError : public ProgramError {

    public:
        FileError(const std::string &message) : FileError(message, code::FILE_ERROR)  {}
        FileError(const std::string &message, const error::code &code) : ProgramError(message, code) {}
};

class ImplementationError : public ProgramError {

    public:
        ImplementationError(const std::string &message) : ImplementationError(message, code::IMPLEMENTATION_ERROR)  {}
        ImplementationError(const std::string &message, const error::code &code) : ProgramError(message, code) {}
};

class LogError : public ProgramError {

    public:
        LogError(const std::string &message) : LogError(message, code::FILE_ERROR)  {}
        LogError(const std::string &message, const error::code &code) : ProgramError(message, code) {}
};

class ParserError : public ProgramError {

    public:
        ParserError(const std::string &message) : ParserError(message, code::PARSER_ERROR)  {}
        ParserError(const std::string &message, const error::code &code) : ProgramError(message, code) {}
};

class StateError : public ProgramError {

    public:
        StateError(const std::string &message) : StateError(message, code::STATE_ERROR)  {}
        StateError(const std::string &message, const error::code &code) : ProgramError(message, code) {}
};

class ValueError : public ProgramError {

    public:
        ValueError(const std::string &message) : ValueError(message, code::VALUE_ERROR)  {}
        ValueError(const std::string &message, const error::code &code) : ProgramError(message, code) {}
};

} // namespace errors

}   // namespace ck

#endif  // __CK_ERRORS_HPP__
