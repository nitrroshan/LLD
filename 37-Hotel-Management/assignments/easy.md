# Chapter 37 — Assignment (Easy)

## Add a Maintenance state + Weekend pricing

A **design + implementation** exercise reinforcing **State** and **Strategy**. Both
additions must be *additive* — no changes to existing states or the booking flow.

### Part A — `MaintenanceState` (State)

Rooms sometimes go out of service (a burst pipe, deep cleaning).

Requirements:
- Add a `MaintenanceState` implementing `RoomState` in which **all guest actions are
  refused** (`book`, `checkIn`, `checkOut` all print a "room under maintenance" message
  and do nothing).
- Add a way to put a room into and out of maintenance. Two clean options — pick one and
  justify it:
  - a method on `Room` (`enterMaintenance()` / `markReady()`), or
  - two extra actions on the `RoomState` interface (only if you think every state should
    answer them).
- Entering maintenance should only be allowed from **Available** (you can't send an
  occupied room for maintenance without checkout first). `markReady()` returns it to
  Available.
- `searchAvailable(type)` must **skip** rooms in maintenance (it already filters on the
  `AVAILABLE` state name, so verify this still holds).

### Part B — `WeekendPricingStrategy` (Strategy)

Requirements:
- Add a `WeekendPricingStrategy` that charges a surcharge (e.g., +25%) on top of the base
  nightly rate: `basePrice * nights * 1.25`.
- It plugs in via the existing `PricingStrategy` interface — the `Hotel` and booking code
  must not change.
- Demonstrate swapping the hotel's pricing to weekend rates and booking a room.

### Constraints

- **Do not modify** `AvailableState`, `BookedState`, `OccupiedState`, or `Hotel`'s booking
  logic (a small `Room` method for maintenance entry is fine).
- Maintenance and weekend pricing are each **one new class** — if you're editing the
  booking flow, reconsider.

### Demo (extend `Main` / `main.cpp`)

1. Put room 101 into maintenance; show that `searchAvailable(SINGLE)` no longer returns it
   and that trying to `book()` it is refused.
2. `markReady()` room 101 and show it can be booked again.
3. Switch the hotel to `WeekendPricingStrategy` and book a Double — confirm the amount is
   the surcharged price.

### What good looks like

- `MaintenanceState` is additive; the other states are untouched.
- Weekend pricing is one class; the hotel didn't change.
- You can articulate *why* maintenance entry is restricted to the Available state (the
  state machine enforces legal transitions).
