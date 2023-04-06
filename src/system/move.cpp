#include "move.hpp"
#include "strings.hpp"

namespace ck {

Move::Move(): Move("<NULL>", 0, 0, 0, Type::NONE) {}

Move::Move(const std::string &name,
           const unsigned int &accuracy,
           const unsigned int &points,
           const unsigned int &power,
           const Type &type)  :
           myName(name),
           myAccuracy(accuracy),
           myPoints(points),
           myPower(power),
           myType(type) {}


unsigned int Move::accuracy() const {
    return myAccuracy;
}

std::string Move::name() const {
    return myName;
}

unsigned int Move::power() const {
    return myPower;
}

unsigned int Move::pp() const {
    return myPoints;
}

unsigned int Move::points() const {
    return pp();
}

Type Move::type() const {
    return myType;
}

Move& Move::operator=(const Move &other) {
    if (this != &other) {
        myAccuracy = other.myAccuracy;
        myName     = other.myName;
        myPoints   = other.myPoints;
        myPower    = other.myPower;
        myType     = other.myType;
    }
    return *this;
}

std::string Move::string() const {
    return string::format("[%s]: %s, %u PP, %u%%, %u power.",
                          myName.c_str(),
                          string::lexical(Types::string(myType)).c_str(),
                          myPoints,
                          myAccuracy,
                          myPower);
}

}   // namespace ck



