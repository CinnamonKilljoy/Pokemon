/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   Pokemon types.
 * @date    2022-02-02
 */
#ifndef __CK_TYPES_HPP__
#define __CK_TYPES_HPP__

#include "collections.hpp"
#include "log.hpp"
#include "strings.hpp"

namespace ck {

enum class Type {
    NONE,
    BUG,
    DRAGON,
    ELECTRIC,
    FIGHTING,
    FIRE,
    FLYING,
    GHOST,
    GRASS,
    GROUND,
    ICE,
    NORMAL,
    POISON,
    PSYCHIC,
    ROCK,
    WATER
};

class Types {

    public:
        Types(Type primary);
        Types(Type primary, Type secondary);

        Type primary() const;
        Type secondary() const;
        bool dual() const;

        static bool exists(const std::string &name);
        static Type parse(const std::string &string);
        static std::string string(Type type);
        static std::string string(Types types);

    private:
        Types() = delete;

        Type first;
        Type second;
};

}   // namespace ck

#endif  // __CK_TYPES_HPP__
