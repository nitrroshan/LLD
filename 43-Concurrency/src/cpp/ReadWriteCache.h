#pragma once
#include <unordered_map>
#include <shared_mutex>
#include <mutex>

// A read/write-locked cache: many readers concurrently (shared_lock), one
// exclusive writer (unique_lock). Good when reads are genuinely read-only.
template <class K, class V>
class ReadWriteCache {
    std::unordered_map<K, V> map_;
    mutable std::shared_mutex mtx_;

public:
    bool get(const K& key, V& out) const {
        std::shared_lock<std::shared_mutex> lock(mtx_);   // shared (read) lock
        auto it = map_.find(key);
        if (it == map_.end()) return false;
        out = it->second;
        return true;
    }

    void put(const K& key, const V& value) {
        std::unique_lock<std::shared_mutex> lock(mtx_);   // exclusive (write) lock
        map_[key] = value;
    }

    int size() const {
        std::shared_lock<std::shared_mutex> lock(mtx_);
        return static_cast<int>(map_.size());
    }
};
