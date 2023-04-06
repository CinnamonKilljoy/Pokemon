#ifndef __CK_PLAYER_HPP__
#define __CK_PLAYER_HPP__

#include "actor.hpp"
#include "badge.hpp"
#include "pokemon.hpp"

namespace ck {

class Player : public Actor {
    public:
        Player(const std::string &name,
               const std::vector<std::pair<Pokemon, unsigned int>> &party,
               const std::vector<Badge> &badges = {});

        std::vector<Badge> badges(const bool &includeMissing = false) const;

    private:
        std::vector<Badge> myBadges;
};

}

#endif  // __CK_PLAYER_HPP__
