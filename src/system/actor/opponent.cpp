#include "opponent.hpp"

namespace ck {

Opponent::Opponent() : Opponent("<NULL>", {}) {}

Opponent::Opponent(const std::string &name,
                   const std::vector<std::pair<Pokemon, unsigned int>> &party) :
                        Actor(name, party) {}

Opponent& Opponent::operator=(const Opponent &other) {
    if (this != &other) {
        myName = other.myName;
        myParty = other.myParty;
    }
    return *this;
}

} // namespace ck
