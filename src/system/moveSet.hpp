#ifndef __CK_MOVESET_HPP__
#define __CK_MOVESET_HPP__

#include <string>
#include <vector>

#include "move.hpp"

namespace ck {

class MoveSet {

    public:
        MoveSet();
        MoveSet(const std::vector<std::pair<Move, unsigned int>> &moves);

        bool has(const std::string &name) const;
        Move get(const std::string &name) const;
        std::vector<Move> list() const;
        std::vector<Move> list(const unsigned int &level) const;
        MoveSet subList(const unsigned int &level) const;

        /**
         *  Prints a string representation of this moveset.
         */
        std::vector<std::string> string(const std::string &prefix="") const;

    private:
        void checkMove(const std::string &name) const;

        std::vector<std::pair<Move, unsigned int>> myMoves;
};

}   // namespace ck

#endif  // __CK_MOVESET_HPP__
