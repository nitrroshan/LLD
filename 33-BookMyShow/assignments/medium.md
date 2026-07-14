# Assignment: Dynamic Pricing + Real Concurrency (Design + Code)

## Objective

Add **demand-based dynamic pricing** and prove the booking flow is **truly concurrency-safe** under real threads. Implement in **Java and C++**.

## Part 1 — Dynamic (Demand-Based) Pricing Strategy

Add a `DemandPricingStrategy` whose price rises as the show fills up:

- Base tier price × a demand multiplier that depends on the show's **occupancy** at booking time:
  - < 50% booked → ×1.0
  - 50–80% → ×1.25
  - > 80% → ×1.5
- The strategy needs the show's occupancy. Get it **without** coupling the strategy to the whole `BookingSystem` — `Show` already exposes availability; use just that.
- Compose with `WeekendSurgePricingStrategy` (surge × demand × base) to show strategies stacking.

## Part 2 — Real Concurrency

Make `book(...)` safe when multiple threads book the **same show** simultaneously:

- Spawn several threads (Java `Thread`/`ExecutorService`, C++ `std::thread`) that all try to book overlapping seats on one show.
- Exactly one thread must win each contested seat; the losers get a clean `FAILED` — **no seat double-booked, no lost update**.
- Verify by asserting the total booked seats never exceeds capacity and no seat is booked twice.

## Design Tasks (answer in `DESIGN.md`)

1. Your `Show.lockSeats` is the critical section. Explain why the **lock-then-confirm** ordering (not "check then later book") is what makes it race-free.
2. `DemandPricingStrategy` reads occupancy that changes concurrently. Is a slightly stale price acceptable, or must occupancy be read inside the lock? Justify the trade-off.
3. Under heavy contention, coarse locking (one mutex per show) can bottleneck. Sketch how per-seat locks or optimistic versioning would improve it — and the new risks (deadlock, retries).

## Implementation Requirements

- `DemandPricingStrategy` (occupancy-aware), composable with weekend surge.
- A concurrency test: N threads booking overlapping seats on one show; assert no double-booking and count ≤ capacity.
- Keep the pricing strategy decoupled from `BookingSystem`.

## Constraints

- One file per class/type in **Java and C++**
- `book(...)` must be race-free for the same show (guard the lock step correctly)
- Adding dynamic pricing must not modify existing strategies (OCP) — compose them
- The demand strategy depends only on `Show` availability, not the whole system

## Design Question to Answer

You now have four plug-in axes on `BookingSystem`: **seat creation** (Factory), **pricing** (Strategy, composed), **notifications** (Observer), and **one coordinator** (Singleton). Explain how each keeps the system open for extension while `BookingSystem` stays small — and where the Singleton could become a testing/concurrency liability.

## Submission

Put your solution in `33-BookMyShow/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
