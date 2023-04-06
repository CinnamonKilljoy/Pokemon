#include <utility>

#include "errors.hpp"
#include "statistics.hpp"

namespace ck {

Statistics::Statistics() : Statistics({
    { "Attack",  0 },
    { "Defense", 0 },
    { "Health",  0 },
    { "Speed",   0 },
    { "Special", 0 },
}) {}

Statistics::Statistics(const std::map<std::string, unsigned int> stats) : myStats({}) {
    for (std::pair<std::string, unsigned int> entry : stats) {
        myStats[entry.first] = entry.second;
    }
}

void Statistics::checkStat(const std::string &name) const {
    if (!has(name)) {
        throw error::ValueError("No such statistic: " + name, error::code::UNKNOWN_STATISTIC);
    }
}

std::string Statistics::string() const {
    std::string result = "{";
    std::string prefix = "";

    for (std::pair<std::string, unsigned int> entry : myStats) {
        result = result + prefix + entry.first + ": " + std::to_string(entry.second);
        prefix = ",";
    }

    return result + "}";
}

bool Statistics::has(const std::string &name) const {
    return myStats.find(name) != myStats.end();
}

unsigned int Statistics::get(const std::string &name) const {
    checkStat(name);
    return myStats.at(name);
}

void Statistics::set(const std::string &name, unsigned int value) {
    checkStat(name);
    myStats[name] = value;
}

std::vector<std::string> Statistics::names() const {
    std::vector<std::string> result = {};
    for (const std::pair<std::string, unsigned int> entry : myStats) {
        result.push_back(entry.first);
    }
    return result;
}

}   // namespace ck
