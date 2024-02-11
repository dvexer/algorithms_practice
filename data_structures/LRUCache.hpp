#ifndef ALGORITHMS_PRACTICE_LRU_CACHE_HPP
#define ALGORITHMS_PRACTICE_LRU_CACHE_HPP

#include <algorithm>
#include <optional>
#include <list>

// Least recently used cache
template <typename K, typename V>
class LRUCache {
public:
    explicit LRUCache(const size_t capacity) : m_capacity(capacity) {}

    std::optional<V> top() const {
        if (m_cache.empty())
            return std::nullopt;
        return m_cache.front().second;
    }

    std::optional<V> get(const K key) {
        std::optional<V> res_value;
        const auto predicate = [key](const std::pair<int, V>& p) {
            return p.first == key;
        };
        const auto val_it = std::find_if(m_cache.begin(), m_cache.end(), predicate);
        if (val_it != m_cache.end()) {
            res_value = val_it->second;
            m_cache.erase(val_it);
            m_cache.push_front({key, res_value.value()});
        }
        return res_value;
    };

    void put(const K key, const V value) {
        if (m_capacity == 0)
            // TODO: consider adding proper handling, e.g. exception throw
            return;

        if (m_cache.size() >= m_capacity)
            m_cache.pop_back();
        m_cache.push_front({key, value});
    }

private:
    size_t m_capacity;
    std::list<std::pair<K, V>> m_cache;
};

#endif //ALGORITHMS_PRACTICE_LRU_CACHE_HPP
