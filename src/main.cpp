#include <iostream>
#include <string>

#include "battle.hpp"
#include "data.hpp"
#include "errors.hpp"
#include "log.hpp"
#include "opponent.hpp"
#include "options.hpp"
#include "parser.hpp"
#include "player.hpp"
#include "pokemon.hpp"

using log = ck::log;

using namespace ck;

namespace ck {

static void programError(const std::string &message, const error::code &code) {
    log::error(message + " (" + std::to_string((int) code) + ")");
    exit(1);
}

static void usage(const int &exitCode = 0) {
    log::echo({
        "usage: pokemon-text [-c file_name] [-h] [-l level] [-m file_name] [-p file_name]",
        "--------------------------------------------",
        "Option   Description               Default  ",
        " -c      Path to player file.     <internal>",
        " -h      Print this.                        ",
        " -l      Set the log level.           0     ",
        " -m      Path to moves file.      <internal>",
        " -o      Path to opponent file.   <internal>",
        " -p      Path to pokemon file.    <internal>",
        "--------------------------------------------"
    });

    exit(exitCode);
}

static void loop(Options options) {

    if (options.has("h")) {
        usage();
    }
    if (options.has("l")) {
        log::setLevel(options.get("l"));
    }

    MoveData moves = MoveData(options.get("m"));
    PokemonData pokemon = PokemonData(moves, options.get("p"));
    Player player = parse::player(pokemon, options.get("c"));
    Opponent opponent = parse::opponentData(pokemon, options.get("o")).at("BlueA");
    Battle battle = Battle(player, opponent);
    log::debug(battle.string());
}

}   // namespace ck

int main(int argc, char** argv) {
    std::vector<std::string> arguments = {};
    for (int i = 1; i < argc; ++i) {
        arguments.push_back(argv[i]);
    }

    try {
        ck::loop(ck::Options::set(arguments));
    } catch (const error::ProgramError &error) {
        ck::programError(std::string(error.what()), error.code());
    } catch (const std::exception &error) {
        ck::programError("Internal error: " + std::string(error.what()), error::code::INTERNAL);
    }

    return 0;
}
