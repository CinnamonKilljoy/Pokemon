#ifndef __CK_POKEMON_HPP__
#define __CK_POKEMON_HPP__

#include <ostream>
#include <string>

#include "moveSet.hpp"
#include "statistics.hpp"
#include "types.hpp"

namespace ck {

class Pokemon {

    public:
        Pokemon();
        Pokemon(const unsigned int &id,
                const std::string &name,
                const Statistics &baseStats,
                const MoveSet &moves,
                const Types &types);

        Pokemon& operator=(const Pokemon &other);

        unsigned int id() const;
        std::string name() const;
        MoveSet moves() const;
        Statistics statistics() const;
        Type primaryType() const;
        Type secondaryType() const;
        Types types() const;

        friend std::ostream& operator<<(std::ostream& os, const Pokemon& monster);

    protected:
        unsigned int myId;
        std::string myName;
        Statistics myStats;
        MoveSet myMoves;
        Types myTypes;
};

}

#endif  // __CK_POKEMON_HPP__
