#include "player.hpp"

namespace ck {

Player::Player(const std::string &name,
               const std::vector<std::pair<Pokemon, unsigned int>> &party,
               const std::vector<Badge> &badges) :
                    Actor(name, party),
                    myBadges(badges) {}

std::vector<Badge> Player::badges(const bool &includeMissing) const {
     std::vector<Badge> result = {};
     for (const Badge &badge : myBadges) {
          if (badge.acquired() || includeMissing) {
               result.push_back(badge);
          }
     }
     return result;
}

} // namespace ck
