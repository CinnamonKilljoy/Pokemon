#ifndef __CK_ACTOR_HPP__
#define __CK_ACTOR_HPP__

#include "pokemon.hpp"

namespace ck {

class Actor {
    public:
        std::string name() const;
        std::vector<std::pair<Pokemon, unsigned int>> party() const;

    protected:
        Actor(const std::string &name, const std::vector<std::pair<Pokemon, unsigned int>> &party);

        std::string myName;
        std::vector<std::pair<Pokemon, unsigned int>> myParty;
};

}

#endif  // __CK_ACTOR_HPP__
