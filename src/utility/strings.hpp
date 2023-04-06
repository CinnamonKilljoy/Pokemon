/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   String utility functions.
 * @date    2022-01-23
 */
#ifndef __CK_STRINGS_HPP__
#define __CK_STRINGS_HPP__

#include <cctype>
#include <functional>
#include <string.h>

#include <errno.h>
#include <stdarg.h>

#include "errors.hpp"


namespace ck::string {

std::string addPrefix(const std::string &string, const std::string &prefix = "");

std::string subtractPrefix(const std::string &string, const std::string &prefix = "");

/**
 *  Invert the case of alphabetic characters in a string.
 *
 *  @param string   The string which characters to convert.
 *  @param check    A function specifying when to invert a character.
 *  @return         `string` with all characters satisfying the case in `check` inverted.
 */
std::string changeCase(const std::string &string, const std::function<bool(int)> &check);

std::string toLower(const std::string &string);

std::string toUpper(const std::string &string);

/**
 *  Formats a string printf-style.
 *
 *  @param format   The format of the result string.
 *  @return         A string formatted printf-style using the variable arguments.
 */
std::string format(const std::string format, ...);

/**
 *  Formats the words in a string lexically.
 *
 *  First letter in every sentence, separated by a separator, will be uppercase, the rest lowercase.
 */
std::string lexical(const std::string &string);

/**
 * @param string    The base string to pad.
 * @param length    The length to pad to.
 * @return          `string` padded with `padding` to the length `length.`
 */
std::string pad(const std::string &string, const std::size_t &length, const char &padding=' ');

/**
 * @param vector    The vector to stringify.
 * @param separator The element separator to use.
 * @param curly     Specify whether to use curly braces "{...}". Uses brackets "[...]" if `false`.
 * @return          A string representation of a vector.
 */
std::string vectorString(const std::vector<std::string> &vector, const std::string &separator=",", const bool &curly=true);

}

#endif  // __CK_STRINGS_HPP__
