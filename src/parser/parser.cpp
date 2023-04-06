#include <fstream>
#include <map>

#include "errors.hpp"
#include "files.hpp"
#include "log.hpp"
#include "moveSet.hpp"
#include "parser.hpp"
#include "strings.hpp"
#include "types.hpp"

namespace ck {

/* ********* *
 *  General. *
 * ********* */

Json::Value parse::asJSON(const std::string &fileName) {
    if (!filesystem::exists(fileName)) {
        throw error::FileError("Could not find " + fileName + ".");
    }

    Json::Value root;
    std::ifstream file(file::fromRoot(fileName));
    file >> root;
    file.close();
    return root;
}

void validateEntry(const Json::Value &data, std::vector<std::string> expectedMembers) {
    std::vector<std::string> illegal = {};
    std::vector<std::string> missing = {};

    std::vector<std::string> jsonMembers = data.getMemberNames();
    std::vector<std::string>::const_iterator start = expectedMembers.begin();
    std::vector<std::string>::const_iterator end = expectedMembers.end();

    for (const std::string &member : jsonMembers) {
        if (std::count(start, end, member) == 0) {
            illegal.push_back(member);
        }
    }

    start = jsonMembers.begin();
    end = jsonMembers.end();
    for (const std::string &member : expectedMembers) {
        if (std::count(start, end, member) == 0) {
            missing.push_back(member);
        }
    }

    if (missing.empty() && illegal.empty()) {
        return;
    }

    std::string illegalString = illegal.empty() ? "" : "unexpected: " + string::vectorString(illegal);
    std::string missingString = missing.empty() ? "" : "missing: " + string::vectorString(missing);

    if (!illegal.empty() && !missing.empty()) {
        missingString = ", " + missingString;
    }

    throw error::ParserError("Illegal Json: " + illegalString + missingString);
}

/* ************** *
 *  File parsing. *
 * ************** */

std::map<std::string, Move> parse::moveData(const std::string &fileName) {
    log::debug("Parsing " + fileName);
    Json::Value root = file::asJSON(file::fromRoot(fileName));

    std::map<std::string, Move> data = {};
    for (const std::string &name : root.getMemberNames()) {
        data[name] = move(name, root[name]);
    }

    return data;
}

std::map<std::string, Opponent> parse::opponentData(const PokemonData &pokemonData,
                                                    const std::string &fileName) {
    log::debug("Parsing " + fileName);
    Json::Value root = file::asJSON(file::fromRoot(fileName));

    std::map<std::string, Opponent> data = {};
    for (const std::string &name : root.getMemberNames()) {
        data[name] = opponent(pokemonData, name, root[name]);
    }

    return data;
}

std::map<std::string, Pokemon> parse::pokemonData(const MoveData &moveData, const std::string &fileName) {
    log::debug("Parsing " + fileName);
    Json::Value root = file::asJSON(file::fromRoot(fileName));

    std::map<std::string, Pokemon> data = {};
    for (const std::string &name : root.getMemberNames()) {
        data[name] = pokemon(moveData, name, root[name]);
    }
    return data;
}

/* *************** *
 *  Entry parsing. *
 * *************** */

Badge parse::badge(const std::string &name, const Json::Value &data) {
    validateEntry(data, {"Acquired", "Leader", "Bonus"});

    const bool &acquired = data["Acquired"].asBool();
    const std::string &leader = data["Leader"].asString();

    return data["Bonus"].isString() ?
            Badge(name, leader, data["Bonus"].asString(), acquired) :
            Badge(name, leader, data["Bonus"].asUInt(), acquired);
}

Move parse::move(const std::string &name, const Json::Value &data) {
    validateEntry(data, {"Accuracy", "PP", "Power", "Type"});
    return Move(name,
                data["Accuracy"].asUInt(),
                data["PP"].asUInt(),
                data["Power"].asUInt(),
                Types::parse(data["Type"].asString()));
}

Opponent parse::opponent(const PokemonData &pokemonData, const std::string &name, const Json::Value &data) {
    validateEntry(data, {"AI", "Party", "Reward"});

    std::vector<std::pair<Pokemon, unsigned int>> party = {};

    for (const std::string &monster : data["Party"].getMemberNames()) {
        party.push_back({pokemonData.get(monster), data["Party"][monster].asUInt()});
    }

    return Opponent(name, party);
}

Player parse::player(const PokemonData &pokemonData, const std::string &fileName) {
    log::debug("Parsing " + fileName);
    Json::Value root = file::asJSON(file::fromRoot(fileName));

    validateEntry(root, {"Name", "Party", "Badges"});

    std::vector<Badge> badges = {};
    std::vector<std::pair<Pokemon, unsigned int>> party = {};

    for (const std::string &name : root["Badges"].getMemberNames()) {
        badges.push_back(badge(name, root["Badges"][name]));
    }

    for (const std::string &name : root["Party"].getMemberNames()) {
        party.push_back({pokemonData.get(name), root["Party"][name].asUInt()});
    }

    return Player(root["Name"].asString(), party, badges);
}

Pokemon parse::pokemon(const MoveData &moveData, const std::string &name, const Json::Value &data) {
    validateEntry(data, {"Id", "BaseStats", "MoveList", "Types"});

    std::vector<std::pair<Move, unsigned int>> moves = {};
    for (const std::string &name : data["MoveList"].getMemberNames()) {
        moves.push_back({ moveData.get(name), data["MoveList"][name].asUInt() });
    }

    return Pokemon(data["Id"].asUInt(),
                   name,
                   statistics(data["BaseStats"]),
                   MoveSet(moves),
                   types(data["Types"]));
}

Statistics parse::statistics(const Json::Value &statList) {
    std::map<std::string, unsigned int> stats = {};

    for (std::string &name: statList.getMemberNames()) {
        stats[name] = statList[name].asUInt();
    }
    return Statistics(stats);
}

Types parse::types(const Json::Value &typeList) {
    Type type1 = Types::parse(typeList[0].asString());
    if (typeList.size() < 2) {
        return type1;
    }
    return Types(type1, Types::parse(typeList[1].asString()));
}

}   // namespace ck
