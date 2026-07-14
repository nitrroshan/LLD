#pragma once
#include <deque>
#include "EvictionPolicy.h"

// First In, First Out — evict in insertion order; access does not matter.
template <class K>
class FifoEvictionPolicy : public EvictionPolicy<K> {
    std::deque<K> queue_;

public:
    void key_added(const K& key) override { queue_.push_back(key); }
    void key_accessed(const K&) override { /* FIFO ignores access */ }
    K evict_key() override {
        K victim = queue_.front();       // oldest inserted
        queue_.pop_front();
        return victim;
    }
};
