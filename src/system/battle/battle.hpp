#ifndef __CK_BATTLE_HPP__
#define __CK_BATTLE_HPP__

#include <string>

#include "opponent.hpp"
#include "player.hpp"

namespace ck {

class Battle {

    public:
        Battle(const Player &player, const Opponent &opponent);

        Opponent opponent() const;
        Player player() const;
        std::vector<std::string> string(const std::string &prefix = "") const;

    private:
        const Opponent myOpponent;
        const Player myPlayer;
};

}   // namespace ck

#endif  // __CK_BATTLE_HPP__
