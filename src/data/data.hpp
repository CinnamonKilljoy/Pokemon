#ifndef __CK_DATA_HPP__
#define __CK_DATA_HPP__

#include <map>
#include <vector>

#include "move.hpp"
#include "pokemon.hpp"

// TODO: Should completely type-parameterize. Couldn't solve it quickly...
namespace ck {

template <typename DataType>
class Data {

    public:
        std::map<std::string, DataType> all() const;
        std::vector<DataType> list() const;
        bool has(const std::string &name) const;
        DataType get(const std::string &name) const;

    protected:
        Data();
        virtual std::string myType() const;

        std::map<std::string, DataType> myData;
};

class MoveData : public Data<Move> {
    public:
        MoveData(const std::string &fileName);
        std::map<std::string, Move> all() const;
        std::vector<Move> list() const;
        bool has(const std::string &name) const;
        Move get(const std::string &name) const;

    private:
        std::string myType() const override final;
};

class PokemonData : public Data<Pokemon> {
    public:
        PokemonData(const MoveData &moveData, const std::string &fileName);
        std::map<std::string, Pokemon> all() const;
        std::vector<Pokemon> list() const;
        bool has(const std::string &name) const;
        Pokemon get(const std::string &name) const;

    private:
        std::string myType() const override final;
};

}   // namespace ck

#endif  // __CK_DATA_HPP__
