/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   Pokemon stats.
 * @date    2022-02-05
 */
#ifndef __CK_STATISTICS_HPP__
#define __CK_STATISTICS_HPP__

#include <map>
#include <vector>

namespace ck {

class Statistics {

    public:
        Statistics();
        Statistics(const std::map<std::string, unsigned int> stats);

        bool has(const std::string &name) const;
        virtual unsigned int get(const std::string &name) const;
        void set(const std::string &name, unsigned int value);

        std::vector<std::string> names() const;

        std::string string() const;

    protected:
        void checkStat(const std::string &name) const;

        std::map<std::string, unsigned int> myStats;
};

}   // namespace ck

#endif  // __CK_STATISTICS_HPP__
