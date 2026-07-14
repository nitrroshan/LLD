#pragma once

// Strategy — the eviction policy. Owns ONLY the bookkeeping needed to decide
// which key to evict; the Cache owns the key->value storage. This split is what
// makes LRU / LFU / FIFO interchangeable.
template <class K>
class EvictionPolicy {
public:
    virtual ~EvictionPolicy() = default;
    virtual void key_added(const K& key) = 0;      // a brand-new key was inserted
    virtual void key_accessed(const K& key) = 0;   // an existing key was read/updated
    virtual K evict_key() = 0;                      // choose + remove the victim from bookkeeping
};
