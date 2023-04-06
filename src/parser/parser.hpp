/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   Parser functionality.
 * @date    2022-01-25
 */
#ifndef __CK_PARSER_HPP__
#define __CK_PARSER_HPP__

#include <json/json.h>
#include <string>
#include <vector>

#include "data.hpp"
#include "move.hpp"
#include "opponent.hpp"
#include "player.hpp"
#include "pokemon.hpp"

/**
 *  Functions responsible for all <i>.json</i> file parsing; essentially a wrapper around jsoncpp.
 */
namespace ck {

class parse {

    public:
        /**
         *  Parses a .json file.
         *
         *  @param  fileName    The path to the file.
         *  @return             Root to a Json::Value tree.
         *  @see                <json/json.h>
         */
        static Json::Value asJSON(const std::string &fileName);

        /**
         *  Parses move data from a .json file.
         *
         *  @param  fileName    The path to the file.
         *  @return             A name->object map of `Move`s.
         */
        static std::map<std::string, Move> moveData(const std::string &fileName);

        /**
         *  Parses pokemon data from a .json file.
         *
         *  @param  moveData    Collection of all `Move` data.
         *  @param  fileName    The path to the file.
         *  @return             A name->object map of `Pokemon`.
         */
        static std::map<std::string, Pokemon> pokemonData(const MoveData &moveData, const std::string &fileName);

        /**
         *  Parses opponent data from a .json file.
         *
         *  @param  pokemonData Collection of all `Pokemon` data.
         *  @param  fileName    The path to the file.
         *  @return             A name->object map of `Opponent`s.
         */
        static std::map<std::string, Opponent> opponentData(const PokemonData &pokemonData,
                                                            const std::string &fileName);

        /**
         *  Parses player data from a .json file.
         *
         *  N.b. this function, unlike the other <typeName>Data(...) functions, does <i>not</i> return a map,
         *  but rather the Player object directly. This because only one such object is ever intended to exist.
         *
         *  @param  fileName    The path to the file.
         *  @return             A `Player` object instance.
         */
        static Player player(const PokemonData &pokemonData, const std::string &fileName);

    private:
        /**
         *  Pure virtial (function) destructor makes class non-instantiable.
         */
        virtual ~parse() = 0;

        /**
         *  @param name The name of the badge.
         *  @param data The Json::Value data.
         *  @return     A `Badge` object instance.
         */
        static Badge badge(const std::string &name, const Json::Value &data);

        /**
         *  @param name The name of the move.
         *  @param data The Json::Value data.
         *  @return     A `Move` object instance.
         */
        static Move move(const std::string &name, const Json::Value &data);

        /**
         *  @param name The name of the opponent.
         *  @param data The Json::Value data.
         *  @return     An `Opponent` object instance.
         */
        static Opponent opponent (const PokemonData &pokemonData,
                                        const std::string &fileName,
                                        const Json::Value &data);

        /**
         *  @param name The name of the pokemon.
         *  @param data The Json::Value data.
         *  @return     A `Pokemon` object instance.
         */
        static Pokemon pokemon (const MoveData &moveData, const std::string &name, const Json::Value &data);

        /**
         *  @param data The Json::Value data.
         *  @return     A `Statistics` object instance.
         */
        static Statistics statistics(const Json::Value &statList);

        /**
         *  @param data The Json::Value data.
         *  @return     A `Types` object instance.
         */
        static Types types (const Json::Value &typeList);

};

}   // namespace ck


#endif  // __CK_PARSER_HPP__
