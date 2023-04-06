#include "types.hpp"

namespace ck {

Types::Types(Type primary) : Types(primary, Type::NONE) {}

Types::Types(Type primary, Type secondary): first(primary), second(secondary) {
    if (primary != Type::NONE && primary == secondary) {
        throw error::ValueError("Can't create dual-type with identical types! (" + string(primary) + ").");
    }
}

bool Types::exists(const std::string &name) {
    try {
        parse(name);
    } catch (const error::ValueError &error) {
        return false;
    }
    return true;
}

Type Types::primary() const {
    return first;
}

Type Types::secondary() const {
    return second;
}

bool Types::dual() const {
    return second != Type::NONE;
}

Type Types::parse(const std::string &string) {
    const std::string input = string::toUpper(string);
    if (input == "BUG")      { return Type::BUG;      }
    if (input == "DRAGON")   { return Type::DRAGON;   }
    if (input == "ELECTRIC") { return Type::ELECTRIC; }
    if (input == "FIGHTING") { return Type::FIGHTING; }
    if (input == "FIRE")     { return Type::FIRE;     }
    if (input == "FLYING")   { return Type::FLYING;   }
    if (input == "GHOST")    { return Type::GHOST;    }
    if (input == "GRASS")    { return Type::GRASS;    }
    if (input == "GROUND")   { return Type::GROUND;   }
    if (input == "ICE")      { return Type::ICE;      }
    if (input == "NORMAL")   { return Type::NORMAL;   }
    if (input == "POISON")   { return Type::POISON;   }
    if (input == "PSYCHIC")  { return Type::PSYCHIC;  }
    if (input == "ROCK")     { return Type::ROCK;     }
    if (input == "WATER")    { return Type::WATER;    }
    if (input == "NONE")     { return Type::NONE;     }
    throw error::ValueError("Unable to parse string " + string + " into a type!");
}

std::string Types::string(Type type) {
    if (type == Type::BUG)      { return "BUG";      }
    if (type == Type::DRAGON)   { return "DRAGON";   }
    if (type == Type::ELECTRIC) { return "ELECTRIC"; }
    if (type == Type::FIGHTING) { return "FIGHTING"; }
    if (type == Type::FIRE)     { return "FIRE";     }
    if (type == Type::FLYING)   { return "FLYING";   }
    if (type == Type::GHOST)    { return "GHOST";    }
    if (type == Type::GRASS)    { return "GRASS";    }
    if (type == Type::GROUND)   { return "GROUND";   }
    if (type == Type::ICE)      { return "ICE";      }
    if (type == Type::NORMAL)   { return "NORMAL";   }
    if (type == Type::POISON)   { return "POISON";   }
    if (type == Type::PSYCHIC)  { return "PSYCHIC";  }
    if (type == Type::ROCK)     { return "ROCK";     }
    if (type == Type::WATER)    { return "WATER";    }
    if (type == Type::NONE)     { return "NONE";     }
    throw error::ValueError("No such type!");
}

std::string Types::string(Types types) {
    return string::lexical(string(types.primary())) +
           (types.dual() ? " / " + string::lexical(string(types.secondary())) : "");
}

}   // namespace ck
