# Chapter 43 — Exercises

Concept-chapter practice. Each exercise is **build + reason** — write the code *and* answer the
design question. Verify concurrency code by running it many times (races are intermittent).

---

## Exercise 1 (Easy) — Bounded Thread Pool

Build a small **fixed-size thread pool** on top of the `BlockingBuffer` from this chapter — the
Producer-Consumer pattern applied to *tasks*.

Requirements:
- `ThreadPool(int nThreads)` starts `nThreads` **worker** threads.
- `submit(task)` enqueues a task (a `Runnable` in Java / a `std::function<void()>` in C++) onto a
  bounded blocking queue; workers `take()` and run tasks in a loop.
- `shutdown()` stops the workers cleanly **after** draining queued tasks (use a poison-pill
  sentinel or a "stop after empty" flag + `join()` each worker).
- Demonstrate: submit 20 tasks to a pool of 4 workers; show all 20 run and `shutdown()` returns
  only after they finish.

Design questions to answer:
- Why is a **fixed** pool usually better than spawning a thread per task? (thread creation cost,
  unbounded threads under load, context-switch thrashing)
- What happens if `submit` is called after `shutdown`? Define the behavior (reject vs ignore).
- How does the **bounded** queue provide **backpressure** when producers outrun workers?

> Java shortcut to compare against: `Executors.newFixedThreadPool(n)`. Build yours first, then
> note what the JDK gives you for free.

---

## Exercise 2 (Easy/Medium) — Fix a Deadlock with Lock Ordering

Start from a broken **bank transfer**: two accounts, each with its own mutex; `transfer(a, b)`
locks `a` then `b`. Two concurrent transfers in opposite directions (`A→B` and `B→A`) deadlock.

Requirements:
1. **Reproduce** the deadlock: two threads doing `transfer(A, B)` and `transfer(B, A)` in a loop;
   show the program hangs (then kill it).
2. **Fix it** with a **global lock order** — always lock the account with the smaller id (or
   address) first, regardless of transfer direction. Show the fix runs to completion.
3. **Alternative fix** (bonus): C++ `std::scoped_lock(m1, m2)` / `std::lock(m1, m2)` acquires both
   deadlock-free; Java `tryLock` with timeout + backoff.

Design questions to answer:
- Why does a **consistent global lock order** eliminate the cycle in the wait-for graph?
- What's the trade-off of `tryLock`-with-retry vs strict lock ordering? (livelock risk, fairness,
  simplicity)
- Where else in this course would this bite? (transferring between Splitwise balances, moving a
  seat/spot between holds) — name one and how you'd order the locks.

---

## Exercise 3 (Medium) — Make the Ch42 LRU cache thread-safe *correctly*

Revisit the LRU cache. Recall the subtlety: **an LRU `get` is a write** (it reorders recency), so
a read/write lock gives you **no** real read concurrency.

Requirements:
- Wrap the Ch42 `Cache` so `get`/`put` are safe under many threads — start with a single mutex.
- Then argue (in `DESIGN.md`) why a `ReadWriteLock`/`shared_mutex` does **not** help a true LRU,
  and sketch an **approximate LRU** that does allow read concurrency (e.g., sampled eviction, or a
  second-chance/CLOCK bit set on read without reordering a list).
- Demonstrate correctness: many threads hammering `get`/`put` never corrupt the map or the policy
  structure.

Design question to answer: state the exact trade-off approximate LRU makes — **slightly worse
eviction accuracy** in exchange for **far better concurrency** — and why production caches accept
it.

---

## What good looks like
- A working fixed thread pool with clean shutdown and backpressure.
- A reproduced-then-fixed deadlock, with a clear explanation of why lock ordering works.
- A thread-safe cache plus a written argument for approximate LRU under contention.
