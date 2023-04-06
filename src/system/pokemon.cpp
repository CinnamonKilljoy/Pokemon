#include <string>

#include "pokemon.hpp"
#include "statistics.hpp"
#include "types.hpp"

namespace ck {

Pokemon::Pokemon(): Pokemon(0, "", Statistics(), MoveSet(), Types(Type::NONE)) {}

Pokemon::Pokemon(const unsigned int &id,
                 const std::string &name,
                 const Statistics &baseStats,
                 const MoveSet &moves,
                 const Types &types) :
                    myId(id),
                    myName(name),
                    myStats(baseStats),
                    myMoves(moves),
                    myTypes(types) {}

unsigned int Pokemon::id() const {
    return myId;
}

std::string Pokemon::name() const {
    return myName;
}

Statistics Pokemon::statistics() const {
    return myStats;
}

Types Pokemon::types() const {
    return myTypes;
}

Type Pokemon::primaryType() const {
    return myTypes.primary();
}

Type Pokemon::secondaryType() const {
    return myTypes.secondary();
}

MoveSet Pokemon::moves() const {
    return myMoves;
}

Pokemon& Pokemon::operator=(const Pokemon &other) {
    if (this != &other) {
        myId    = other.myId;
        myName  = other.myName;
        myStats = other.myStats;
        myMoves = other.myMoves;
        myTypes = other.myTypes;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Pokemon& monster) {
    out << "[" << monster.myId << "]: " << monster.myName;
    return out;
}

}   // namespace ck
