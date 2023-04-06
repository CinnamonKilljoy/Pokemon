#include "move.hpp"
#include "moveSet.hpp"
#include "types.hpp"

namespace ck {

MoveSet::MoveSet(): myMoves({}) {}

MoveSet::MoveSet(const std::vector<std::pair<Move, unsigned int>> &moves) : myMoves(moves) {}

void MoveSet::checkMove(const std::string &name) const {
    if (!has(name)) {
        throw error::ValueError("No such move: " + name, error::code::UNKNOWN_MOVE);
    }
}

bool MoveSet::has(const std::string &name) const {
    for (const std::pair<Move, unsigned int> &move : myMoves) {
        if (move.first.name() == name) {
            return true;
        }
    }
    return false;
}

Move MoveSet::get(const std::string &name) const {
    for (const std::pair<Move, unsigned int> &move : myMoves) {
        if (move.first.name() == name) {
            return move.first;
        }
    }

    throw error::ValueError("No such move: " + name, error::code::UNKNOWN_MOVE);
}

std::vector<Move> MoveSet::list() const {
    return list(100);
}

std::vector<Move> MoveSet::list(const unsigned int &level) const {
    std::vector<Move> result = {};
    for (const std::pair<Move, unsigned int> entry : myMoves) {
        if (level >= entry.second) {
            result.push_back(entry.first);
        }
    }
    return result;
}

MoveSet MoveSet::subList(const unsigned int &level) const {
    MoveSet result = MoveSet(*this);

    result.myMoves.clear();
    for (const std::pair<Move, unsigned int> entry : myMoves) {
        if (level >= entry.second) {
            result.myMoves.push_back({entry.first, entry.second});
        }
    }

    return result;
}

std::vector<std::string> MoveSet::string(const std::string &prefix) const {
    const std::vector<std::string> keys = {"Name", "Type", "Accuracy", "PP", "Power"};

    std::map<std::string, std::map<std::string, std::string>> parts = {};
    std::map<std::string, std::string> longest = {};

    for (const std::string key : keys) {
        parts[key] = {};
        longest[key] = "";
    }

    for (const std::pair<Move, unsigned int> entry : myMoves) {
        Move move = entry.first;

        std::string accuracyString = std::to_string(move.accuracy());
        std::string nameString = move.name();
        std::string pointsString = std::to_string(move.points());
        std::string powerString = std::to_string(move.power());
        std::string typesString = string::lexical(Types::string(move.type()));

        const std::vector<std::string> newStrings =
            {nameString, typesString, accuracyString, pointsString, powerString};

        for (std::size_t i = 0; i < newStrings.size(); ++i) {
            const std::string key = keys[i];
            const std::string newString = newStrings[i];
            const std::string longestString = longest[key];

            parts[key][nameString] = newString;
            longest[key] = longestString.size() < newString.size() ? newString : longestString;
        }
    }

    std::vector<std::string> lines = {};
    for (const std::pair<Move, unsigned int> entry : myMoves) {
        const std::string &name = entry.first.name();

        std::string comma = ",";
        std::string line = "" + prefix;
        std::string prepend = "";

        for (const std::string &key : keys) {
            if (key == keys.at(keys.size() - 1)) {
                comma = ".";
            }

            line = line + prepend + key + ": " +
                   string::pad(parts[key][name] + comma, static_cast<unsigned int>(longest[key].size()) + 1);
            prepend = " ";
        }
        lines.push_back(line);
    }

    return lines;
}

}   // namespace ck
