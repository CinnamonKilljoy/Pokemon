#ifndef __CK_MOVE_HPP__
#define __CK_MOVE_HPP__

#include <string>

#include "types.hpp"


namespace ck {
class Move {

    public:
        Move();
        Move(const std::string &name,
             const unsigned int &accuracy,
             const unsigned int &points,
             const unsigned int &power,
             const Type &type);

        Move& operator=(const Move &other);

        unsigned int accuracy() const;
        std::string name() const;
        unsigned int power() const;
        unsigned int pp() const;
        unsigned int points() const;
        Type type() const;
        std::string string() const;

    private:
        std::string myName;
        unsigned int myAccuracy;
        unsigned int myPoints;
        unsigned int myPower;
        Type myType;
};

}   // namespace ck

#endif  // __CK_MOVE_HPP__
