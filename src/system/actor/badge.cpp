#include "badge.hpp"

namespace ck {

Badge::Badge(const std::string &name, const std::string &leader, const unsigned int &bonus, const bool &acquired) :
             myName(name), myLeader(leader), myLevel(bonus), myStat(""), isAcquired(acquired) {}

Badge::Badge(const std::string &name, const std::string &leader, const std::string &bonus, const bool &acquired) :
             myName(name), myLeader(leader), myLevel(0), myStat(bonus), isAcquired(acquired) {}

bool Badge::acquired() const {
    return isAcquired;
}

bool Badge::hasLevel() const {
    return myLevel != 0;
}

bool Badge::hasStat() const {
    return myStat != "";
}

std::string Badge::leader() const {
    return myLeader;
}

std::string Badge::name() const {
    return myName;
}

unsigned int Badge::level() const {
    return myLevel;
}

std::string Badge::stat() const {
    return myStat;
}

} // namespace ck
