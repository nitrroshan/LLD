# Chapter 43 — Concurrency in LLD

> **Phase 6 begins: Advanced Topics.** These chapters are concept-driven (theory + before/after code + exercises), not case-study walkthroughs. Everything is shown in **Java and C++** side by side.

## What & Why

Most LLD designs eventually run under **many threads**: a shared cache, a logger, a booking coordinator, a connection pool. The moment two threads touch the same mutable state, you can get **race conditions**, **torn reads**, **deadlocks**, and **lost updates** — bugs that are intermittent, hard to reproduce, and catastrophic in production.

This chapter is the toolbox: how to make shared state **safe** and **fast** under concurrency, and the patterns (Producer–Consumer, thread-safe Singleton) that keep showing up. It directly builds on the thread-safety follow-ups from the **Logging** (async) and **Cache** (concurrent access) chapters.

---

## 1. The Core Problem: Race Conditions

A race condition is when the **correctness of a result depends on the timing** of threads. The classic is a non-atomic increment.

`count++` looks like one step but is **three**: read → add → write. Two threads can both read the same old value, both add one, both write back — **one update is lost**.

```
Thread A: read count (5)
Thread B: read count (5)
Thread A: write 6
Thread B: write 6      ← should be 7! one increment lost
```

**Java (the bug):**
```java
class Counter {
    private int count = 0;
    public void increment() { count++; }      // NOT atomic
    public int get() { return count; }
}
// 4 threads × 100_000 increments → final count is usually < 400_000
```

**C++ (the bug):**
```cpp
struct Counter {
    int count = 0;
    void increment() { count++; }             // NOT atomic — undefined behavior under data race
    int get() const { return count; }
};
```

> In C++ a data race on a plain `int` is **undefined behavior** (not just a wrong number) — the standard makes no promises at all. In Java it's defined but wrong (a lost update + possible stale reads).

---

## 2. Mutual Exclusion: `synchronized` / `std::mutex`

The simplest fix: make the read-modify-write **atomic** by letting only one thread into the critical section at a time.

**Java — `synchronized`:**
```java
class SynchronizedCounter {
    private int count = 0;
    public synchronized void increment() { count++; }   // one thread at a time
    public synchronized int get() { return count; }
}
```
`synchronized` acquires the object's intrinsic **monitor lock** on entry and releases it on exit (even on exception).

**C++ — `std::mutex` + `std::lock_guard`:**
```cpp
class SynchronizedCounter {
    int count_ = 0;
    mutable std::mutex mtx_;
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx_);   // RAII: unlocks on scope exit
        count_++;
    }
    int get() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return count_;
    }
};
```

| | Java | C++ |
|---|------|-----|
| Lock a scope | `synchronized (obj) { }` / `synchronized` method | `std::lock_guard<std::mutex>` / `std::unique_lock` |
| Auto-release | on block/method exit | on scope exit (**RAII**) |
| The lock object | every object has a monitor | an explicit `std::mutex` member |

Both guarantee: only one thread in the critical section, and changes made under the lock are **visible** to the next thread that acquires it.

---

## 3. Visibility: `volatile` / `std::atomic`

Locks solve *both* mutual exclusion **and** visibility. But sometimes you only need **visibility** — one thread writes a flag, another reads it — without a full lock.

The hazard: without a memory barrier, a thread may read a **stale cached** copy of a variable forever (the compiler/CPU can hoist the read out of a loop).

**Java — `volatile`:**
```java
class Worker {
    private volatile boolean running = true;   // writes are visible to other threads
    public void stop() { running = false; }
    public void run() {
        while (running) { /* work */ }          // sees stop() without volatile? maybe never
    }
}
```
`volatile` guarantees **visibility** and prevents reordering — but it does **not** make compound actions (`count++`) atomic.

**C++ — `std::atomic` (NOT `volatile`!):**
```cpp
class Worker {
    std::atomic<bool> running{true};            // atomic + visibility + ordering
public:
    void stop() { running = false; }
    void run() { while (running) { /* work */ } }
};
```

> **Critical difference:** C++ `volatile` is **not** a threading tool — it does *not* provide atomicity or cross-thread ordering (it's for memory-mapped hardware). Use **`std::atomic`**. Java's `volatile` ≈ C++ `std::atomic` with the default (sequentially-consistent) ordering.

---

## 4. Atomics for Counters

For a simple counter, a full lock is overkill — use an **atomic** with a lock-free hardware instruction.

**Java — `AtomicInteger`:**
```java
class AtomicCounter {
    private final AtomicInteger count = new AtomicInteger(0);
    public void increment() { count.incrementAndGet(); }   // atomic RMW, no lock
    public int get() { return count.get(); }
}
```

**C++ — `std::atomic<int>`:**
```cpp
class AtomicCounter {
    std::atomic<int> count_{0};
public:
    void increment() { count_.fetch_add(1); }   // or ++count_;  atomic RMW
    int get() const { return count_.load(); }
};
```

Atomics are **faster** than locks for single-variable updates (no blocking), but they only cover **one** variable — for multi-variable invariants you still need a lock.

---

## 5. Read/Write Locks (many readers, one writer)

When reads vastly outnumber writes (a cache, a config), a plain mutex serializes even reads. A **read-write lock** lets **many readers** in concurrently but gives a **writer** exclusive access.

**Java — `ReentrantReadWriteLock`:**
```java
class ThreadSafeCache<K, V> {
    private final Map<K, V> map = new HashMap<>();
    private final ReadWriteLock lock = new ReentrantReadWriteLock();

    public V get(K key) {
        lock.readLock().lock();               // shared — many readers at once
        try { return map.get(key); }
        finally { lock.readLock().unlock(); }
    }
    public void put(K key, V value) {
        lock.writeLock().lock();              // exclusive — blocks all readers/writers
        try { map.put(key, value); }
        finally { lock.writeLock().unlock(); }
    }
}
```

**C++ — `std::shared_mutex` (C++17):**
```cpp
template <class K, class V>
class ThreadSafeCache {
    std::unordered_map<K, V> map_;
    mutable std::shared_mutex mtx_;
public:
    bool get(const K& key, V& out) const {
        std::shared_lock lock(mtx_);          // shared (read) lock — many readers
        auto it = map_.find(key);
        if (it == map_.end()) return false;
        out = it->second;
        return true;
    }
    void put(const K& key, const V& value) {
        std::unique_lock lock(mtx_);          // exclusive (write) lock
        map_[key] = value;
    }
};
```

> Recall the caching caveat from Ch42: **LRU `get` is a write** (it reorders recency), so a read-write lock doesn't help a true LRU — its "reads" mutate state. Read-write locks shine for genuinely read-only reads.

---

## 6. Producer–Consumer (bounded blocking queue)

The workhorse concurrency pattern: producers hand work to consumers through a **bounded, thread-safe queue**. Producers **block when it's full**, consumers **block when it's empty** — natural backpressure. (This is the engine behind the async logger in Ch41.)

**Java — `BlockingQueue` does it for you:**
```java
BlockingQueue<Task> queue = new ArrayBlockingQueue<>(100);
// producer:
queue.put(task);         // blocks if full
// consumer (worker thread):
Task t = queue.take();   // blocks if empty
```

**C++ — hand-rolled with `mutex` + `condition_variable`:**
```cpp
template <class T>
class BlockingQueue {
    std::queue<T> q_;
    std::mutex mtx_;
    std::condition_variable not_empty_, not_full_;
    size_t capacity_;
public:
    explicit BlockingQueue(size_t capacity) : capacity_(capacity) {}

    void put(T item) {
        std::unique_lock<std::mutex> lock(mtx_);
        not_full_.wait(lock, [&]{ return q_.size() < capacity_; });   // block if full
        q_.push(std::move(item));
        not_empty_.notify_one();
    }
    T take() {
        std::unique_lock<std::mutex> lock(mtx_);
        not_empty_.wait(lock, [&]{ return !q_.empty(); });            // block if empty
        T item = std::move(q_.front());
        q_.pop();
        not_full_.notify_one();
        return item;
    }
};
```

Key points: `wait(lock, predicate)` releases the lock while sleeping and re-checks the predicate on wakeup (guards against **spurious wakeups**); `notify_one` wakes a waiter.

---

## 7. Thread-Safe Singleton (recap)

From Ch08, but it's a concurrency question. Lazy init has a race (two threads both create the instance). The safe idioms:

**Java — Bill Pugh (initialization-on-demand holder):**
```java
public class Config {
    private Config() {}
    private static class Holder { static final Config INSTANCE = new Config(); }
    public static Config getInstance() { return Holder.INSTANCE; }   // JVM guarantees once
}
```

**C++ — Meyer's Singleton:**
```cpp
static Config& instance() {
    static Config instance;   // C++11 guarantees thread-safe one-time init
    return instance;
}
```

Both are lazy **and** thread-safe with no locks you write — the classloader (Java) / compiler (C++) inserts the synchronization. Avoid hand-rolled double-checked locking.

---

## 8. Thread-Safe Collections

Don't guard a plain collection by hand if a concurrent one exists.

| Need | Java | C++ |
|------|------|-----|
| Concurrent map | `ConcurrentHashMap` (lock striping) | none in std — guard `unordered_map` with a mutex / use TBB / `folly` |
| Blocking queue | `ArrayBlockingQueue`, `LinkedBlockingQueue` | hand-rolled (see §6) |
| Atomic counter | `AtomicInteger/Long` | `std::atomic<int>` |
| Copy-on-write list | `CopyOnWriteArrayList` | none in std |

> The C++ standard library has **no concurrent containers** — you compose `std::mutex`/`std::shared_mutex` around standard containers, or reach for a library (Intel TBB, Folly). Java ships a rich `java.util.concurrent`.

### `ConcurrentHashMap` — use atomic compound methods, not get-then-put

The trap: even with a `ConcurrentHashMap`, a `get` **then** `put` is *two* operations — two threads can both read the same count and both write `n+1`, losing an update (the same read-modify-write race as §1).

```java
// ❌ STILL a race — two operations, not atomic:
counts.put(word, counts.getOrDefault(word, 0) + 1);

// ✅ atomic — merge() does the whole read-modify-write as ONE operation:
ConcurrentHashMap<String, Integer> counts = new ConcurrentHashMap<>();
counts.merge(word, 1, Integer::sum);   // absent -> 1, else old + 1
```

A word counter under 8 threads, exact result, no lost updates:
```java
ConcurrentHashMap<String, Integer> counts = new ConcurrentHashMap<>();
Runnable job = () -> {
    for (int i = 0; i < 100_000; i++) counts.merge("apple", 1, Integer::sum);
};
// start/join 8 threads running job → counts.get("apple") == 800_000 exactly
```

The key **atomic** methods (prefer these over `get`+`put`):

| Method | Atomically… |
|--------|-------------|
| `merge(k, v, remap)` | insert `v` if absent, else combine old+new — **best for counters** |
| `compute(k, (k,v) -> …)` | recompute a value from the current one |
| `computeIfAbsent(k, k -> init())` | build-and-insert only if missing — **lazy cache** (a mini single-flight, cf. Ch42 stampede) |
| `putIfAbsent(k, v)` | insert only if the key is absent |

`ConcurrentHashMap` beats `Collections.synchronizedMap` because it uses **lock striping** (locks per bin) so operations on *different* keys run in parallel, whereas `synchronizedMap` locks the whole map every call.

**C++ equivalent** (no std concurrent map — do the whole RMW inside the lock):
```cpp
class ConcurrentCounter {
    std::unordered_map<std::string, int> map_;
    std::mutex mtx_;
public:
    void increment(const std::string& key) {
        std::lock_guard<std::mutex> lock(mtx_);   // the whole ++ is atomic
        map_[key]++;
    }
};
```
For real lock-striped throughput in C++, reach for TBB `concurrent_hash_map` or Folly `ConcurrentHashMap`.

---

## 9. Deadlock (and how to avoid it)

A **deadlock**: thread A holds lock 1 and waits for lock 2; thread B holds lock 2 and waits for lock 1 — both stuck forever.

```
A: lock(account1); ... lock(account2)   // transfer 1 -> 2
B: lock(account2); ... lock(account1)   // transfer 2 -> 1   ← deadlock
```

**Avoidance strategies:**
- **Lock ordering** — always acquire locks in a **global order** (e.g., by account id). Then A and B both lock the lower id first; no cycle.
- **Lock both at once** — C++ `std::lock(m1, m2)` / `std::scoped_lock(m1, m2)` acquires multiple locks deadlock-free; Java: `tryLock` with timeout + backoff.
- **Hold locks briefly**, never call foreign/callback code while holding a lock.
- **Prefer higher-level constructs** (concurrent collections, immutable data, message passing) over manual locks.

```cpp
// C++ deadlock-free multi-lock:
std::scoped_lock lock(account1.mtx, account2.mtx);   // acquires both atomically
```

---

## 10. Best Practices & Pitfalls

1. **Minimize shared mutable state** — the less you share, the less you lock. Immutable objects are automatically thread-safe.
2. **Prefer high-level tools** — `AtomicInteger`, `ConcurrentHashMap`, `BlockingQueue`, `std::atomic` — over hand-rolled locking.
3. **Hold locks for the shortest time** — never do I/O or call unknown code under a lock.
4. **One consistent lock order** everywhere — the simplest deadlock cure.
5. **Java `volatile` ≠ atomic** — it gives visibility, not compound atomicity. **C++ `volatile` is not a threading tool at all** — use `std::atomic`.
6. **RAII locks in C++** (`lock_guard`/`scoped_lock`) — never manual `lock()`/`unlock()` (leaks on exception).
7. **Guard the whole invariant, not each field** — if two fields must stay consistent, one lock must cover both.
8. **Beware "reads that write"** — LRU recency updates, lazy init — they need write protection despite looking like reads.

---

## What's Next

Study the runnable demos in `src/java` and `src/cpp`: a counter race (unsafe vs `synchronized`/mutex vs atomic), a producer–consumer bounded buffer, and a read/write-locked cache. The C++ demo compiles with `g++ -std=c++17 -pthread`. Then the exercises: make a bounded thread pool, and fix a deadlock with lock ordering. Next chapter: **44 — Refactoring & Code Smells**.
