# Assignment: EV Charging Spots + Reservations (Design + Code)

## Objective

Extend the parking lot with **electric-vehicle charging spots** and a **reservation** capability, exercising the pattern choices from the chapter. This is a **mini design problem** — decide the classes, then implement in **Java and C++**.

## New Requirements

1. **EV charging spots** — a spot that can charge an electric vehicle. Only electric vehicles may use it; a non-EV should be sent to a normal spot instead.
2. **Electric vehicles** — a new vehicle type (`ElectricCar`) that *prefers* an EV spot but can fall back to a normal spot if none is free.
3. **Reservations** — a customer can reserve a spot type on a floor ahead of time; a reserved spot is not handed to walk-in vehicles until the reservation is used or expires.

## Design Tasks (answer briefly in a comment or `DESIGN.md`)

1. **Where does `ElectricSpot` fit** in the `ParkingSpot` hierarchy? Does `canFit` need to change, and how do you prevent a gas car from taking a charging spot while still letting the EV fall back to a normal spot?
2. **Reservation** — which class owns reservations (the `ParkingLot`, the `ParkingFloor`, or a new `ReservationManager`)? Justify using the Single Responsibility Principle.
3. Which existing patterns do you reuse, and do you introduce any new one (e.g., **State** for a spot that is `Free`/`Reserved`/`Occupied`)?

## Implementation Requirements

- Add `VehicleType.ELECTRIC` (or an `ElectricCar` subclass) and an `ElectricSpot` (subclass of `ParkingSpot`).
- `ElectricSpot.canFit` accepts **only** electric vehicles.
- Parking an electric vehicle tries an `ElectricSpot` first, then falls back to a normal fitting spot.
- Add a `reserve(int floor, SpotType type)` that marks a matching spot reserved; `parkVehicle` must skip reserved spots for other vehicles.
- Update the demo to: reserve a large spot, show a walk-in truck skips it, then use the reservation.

## Constraints

- One file per class/type in **Java and C++**
- Do **not** modify the pricing or vehicle-factory code more than necessary (OCP)
- The `ParkingLot` stays the single coordinator (Singleton)
- Electric fallback logic must not duplicate the normal fit logic — reuse `canFit`

## Submission

Put your solution in `28-Parking-Lot/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md` answering the design tasks.
