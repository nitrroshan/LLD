#pragma once
#include <list>
#include <unordered_map>
#include "EvictionPolicy.h"

// Least Recently Used — evict the key accessed longest ago. Classic O(1) design:
// a list keeps keys in recency order (front = MRU, back = LRU), and a map gives
// O(1) access to a node so it can be spliced to the front on access.
template <class K>
class LruEvictionPolicy : public EvictionPolicy<K> {
    std::list<K> order_;                                             // front = MRU, back = LRU
    std::unordered_map<K, typename std::list<K>::iterator> pos_;

public:
    void key_added(const K& key) override {
        order_.push_front(key);
        pos_[key] = order_.begin();
    }

    void key_accessed(const K& key) override {
        auto it = pos_.find(key);
        if (it == pos_.end()) return;
        order_.erase(it->second);        // O(1) remove of a known node
        order_.push_front(key);          // move to most-recent
        pos_[key] = order_.begin();
    }

    K evict_key() override {
        K victim = order_.back();        // least recently used
        order_.pop_back();
        pos_.erase(victim);
        return victim;
    }
};
