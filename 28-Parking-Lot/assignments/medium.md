# Assignment: Dynamic Surge Pricing + Multiple Entrances (Design + Code)

## Objective

Add **dynamic (surge) pricing** and support **multiple entrance/exit panels** with a payment step, deepening the Strategy and Singleton usage and introducing an **Observer** touch. Implement in **Java and C++**.

## Part 1 — Dynamic Surge Pricing (Strategy)

Add a `SurgePricingStrategy` whose per-hour rate rises with **occupancy**:

- Base hourly rate, multiplied by a **surge factor** that depends on how full the lot is when the vehicle exits:
  - < 50% full → ×1.0
  - 50–80% full → ×1.5
  - > 80% full → ×2.0
- The strategy needs the lot's current occupancy. Decide **how it gets that** without tightly coupling the strategy to the whole `ParkingLot` (hint: pass an occupancy value or a small read-only interface, not the entire lot).

## Part 2 — Entrance / Exit Panels

Add `EntrancePanel` and `ExitPanel`:
- `EntrancePanel.scanAndPark(VehicleType, plate, entryTime)` uses the `VehicleFactory` + `ParkingLot` to park and returns a ticket.
- `ExitPanel.processExit(ticket, exitTime, strategy)` computes the fee and processes payment.
- Multiple panels share the **one** `ParkingLot` (Singleton) — demonstrate two entrances parking concurrently (sequentially in the demo is fine).

## Part 3 — Observer: full-lot notifications

When the lot becomes **full** (0 spots free) or transitions back to **available**, notify observers (e.g., a `DisplayBoard` at each entrance that shows FULL / SPACES). Reuse the **Observer** pattern (Ch23).

## Design Tasks (answer briefly)

1. How does `SurgePricingStrategy` obtain occupancy **without** depending on the concrete `ParkingLot`? What abstraction did you introduce, and why is that better?
2. Why are `EntrancePanel`/`ExitPanel` separate from `ParkingLot`? (Single Responsibility — the lot coordinates state; panels are the I/O boundary.)
3. Is the full/available notification **Observer** or **Mediator**? Justify (Ch20 vs Ch23).

## Implementation Requirements

- `SurgePricingStrategy implements PricingStrategy`, occupancy-aware.
- `EntrancePanel`, `ExitPanel`, `DisplayBoard` (observer).
- `ParkingLot` notifies display boards on full/available transitions.
- Demo: two entrances park several vehicles until FULL (boards show FULL), one exits (boards show SPACES), and a surge-priced exit charges more when the lot was busy.

## Constraints

- One file per class/type in **Java and C++**
- The pricing strategy must not hold a reference to the concrete `ParkingLot`
- Adding surge pricing must not modify existing strategies (OCP)
- The lot remains the single Singleton coordinator; panels/boards depend on abstractions

## Stretch Goal (optional)

Add a `LostTicketStrategy` (a fixed penalty fee) and show the exit panel can select it when a ticket is missing — reinforcing that pricing is fully pluggable.

## Submission

Put your solution in `28-Parking-Lot/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md` answering the design tasks.
