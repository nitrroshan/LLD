#pragma once
#include <memory>
#include <unordered_map>
#include <iostream>
#include "EvictionPolicy.h"

// A fixed-capacity cache. Owns the key->value store and delegates the
// "who to evict" decision to a pluggable EvictionPolicy (Strategy).
template <class K, class V>
class Cache {
    int capacity_;
    std::unordered_map<K, V> store_;
    std::unique_ptr<EvictionPolicy<K>> policy_;   // owns the strategy

public:
    Cache(int capacity, std::unique_ptr<EvictionPolicy<K>> policy)
        : capacity_(capacity), policy_(std::move(policy)) {}

    // Returns true on a hit, writing the value to `out`. A hit updates the policy.
    bool get(const K& key, V& out) {
        auto it = store_.find(key);
        if (it == store_.end()) return false;
        policy_->key_accessed(key);
        out = it->second;
        return true;
    }

    void put(const K& key, const V& value) {
        if (store_.find(key) != store_.end()) {
            store_[key] = value;
            policy_->key_accessed(key);
            return;
        }
        if (static_cast<int>(store_.size()) >= capacity_) {
            K victim = policy_->evict_key();       // Strategy decides the victim
            store_.erase(victim);
            std::cout << "    evicted " << victim << "\n";
        }
        store_[key] = value;
        policy_->key_added(key);
    }

    bool contains(const K& key) const { return store_.find(key) != store_.end(); }
    int size() const { return static_cast<int>(store_.size()); }
};
