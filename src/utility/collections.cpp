#include <utility>

#include "collections.hpp"

namespace ck::collection {

template <typename K, typename V>
std::map<V, K> inverseMap(std::map<K, V> map) {
    std::map<V, K> result = std::map<V, K>();

    for (std::pair<K, V> pair : map) {
        result[pair.second] = pair.first;
    }
    return result;
}

} // namespace ck::collections
