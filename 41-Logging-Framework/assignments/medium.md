# Chapter 41 — Assignment (Medium)

## Asynchronous (queued) logging with a thread-safe appender

The **performance** upgrade — the follow-up that separates a toy logger from a production one.
Move the slow work (formatting + I/O) **off the caller's thread** and make concurrent logging
safe.

### Part A — Async logging (producer/consumer)

Right now `log()` runs the whole handler chain **synchronously** on the caller's thread — so a
slow appender blocks the request path. Decouple them.

Requirements:
- `log()` should build the `LogRecord` and **enqueue** it on a **bounded, thread-safe queue**,
  then return immediately (the "producer").
- A dedicated **background worker thread** drains the queue and runs the handler chain for each
  record (the "consumer"). Java: `BlockingQueue` + a worker `Thread`; C++: a `std::queue` +
  `std::mutex` + `std::condition_variable` + a `std::thread`.
- Add a `shutdown()` / `flush()` that stops the worker cleanly after draining remaining records
  (so a program exit doesn't lose buffered logs — as much as possible).

Design questions to answer:
- **Loss on crash**: records sitting in the queue when the process dies are lost. How would you
  bound the window (small queue + frequent flush) or accept it (logs are best-effort)?
- **Backpressure**: what happens when the queue is full — block the producer, or drop records?
  State the trade-off (latency vs loss).
- **Ordering**: a single consumer preserves order; multiple consumers don't. Which do you pick
  for logs and why?

### Part B — Thread-safe appender

Even async, if two workers (or the async worker plus a synchronous fallback) write to the same
destination, lines interleave.

Requirements:
- Wrap or extend an appender so its `append` is **mutually exclusive** (a lock around the
  write). Java: `synchronized` / a `Lock`; C++: a `std::mutex` + `std::lock_guard`.
- Demonstrate multiple producer threads logging concurrently and show the output lines are
  **whole** (never interleaved mid-line).

### Part C — Singleton thread-safety note (design only)

In a comment, confirm why the Singleton itself is already safe to *create* concurrently (Bill
Pugh in Java / Meyer's in C++ — Ch08), and note that the remaining concurrency concern is the
**write path**, which Parts A/B address.

### Constraints

- The public logging API (`log`, `info`, `error`, …) is **unchanged** — callers don't know it
  became async.
- Use standard concurrency primitives; keep the queue **bounded** and the shutdown **clean**.

### Demo (extend `Main` / `main.cpp`)

1. Configure async logging; spawn several threads that each log many messages; `flush()` at the
   end and show all messages were written and no line is interleaved.
2. Show a simple timing contrast: the caller's `log()` returns quickly even when the appender is
   artificially slow (e.g., a small sleep in `append`).

### What good looks like

- `log()` enqueues and returns; a background worker does the formatting + I/O.
- Concurrent writes produce whole, non-interleaved lines (thread-safe appender).
- A written analysis of loss-on-crash, backpressure, and ordering trade-offs.
