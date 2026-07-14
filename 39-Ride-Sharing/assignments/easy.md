# Chapter 39 — Assignment (Easy)

## ETA / rating-based matching + a cancellation fee

A **design + implementation** exercise reinforcing **Strategy** and **State**. Both
additions must be *additive* — no changes to the service's core flow.

### Part A — New matching strategies

The service currently matches the **nearest** driver. Add alternatives behind the same
`RideMatchingStrategy` interface:

1. **`HighestRatedNearbyMatchingStrategy`** — among drivers within a distance threshold of the
   pickup, pick the one with the **highest rating** (`Driver.rating()`), breaking ties by
   distance.
2. **`EtaMatchingStrategy`** (bonus) — pick the driver with the smallest **ETA**. For the demo,
   approximate ETA as `distance / speed` where each vehicle type has a nominal speed; this
   shows that "nearest by straight-line distance" and "soonest to arrive" can differ.

Requirements:
- Each is a new class implementing `RideMatchingStrategy`; the `RideSharingService` is
  **unchanged** — the caller passes the strategy to `requestRide`.
- Reuse the `LocationService` (the caching proxy) for distances — don't recompute or bypass it.

### Part B — Cancellation fee

Right now cancelling is free. Add a fee when a driver was already assigned/en route.

Requirements:
- Introduce a `CancellationPolicy` **Strategy**: `computeFee(Trip trip)`.
  - `FreeCancellation` → 0.
  - `FlatFeeCancellation(amount)` → charges a flat fee **only if** the trip was already in
    `DRIVER_ASSIGNED` (a driver was dispatched), else 0.
- The service (or the trip) applies the policy on cancel and reports the fee. Keep the policy
  pluggable (injected), not hardcoded.
- Cancelling still frees the driver (`setAvailable(true)`).

Design question to answer: the fee depends on **which state** the trip is in when cancelled.
Explain how you'd read that cleanly — via the `TripState` (e.g., a `cancellationFee` hook per
state) vs. checking the state name in the policy — and the trade-off.

### Constraints

- New matching strategies and the cancellation policy are **new classes**; don't edit
  `RideSharingService`'s existing logic beyond wiring the cancel-fee call.
- Reuse the location **proxy** for any distance/ETA math.

### Demo (extend `Main` / `main.cpp`)

1. Register drivers with different ratings; request a ride with
   `HighestRatedNearbyMatchingStrategy` and show a different driver is chosen than "nearest".
2. Assign a driver, then cancel with a `FlatFeeCancellation` and show the fee is charged;
   cancel a still-`REQUESTED` trip and show the fee is 0.

### What good looks like

- Matching variety = new strategies; the service didn't change.
- Cancellation fee is a pluggable Strategy that depends on the trip's **State**.
- Distances still go through the caching proxy.
