# Assignment: Lock Expiry + Waitlist (Design + Code)

## Objective

Make seat locks **expire** (so abandoned selections free up) and add a **waitlist** that notifies users when a seat frees up on a sold-out show. Implement in **Java and C++**.

## New Requirements

1. **Lock expiry** — when a user locks seats but doesn't pay within a timeout (in the demo, a passed-in "current time" or a tick counter), the lock **auto-releases** and the seats return to `AVAILABLE`.
2. **Waitlist** — for a sold-out show, users can join a waitlist; when a booked seat is **cancelled** (or a lock expires) the first waitlisted user is **notified** that a seat is available.

## Design Tasks (answer in `DESIGN.md`)

1. Where does lock-expiry logic live — in `Show`, the `BookingSystem`, or a separate `LockManager`? How do you avoid a background thread in a deterministic demo (hint: pass "now" / a tick, and sweep expired locks on each booking attempt)?
2. Is the waitlist an **Observer** concern, a queue owned by the `Show`, or both? Model who gets notified and in what order (FIFO fairness).
3. Cancellation frees a seat and may promote a waitlisted user. Which existing methods (`releaseSeats`, notify) do you reuse, and what new events do observers need?

## Implementation Requirements

- Locks carry a `lockedAt` time; add `expireLocks(now)` that releases locks older than the timeout.
- A `Waitlist` per show (FIFO); `joinWaitlist(showId, user)`.
- On a freed seat (expiry or cancellation), notify the next waitlisted user via a new observer event.
- Demo: Alice locks but never pays → after the timeout her seats free up; Bob (waitlisted) is notified and books them.

## Constraints

- One file per class/type in **Java and C++**
- No real background threads — drive time via an injected value/tick
- Reuse `releaseSeats` and the observer mechanism; don't duplicate seat-state logic
- Adding expiry/waitlist must not change the core lock→pay→confirm flow's happy path

## Submission

Put your solution in `33-BookMyShow/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
