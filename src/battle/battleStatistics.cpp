#include <utility>

#include "battleStatistics.hpp"
#include "errors.hpp"

#define MAX_MODIFIER 6
#define MIN_MODIFIER -MAX_MODIFIER

namespace ck {

void BattleStatistics::checkModification(const int &level) {
    if (level < MIN_MODIFIER || level > MAX_MODIFIER) {
        throw error::ValueError("Can't use stat modifier " + std::to_string(level));
    }
}

double BattleStatistics::adjustment(const int &level) {
    checkModification(level);

    if (!level) {
        return 1.0;
    }

    if (level > 0) {
        return 1.0 + 0.5 * static_cast<double>(level);
    }

    unsigned int index = static_cast<unsigned int>(level * -1);
    return std::vector<unsigned int>{66, 50, 40, 33, 28, 25}[index] / 100;
}

BattleStatistics::BattleStatistics(const Statistics &stats) : modifiers({}) {
    for (const std::string stat : stats.names()) {
        modifiers[stat] = 0;
    }
}

unsigned int BattleStatistics::get(const std::string &stat) const {
    return static_cast<unsigned int>(Statistics::get(stat) * adjustment(modifiers.at(stat)) + 0.5);
}

int BattleStatistics::stage(const std::string &stat) const {
    checkStat(stat);
    return modifiers.at(stat);
}

bool BattleStatistics::modify(const std::string &stat, const int &level) {
    checkModification(level);
    checkStat(stat);

    const int current = modifiers.at(stat);
    if (current == MAX_MODIFIER || current == MIN_MODIFIER) {
        return false;
    }

    modifiers[stat] = std::max(MIN_MODIFIER, std::min(MAX_MODIFIER, current + level));
    return true;
}

}   // namespace ck
