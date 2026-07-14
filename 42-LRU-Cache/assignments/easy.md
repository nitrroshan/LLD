# Chapter 42 — Assignment (Easy)

## TTL expiry + a LinkedHashMap-based LRU

A **design + implementation** exercise reinforcing that eviction (**Strategy**) and expiry are
**orthogonal**, plus showing the pragmatic production LRU.

### Part A — TTL (time-to-live) expiry

Entries should be able to **expire** independent of capacity eviction.

Requirements:
- Store an **expiry timestamp** alongside each value (wrap the value in a small `CacheEntry`
  holding `value` + `expiresAt`). Use an injectable/mockable clock (an integer "tick" is fine
  for a deterministic demo).
- On `get`, treat an entry whose `expiresAt <= now` as a **miss** and lazily remove it (and
  notify the policy via a new `keyRemoved(key)` so its bookkeeping stays in sync).
- `put(key, value, ttl)` records `expiresAt = now + ttl`.

Design question to answer: TTL and the eviction **Strategy** are independent — an entry can
leave the cache because it **expired** *or* because it was **evicted for capacity**. Explain why
keeping them separate (not folding TTL into the LRU policy) keeps both simple, and where a
proactive background sweeper would fit vs the lazy on-get check.

### Part B — `LinkedHashMapLruCache` (the pragmatic LRU)

Your `LruEvictionPolicy` demonstrates the mechanics. Now show the production shortcut.

Requirements:
- Implement an LRU cache using **`LinkedHashMap(capacity, 0.75f, true)`** (access-order) and
  overriding `removeEldestEntry(...)` to auto-evict when over capacity (Java). In C++, keep the
  `std::list` + `unordered_map<K, iterator>` version and note it *is* the same structure
  `LinkedHashMap` uses internally.
- Verify it produces the **same eviction order** as your policy-based cache for a given access
  sequence.

Design question to answer: when would you hand-roll the policy-based cache (pluggable eviction,
teaching, custom behavior) vs just use `LinkedHashMap` (LRU-only, least code)? Both are correct;
name the trade-off.

### Constraints

- TTL is **additive** — the eviction policies and the `Cache` core stay usable without it (TTL
  is an extra check, not a rewrite).
- The `LinkedHashMap` LRU is a *separate* class; don't delete the policy-based design.

### Demo (extend `Main` / `main.cpp`)

1. Put a key with a short TTL; `get` it before expiry (hit) and after advancing the clock past
   expiry (miss + lazily removed).
2. Run the same access sequence through the policy-based LRU and the `LinkedHashMap` LRU; show
   identical eviction order.

### What good looks like

- Expiry is a separate concern layered over the cache; capacity eviction still works unchanged.
- A `LinkedHashMap`-based LRU matches the hand-rolled one's behavior.
- A clear articulation of TTL-vs-eviction orthogonality and hand-rolled-vs-`LinkedHashMap`.
