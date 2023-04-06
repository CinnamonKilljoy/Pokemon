#include "battle.hpp"

namespace ck {

Battle::Battle(const Player &player, const Opponent &opponent) : myOpponent(opponent), myPlayer(player) {}

Opponent Battle::opponent() const {
    return myOpponent;
}

Player Battle::player() const {
    return myPlayer;
}

std::vector<std::string> Battle::string(const std::string &prefix) const {
    std::vector<std::string> result = {};
    std::string pre = "";
    std::string prepend = string::addPrefix(pre, prefix);

    result.push_back(pre + myPlayer.name() + " vs. " + myOpponent.name());
    const std::string line = string::pad("", result[0].size(), '-');
    result.push_back(pre + line);

    bool first = true;
    for (const Actor &actor : std::vector<Actor> { myPlayer, myOpponent }) {
        if (!first) {
            result.push_back("");
        } else {
            first = false;
        }
        result.push_back(pre + actor.name() + "'s party:");

        pre = string::addPrefix(pre, prepend);
        for (const std::pair<Pokemon, unsigned int> &monster : actor.party()) {
            result.push_back(pre + monster.first.name() + " (" + std::to_string(monster.second) + ")");
        }
        pre = string::subtractPrefix(pre, prepend);
    }

    result.push_back(pre + line);

    return result;
}

} // namespace ck
