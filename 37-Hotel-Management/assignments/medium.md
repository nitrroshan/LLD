# Chapter 37 — Assignment (Medium)

## Date-range availability + cancellation with a fee strategy

The **big** upgrade — this is the follow-up the interviewer really cares about. v1 models
"available now" with a single room `State`; real hotels book **future date ranges**. Add a
calendar model, then cancellations.

### Part A — Date-range availability

Replace "is the room free *now*" with "is the room free for `[checkIn, checkOut)`".

Requirements:
- Represent a stay as a **date range** (use integer day numbers to stay deterministic, like
  earlier chapters — e.g., `checkIn = 10`, `checkOut = 13` means 3 nights).
- Give each `Room` (or a `BookingCalendar` helper it owns) a set of booked intervals.
  `isAvailable(checkIn, checkOut)` returns true only if the range does **not overlap** any
  existing booking. Standard interval-overlap test: `aStart < bEnd && bStart < aEnd`.
- `Hotel.searchAvailable(type, checkIn, checkOut)` returns rooms of that type free for the
  whole range.
- `bookRoom(guest, type, checkIn, checkOut)` reserves the interval on the chosen room.
- **Two non-overlapping reservations on the same room must both succeed.** Prove it in the
  demo (e.g., room 201 booked for days 10–13 and again for 15–18).

Design note to answer: the physical `RoomState` (Available/Booked/Occupied) still models
the room **on the day of stay** (check-in/out). Explain in a short comment or `DESIGN.md`
how the *calendar* (future availability) and the *state machine* (today's physical status)
are **two different concerns** — and why conflating them into one flag was the v1 limitation.

### Part B — Cancellation with a fee `Strategy`

Requirements:
- Add `Hotel.cancel(Reservation)` that frees the room's interval, sets the reservation
  status to `CANCELLED`, and fires an observer event (`onCancelled`) — add that method to
  `ReservationObserver` (its existing implementers can no-op it).
- Introduce a `CancellationPolicy` **Strategy** computing the fee: e.g.,
  - `FreeCancellation` → 0,
  - `PercentageCancellation(0.5)` → 50% of the amount if cancelled "late."
- The hotel applies the policy on cancel and reports the fee. Keep the policy pluggable
  (constructor-injected on the hotel or passed to `cancel`).

### Part C — Concurrency note (design only)

In a comment or `DESIGN.md`, describe how you'd make `searchAvailable → book` **atomic** so
two guests can't grab the same room+range simultaneously (lock the room / CAS the interval /
DB row-lock). No threading code required — just the reasoning, connecting it to the parking
lot and BookMyShow chapters.

### Constraints

- Availability logic belongs on the room/calendar, not smeared across the hotel.
- Cancellation fee is a **Strategy** — no `if (policyType == …)` in the hotel.
- Keep money and dates as integers for a deterministic demo.

### Demo (extend `Main` / `main.cpp`)

1. Book room 201 for days 10–13; then book it again for 15–18 (both succeed — no overlap).
2. Attempt to book 201 for 12–16 (overlaps 10–13) — rejected.
3. Cancel the first reservation with a `PercentageCancellation(0.5)` policy; show the fee and
   that days 10–13 are free again.

### What good looks like

- Availability is a clean interval-overlap check; non-overlapping bookings coexist.
- Cancellation fee is a swappable Strategy; the state machine still models the physical stay.
- A crisp written explanation of *calendar availability vs physical room state* and how you'd
  make claiming atomic under concurrency.
