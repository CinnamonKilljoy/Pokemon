/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   Pokemon stats.
 * @date    2022-02-05
 */
#ifndef __CK_BATTLESTATISTICS_HPP__
#define __CK_BATTLESTATISTICS_HPP__

#include <map>

#include "statistics.hpp"

namespace ck {

class BattleStatistics : public Statistics {

    public:
        BattleStatistics(const Statistics &stats);

        unsigned int get(const std::string &stat) const override;

        int stage(const std::string &stat) const;
        bool modify(const std::string &stat, const int &level);

    private:
        static void checkModification(const int &level);
        static double adjustment(const int &level);
        std::map<std::string, int> modifiers;
};

}   // namespace ck

#endif  // __CK_BATTLESTATISTICS_HPP__
