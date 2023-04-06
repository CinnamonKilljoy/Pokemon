/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   Error functionality.
 * @date    2022-01-25
 */
#ifndef __CK_COLLECTIONS_HPP__
#define __CK_COLLECTIONS_HPP__

#include <map>

namespace ck::collection {

template <typename K, typename V>
std::map<V, K> inverseMap(std::map<K, V> map);

}   // namespace ck::Collections

#endif  // __CK_COLLECTIONS_HPP__
