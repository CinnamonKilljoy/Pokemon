#include <utility>

#include "data.hpp"
#include "errors.hpp"
#include "parser.hpp"

namespace ck {

template <typename DataType>
Data<DataType>::Data() {}

MoveData::MoveData(const std::string &fileName) : Data<Move>() {
    myData = std::map<std::string, Move>();
    for (const std::pair<std::string, Move> pair : parse::moveData(fileName)) {
        myData[pair.first] = pair.second;
    }
}

PokemonData::PokemonData(const MoveData &moveData, const std::string &fileName) : Data<Pokemon>() {
    myData = std::map<std::string, Pokemon>();
    for (const std::pair<std::string, Pokemon> pair : parse::pokemonData(moveData, fileName)) {
        myData[pair.first] = pair.second;
    }
}

template <typename DataType>
std::map<std::string, DataType> Data<DataType>::all() const {
    std::map<std::string, DataType> result = {};
    for (const std::pair<std::string, DataType> &data : myData) {
        result[data.first] = data.second;
    }
    return result;
}

std::map<std::string, Move> MoveData::all() const {
    return Data<Move>::all();
}

std::map<std::string, Pokemon> PokemonData::all() const {
    return Data<Pokemon>::all();
}

template <typename DataType>
std::vector<DataType> Data<DataType>::list() const {
    std::vector<DataType> result = {};
    for (const std::pair<std::string, DataType> &data : myData) {
        result.push_back(data.second);
    }
    return result;
}

std::vector<Move> MoveData::list() const {
    return Data<Move>::list();
}

std::vector<Pokemon> PokemonData::list() const {
    return Data<Pokemon>::list();
}

template <typename DataType>
DataType Data<DataType>::get(const std::string &name) const {
    if (!has(name)) {
        throw error::ValueError("No such " + myType() + ": " + name, error::code::UNKNOWN_MOVE);
    }
    return myData.at(name);
}

Move MoveData::get(const std::string &name) const {
    return Data<Move>::get(name);
}

Pokemon PokemonData::get(const std::string &name) const {
    return Data<Pokemon>::get(name);
}

template <typename DataType>
bool Data<DataType>::has(const std::string &name) const {
    return myData.find(name) != myData.end();
}

bool MoveData::has(const std::string &name) const {
    return Data<Move>::has(name);
}

bool PokemonData::has(const std::string &name) const {
    return Data<Pokemon>::has(name);
}

template <typename DataType>
std::string Data<DataType>::myType() const {
    throw error::ImplementationError("myType() must be overriden.");
}

std::string MoveData::myType() const {
    return "Move";
}

std::string PokemonData::myType() const {
    return "Pokemon";
}

}   // namespace ck
