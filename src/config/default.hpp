#ifndef __CK_DEFAULT_HPP__
#define __CK_DEFAULT_HPP__

#include <map>
#include <string>

static std::map<std::string, std::string> DEFAULT_OPTIONS = {
    { "c", "data/player.json"           },
    { "l", "0"                          },
    { "m", "data/moves.json"            },
    { "o", "data/battlers/rival.json"   },
    { "p", "data/pokemon.json"          },
    { "t", "data/types.json"            },
};

#endif  // __CK_DEFAULT_HPP__
