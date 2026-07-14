# Chapter 42 — Assignment (Medium)

## Thread-safe concurrent cache + single-flight (cache stampede)

The **production** upgrade — make the cache safe under many threads, and stop a hot key from
hammering the backing source. This sets up Phase 6 (Concurrency).

### Part A — Thread-safe cache

Concurrent `get`/`put` race on both the store map **and** the policy's ordering structure.

Requirements:
- Make `get`/`put` safe under concurrent access. Start with a **single lock** around cache ops
  (Java: `ReentrantLock` / `synchronized`; C++: `std::mutex` + `std::lock_guard`).
- Then improve throughput with **lock striping**: partition keys into `S` segments (by
  `hash(key) % S`), each with its own small cache + lock, so operations on different segments
  don't block each other. (This is how `ConcurrentHashMap` scales.)

Design question to answer — the LRU subtlety: **a `get` is a write** (it reorders recency), so a
plain read-write lock gives you *no* read concurrency. Explain how this pushes real systems
toward **approximate LRU** (sampled eviction, or second-chance/CLOCK) that tolerates slightly
stale ordering for far better concurrency.

### Part B — Single-flight (prevent cache stampede / thundering herd)

When a hot key expires, N concurrent requests all miss and all hit the slow source at once.

Requirements:
- In the `CacheProxy`, add **single-flight**: for a given missing key, only the **first**
  requester fetches from the real source; concurrent requests for the **same key** wait for that
  in-flight fetch and share its result (a per-key lock / a map of in-flight futures).
- Demonstrate: several threads request the same missing key simultaneously and the backing
  source is called **once**, not N times.

Design question to answer: single-flight trades a little **latency** (waiters block on the
in-flight fetch) for a big drop in **backend load**. When is that the wrong trade (e.g., if the
fetch can fail — do waiters all retry, or share the failure)?

### Part C — Design write-up

In a comment or `DESIGN.md`, connect the dots:
- Why LRU is hard to make lock-free (reads mutate order) → approximate LRU.
- How lock striping improves throughput and its trade-off (per-segment eviction isn't global).
- How single-flight relates to the caching **Proxy** (it lives in the proxy's miss path).

### Constraints

- The cache's public API stays the same; concurrency is internal.
- Single-flight lives in the **proxy**, not the core cache.
- Use standard concurrency primitives; keep locking scopes tight.

### Demo (extend `Main` / `main.cpp`)

1. Spawn many threads doing mixed `get`/`put` on a striped cache; show it doesn't crash/corrupt
   and final contents are consistent.
2. Spawn many threads requesting the same missing key through the single-flight proxy; show the
   `[DB] fetching` line prints **once**.

### What good looks like

- Concurrent access is safe (single lock, then lock striping) with the same public API.
- Single-flight collapses a stampede to one backend fetch, implemented in the proxy.
- A written analysis: LRU-reads-are-writes → approximate LRU, striping trade-offs, single-flight
  latency-vs-load.
