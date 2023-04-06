#ifndef __CK_MONSTER_HPP__
#define __CK_MONSTER_HPP__

#include <ostream>
#include <string>

#include "pokemon.hpp"

namespace ck {

class Monster : public Pokemon {

    public:
        Monster(const Pokemon &pokemon, const int &level);
        Monster& operator=(const Monster &other);

        friend std::ostream& operator<<(std::ostream& os, const Pokemon& monster);

        void load(const std::vector<std::string> &loadout);

    private:
        Statistics currentStats;
        std::vector<Move> myLoadout;
};

}

#endif  // __CK_MONSTER_HPP__
