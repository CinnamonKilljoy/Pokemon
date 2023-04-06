#ifndef __CK_OPPONENT_HPP__
#define __CK_OPPONENT_HPP__

#include "actor.hpp"
#include "pokemon.hpp"

namespace ck {

class Opponent : public Actor {
    public:
        Opponent();
        Opponent(const std::string &name,
               const std::vector<std::pair<Pokemon, unsigned int>> &party);

        Opponent& operator=(const Opponent &other);
};

}

#endif  // __CK_OPPONENT_HPP__
