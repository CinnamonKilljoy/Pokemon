#include "errors.hpp"
#include "log.hpp"
#include "strings.hpp"

#define DEFAULT_PREFIX std::string("    ")

namespace ck::string {

std::string addPrefix(const std::string &string, const std::string &prefix) {
    return (prefix.empty() ? DEFAULT_PREFIX : prefix) + string;
}

std::string subtractPrefix(const std::string &string, const std::string &prefix) {
    const std::string prepend = prefix.empty() ? DEFAULT_PREFIX : prefix;

    const std::size_t baseSize = string.size();
    const std::size_t prefixSize = prepend.size();

    if (prefixSize > baseSize) {
        return string;
    } else if (prefixSize == baseSize && prepend == string) {
        return "";
    }

    const std::string toRemove = string.substr(string.size() - prepend.size(), string.size());

    if (toRemove != prepend) {
        return string;
    }

    return string.substr(string.size() - prepend.size());
}

std::string changeCase(const std::string &string, const std::function<bool(int)> &check) {
    std::string result = "";
    for (char ch : string) {
        int ascii = int(ch);
        result += (isalpha(ascii) && check(ascii)) ? (char) (ascii ^ int(' ')) : ch;

    }
    return result;
}

std::string toLower(const std::string &string) {
    return changeCase(string, [](int ch) -> bool {
        return ch < int('a');
    });
}

std::string toUpper(const std::string &string) {
    return changeCase(string, [](int ch) -> bool {
        return ch >= int('a');
    });
}

std::string lexical(const std::string &string) {
    if (string.empty()) {
        return string;
    }

    std::string result = "";
    bool first = true;
    for (size_t i = 0; i < string.size(); ++i) {
        std::string toAdd = string.substr(i, 1);
        std::string old = toAdd;

        if (toAdd == ".") {
            first = true;
        } else if (first) {
            first = false;
            toAdd = toUpper(toAdd);
        } else {
            toAdd = toLower(toAdd);
        }

        result = result + toAdd;
    }

    return result;
}

std::string format(const std::string format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);

    if (!vsprintf(buffer, format.c_str(), args)) {
        throw error::ValueError("Could not format string: " + std::string(strerror(errno)), error::code::STRING_ERROR);
    }
    std::string result = std::string(buffer);

    va_end(args);
    return result;
}

std::string pad(const std::string &string, const std::size_t &length, const char &padding) {

    std::size_t start = string.length();
    if (start >= length) {
        return string;
    }

    std::string result = string;
    for (std::size_t i = start; i < length; ++i) {
        result += padding;
    }
    return result;
}

std::string vectorString(const std::vector<std::string> &vector, const std::string &separator, const bool &curly) {
    std::string result = curly ? "{" : "[";

    std::string prefix = "";
    for (const std::string &element : vector) {
        result = result + std::string(element);
        prefix = separator;
    }

    return result + (curly ? "}" : "]");
}

} // namespace ck::string
