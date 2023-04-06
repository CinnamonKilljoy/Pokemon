#include <string>

#include "battleStatistics.hpp"
#include "monster.hpp"
#include "pokemon.hpp"

#define MOVE_AMOUNT 4

namespace ck {

Monster::Monster(const Pokemon &pokemon, const int &level) : Pokemon() {
    myId = pokemon.id();
    myName = pokemon.name();
    myStats = BattleStatistics(pokemon.statistics());
    myTypes = pokemon.types();
    myMoves = pokemon.moves().subList(level);
    myLoadout = {};
}

void Monster::load(const std::vector<std::string> &loadout) {
    const std::size_t amount = loadout.size();
    if (!amount || amount > MOVE_AMOUNT) {
        throw error::ValueError("Must load [1, " + std::to_string(MOVE_AMOUNT) + "] moves, not " +
                                std::to_string(amount) , error::code::WRONG_MOVE_AMOUNT);
    }

    myLoadout.clear();
    for (const std::string &name : loadout) {
        myLoadout.push_back(myMoves.get(name));
    }
}

}   // namespace ck
