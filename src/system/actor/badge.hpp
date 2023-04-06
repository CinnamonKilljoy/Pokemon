#ifndef __CK_BADGE_HPP__
#define __CK_BADGE_HPP__

#include <ostream>
#include <string>

namespace ck {

class Badge {
    public:
        Badge(const std::string &name,
              const std::string &leader,
              const unsigned int &bonus,
              const bool &acquired = false );

        Badge(const std::string &name,
              const std::string &leader,
              const std::string &bonus,
              const bool &acquired = false);

        bool acquired() const;
        bool hasLevel() const;
        bool hasStat() const;

        std::string leader() const;
        std::string name() const;
        unsigned int level() const;
        std::string stat() const;

    private:
        const std::string myName;
        const std::string myLeader;
        const unsigned int myLevel;
        const std::string myStat;
        const bool isAcquired;
};

}

#endif  // __CK_BADGE_HPP__
