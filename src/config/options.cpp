#include <string>
#include <utility>
#include <vector>

#include "default.hpp"
#include "errors.hpp"
#include "log.hpp"
#include "options.hpp"

namespace ck {

Options *Options::instance = nullptr;

Options::Options(std::vector<std::string> arguments) {
    std::string option = "";
    std::vector<std::string> values = {};

    for (std::string argument : arguments) {
        if (argument.substr(0, 1) == "-") {
            if (option != "") {
                options[option] = values.empty() ? std::vector<std::string>({ "true" }) : values;
                values = {};
            }
            option = argument.substr(1);
        } else {
            if (option == "") {
                throw error::ValueError("No option before value " + argument, error::code::INITIALIZATION);
            }
            values.push_back(argument);
        }
    }

    if (option != "") {
        options[option] = values.empty() ? std::vector<std::string>({ "true" }) : values;
    }

    // for (std::pair<std::string, std::vector<std::string>> option : options) {
    //     std::string valueString = "{ ";
    //     std::string prefix = "";
    //     for (std::string value : option.second) {
    //         valueString = valueString + prefix + value;
    //         prefix = ", ";
    //     }
    //     log::debug(option.first + " = " + valueString + " }");
    // }

    for (std::pair<std::string, std::string> option : DEFAULT_OPTIONS) {
        const std::string &name = option.first;
        if (!has(option.first)) {
            options[name] = { option.second };
        }
    }
}

Options Options::get() {
    if (instance == nullptr) {
        throw error::StateError("Options must be initialized before they can be retrieved.",
            error::code::INITIALIZATION);
    }
    return *instance;
}

Options Options::set(std::vector<std::string> arguments) {
    return *(Options::instance = new Options(arguments));
}

bool Options::asBool(const std::string &name) const {
    const std::string &value = get(name);
    if (value == "false") {
        return false;
    }
    return value == "true" || asInt(name) != 0;
}

double Options::asFloat(const std::string &name) const {
    return std::stof(get(name));
}

int Options::asInt(const std::string &name) const {
    return std::stoi(get(name));
}

std::string Options::get(const std::string &name) const {
    return list(name)[0];
}

std::vector<std::string> Options::list(const std::string &name) const {
    if (!has(name)) {
        throw error::ValueError("No such option: " + name, error::code::INITIALIZATION);
    }
    return std::vector<std::string>(options.at(name));
}

bool Options::has(const std::string &name) const {
    return options.find(name) != options.end();
}

std::vector<char> Options::keys() const {
    std::vector<char> result = {};
    for (const std::pair<std::string, std::vector<std::string>> tuple : options) {
        result.push_back(tuple.first.at(0));
    }
    return result;
}

}   // namespace ck
