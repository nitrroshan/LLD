#pragma once
#include <unordered_map>
#include <limits>
#include "EvictionPolicy.h"

// Least Frequently Used — evict the key with the fewest accesses. Ties broken
// arbitrarily (first minimum found).
template <class K>
class LfuEvictionPolicy : public EvictionPolicy<K> {
    std::unordered_map<K, int> frequency_;

public:
    void key_added(const K& key) override { frequency_[key] = 1; }
    void key_accessed(const K& key) override { frequency_[key]++; }

    K evict_key() override {
        K victim{};
        int min = std::numeric_limits<int>::max();
        for (const auto& [key, freq] : frequency_) {
            if (freq < min) {
                min = freq;
                victim = key;
            }
        }
        frequency_.erase(victim);
        return victim;
    }
};
