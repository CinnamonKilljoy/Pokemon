#include "actor.hpp"

namespace ck {

Actor::Actor(const std::string &name, const std::vector<std::pair<Pokemon, unsigned int>> &party) :
             myName(name), myParty(party) {}

std::string Actor::name() const {
     return myName;
}

std::vector<std::pair<Pokemon, unsigned int>> Actor::party() const {
     return myParty;
}

} // namespace ck
